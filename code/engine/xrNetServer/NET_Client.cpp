#include "stdafx.h"
#include "NET_Common.h"
#include "net_client.h"
#include "net_server.h"
#include "net_messages.h"
#include "NET_Log.h"

#pragma warning(push)
#pragma warning(disable : 4995)
#include <malloc.h>
#include "dxerr2015/dxerr.h"

//#pragma warning(pop)

// {0218FA8B-515B-4bf2-9A5F-2F079D1759F3}
static const GUID NET_GUID = {
    0x218fa8b, 0x515b, 0x4bf2, { 0x9a, 0x5f, 0x2f, 0x7, 0x9d, 0x17, 0x59, 0xf3 }
};

// {8D3F9E5E-A3BD-475b-9E49-B0E77139143C}
static const GUID CLSID_NETWORKSIMULATOR_DP8SP_TCPIP = {
    0x8d3f9e5e, 0xa3bd, 0x475b, { 0x9e, 0x49, 0xb0, 0xe7, 0x71, 0x39, 0x14, 0x3c }
};

const GUID CLSID_DirectPlay8Client = {
    0x743f1dc6, 0x5aba, 0x429f, { 0x8b, 0xdf, 0xc5, 0x4d, 0x03, 0x25, 0x3d, 0xc2 }
};

// {DA825E1B-6830-43d7-835D-0B5AD82956A2}
const GUID CLSID_DirectPlay8Server = {
    0xda825e1b, 0x6830, 0x43d7, { 0x83, 0x5d, 0x0b, 0x5a, 0xd8, 0x29, 0x56, 0xa2 }
};

// {286F484D-375E-4458-A272-B138E2F80A6A}
const GUID CLSID_DirectPlay8Peer = {
    0x286f484d, 0x375e, 0x4458, { 0xa2, 0x72, 0xb1, 0x38, 0xe2, 0xf8, 0x0a, 0x6a }
};

// CLSIDs added for DirectX 9

// {FC47060E-6153-4b34-B975-8E4121EB7F3C}
const GUID CLSID_DirectPlay8ThreadPool = {
    0xfc47060e, 0x6153, 0x4b34, { 0xb9, 0x75, 0x8e, 0x41, 0x21, 0xeb, 0x7f, 0x3c }
};

// {E4C1D9A2-CBF7-48bd-9A69-34A55E0D8941}
const GUID CLSID_DirectPlay8NATResolver = {
    0xe4c1d9a2, 0xcbf7, 0x48bd, { 0x9a, 0x69, 0x34, 0xa5, 0x5e, 0x0d, 0x89, 0x41 }
};

/****************************************************************************
 *
 * DirectPlay8 Interface IIDs
 *
 ****************************************************************************/

typedef REFIID DP8REFIID;

// {5102DACD-241B-11d3-AEA7-006097B01411}
const GUID IID_IDirectPlay8Client = {
    0x5102dacd, 0x241b, 0x11d3, { 0xae, 0xa7, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// {5102DACE-241B-11d3-AEA7-006097B01411}
const GUID IID_IDirectPlay8Server = {
    0x5102dace, 0x241b, 0x11d3, { 0xae, 0xa7, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// {5102DACF-241B-11d3-AEA7-006097B01411}
const GUID IID_IDirectPlay8Peer = {
    0x5102dacf, 0x241b, 0x11d3, { 0xae, 0xa7, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// IIDs added for DirectX 9

// {0D22EE73-4A46-4a0d-89B2-045B4D666425}
const GUID IID_IDirectPlay8ThreadPool = {
    0xd22ee73, 0x4a46, 0x4a0d, { 0x89, 0xb2, 0x04, 0x5b, 0x4d, 0x66, 0x64, 0x25 }
};

// {A9E213F2-9A60-486f-BF3B-53408B6D1CBB}
const GUID IID_IDirectPlay8NATResolver = {
    0xa9e213f2, 0x9a60, 0x486f, { 0xbf, 0x3b, 0x53, 0x40, 0x8b, 0x6d, 0x1c, 0xbb }
};

// {53934290-628D-11D2-AE0F-006097B01411}
const GUID CLSID_DP8SP_IPX = {
    0x53934290, 0x628d, 0x11d2, { 0xae, 0x0f, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// {6D4A3650-628D-11D2-AE0F-006097B01411}
const GUID CLSID_DP8SP_MODEM = {
    0x6d4a3650, 0x628d, 0x11d2, { 0xae, 0x0f, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// {743B5D60-628D-11D2-AE0F-006097B01411}
const GUID CLSID_DP8SP_SERIAL = {
    0x743b5d60, 0x628d, 0x11d2, { 0xae, 0x0f, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// {EBFE7BA0-628D-11D2-AE0F-006097B01411}
const GUID CLSID_DP8SP_TCPIP = {
    0xebfe7ba0, 0x628d, 0x11d2, { 0xae, 0x0f, 0x00, 0x60, 0x97, 0xb0, 0x14, 0x11 }
};

// Service providers added for DirectX 9

// {995513AF-3027-4b9a-956E-C772B3F78006}
const GUID CLSID_DP8SP_BLUETOOTH = {
    0x995513af, 0x3027, 0x4b9a, { 0x95, 0x6e, 0xc7, 0x72, 0xb3, 0xf7, 0x80, 0x06 }
};

const GUID CLSID_DirectPlay8Address = {
    0x934a9523, 0xa3ca, 0x4bc5, { 0xad, 0xa0, 0xd6, 0xd9, 0x5d, 0x97, 0x94, 0x21 }
};

const GUID IID_IDirectPlay8Address = {
    0x83783300, 0x4063, 0x4c8a, { 0x9d, 0xb3, 0x82, 0x83, 0x0a, 0x7f, 0xeb, 0x31 }
};

static INetLog* pClNetLog = NULL;

void dump_URL(LPCSTR p, IDirectPlay8Address* A) {
    string256 aaaa;
    DWORD aaaa_s = sizeof(aaaa);
    R_CHK(A->GetURLA(aaaa, &aaaa_s));
    Log(p, aaaa);
}

//
INetQueue::INetQueue() {
    unused.reserve(128);
    for (int i = 0; i < 16; i++)
        unused.push_back(xr_new<NET_Packet>());
}

INetQueue::~INetQueue() {
    std::lock_guard<decltype(cs)> lock(cs);
    u32 it;
    for (it = 0; it < unused.size(); it++)
        xr_delete(unused[it]);
    for (it = 0; it < ready.size(); it++)
        xr_delete(ready[it]);
}

static u32 LastTimeCreate = 0;
NET_Packet* INetQueue::Create() {
    NET_Packet* P = 0;
    // cs.Enter		();
    //#ifdef _DEBUG
    //		Msg ("- INetQueue::Create - ready %d, unused %d", ready.size(), unused.size());
    //#endif
    if (unused.empty()) {
        ready.push_back(xr_new<NET_Packet>());
        P = ready.back();
        //---------------------------------------------
        LastTimeCreate = GetTickCount();
        //---------------------------------------------
    } else {
        ready.push_back(unused.back());
        unused.pop_back();
        P = ready.back();
    }
    // cs.Leave		();
    return P;
}
NET_Packet* INetQueue::Create(const NET_Packet& _other) {
    NET_Packet* P = 0;
    std::lock_guard<decltype(cs)> lock(cs);
    //#ifdef _DEBUG
    //		Msg ("- INetQueue::Create - ready %d, unused %d", ready.size(), unused.size());
    //#endif
    if (unused.empty()) {
        ready.push_back(xr_new<NET_Packet>());
        P = ready.back();
        //---------------------------------------------
        LastTimeCreate = GetTickCount();
        //---------------------------------------------
    } else {
        ready.push_back(unused.back());
        unused.pop_back();
        P = ready.back();
    }
    std::memcpy(P, &_other, sizeof(NET_Packet));
    return P;
}
NET_Packet* INetQueue::Retreive() {
    NET_Packet* P = 0;
    // cs.Enter		();
    //#ifdef _DEBUG
    //			Msg ("INetQueue::Retreive - ready %d, unused %d", ready.size(),
    //unused.size()); #endif
    if (!ready.empty())
        P = ready.front();
    //---------------------------------------------
    else {
        u32 tmp_time = GetTickCount() - 60000;
        u32 size = unused.size();
        if ((LastTimeCreate < tmp_time) && (size > 32)) {
            xr_delete(unused.back());
            unused.pop_back();
        }
    }
    //---------------------------------------------
    // cs.Leave		();
    return P;
}
void INetQueue::Release() {
    // cs.Enter		();
    //#ifdef _DEBUG
    //		Msg ("INetQueue::Release - ready %d, unused %d", ready.size(), unused.size());
    //#endif
    VERIFY(!ready.empty());
    //---------------------------------------------
    u32 tmp_time = GetTickCount() - 60000;
    u32 size = unused.size();
    ready.front()->B.count = 0;
    if ((LastTimeCreate < tmp_time) && (size > 32)) {
        xr_delete(ready.front());
    } else
        unused.push_back(ready.front());
    //---------------------------------------------
    ready.pop_front();
    // cs.Leave		();
}

//
const u32 syncQueueSize = 512;
const int syncSamples = 256;
class XRNETSERVER_API syncQueue {
    u32 table[syncQueueSize];
    u32 write;
    u32 count;

public:
    syncQueue() { clear(); }

    IC void push(u32 value) {
        table[write++] = value;
        if (write == syncQueueSize)
            write = 0;

        if (count <= syncQueueSize)
            count++;
    }
    IC u32* begin() { return table; }
    IC u32* end() { return table + count; }
    IC u32 size() { return count; }
    IC void clear() {
        write = 0;
        count = 0;
    }
} net_DeltaArray;

//-------
XRNETSERVER_API Flags32 psNET_Flags = { 0 };
XRNETSERVER_API int psNET_ClientUpdate = 30; // FPS
XRNETSERVER_API int psNET_ClientPending = 2;
XRNETSERVER_API char psNET_Name[32] = "Player";
XRNETSERVER_API BOOL psNET_direct_connect = FALSE;

/****************************************************************************
 *
 * DirectPlay8 Service Provider GUIDs
 *
 ****************************************************************************/

static HRESULT WINAPI Handler(PVOID pvUserContext, DWORD dwMessageType, PVOID pMessage) {
    IPureClient* C = (IPureClient*)pvUserContext;
    return C->net_Handler(dwMessageType, pMessage);
}

//------------------------------------------------------------------------------

void IPureClient::_SendTo_LL(const void* data, u32 size, u32 flags, u32 timeout) {
    IPureClient::SendTo_LL(const_cast<void*>(data), size, flags, timeout);
}

//------------------------------------------------------------------------------

void IPureClient::_Recieve(const void* data, u32 data_size, u32 /*param*/) {
    MSYS_PING* cfg = (MSYS_PING*)data;
    net_Statistic.dwBytesReceived += data_size;

    if ((data_size >= 2 * sizeof(u32)) && (cfg->sign1 == 0x12071980) &&
        (cfg->sign2 == 0x26111975)) {
        // Internal system message
        if ((data_size == sizeof(MSYS_PING))) {
            // It is reverted(server) ping
            u32 time = TimerAsync(device_timer);
            u32 ping = time - (cfg->dwTime_ClientSend);
            u32 delta = cfg->dwTime_Server + ping / 2 - time;

            net_DeltaArray.push(delta);
            Sync_Average();
            return;
        }

        if (data_size == sizeof(MSYS_CONFIG)) {
            net_Connected = EnmConnectionCompleted;
            return;
        }
        Msg("! Unknown system message");
        return;
    } else if (net_Connected == EnmConnectionCompleted) {
        // one of the messages - decompress it

        if (psNET_Flags.test(NETFLAG_LOG_CL_PACKETS)) {
            if (!pClNetLog)
                pClNetLog = xr_new<INetLog>("logs\\net_cl_log.log", timeServer());

            if (pClNetLog)
                pClNetLog->LogData(timeServer(), const_cast<void*>(data), data_size, TRUE);
        }

        OnMessage(const_cast<void*>(data), data_size);
    }
}

//==============================================================================

IPureClient::IPureClient(CTimer* timer) : net_Statistic(timer) {
    NET = NULL;
    net_Address_server = NULL;
    net_Address_device = NULL;
    device_timer = timer;
    net_TimeDelta_User = 0;
    net_Time_LastUpdate = 0;
    net_TimeDelta = 0;
    net_TimeDelta_Calculated = 0;

    pClNetLog = NULL; // xr_new<INetLog>("logs\\net_cl_log.log", timeServer());
}

IPureClient::~IPureClient() {
    xr_delete(pClNetLog);
    pClNetLog = NULL;
}

BOOL IPureClient::Connect(LPCSTR options) {
    R_ASSERT(options);
    net_Disconnected = FALSE;

    // Sync
    net_TimeDelta = 0;
    return TRUE;
}

void IPureClient::Disconnect() {
    if (NET)
        NET->Close(0);

    // Clean up Host _list_
    net_csEnumeration.lock();
    for (u32 i = 0; i < net_Hosts.size(); i++) {
        HOST_NODE& N = net_Hosts[i];
        _RELEASE(N.pHostAddress);
    }
    net_Hosts.clear();
    net_csEnumeration.unlock();

    // Release interfaces
    _SHOW_REF("cl_netADR_Server", net_Address_server);
    _RELEASE(net_Address_server);
    _SHOW_REF("cl_netADR_Device", net_Address_device);
    _RELEASE(net_Address_device);
    _SHOW_REF("cl_netCORE", NET);
    _RELEASE(NET);

    net_Connected = EnmConnectionWait;
    net_Syncronised = FALSE;
}

HRESULT IPureClient::net_Handler(u32 dwMessageType, PVOID pMessage) {
    // HRESULT     hr = S_OK;

    switch (dwMessageType) {
    case DPN_MSGID_ENUM_HOSTS_RESPONSE: {
        PDPNMSG_ENUM_HOSTS_RESPONSE pEnumHostsResponseMsg;
        const DPN_APPLICATION_DESC* pDesc;
        // HOST_NODE*                      pHostNode = NULL;
        // WCHAR*                          pwszSession = NULL;

        pEnumHostsResponseMsg = (PDPNMSG_ENUM_HOSTS_RESPONSE)pMessage;
        pDesc = pEnumHostsResponseMsg->pApplicationDescription;

        if (pDesc->dwApplicationReservedDataSize && pDesc->pvApplicationReservedData) {
            R_ASSERT(pDesc->dwApplicationReservedDataSize == sizeof(m_game_description));
            std::memcpy(&m_game_description, pDesc->pvApplicationReservedData,
                        pDesc->dwApplicationReservedDataSize);
        }

        // Insert each host response if it isn't already present
        net_csEnumeration.lock();
        BOOL bHostRegistered = FALSE;
        for (u32 I = 0; I < net_Hosts.size(); I++) {
            HOST_NODE& N = net_Hosts[I];
            if (pDesc->guidInstance == N.dpAppDesc.guidInstance) {
                // This host is already in the list
                bHostRegistered = TRUE;
                break;
            }
        }

        if (!bHostRegistered) {
            // This host session is not in the list then so insert it.
            HOST_NODE NODE;
            std::memset(&NODE, 0, sizeof(HOST_NODE));

            // Copy the Host Address
            R_CHK(pEnumHostsResponseMsg->pAddressSender->Duplicate(&NODE.pHostAddress));
            std::memcpy(&NODE.dpAppDesc, pDesc, sizeof(DPN_APPLICATION_DESC));

            // Null out all the pointers we aren't copying
            NODE.dpAppDesc.pwszSessionName = NULL;
            NODE.dpAppDesc.pwszPassword = NULL;
            NODE.dpAppDesc.pvReservedData = NULL;
            NODE.dpAppDesc.dwReservedDataSize = 0;
            NODE.dpAppDesc.pvApplicationReservedData = NULL;
            NODE.dpAppDesc.dwApplicationReservedDataSize = 0;

            if (pDesc->pwszSessionName) {
                string4096 dpSessionName;
                R_CHK(WideCharToMultiByte(CP_ACP, 0, pDesc->pwszSessionName, -1, dpSessionName,
                                          sizeof(dpSessionName), 0, 0));
                NODE.dpSessionName = (char*)(&dpSessionName[0]);
            }

            net_Hosts.push_back(NODE);
        }
        net_csEnumeration.unlock();
    } break;

    case DPN_MSGID_RECEIVE: {
        PDPNMSG_RECEIVE pMsg = (PDPNMSG_RECEIVE)pMessage;

        MultipacketReciever::RecievePacket(pMsg->pReceiveData, pMsg->dwReceiveDataSize);
    } break;
    case DPN_MSGID_TERMINATE_SESSION: {
        PDPNMSG_TERMINATE_SESSION pMsg = (PDPNMSG_TERMINATE_SESSION)pMessage;
        char* m_data = (char*)pMsg->pvTerminateData;
        u32 m_size = pMsg->dwTerminateDataSize;
        HRESULT m_hResultCode = pMsg->hResultCode;

        net_Disconnected = TRUE;

        if (m_size != 0) {
            OnSessionTerminate(m_data);
#ifdef DEBUG
            Msg("- Session terminated : %s", m_data);
#endif
        } else {
#ifdef DEBUG
            OnSessionTerminate((::Debug.error2string(m_hResultCode)));
            Msg("- Session terminated : %s", (::Debug.error2string(m_hResultCode)));
#endif
        }
    }; break;
    default: {
#if 1
        LPSTR msg = "";
        switch (dwMessageType) {
        case DPN_MSGID_ADD_PLAYER_TO_GROUP:
            msg = "DPN_MSGID_ADD_PLAYER_TO_GROUP";
            break;
        case DPN_MSGID_ASYNC_OP_COMPLETE:
            msg = "DPN_MSGID_ASYNC_OP_COMPLETE";
            break;
        case DPN_MSGID_CLIENT_INFO:
            msg = "DPN_MSGID_CLIENT_INFO";
            break;
        case DPN_MSGID_CONNECT_COMPLETE: {
            PDPNMSG_CONNECT_COMPLETE pMsg = (PDPNMSG_CONNECT_COMPLETE)pMessage;
#ifdef DEBUG
            //					const char* x =
            //DXGetErrorString9(pMsg->hResultCode);
            if (pMsg->hResultCode != S_OK) {
                DXTRACE_ERR(L"", pMsg->hResultCode);
            }
#endif
            if (pMsg->dwApplicationReplyDataSize) {
                string256 ResStr = "";
                strncpy_s(ResStr, (char*)(pMsg->pvApplicationReplyData),
                          pMsg->dwApplicationReplyDataSize);
                Msg("Connection result : %s", ResStr);
            } else
                msg = "DPN_MSGID_CONNECT_COMPLETE";
        } break;
        case DPN_MSGID_CREATE_GROUP:
            msg = "DPN_MSGID_CREATE_GROUP";
            break;
        case DPN_MSGID_CREATE_PLAYER:
            msg = "DPN_MSGID_CREATE_PLAYER";
            break;
        case DPN_MSGID_DESTROY_GROUP:
            msg = "DPN_MSGID_DESTROY_GROUP";
            break;
        case DPN_MSGID_DESTROY_PLAYER:
            msg = "DPN_MSGID_DESTROY_PLAYER";
            break;
        case DPN_MSGID_ENUM_HOSTS_QUERY:
            msg = "DPN_MSGID_ENUM_HOSTS_QUERY";
            break;
        case DPN_MSGID_GROUP_INFO:
            msg = "DPN_MSGID_GROUP_INFO";
            break;
        case DPN_MSGID_HOST_MIGRATE:
            msg = "DPN_MSGID_HOST_MIGRATE";
            break;
        case DPN_MSGID_INDICATE_CONNECT:
            msg = "DPN_MSGID_INDICATE_CONNECT";
            break;
        case DPN_MSGID_INDICATED_CONNECT_ABORTED:
            msg = "DPN_MSGID_INDICATED_CONNECT_ABORTED";
            break;
        case DPN_MSGID_PEER_INFO:
            msg = "DPN_MSGID_PEER_INFO";
            break;
        case DPN_MSGID_REMOVE_PLAYER_FROM_GROUP:
            msg = "DPN_MSGID_REMOVE_PLAYER_FROM_GROUP";
            break;
        case DPN_MSGID_RETURN_BUFFER:
            msg = "DPN_MSGID_RETURN_BUFFER";
            break;
        case DPN_MSGID_SEND_COMPLETE:
            msg = "DPN_MSGID_SEND_COMPLETE";
            break;
        case DPN_MSGID_SERVER_INFO:
            msg = "DPN_MSGID_SERVER_INFO";
            break;
        case DPN_MSGID_TERMINATE_SESSION:
            msg = "DPN_MSGID_TERMINATE_SESSION";
            break;
        default:
            msg = "???";
            break;
        }
// Msg("! ************************************ : %s",msg);
#endif
    } break;
    }

    return S_OK;
}

void IPureClient::OnMessage(void* data, u32 size) {
    // One of the messages - decompress it
    net_Queue.Lock();
    NET_Packet* P = net_Queue.Create();

    P->construct(data, size);
    P->timeReceive = timeServer_Async(); // TimerAsync				(device_timer);

    u16 m_type;
    P->r_begin(m_type);
    net_Queue.Unlock();
}

void IPureClient::timeServer_Correct(u32 sv_time, u32 cl_time) {
    u32 ping = net_Statistic.getPing();
    u32 delta = sv_time + ping / 2 - cl_time;
    net_DeltaArray.push(delta);
    Sync_Average();
}

void IPureClient::SendTo_LL(void* data, u32 size, u32 dwFlags, u32 dwTimeout) {
    if (net_Disconnected)
        return;

    if (psNET_Flags.test(NETFLAG_LOG_CL_PACKETS)) {
        if (!pClNetLog)
            pClNetLog = xr_new<INetLog>("logs\\net_cl_log.log", timeServer());
        if (pClNetLog)
            pClNetLog->LogData(timeServer(), data, size);
    }
    DPN_BUFFER_DESC desc;

    desc.dwBufferSize = size;
    desc.pBufferData = (BYTE*)data;

    net_Statistic.dwBytesSended += size;

    // verify
    VERIFY(desc.dwBufferSize);
    VERIFY(desc.pBufferData);
    VERIFY(NET);

    DPNHANDLE hAsync = 0;
    HRESULT hr = NET->Send(&desc, 1, dwTimeout, 0, &hAsync, dwFlags | DPNSEND_COALESCE);

    //	Msg("- Client::SendTo_LL [%d]", size);
    if (FAILED(hr)) {
        Msg("! ERROR: Failed to send net-packet, reason: %s", ::Debug.error2string(hr));
        //		const char* x = DXGetErrorString9(hr);
        DXTRACE_ERR(L"", hr);
    }

    //	UpdateStatistic();
}

void IPureClient::Send(NET_Packet& packet, u32 dwFlags, u32 dwTimeout) {
    MultipacketSender::SendPacket(packet.B.data, packet.B.count, dwFlags, dwTimeout);
}

void IPureClient::Flush_Send_Buffer() { MultipacketSender::FlushSendBuffer(0); }

BOOL IPureClient::net_HasBandwidth() {
    u32 dwTime = TimeGlobal(device_timer);
    u32 dwInterval = 0;
    if (net_Disconnected)
        return FALSE;

    if (psNET_ClientUpdate != 0)
        dwInterval = 1000 / psNET_ClientUpdate;
    if (psNET_Flags.test(NETFLAG_MINIMIZEUPDATES))
        dwInterval = 1000; // approx 3 times per second

    if (0 != psNET_ClientUpdate && (dwTime - net_Time_LastUpdate) > dwInterval) {
        net_Time_LastUpdate = dwTime;
        return TRUE;
    } else
        return FALSE;
}

void IPureClient::UpdateStatistic() {
    // Query network statistic for this client
    DPN_CONNECTION_INFO CI;
    std::memset(&CI, 0, sizeof(CI));
    CI.dwSize = sizeof(CI);
    HRESULT hr = NET->GetConnectionInfo(&CI, 0);
    if (FAILED(hr))
        return;

    net_Statistic.Update(CI);
}

void IPureClient::Sync_Average() {
    //***** Analyze results
    s64 summary_delta = 0;
    s32 size = net_DeltaArray.size();
    u32* I = net_DeltaArray.begin();
    u32* E = I + size;
    for (; I != E; I++)
        summary_delta += *((int*)I);

    s64 frac = s64(summary_delta) % s64(size);
    if (frac < 0)
        frac = -frac;
    summary_delta /= s64(size);
    if (frac > s64(size / 2))
        summary_delta += (summary_delta < 0) ? -1 : 1;
    net_TimeDelta_Calculated = s32(summary_delta);
    net_TimeDelta = (net_TimeDelta * 5 + net_TimeDelta_Calculated) / 6;
    //	Msg("* CLIENT: d(%d), dc(%d), s(%d)",net_TimeDelta,net_TimeDelta_Calculated,size);
}

void IPureClient::ClearStatistic() { net_Statistic.Clear(); }

BOOL IPureClient::net_IsSyncronised() { return net_Syncronised; }
