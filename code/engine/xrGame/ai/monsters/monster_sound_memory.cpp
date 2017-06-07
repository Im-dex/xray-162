#include "stdafx.h"
#include "monster_sound_memory.h"
#include "BaseMonster/base_monster.h"

#define CHECK_SOUND_TYPE(a,b,c) { if ((a & b) == b) return c; }

const	u32	time_help_sound_remember = 10000;

TSoundDangerValue tagSoundElement::ConvertSoundType(ESoundTypes stype)
{ 

	if (((stype & SOUND_TYPE_WEAPON) != SOUND_TYPE_WEAPON) && 
		((stype & SOUND_TYPE_MONSTER) != SOUND_TYPE_MONSTER) && 
		((stype & SOUND_TYPE_WORLD) != SOUND_TYPE_WORLD)) return NONE_DANGEROUS_SOUND;

	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WEAPON_RECHARGING,	WEAPON_RECHARGING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WEAPON_SHOOTING,		WEAPON_SHOOTING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_ITEM_TAKING,			WEAPON_TAKING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_ITEM_HIDING,			WEAPON_HIDING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WEAPON_EMPTY_CLICKING,	WEAPON_EMPTY_CLICKING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WEAPON_BULLET_HIT,	WEAPON_BULLET_RICOCHET);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_MONSTER_DYING,		MONSTER_DYING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_MONSTER_INJURING,	MONSTER_INJURING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_MONSTER_STEP,		MONSTER_WALKING);

	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_MONSTER_TALKING,		MONSTER_TALKING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_MONSTER_ATTACKING,	MONSTER_ATTACKING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WORLD_OBJECT_BREAKING,	OBJECT_BREAKING);
	CHECK_SOUND_TYPE(stype,	SOUND_TYPE_WORLD_OBJECT_COLLIDING,	OBJECT_FALLING);


	return NONE_DANGEROUS_SOUND;
}


CMonsterSoundMemory::CMonsterSoundMemory()
{
	Sounds.reserve		(20);
	m_time_help_sound	= 0;
	m_help_node			= u32(-1);
}
CMonsterSoundMemory::~CMonsterSoundMemory()
{

}

void CMonsterSoundMemory::init_external(CBaseMonster *M, TTime mem_time)
{
	monster		= M;
	time_memory = mem_time;
}

void CMonsterSoundMemory::HearSound(const SoundElem &s)
{
	if (NONE_DANGEROUS_SOUND	== s.type) return;
	if (DOOR_OPENING			<= s.type) return;
	if ((s.type == MONSTER_WALKING) && !s.who) return;

	// ����� � ������� �����
	xr_vector<SoundElem>::iterator it;

	bool b_sound_replaced = false;
	for (it = Sounds.begin(); Sounds.end() != it; ++it) {
		if ((s.who == it->who) && (it->type == s.type)) {
			if (s.time >= it->time) {
				*it = s; 
				b_sound_replaced = true;
			}
		}
	}

	if (!b_sound_replaced) Sounds.push_back(s);

}

void CMonsterSoundMemory::HearSound(const CObject* who, int eType, const Fvector &Position, float power, TTime time)
{
	SoundElem s;
	s.SetConvert(who,eType,Position,power,time);
	s.CalcValue(time,monster->Position());

	HearSound(s);
} 

// Lain: added
void   CMonsterSoundMemory::GetFirstSound (SoundElem& s, bool& bDangerous)
{
	VERIFY(!Sounds.empty());
	s = *Sounds.begin();
	if (s.type > WEAPON_EMPTY_CLICKING) bDangerous = false;
	else bDangerous = true;
}

void CMonsterSoundMemory::GetSound(SoundElem &s, bool &bDangerous)
{
	VERIFY(!Sounds.empty());

	// ������� ������ ��������
	s = GetSound();

	if (s.type > WEAPON_EMPTY_CLICKING) bDangerous = false;
	else bDangerous = true;
}

SoundElem &CMonsterSoundMemory::GetSound()
{
	VERIFY ( !Sounds.empty() );

	xr_vector<SoundElem>::iterator it = std::max_element(Sounds.begin(), Sounds.end());
	return (*it);
}


struct pred_remove_nonactual_sounds {
	TTime new_time;

	pred_remove_nonactual_sounds(TTime time) {new_time = time;}

	bool operator() (const SoundElem &x) {

		// ������� ����� �� ��������, ���������� � �������	
		if (x.who && x.who->getDestroy()) return true;

		// ������� '������' �����
		if (x.time < new_time)	return true;

		// ������� ����� �� ������� ��������
		if (x.who) {
			const CEntityAlive *pE = smart_cast<const CEntityAlive*> (x.who);
			if (pE && !pE->g_Alive()) return true;
		}

		return false;
	}
};


void CMonsterSoundMemory::UpdateHearing()
{
	// �������� ���������� ������
	Sounds.erase	(
		std::remove_if(
			Sounds.begin(),
			Sounds.end(),
			pred_remove_nonactual_sounds(
				Device.dwTimeGlobal - time_memory
			)
		),
		Sounds.end()
	);

	// ����������� value
	for (xr_vector<SoundElem>::iterator I = Sounds.begin(); I != Sounds.end(); ++I) I->CalcValue(Device.dwTimeGlobal, monster->Position());

	// update help sound
	if (m_time_help_sound + time_help_sound_remember < time()) m_time_help_sound = 0;
}

bool CMonsterSoundMemory::is_loud_sound(float val)
{
	for (u32 i=0; i<Sounds.size(); i++) 
		if (Sounds[i].power > val) return true;

	return false;
}

bool CMonsterSoundMemory::get_sound_from_object(const CObject* obj, SoundElem	&value)
{
	for (u32 i=0; i<Sounds.size(); i++) 
		if (Sounds[i].who == obj) {
			value	= Sounds[i];
			return	true;
		}

	return false;
}

struct pred_remove_relcase {
	CObject *obj;
	pred_remove_relcase(CObject *o) {obj = o;}

	bool operator() (const SoundElem &x) const {
		if (x.who == obj) return true;

		return false;
	}
};

void CMonsterSoundMemory::remove_links(CObject *O)
{
	// �������� ���������� ������
	Sounds.erase	(
		std::remove_if(
			Sounds.begin(),
			Sounds.end(),
			pred_remove_relcase(O)
		),
		Sounds.end()
	);
}

//////////////////////////////////////////////////////////////////////////
// Help Sounds
//////////////////////////////////////////////////////////////////////////
bool CMonsterSoundMemory::hear_help_sound()
{
	if ((m_time_help_sound == 0) || (m_time_help_sound + time_help_sound_remember < time())) return false;
	return true;
}

void CMonsterSoundMemory::check_help_sound(int eType, u32 node)
{
	if ((eType & SOUND_TYPE_MONSTER_ATTACKING) != SOUND_TYPE_MONSTER_ATTACKING) return;
	if ((eType & SOUND_TYPE_MONSTER_INJURING) != SOUND_TYPE_MONSTER_INJURING) return;
	if ((eType & SOUND_TYPE_MONSTER_DYING) != SOUND_TYPE_MONSTER_DYING) return;

	if (m_time_help_sound) return;

	m_time_help_sound	= time();
	m_help_node			= node;
}

