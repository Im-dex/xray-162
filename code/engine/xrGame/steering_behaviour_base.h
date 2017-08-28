////////////////////////////////////////////////////////////////////////////
//	Module 		: steering_behaviour_base.h
//	Created 	: 07.11.2007
//  Modified 	: 07.11.2007
//	Author		: Dmitriy Iassenev
//	Description : steering behaviour base class
////////////////////////////////////////////////////////////////////////////

#ifndef STEERING_BEHAVIOUR_BASE_H_INCLUDED
#define STEERING_BEHAVIOUR_BASE_H_INCLUDED

class CAI_Rat;

namespace steering_behaviour {

class base {
public:
    base(CAI_Rat const* object);

    base(const base& other) = delete;
    base& operator=(const base& other) = delete;
    virtual ~base() {}
    virtual Fvector direction() = 0;

public:
    IC void enabled(bool const& value);
    IC bool const& enabled() const;

private:
    CAI_Rat const* m_object;
    bool m_enabled;
};

} // namespace steering_behaviour

#include "steering_behaviour_base_inline.h"

#endif // STEERING_BEHAVIOUR_BASE_H_INCLUDED