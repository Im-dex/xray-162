////////////////////////////////////////////////////////////////////////////
//	Module 		: danger_object_location.cpp
//	Created 	: 24.05.2004
//  Modified 	: 14.01.2005
//	Author		: Dmitriy Iassenev
//	Description : Danger object location
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "danger_object_location.h"
#include "gameobject.h"

const Fvector &CDangerObjectLocation::position	() const
{
	return		(m_object->Position());
}

bool CDangerObjectLocation::useful				() const
{
	return		(true);
}

bool CDangerObjectLocation::operator==			(const CObject *object) const
{
	return		(m_object->ID() == object->ID());
}
