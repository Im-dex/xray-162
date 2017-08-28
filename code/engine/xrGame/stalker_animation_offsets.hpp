////////////////////////////////////////////////////////////////////////////
//	Module 		: stalker_animation_offsets.hpp
//	Created 	: 19.12.2007
//	Author		: Alexander Dudin
//	Description : Animation offsets class
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "associative_vector.h"
#include "xrServer_Objects.h"

struct SRotation;

class animation_offsets final {
    class anim_id_predicate {
    public:
        bool operator()(shared_str const& lhs, shared_str const& rhs) const {
            return (lhs._get() < rhs._get());
        }
    };

public:
    typedef associative_vector<shared_str, SRotation, anim_id_predicate> AnimationOffsets;

private:
    AnimationOffsets m_animation_offsets;

public:
    SRotation const offsets(shared_str const& animation_id) const;
    void load(LPCSTR section);
};
