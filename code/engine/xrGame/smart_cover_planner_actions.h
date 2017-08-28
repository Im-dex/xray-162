////////////////////////////////////////////////////////////////////////////
//	Module 		: smart_cover_planner_actions.h
//	Created 	: 04.09.2007
//	Author		: Alexander Dudin
//	Description : Smart cover planner action classes
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "smart_cover_detail.h"
#include "stalker_combat_action_base.h"

class CAI_Stalker;

namespace smart_cover {

class animation_planner;

////////////////////////////////////////////////////////////////////////////
// action_base
////////////////////////////////////////////////////////////////////////////

class action_base : public CStalkerActionCombatBase {
private:
    typedef CStalkerActionCombatBase inherited;

public:
    action_base(CAI_Stalker* object, LPCSTR action_name = "");

    action_base(const action_base& other) = delete;
    action_base& operator=(const action_base& other) = delete;
    virtual void select_animation(shared_str& result) = 0;
    virtual void on_animation_end() = 0;
    virtual void on_mark();
    virtual void on_no_mark();
    virtual bool is_animated_action();
    void setup_orientation();
};

////////////////////////////////////////////////////////////////////////////
// change_loophole
////////////////////////////////////////////////////////////////////////////

class change_loophole final : public action_base {
    typedef action_base inherited;

public:
    change_loophole(CAI_Stalker* object, LPCSTR action_name);
    virtual void initialize();
    virtual void execute();
    virtual void finalize();
    virtual void select_animation(shared_str& result);
    virtual void on_animation_end();
};

////////////////////////////////////////////////////////////////////////////
// non_animated_change_loophole
////////////////////////////////////////////////////////////////////////////

class non_animated_change_loophole final : public action_base {
    typedef action_base inherited;

public:
    non_animated_change_loophole(CAI_Stalker* object, LPCSTR action_name);
    virtual void initialize();
    virtual void execute();
    virtual void finalize();
    virtual bool is_animated_action();
    virtual void select_animation(shared_str& result);
    virtual void on_animation_end();
};

////////////////////////////////////////////////////////////////////////////
// exit
////////////////////////////////////////////////////////////////////////////

class exit final : public action_base {
    typedef action_base inherited;

public:
    exit(CAI_Stalker* object, LPCSTR action_name);
    virtual void initialize();
    virtual void execute();
    virtual void finalize();
    virtual bool is_animated_action();
    virtual void select_animation(shared_str& result);
    virtual void on_animation_end();
};

} // namespace smart_cover

#include "smart_cover_planner_actions_inline.h"