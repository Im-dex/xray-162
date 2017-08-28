#include "stdafx.h"
#include "xrserver.h"
#include "game_sv_single.h"
#include "xrMessages.h"
#include "game_cl_single.h"
#include "MainMenu.h"
#include "../xrEngine/x_ray.h"
#pragma warning(push)
#pragma warning(disable : 4995)
#include <malloc.h>
#include "Level.h"
#pragma warning(pop)

LPCSTR xrServer::get_map_download_url(LPCSTR level_name, LPCSTR level_version) {
    R_ASSERT(level_name && level_version);
    LPCSTR ret_url = "";
    CInifile* level_ini = pApp->GetArchiveHeader(level_name, level_version);
    if (!level_ini) {
        if (!IsGameTypeSingle())
            Msg("! Warning: level [%s][%s] has not header ltx", level_name, level_version);

        return ret_url;
    }

    ret_url = level_ini->r_string_wb("header", "link").c_str();
    if (!ret_url)
        ret_url = "";

    return ret_url;
}

xrServer::EConnect xrServer::Connect(shared_str& session_name, GameDescriptionData& game_descr) {
#ifdef DEBUG
    Msg("* sv_Connect: %s", *session_name);
#endif

    // Parse options and create game
    if (0 == strchr(*session_name, '/'))
        return ErrConnect;

    string1024 options;
    R_ASSERT2(xr_strlen(session_name) <= sizeof(options), "session_name too BIIIGGG!!!");
    xr_strcpy(options, strchr(*session_name, '/') + 1);

    // Parse game type
    string1024 type;
    R_ASSERT2(xr_strlen(options) <= sizeof(type), "session_name too BIIIGGG!!!");
    xr_strcpy(type, options);
    if (strchr(type, '/'))
        *strchr(type, '/') = 0;
    game = NULL;

    CLASS_ID clsid = game_GameState::getCLASS_ID(type, true);
    game = smart_cast<game_sv_GameState*>(NEW_INSTANCE(clsid));

    // Options
    if (0 == game)
        return ErrConnect;
#ifdef DEBUG
    Msg("* Created server_game %s", game->type_name());
#endif

    std::memset(&game_descr, 0, sizeof(game_descr));
    xr_strcpy(game_descr.map_name, game->level_name(session_name.c_str()).c_str());
    xr_strcpy(game_descr.map_version,
              game_sv_GameState::parse_level_version(session_name.c_str()).c_str());
    xr_strcpy(game_descr.download_url,
              get_map_download_url(game_descr.map_name, game_descr.map_version));

    game->Create(session_name);

    return IPureServer::Connect(*session_name, game_descr);
}

IClient* xrServer::new_client(SClientConnectData* cl_data) {
    IClient* CL = client_Find_Get(cl_data->clientID);
    VERIFY(CL);

    // copy entity
    CL->ID = cl_data->clientID;
    CL->name = cl_data->name; // only for offline mode
    CL->pass._set(cl_data->pass);

    NET_Packet P;
    P.B.count = 0;
    P.r_pos = 0;

    game->AddDelayedEvent(P, GAME_EVENT_CREATE_CLIENT, 0, CL->ID);

    return CL;
}

void xrServer::AttachNewClient(IClient* CL) {
    MSYS_CONFIG msgConfig;
    msgConfig.sign1 = 0x12071980;
    msgConfig.sign2 = 0x26111975;

    SV_Client = CL;
    CL->flags.bLocal = 1;
    SendTo_LL(SV_Client->ID, &msgConfig, sizeof(msgConfig), net_flags(TRUE, TRUE, TRUE, TRUE));

    RequestClientDigest(CL);

    // xrClientData * CL_D=(xrClientData*)(CL);
    // ip_address				ClAddress;
    // GetClientAddress		(CL->ID, ClAddress);
    CL->m_guid[0] = 0;
}

void xrServer::RequestClientDigest(IClient* CL) {
    if (IsGameTypeSingle() || (CL == GetServerClient())) {
        Check_BuildVersion_Success(CL);
        return;
    }

    NET_Packet P;
    P.w_begin(M_SV_DIGEST);
    SendTo(CL->ID, P);
}

void xrServer::ProcessClientDigest(xrClientData*, NET_Packet*) {
    // NOTE: multiplayer code was here
}