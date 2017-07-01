#include "stdafx.h"
#include "dxerr2015/dxerr.h"
#include "NET_Common.h"
#include "net_server.h"
#include <functional>

#include "NET_Log.h"

#pragma warning(push)
#pragma warning(disable : 4995)
#include <malloc.h>
#pragma warning(pop)

static INetLog* pSvNetLog = NULL;

#define NET_BANNED_STR "Player banned by server!"
#define NET_PROTECTED_SERVER_STR "Access denied by protected server for this player!"
#define NET_NOTFOR_SUBNET_STR "Your IP does not present in server's subnet"

void dump_URL(LPCSTR p, IDirectPlay8Address* A);

LPCSTR nameTraffic = "traffic.net";

XRNETSERVER_API int psNET_ServerUpdate = 30; // FPS
XRNETSERVER_API int psNET_ServerPending = 3;

XRNETSERVER_API ClientID BroadcastCID(0xffffffff);

IClient::IClient(CTimer* timer) : stats(timer), server(NULL) {
    dwTime_LastUpdate = 0;
    flags.bLocal = FALSE;
    flags.bConnected = FALSE;
    flags.bReconnect = FALSE;
    flags.bVerified = TRUE;
}

IClient::~IClient() {}

void IClientStatistic::Update(DPN_CONNECTION_INFO& CI) {
    u32 time_global = TimeGlobal(device_timer);
    if (time_global - dwBaseTime >= 999) {
        dwBaseTime = time_global;

        mps_recive = CI.dwMessagesReceived - mps_receive_base;
        mps_receive_base = CI.dwMessagesReceived;

        u32 cur_msend = CI.dwMessagesTransmittedHighPriority +
                        CI.dwMessagesTransmittedNormalPriority +
                        CI.dwMessagesTransmittedLowPriority;
        mps_send = cur_msend - mps_send_base;
        mps_send_base = cur_msend;

        dwBytesSendedPerSec = dwBytesSended;
        dwBytesSended = 0;
        dwBytesReceivedPerSec = dwBytesReceived;
        dwBytesReceived = 0;
    }
    ci_last = CI;
}

// {0218FA8B-515B-4bf2-9A5F-2F079D1759F3}
static const GUID NET_GUID = {
    0x218fa8b, 0x515b, 0x4bf2, { 0x9a, 0x5f, 0x2f, 0x7, 0x9d, 0x17, 0x59, 0xf3 }
};
// {8D3F9E5E-A3BD-475b-9E49-B0E77139143C}
static const GUID CLSID_NETWORKSIMULATOR_DP8SP_TCPIP = {
    0x8d3f9e5e, 0xa3bd, 0x475b, { 0x9e, 0x49, 0xb0, 0xe7, 0x71, 0x39, 0x14, 0x3c }
};

static HRESULT WINAPI Handler(PVOID pvUserContext, DWORD dwMessageType, PVOID pMessage) {
    IPureServer* C = (IPureServer*)pvUserContext;
    return C->net_Handler(dwMessageType, pMessage);
}

//------------------------------------------------------------------------------

void IClient::_SendTo_LL(const void* data, u32 size, u32 flags, u32 timeout) {
    R_ASSERT(server);
    server->IPureServer::SendTo_LL(ID, const_cast<void*>(data), size, flags, timeout);
}

//------------------------------------------------------------------------------
IClient* IPureServer::ID_to_client(ClientID ID, bool ScanAll) {
    if (0 == ID.value())
        return NULL;
    IClient* ret_client = GetClientByID(ID);
    if (ret_client || !ScanAll)
        return ret_client;

    return NULL;
}

void IPureServer::_Recieve(const void* data, u32 data_size, u32 param) {
    if (data_size >= NET_PacketSizeLimit) {
        Msg("! too large packet size[%d] received, DoS attack?", data_size);
        return;
    }

    NET_Packet packet;
    ClientID id;

    id.set(param);
    packet.construct(data, data_size);
    // DWORD currentThreadId = GetCurrentThreadId();
    // Msg("-S- Entering to csMessages from _Receive [%d]", currentThreadId);
    csMessage.lock();
    // LogStackTrace(
    //		make_string("-S- Entered to csMessages [%d]", currentThreadId).c_str());
    //---------------------------------------
    if (psNET_Flags.test(NETFLAG_LOG_SV_PACKETS)) {
        if (!pSvNetLog)
            pSvNetLog = xr_new<INetLog>("logs\\net_sv_log.log", TimeGlobal(device_timer));

        if (pSvNetLog)
            pSvNetLog->LogPacket(TimeGlobal(device_timer), &packet, TRUE);
    }
    //---------------------------------------
    u32 result = OnMessage(packet, id);
    // Msg("-S- Leaving from csMessages [%d]", currentThreadId);
    csMessage.unlock();

    if (result)
        SendBroadcast(id, packet, result);
}

//==============================================================================

IPureServer::IPureServer(CTimer* timer) {
    device_timer = timer;
    stats.clear();
    stats.dwSendTime = TimeGlobal(device_timer);
    SV_Client = NULL;
    NET = NULL;
    net_Address_device = NULL;
    pSvNetLog = NULL; // xr_new<INetLog>("logs\\net_sv_log.log", TimeGlobal(device_timer));
#ifdef DEBUG
    sender_functor_invoked = false;
#endif
}

IPureServer::~IPureServer() {
    SV_Client = NULL;
    xr_delete(pSvNetLog);
}

IPureServer::EConnect IPureServer::Connect(LPCSTR options, GameDescriptionData& game_descr) {
    connect_options = options;

    // Parse options
    string4096 session_name;

    string64 password_str = "";
    u32 dwMaxPlayers = 0;

    // sertanly we can use game_descr structure for determinig level_name, but for backward
    // compatibility we save next line...
    xr_strcpy(session_name, options);
    if (strchr(session_name, '/'))
        *strchr(session_name, '/') = 0;

    if (strstr(options, "psw=")) {
        const char* PSW = strstr(options, "psw=") + 4;
        if (strchr(PSW, '/'))
            strncpy_s(password_str, PSW, strchr(PSW, '/') - PSW);
        else
            strncpy_s(password_str, PSW, 63);
    }
    if (strstr(options, "maxplayers=")) {
        const char* sMaxPlayers = strstr(options, "maxplayers=") + 11;
        string64 tmpStr = "";
        if (strchr(sMaxPlayers, '/'))
            strncpy_s(tmpStr, sMaxPlayers, strchr(sMaxPlayers, '/') - sMaxPlayers);
        else
            strncpy_s(tmpStr, sMaxPlayers, 63);
        dwMaxPlayers = atol(tmpStr);
    }
    if (dwMaxPlayers > 32 || dwMaxPlayers < 1)
        dwMaxPlayers = 32;
#ifdef DEBUG
    Msg("MaxPlayers = %d", dwMaxPlayers);
#endif // #ifdef DEBUG

    //-------------------------------------------------------------------
    BOOL bPortWasSet = FALSE;
    u32 dwServerPort = START_PORT_LAN_SV;
    if (strstr(options, "portsv=")) {
        const char* ServerPort = strstr(options, "portsv=") + 7;
        string64 tmpStr = "";
        if (strchr(ServerPort, '/'))
            strncpy_s(tmpStr, ServerPort, strchr(ServerPort, '/') - ServerPort);
        else
            strncpy_s(tmpStr, ServerPort, 63);
        dwServerPort = atol(tmpStr);
        clamp(dwServerPort, u32(START_PORT), u32(END_PORT));
        bPortWasSet = TRUE; // this is not casual game
    }

    return ErrNoError;
}

void IPureServer::Disconnect() {
    //.	config_Save		();

    if (NET)
        NET->Close(0);

    // Release interfaces
    _RELEASE(net_Address_device);
    _RELEASE(NET);
}

HRESULT IPureServer::net_Handler(u32 dwMessageType, PVOID pMessage) {
    // HRESULT     hr = S_OK;

    switch (dwMessageType) {
    case DPN_MSGID_ENUM_HOSTS_QUERY: {
        PDPNMSG_ENUM_HOSTS_QUERY msg = PDPNMSG_ENUM_HOSTS_QUERY(pMessage);
        if (0 == msg->dwReceivedDataSize)
            return S_FALSE;
        if (!stricmp((const char*)msg->pvReceivedData, "ToConnect"))
            return S_OK;
        if (*((const GUID*)msg->pvReceivedData) != NET_GUID)
            return S_FALSE;
        if (!OnCL_QueryHost())
            return S_FALSE;
        return S_OK;
    } break;
    case DPN_MSGID_CREATE_PLAYER: {
        PDPNMSG_CREATE_PLAYER msg = PDPNMSG_CREATE_PLAYER(pMessage);
        const u32 max_size = 1024;
        char bufferData[max_size];
        DWORD bufferSize = max_size;
        std::memset(bufferData, 0, bufferSize);
        string512 res;

        // retreive info
        DPN_PLAYER_INFO* Pinfo = (DPN_PLAYER_INFO*)bufferData;
        Pinfo->dwSize = sizeof(DPN_PLAYER_INFO);
        HRESULT _hr = NET->GetClientInfo(msg->dpnidPlayer, Pinfo, &bufferSize, 0);
        if (_hr == DPNERR_INVALIDPLAYER) {
            Assign_ServerType(res); // once
            break;                  // server player
        }

        CHK_DX(_hr);

        // string64			cname;
        // CHK_DX( WideCharToMultiByte( CP_ACP, 0, Pinfo->pwszName, -1, cname, sizeof(cname) , 0, 0
        // ) );

        SClientConnectData cl_data;
        // xr_strcpy( cl_data.name, cname );

        if (Pinfo->pvData && Pinfo->dwDataSize == sizeof(cl_data)) {
            cl_data = *((SClientConnectData*)Pinfo->pvData);
        }
        cl_data.clientID.set(msg->dpnidPlayer);

        new_client(&cl_data);
    } break;
    case DPN_MSGID_DESTROY_PLAYER: {
        PDPNMSG_DESTROY_PLAYER msg = PDPNMSG_DESTROY_PLAYER(pMessage);
        IClient* tmp_client = net_players.GetFoundClient(
            ClientIdSearchPredicate(static_cast<ClientID>(msg->dpnidPlayer)));
        if (tmp_client) {
            tmp_client->flags.bConnected = FALSE;
            tmp_client->flags.bReconnect = FALSE;
            OnCL_Disconnected(tmp_client);
            // real destroy
            client_Destroy(tmp_client);
        }
    } break;
    case DPN_MSGID_RECEIVE: {

        PDPNMSG_RECEIVE pMsg = PDPNMSG_RECEIVE(pMessage);
        void* m_data = pMsg->pReceiveData;
        u32 m_size = pMsg->dwReceiveDataSize;
        DPNID m_sender = pMsg->dpnidSender;

        MSYS_PING* m_ping = (MSYS_PING*)m_data;

        if ((m_size > 2 * sizeof(u32)) && (m_ping->sign1 == 0x12071980) &&
            (m_ping->sign2 == 0x26111975)) {
            // this is system message
            if (m_size == sizeof(MSYS_PING)) {
                // ping - save server time and reply
                m_ping->dwTime_Server = TimerAsync(device_timer);
                ClientID ID;
                ID.set(m_sender);
                //						IPureServer::SendTo_LL
                //(ID,m_data,m_size,net_flags(FALSE,FALSE,TRUE));
                IPureServer::SendTo_Buf(ID, m_data, m_size, net_flags(FALSE, FALSE, TRUE, TRUE));
            }
        } else {
            MultipacketReciever::RecievePacket(pMsg->pReceiveData, pMsg->dwReceiveDataSize,
                                               m_sender);
        }
    } break;

    case DPN_MSGID_INDICATE_CONNECT: {
        PDPNMSG_INDICATE_CONNECT msg = (PDPNMSG_INDICATE_CONNECT)pMessage;

        // first connected client is SV_Client so if it is NULL then this server client tries to
        // connect ;)
        if (SV_Client) {
            msg->dwReplyDataSize = sizeof(NET_NOTFOR_SUBNET_STR);
            msg->pvReplyData = NET_NOTFOR_SUBNET_STR;
            return S_FALSE;
        }
    } break;
    }
    return S_OK;
}

void IPureServer::Flush_Clients_Buffers() {
#if NET_LOG_PACKETS
    Msg("#flush server send-buf");
#endif

    struct LocalSenderFunctor {
        static void FlushBuffer(IClient* client) { client->MultipacketSender::FlushSendBuffer(0); }
    };

    net_players.ForEachClientDo(LocalSenderFunctor::FlushBuffer);
}

void IPureServer::SendTo_Buf(ClientID id, void* data, u32 size, u32 dwFlags, u32 dwTimeout) {
    IClient* tmp_client = net_players.GetFoundClient(ClientIdSearchPredicate(id));
    VERIFY(tmp_client);
    tmp_client->MultipacketSender::SendPacket(data, size, dwFlags, dwTimeout);
}

void IPureServer::SendTo_LL(ClientID ID /*DPNID ID*/, void* data, u32 size, u32 dwFlags,
                            u32 dwTimeout) {
    //	if (psNET_Flags.test(NETFLAG_LOG_SV_PACKETS)) pSvNetLog->LogData(TimeGlobal(device_timer),
    //data, size);
    if (psNET_Flags.test(NETFLAG_LOG_SV_PACKETS)) {
        if (!pSvNetLog)
            pSvNetLog = xr_new<INetLog>("logs\\net_sv_log.log", TimeGlobal(device_timer));
        if (pSvNetLog)
            pSvNetLog->LogData(TimeGlobal(device_timer), data, size);
    }

    // send it
    DPN_BUFFER_DESC desc;
    desc.dwBufferSize = size;
    desc.pBufferData = LPBYTE(data);

#ifdef _DEBUG
    u32 time_global = TimeGlobal(device_timer);
    if (time_global - stats.dwSendTime >= 999) {
        stats.dwBytesPerSec = (stats.dwBytesPerSec * 9 + stats.dwBytesSended) / 10;
        stats.dwBytesSended = 0;
        stats.dwSendTime = time_global;
    };
    if (ID.value())
        stats.dwBytesSended += size;
#endif

    // verify
    VERIFY(desc.dwBufferSize);
    VERIFY(desc.pBufferData);

    DPNHANDLE hAsync = 0;
    HRESULT _hr =
        NET->SendTo(ID.value(), &desc, 1, dwTimeout, 0, &hAsync, dwFlags | DPNSEND_COALESCE);

    //	Msg("- IPureServer::SendTo_LL [%d]", size);

    if (SUCCEEDED(_hr) || (DPNERR_CONNECTIONLOST == _hr))
        return;

    R_CHK(_hr);
}

void IPureServer::SendTo(ClientID ID /*DPNID ID*/, NET_Packet& P, u32 dwFlags, u32 dwTimeout) {
    SendTo_LL(ID, P.B.data, P.B.count, dwFlags, dwTimeout);
}

void IPureServer::SendBroadcast_LL(ClientID exclude, void* data, u32 size, u32 dwFlags) {
    struct ClientExcluderPredicate {
        ClientID id_to_exclude;
        ClientExcluderPredicate(ClientID exclude) : id_to_exclude(exclude) {}
        bool operator()(IClient* client) {
            if (client->ID == id_to_exclude)
                return false;
            if (!client->flags.bConnected)
                return false;
            return true;
        }
    };
    struct ClientSenderFunctor {
        IPureServer* m_owner;
        void* m_data;
        u32 m_size;
        u32 m_dwFlags;
        ClientSenderFunctor(IPureServer* owner, void* data, u32 size, u32 dwFlags)
            : m_owner(owner), m_data(data), m_size(size), m_dwFlags(dwFlags) {}
        void operator()(IClient* client) {
            m_owner->SendTo_LL(client->ID, m_data, m_size, m_dwFlags);
        }
    };
    ClientSenderFunctor temp_functor(this, data, size, dwFlags);
    net_players.ForFoundClientsDo(ClientExcluderPredicate(exclude), temp_functor);
}

void IPureServer::SendBroadcast(ClientID exclude, NET_Packet& P, u32 dwFlags) {
    // Perform broadcasting
    SendBroadcast_LL(exclude, P.B.data, P.B.count, dwFlags);
}

u32 IPureServer::OnMessage(NET_Packet& P,
                           ClientID sender) // Non-Zero means broadcasting with "flags" as returned
{
    /*
    u16 m_type;
    P.r_begin	(m_type);
    switch (m_type)
    {
    case M_CHAT:
            {
                    char	buffer[256];
                    P.r_string(buffer);
                    printf	("RECEIVE: %s\n",buffer);
            }
            break;
    }
    */

    return 0;
}

void IPureServer::OnCL_Connected(IClient* CL) {
    Msg("* Player 0x%08x connected.\n", CL->ID.value());
}
void IPureServer::OnCL_Disconnected(IClient* CL) {
    Msg("* Player 0x%08x disconnected.\n", CL->ID.value());
}

BOOL IPureServer::HasBandwidth(IClient* C) {
    u32 dwTime = TimeGlobal(device_timer);
    u32 dwInterval = 0;

    UpdateClientStatistic(C);
    C->dwTime_LastUpdate = dwTime;
    dwInterval = 1000;
    return TRUE;
}

void IPureServer::UpdateClientStatistic(IClient* C) {
    // Query network statistic for this client
    DPN_CONNECTION_INFO CI;
    std::memset(&CI, 0, sizeof(CI));
    CI.dwSize = sizeof(CI);
    C->stats.Update(CI);
}

void IPureServer::ClearStatistic() {
    stats.clear();
    struct StatsClearFunctor {
        static void Clear(IClient* client) { client->stats.Clear(); }
    };
    net_players.ForEachClientDo(StatsClearFunctor::Clear);
};

/*bool			IPureServer::DisconnectClient	(IClient* C)
{
        if (!C) return false;

        string64 Reason = "st_kicked_by_server";
        HRESULT res = NET->DestroyClient(C->ID.value(), Reason, xr_strlen(Reason)+1, 0);
        CHK_DX(res);
        return true;
}*/

bool IPureServer::DisconnectClient(IClient* C, LPCSTR Reason) {
    if (!C)
        return false;

    HRESULT res = NET->DestroyClient(C->ID.value(), Reason, xr_strlen(Reason) + 1, 0);
    CHK_DX(res);
    return true;
}
