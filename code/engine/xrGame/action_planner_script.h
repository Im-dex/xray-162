////////////////////////////////////////////////////////////////////////////
//	Module 		: action_planner_script.h
//	Created 	: 28.03.2004
//  Modified 	: 28.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Action planner with script support
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "action_planner.h"

class CScriptGameObject;

template <typename _object_type>
class CActionPlannerScript : public CScriptActionPlanner {
protected:
    using inherited = CScriptActionPlanner;

public:
    _object_type* m_object;

    CActionPlannerScript() : m_object(nullptr) {}
    virtual void setup(_object_type* object) {
        VERIFY(object);
        inherited::setup(object->lua_game_object());
        m_object = object;
    }
    _object_type& object() const {
        return *m_object;
    }
};
