////////////////////////////////////////////////////////////////////////////
//	Module 		: smart_cover_action.h
//	Created 	: 16.08.2007
//	Author		: Alexander Dudin
//	Description : Action class for smart cover
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "smart_cover_detail.h"
#include "script_space_forward.h"
#include "ai_monster_space.h"
#include "associative_vector.h"

namespace smart_cover {

class action final {
    class animation_predicate {

    public:
        IC bool operator()(shared_str const& lhs, shared_str const& rhs) const {
            return (lhs._get() < rhs._get());
        }
    };

public:
    typedef xr_vector<shared_str> Animations;
    typedef associative_vector<shared_str, Animations*, animation_predicate> AnimationList;

private:
    AnimationList m_animations;

    bool m_movement;
    Fvector m_target_position;

public:
    action(luabind::object const& description);

    action(const action& other) = delete;
    action& operator=(const action& other) = delete;
    ~action();
    IC bool const& movement() const;
    IC Fvector const& target_position() const;
    IC Animations const& animations(shared_str const& cover_id, shared_str const& id) const;

private:
    void add_animation(LPCSTR animation_type, luabind::object const& table);
};

} // namespace smart_cover

#include "smart_cover_action_inline.h"