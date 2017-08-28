////////////////////////////////////////////////////////////////////////////
//	Module 		: rat_state_base.h
//	Created 	: 31.08.2007
//  Modified 	: 31.08.2007
//	Author		: Dmitriy Iassenev
//	Description : rat state base class
////////////////////////////////////////////////////////////////////////////

#ifndef RAT_STATE_BASE_H_INCLUDED
#define RAT_STATE_BASE_H_INCLUDED

class CAI_Rat;

class rat_state_base {
private:
    CAI_Rat* m_object;

public:
    IC rat_state_base();

    rat_state_base(const rat_state_base& other) = delete;
    rat_state_base& operator=(const rat_state_base& other) = delete;
    void construct(CAI_Rat* object);
    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void finalize() = 0;
    IC CAI_Rat& object() const;
};

#include "rat_state_base_inline.h"

#endif // RAT_STATE_BASE_H_INCLUDED