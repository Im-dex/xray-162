#include "stdafx.h"
#include "xrserver.h"
#include "xrmessages.h"
#include "xrserver_objects.h"
#include "xrServer_Objects_Alife_Monsters.h"
#include "Level.h"

void xrServer::Perform_connect_spawn(CSE_Abstract* E, xrClientData* CL, NET_Packet& P) {
    P.B.count = 0;
    xr_vector<u16>::iterator it =
        std::find(conn_spawned_ids.begin(), conn_spawned_ids.end(), E->ID);
    if (it != conn_spawned_ids.end()) {
        //.		Msg("Rejecting redundant SPAWN data [%d]", E->ID);
        return;
    }

    conn_spawned_ids.push_back(E->ID);

    if (E->net_Processed)
        return;
    if (E->s_flags.is(M_SPAWN_OBJECT_PHANTOM))
        return;

    //.	Msg("Perform connect spawn [%d][%s]", E->ID, E->s_name.c_str());

    // Connectivity order
    CSE_Abstract* Parent = ID_to_entity(E->ID_Parent);
    if (Parent)
        Perform_connect_spawn(Parent, CL, P);

    // Process
    Flags16 save = E->s_flags;
    //-------------------------------------------------
    E->s_flags.set(M_SPAWN_UPDATE, TRUE);
    if (0 == E->owner) {
        // PROCESS NAME; Name this entity
        if (E->s_flags.is(M_SPAWN_OBJECT_ASPLAYER)) {
            CL->owner = E;
            VERIFY(CL->ps);
            E->set_name_replace(CL->ps->getName());
        }

        // Associate
        E->owner = CL;
        E->Spawn_Write(P, TRUE);
        E->UPDATE_Write(P);

        CSE_ALifeObject* object = smart_cast<CSE_ALifeObject*>(E);
        VERIFY(object);
        if (!object->keep_saved_data_anyway())
            object->client_data.clear();
    } else {
        E->Spawn_Write(P, FALSE);
        E->UPDATE_Write(P);
        //		CSE_ALifeObject*	object = smart_cast<CSE_ALifeObject*>(E);
        //		VERIFY				(object);
        //		VERIFY				(object->client_data.empty());
    }
    //-----------------------------------------------------
    E->s_flags = save;
    SendTo(CL->ID, P, net_flags(TRUE, TRUE));
    E->net_Processed = TRUE;
}

void xrServer::SendConfigFinished(ClientID const& clientId) {
    NET_Packet P;
    P.w_begin(M_SV_CONFIG_FINISHED);
    SendTo(clientId, P, net_flags(TRUE, TRUE));
}

void xrServer::SendConnectionData(IClient* _CL) {
    conn_spawned_ids.clear();
    xrClientData* CL = (xrClientData*)_CL;
    NET_Packet P;
    // Replicate current entities on to this client
    xrS_entities::iterator I = entities.begin(), E = entities.end();
    for (; I != E; ++I)
        I->second->net_Processed = FALSE;
    for (I = entities.begin(); I != E; ++I)
        Perform_connect_spawn(I->second, CL, P);

    // Start to send server logo and rules
    SendServerInfoToClient(CL->ID);

    /*
            Msg("--- Our sended SPAWN IDs:");
            xr_vector<u16>::iterator it = conn_spawned_ids.begin();
            for (; it != conn_spawned_ids.end(); ++it)
            {
                    Msg("%d", *it);
            }
            Msg("---- Our sended SPAWN END");
    */
};

void xrServer::OnCL_Connected(IClient* _CL) {
    xrClientData* CL = (xrClientData*)_CL;
    CL->net_Accepted = TRUE;
    /*if (Level().IsDemoPlay())
    {
            Level().StartPlayDemo();
            return;
    };*/
    ///	Server_Client_Check(CL);
    // csPlayers.Enter					();	//sychronized by a parent call
    Export_game_type(CL);
    Perform_game_export();
    SendConnectionData(CL);

    VERIFY2(CL->ps, "Player state not created");
    if (!CL->ps) {
        Msg("! ERROR: Player state not created - incorect message sequence!");
        return;
    }

    game->OnPlayerConnect(CL->ID);
}

void xrServer::SendConnectResult(IClient* CL, u8 res, u8 res1, char* ResultStr) {
    NET_Packet P;
    P.w_begin(M_CLIENT_CONNECT_RESULT);
    P.w_u8(res);
    P.w_u8(res1);
    P.w_stringZ(ResultStr);
    P.w_clientID(CL->ID);

    if (SV_Client && SV_Client == CL)
        P.w_u8(1);
    else
        P.w_u8(0);
    P.w_stringZ(Level().m_caServerOptions);

    SendTo(CL->ID, P);

    if (!res) // need disconnect
    {
#ifdef MP_LOGGING
        Msg("* Server disconnecting client, resaon: %s", ResultStr);
#endif
        Flush_Clients_Buffers();
        DisconnectClient(CL, ResultStr);
    }

    if (Level().IsDemoPlay()) {
        Level().StartPlayDemo();

        return;
    }
}

void xrServer::OnBuildVersionRespond(IClient* CL, NET_Packet& P) {
    // imdex NOTE: useless now
    /*u16 Type;
    P.r_begin(Type);
    u64 _him = P.r_u64();*/

    // Check_BuildVersion_Success( CL );
    RequestClientDigest(CL);
};

void xrServer::Check_BuildVersion_Success(IClient* CL) {
    CL->flags.bVerified = TRUE;
    SendConnectResult(CL, 1, 0, "All Ok");
};