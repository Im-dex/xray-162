#include "pch_script.h"
#include "game_base.h"
#include "ai_space.h"
#include "script_engine.h"
#include "level.h"
#include "xrMessages.h"

u64 g_qwStartGameTime = 12 * 60 * 60 * 1000;
float g_fTimeFactor = pSettings->r_float("alife", "time_factor");
u64 g_qwEStartGameTime = 12 * 60 * 60 * 1000;

EGameIDs ParseStringToGameType(LPCSTR str);

game_PlayerState::game_PlayerState(NET_Packet* account_info) {
    skin = 0;
    m_online_time = 0;
    team = 0;
    money_for_round = 0;

    experience_Real = 0;
    rank = 0;
    af_count = 0;
    experience_New = 0;

    flags__ = 0;
    m_bCurrentVoteAgreed = 2;
    RespawnTime = 0;
    m_bPayForSpawn = false;

    clear();

    if (account_info) {
        net_Import(*account_info);
    }
}

void game_PlayerState::clear() {
    m_iRivalKills = 0;
    m_iSelfKills = 0;
    m_iTeamKills = 0;
    m_iKillsInRowCurr = 0;
    m_iKillsInRowMax = 0;
    m_iDeaths = 0;
    lasthitter = 0;
    lasthitweapon = 0;
    experience_Real = 0;
    rank = 0;
    af_count = 0;
    experience_New = 0;
    pItemList.clear();
    pSpawnPointsList.clear();
    m_s16LastSRoint = -1;
    LastBuyAcount = 0;
    m_bClearRun = false;
    DeathTime = 0;
    mOldIDs.clear();
    money_added = 0;
    m_aBonusMoney.clear();
    m_player_ip = "";
    m_player_digest = "";
}

game_PlayerState::~game_PlayerState() {
    pItemList.clear();
    pSpawnPointsList.clear();
};

bool game_PlayerState::testFlag(u16 f) const { return !!(flags__ & f); }

void game_PlayerState::setFlag(u16 f) { flags__ |= f; }

void game_PlayerState::resetFlag(u16 f) { flags__ &= ~(f); }

void game_PlayerState::net_Export(NET_Packet&, BOOL) {}

void game_PlayerState::net_Import(NET_Packet&) {}

void game_PlayerState::skip_Import(NET_Packet&) {}

void game_PlayerState::SetGameID(u16 NewID) {
    if (mOldIDs.size() >= 10) {
        mOldIDs.pop_front();
    };
    mOldIDs.push_back(GameID);
    GameID = NewID;
}
bool game_PlayerState::HasOldID(u16 ID) {
    auto ID_i = std::find(mOldIDs.begin(), mOldIDs.end(), ID);
    if (ID_i != mOldIDs.end() && *(ID_i) == ID)
        return true;
    return false;
}

game_TeamState::game_TeamState() {
    score = 0;
    num_targets = 0;
}

game_GameState::game_GameState() {
    m_type = EGameIDs(u32(0));
    m_phase = GAME_PHASE_NONE;
    m_round = -1;
    m_round_start_time_str[0] = 0;

    VERIFY(g_pGameLevel);
    m_qwStartProcessorTime = Level().timeServer_Async();
    m_qwStartGameTime = g_qwStartGameTime;
    m_fTimeFactor = g_fTimeFactor;
    m_qwEStartProcessorTime = m_qwStartProcessorTime;
    m_qwEStartGameTime = g_qwEStartGameTime;
    m_fETimeFactor = m_fTimeFactor;
}

CLASS_ID game_GameState::getCLASS_ID(LPCSTR game_type_name, bool isServer) {
    /*
     string_path		S;
                    FS.update_path	(S,"$game_config$","script.ltx");
                    CInifile		*l_tpIniFile = xr_new<CInifile>(S);
                    R_ASSERT		(l_tpIniFile);

                    string256				I;
                    xr_strcpy(I,l_tpIniFile->r_string("common","game_type_clsid_factory"));

                    luabind::functor<LPCSTR>	result;
                    R_ASSERT
     (ai().script_engine().functor(I,result));
                    shared_str clsid = result		(game_type_name, isServer);

                    xr_delete			(l_tpIniFile);
                    if(clsid.size()==0)
                            Debug.fatal		(DEBUG_INFO,"Unknown game type: %s",game_type_name);

                    return				(TEXT2CLSID(*clsid));
     */

    EGameIDs gameID = ParseStringToGameType(game_type_name);
    switch (gameID) {
    case eGameIDSingle:
        return (isServer) ? TEXT2CLSID("SV_SINGL") : TEXT2CLSID("CL_SINGL");

    default:
        return (TEXT2CLSID(""));
    }
}

void game_GameState::switch_Phase(u32 new_phase) {
    OnSwitchPhase(m_phase, new_phase);

    m_phase = u16(new_phase);
    m_start_time = Level().timeServer();
}

ALife::_TIME_ID game_GameState::GetStartGameTime() { return (m_qwStartGameTime); }

ALife::_TIME_ID game_GameState::GetGameTime() {
    return (m_qwStartGameTime + ALife::_TIME_ID(m_fTimeFactor * float(Level().timeServer_Async() -
                                                                      m_qwStartProcessorTime)));
}

float game_GameState::GetGameTimeFactor() { return (m_fTimeFactor); }

void game_GameState::SetGameTimeFactor(const float fTimeFactor) {
    m_qwStartGameTime = GetGameTime();
    m_qwStartProcessorTime = Level().timeServer_Async();
    m_fTimeFactor = fTimeFactor;
}

void game_GameState::SetGameTimeFactor(ALife::_TIME_ID GameTime, const float fTimeFactor) {
    m_qwStartGameTime = GameTime;
    m_qwStartProcessorTime = Level().timeServer_Async();
    m_fTimeFactor = fTimeFactor;
}

ALife::_TIME_ID game_GameState::GetEnvironmentGameTime() {
    return (m_qwEStartGameTime + ALife::_TIME_ID(m_fETimeFactor * float(Level().timeServer_Async() -
                                                                        m_qwEStartProcessorTime)));
}

float game_GameState::GetEnvironmentGameTimeFactor() { return (m_fETimeFactor); }

void game_GameState::SetEnvironmentGameTimeFactor(const float fTimeFactor) {
    m_qwEStartGameTime = GetEnvironmentGameTime();
    m_qwEStartProcessorTime = Level().timeServer_Async();
    m_fETimeFactor = fTimeFactor;
}

void game_GameState::SetEnvironmentGameTimeFactor(ALife::_TIME_ID GameTime,
                                                  const float fTimeFactor) {
    m_qwEStartGameTime = GameTime;
    m_qwEStartProcessorTime = Level().timeServer_Async();
    m_fETimeFactor = fTimeFactor;
}
