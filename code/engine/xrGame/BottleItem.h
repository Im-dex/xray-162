///////////////////////////////////////////////////////////////
// BottleItem.h
// BottleItem - ������� � ��������, ������� ����� �������
///////////////////////////////////////////////////////////////


#pragma once

#include "fooditem.h"


class CBottleItem: public CFoodItem
{
private:
    typedef	CFoodItem inherited;
public:
				CBottleItem			();
	virtual		~CBottleItem		();


	virtual void Load				(LPCSTR section);
	

	void	OnEvent					(NET_Packet& P, u16 type);


	virtual	void	Hit				(SHit* pHDS);
	

			void					BreakToPieces		();
protected:
	//�������� ���������� �������
	shared_str m_sBreakParticles;
	ref_sound sndBreaking;
};