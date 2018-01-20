////////////////////////////////////////////////////////////////////////////
//	Module 		: spawn_constructor_space.h
//	Created 	: 16.10.2004
//  Modified 	: 16.10.2004
//	Author		: Dmitriy Iassenev
//	Description : Spawn constructor space
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "game_graph.h"

class CSE_ALifeLevelChanger;

namespace SpawnConstructorSpace {
typedef std::vector<CGameGraph::CLevelPoint> LEVEL_POINT_STORAGE;
typedef std::vector<CSE_ALifeLevelChanger*> LEVEL_CHANGER_STORAGE;
}; // namespace SpawnConstructorSpace