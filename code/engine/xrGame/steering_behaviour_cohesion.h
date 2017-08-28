////////////////////////////////////////////////////////////////////////////
//	Module 		: steering_behaviour_cohesion.h
//	Created 	: 07.11.2007
//  Modified 	: 07.11.2007
//	Author		: Dmitriy Iassenev
//	Description : steering behaviour cohesion class
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "steering_behaviour_base.h"
#include "smart_cover_detail.h"

class CAI_Rat;

namespace steering_behaviour {

class cohesion final : public base {
public:
    cohesion(CAI_Rat const* object);

    cohesion(const cohesion& other) = delete;
    cohesion& operator=(const cohesion& other) = delete;
    virtual Fvector direction();

private:
    typedef base inherited;
};

} // namespace steering_behaviour
