////////////////////////////////////////////////////////////////////////////
//	Module 		: ai_space.h
//	Created 	: 12.11.2003
//  Modified 	: 12.11.2003
//	Author		: Dmitriy Iassenev
//	Description : AI space class
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "game_graph.h"
#include "game_level_cross_table.h"
#include "level_graph.h"
#include "graph_engine.h"
#include "ef_storage.h"
#include "ai_space.h"
#include "cover_manager.h"
//#include "cover_point.h"
#include "script_engine.h"
#include "patrol_path_storage.h"
#include "alife_simulator.h"
#include "moving_objects.h"
#include "doors_manager.h"

CAI_Space* g_ai_space = nullptr;

CAI_Space::CAI_Space() {
    m_ef_storage = nullptr;
    m_game_graph = nullptr;
    m_graph_engine = nullptr;
    m_cover_manager = nullptr;
    m_level_graph = nullptr;
    m_alife_simulator = nullptr;
    m_patrol_path_storage = nullptr;
    m_script_engine = nullptr;
    m_moving_objects = nullptr;
    m_doors_manager = nullptr;
}

void CAI_Space::init() {
    VERIFY(!m_ef_storage);
    m_ef_storage = xr_new<CEF_Storage>();

    VERIFY(!m_graph_engine);
    m_graph_engine = xr_new<CGraphEngine>(1024);

    VERIFY(!m_cover_manager);
    m_cover_manager = xr_new<CCoverManager>();

    VERIFY(!m_patrol_path_storage);
    m_patrol_path_storage = xr_new<CPatrolPathStorage>();

    VERIFY(!m_moving_objects);
    m_moving_objects = xr_new<::moving_objects>();

    VERIFY(!m_script_engine);
    m_script_engine = xr_new<CScriptEngine>();
    script_engine().init();

    extern string4096 g_ca_stdout;
    setvbuf(stderr, g_ca_stdout, _IOFBF, sizeof(g_ca_stdout));
}

CAI_Space::~CAI_Space() {
    unload();

    try {
        xr_delete(m_script_engine);
    } catch (...) {
    }

    xr_delete(m_doors_manager);
    xr_delete(m_moving_objects);
    xr_delete(m_patrol_path_storage);
    xr_delete(m_cover_manager);
    xr_delete(m_graph_engine);
    xr_delete(m_ef_storage);
    VERIFY(!m_game_graph);
}

void CAI_Space::load(LPCSTR level_name) {
    VERIFY(m_game_graph);

    unload(true);

#ifdef DEBUG
    Memory.mem_compact();
    u32 mem_usage = Memory.mem_usage();
    CTimer timer;
    timer.Start();
#endif

    const CGameGraph::SLevel& current_level = game_graph().header().level(level_name);

    m_level_graph = xr_new<CLevelGraph>();
    game_graph().set_current_level(current_level.id());
    R_ASSERT2(cross_table().header().level_guid() == level_graph().header().guid(),
              "cross_table doesn't correspond to the AI-map");
    R_ASSERT2(cross_table().header().game_guid() == game_graph().header().guid(),
              "graph doesn't correspond to the cross table");
    m_graph_engine = xr_new<CGraphEngine>(
        std::max((u32)game_graph().header().vertex_count(), level_graph().header().vertex_count()));

    R_ASSERT2(current_level.guid() == level_graph().header().guid(),
              "graph doesn't correspond to the AI-map");

#ifdef DEBUG
    if (!xr_strcmp(current_level.name(), level_name))
        validate(current_level.id());
#endif

    level_graph().level_id(current_level.id());
    m_cover_manager->compute_static_cover();
    m_moving_objects->on_level_load();

    VERIFY(!m_doors_manager);
    m_doors_manager = xr_new<::doors::manager>(ai().level_graph().header().box());

#ifdef DEBUG
    Msg("* Loading ai space is successfully completed (%.3fs, %7.3f Mb)", timer.GetElapsed_sec(),
        float(Memory.mem_usage() - mem_usage) / 1048576.0);
#endif
}

void CAI_Space::unload(bool reload) {
    script_engine().unload();

    xr_delete(m_doors_manager);
    xr_delete(m_graph_engine);
    xr_delete(m_level_graph);

    if (!reload && m_game_graph)
        m_graph_engine = xr_new<CGraphEngine>(game_graph().header().vertex_count());
}

#ifdef DEBUG
void CAI_Space::validate(const u32 level_id) const {
    VERIFY(level_graph().header().vertex_count() == cross_table().header().level_vertex_count());
    for (GameGraph::_GRAPH_ID i = 0, n = game_graph().header().vertex_count(); i < n; ++i)
        if ((level_id == game_graph().vertex(i)->level_id()) &&
            (!level_graph().valid_vertex_id(game_graph().vertex(i)->level_vertex_id()) ||
             (cross_table().vertex(game_graph().vertex(i)->level_vertex_id()).game_vertex_id() !=
              i) ||
             !level_graph().inside(game_graph().vertex(i)->level_vertex_id(),
                                   game_graph().vertex(i)->level_point()))) {
            Msg("! Graph doesn't correspond to the cross table");
            R_ASSERT2(false, "Graph doesn't correspond to the cross table");
        }

    //	Msg						("death graph point id :
    //%d",cross_table().vertex(455236).game_vertex_id());

    for (u32 i = 0, n = game_graph().header().vertex_count(); i < n; ++i) {
        if (level_id != game_graph().vertex(i)->level_id())
            continue;

        CGameGraph::const_spawn_iterator I, E;
        game_graph().begin_spawn(i, I, E);
        //		Msg									("vertex [%d] has %d
        //death points",i,game_graph().vertex(i)->death_point_count());
        for (; I != E; ++I) {
            VERIFY(cross_table().vertex((*I).level_vertex_id()).game_vertex_id() == i);
        }
    }

    //	Msg						("* Graph corresponds to the cross table");
}
#endif

void CAI_Space::patrol_path_storage_raw(IReader& stream) {
    xr_delete(m_patrol_path_storage);
    m_patrol_path_storage = xr_new<CPatrolPathStorage>();
    m_patrol_path_storage->load_raw(get_level_graph(), get_cross_table(), get_game_graph(), stream);
}

void CAI_Space::patrol_path_storage(IReader& stream) {
    xr_delete(m_patrol_path_storage);
    m_patrol_path_storage = xr_new<CPatrolPathStorage>();
    m_patrol_path_storage->load(stream);
}

void CAI_Space::set_alife(CALifeSimulator* alife_simulator) {
    VERIFY((!m_alife_simulator && alife_simulator) || (m_alife_simulator && !alife_simulator));
    m_alife_simulator = alife_simulator;

    VERIFY(!alife_simulator || !m_game_graph);
    if (alife_simulator)
        return;

    VERIFY(m_game_graph);
    m_game_graph = 0;
    xr_delete(m_graph_engine);
}

void CAI_Space::game_graph(CGameGraph* game_graph) {
    VERIFY(m_alife_simulator);
    VERIFY(game_graph);
    VERIFY(!m_game_graph);
    m_game_graph = game_graph;

    //	VERIFY					(!m_graph_engine);
    xr_delete(m_graph_engine);
    m_graph_engine = xr_new<CGraphEngine>(this->game_graph().header().vertex_count());
}

const CGameLevelCrossTable& CAI_Space::cross_table() const { return (game_graph().cross_table()); }

const CGameLevelCrossTable* CAI_Space::get_cross_table() const {
    return (&game_graph().cross_table());
}