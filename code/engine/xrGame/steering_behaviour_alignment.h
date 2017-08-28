////////////////////////////////////////////////////////////////////////////
//	Module 		: steering_behaviour_alignment.h
//	Created 	: 07.11.2007
//  Modified 	: 07.11.2007
//	Author		: Dmitriy Iassenev
//	Description : steering behaviour alignment class
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "steering_behaviour_base.h"
#include "smart_cover_detail.h"

class CAI_Rat;

namespace steering_behaviour {

class alignment final : public base {
public:
    alignment(CAI_Rat const* object);

    alignment(const alignment& other) = delete;
    alignment& operator=(const alignment& other) = delete;
    virtual Fvector direction();

private:
    typedef base inherited;
};

} // namespace steering_behaviour