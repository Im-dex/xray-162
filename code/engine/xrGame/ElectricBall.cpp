///////////////////////////////////////////////////////////////
// ElectricBall.cpp
// ElectricBall - �������� ������������� ���
///////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElectricBall.h"
#include "../xrphysics/PhysicsShell.h"


CElectricBall::CElectricBall(void) 
{
}

CElectricBall::~CElectricBall(void) 
{
}

void CElectricBall::Load(LPCSTR section) 
{
	inherited::Load(section);
}

void CElectricBall::UpdateCLChild	()
{
	inherited::UpdateCLChild();

	if(H_Parent()) XFORM().set(H_Parent()->XFORM());
};