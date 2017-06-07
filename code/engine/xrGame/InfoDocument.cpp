///////////////////////////////////////////////////////////////
// InfoDocument.cpp
// InfoDocument - ��������, ���������� �������� ����������
///////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "InfoDocument.h"
#include "../xrphysics/PhysicsShell.h"
#include "PDA.h"
#include "inventoryowner.h"
#include "xrserver_objects_alife_items.h"

CInfoDocument::CInfoDocument(void) 
{
	m_Info = NULL;
}

CInfoDocument::~CInfoDocument(void) 
{
}


BOOL CInfoDocument::net_Spawn(CSE_Abstract* DC) 
{
	BOOL					res = inherited::net_Spawn(DC);

	CSE_Abstract			*l_tpAbstract = static_cast<CSE_Abstract*>(DC);
	CSE_ALifeItemDocument	*l_tpALifeItemDocument = smart_cast<CSE_ALifeItemDocument*>(l_tpAbstract);
	R_ASSERT				(l_tpALifeItemDocument);

	m_Info					= l_tpALifeItemDocument->m_wDoc;

	return					(res);
}

void CInfoDocument::Load(LPCSTR section) 
{
	inherited::Load(section);
}

void CInfoDocument::net_Destroy() 
{
	inherited::net_Destroy();
}

void CInfoDocument::shedule_Update(u32 dt) 
{
	inherited::shedule_Update(dt);
}

void CInfoDocument::UpdateCL() 
{
	inherited::UpdateCL();
}


void CInfoDocument::OnH_A_Chield() 
{
	inherited::OnH_A_Chield		();
	
	//�������� ���������� ������������ � ���������
	//�������, ������� ������ ��������
	CInventoryOwner* pInvOwner = smart_cast<CInventoryOwner*>(H_Parent());
	if(!pInvOwner) return;
	
	//������� � ��������� ����� � ��������� ����� ����������
	if(m_Info.size())
	{
		NET_Packet		P;
		u_EventGen		(P,GE_INFO_TRANSFER, H_Parent()->ID());
		P.w_u16			(ID());						//�����������
		P.w_stringZ		(m_Info);				//���������
		P.w_u8			(1);						//���������� ���������
		u_EventSend		(P);
	}
}

void CInfoDocument::OnH_B_Independent(bool just_before_destroy) 
{
	inherited::OnH_B_Independent(just_before_destroy);
}

void CInfoDocument::renderable_Render() 
{
	inherited::renderable_Render();
}