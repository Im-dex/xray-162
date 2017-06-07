#pragma once
#include "../states/monster_state_attack.h"

template<typename _Object>
class	CBloodsuckerStateAttack : public CStateMonsterAttack<_Object> {
	typedef CStateMonsterAttack<_Object> inherited_attack;

	u32				m_time_stop_invis;
	Fvector			m_dir_point;

	float           m_last_health;
	bool            m_start_with_encircle;

public:
					CBloodsuckerStateAttack		(_Object *obj);
	virtual			~CBloodsuckerStateAttack	();

	virtual	void	initialize					();
	virtual	void	execute						();
	virtual	void	finalize					();
	virtual	void	critical_finalize			();
	
	virtual void	setup_substates				();
private:
			bool	check_hiding				();
			bool	check_vampire				();
};

template<typename _Object>
class CStateMonsterBackstubEnemy : public CState<_Object> {
	typedef CState<_Object> inherited;
public:
	struct StateParams : SStateDataMoveToPointEx
	{
		bool   start_with_encircle;
		StateParams() : start_with_encircle(false) {}
	} data;

protected:

	float                   m_last_health;
	bool                    m_encircle;
	TTime                   m_encircle_end_tick;
	TTime                   m_next_change_behaviour_tick;

public:
	CStateMonsterBackstubEnemy	(_Object *obj) : inherited(obj, &data) {}
	virtual				~CStateMonsterBackstubEnemy	() {}
	virtual void		initialize					();
	virtual	void		execute						();
	virtual bool 		check_start_conditions	    ();
	virtual bool		check_completion			();
	virtual void		remove_links				(CObject* object) { inherited::remove_links(object);}
};

#include "bloodsucker_attack_state_inline.h"
