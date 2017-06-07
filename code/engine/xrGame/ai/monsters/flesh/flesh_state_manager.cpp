#include "stdafx.h"
#include "flesh.h"
#include "flesh_state_manager.h"

#include "../control_animation_base.h"
#include "../control_direction_base.h"
#include "../control_movement_base.h"
#include "../control_path_builder_base.h"

#include "../states/monster_state_rest.h"
#include "../states/monster_state_attack.h"
#include "../states/monster_state_panic.h"
#include "../states/monster_state_eat.h"
#include "../states/monster_state_hear_int_sound.h"
#include "../states/monster_state_hear_danger_sound.h"
#include "../states/monster_state_hitted.h"
#include "../states/monster_state_controlled.h"
#include "../states/monster_state_help_sound.h"
#include "../group_states/group_state_home_point_attack.h"

CStateManagerFlesh::CStateManagerFlesh(CAI_Flesh *monster) : inherited(monster)
{
	add_state(eStateRest,					xr_new<CStateMonsterRest<CAI_Flesh> >				(monster));
	add_state(eStatePanic,					xr_new<CStateMonsterPanic<CAI_Flesh> >				(monster));

 	CStateMonsterAttackMoveToHomePoint<CAI_Flesh>* move2home = 
 		xr_new<CStateMonsterAttackMoveToHomePoint<CAI_Flesh> >(monster);
 
 	add_state(eStateAttack,					xr_new<CStateMonsterAttack<CAI_Flesh> >				(monster, move2home));
	
	add_state(eStateEat,					xr_new<CStateMonsterEat<CAI_Flesh> >				(monster));
	add_state(eStateHearInterestingSound,	xr_new<CStateMonsterHearInterestingSound<CAI_Flesh> >(monster));
	add_state(eStateHearDangerousSound,		xr_new<CStateMonsterHearDangerousSound<CAI_Flesh> >	(monster));
	add_state(eStateHitted,					xr_new<CStateMonsterHitted<CAI_Flesh> >				(monster));
	add_state(eStateControlled,				xr_new<CStateMonsterControlled<CAI_Flesh> >			(monster));
	add_state(eStateHearHelpSound,			xr_new<CStateMonsterHearHelpSound<CAI_Flesh> >		(monster));

}

void CStateManagerFlesh::execute()
{
	u32 state_id = u32(-1);

	if (!object->is_under_control()) {
		
		const CEntityAlive* enemy	= object->EnemyMan.get_enemy();

		if (enemy) {
			state_id = object->EnemyMan.get_danger_type() == eStrong &&
					   !object->HitMemory.is_hit() ? eStatePanic : eStateAttack;

		} else if (object->HitMemory.is_hit()) {
			state_id = eStateHitted;
		} else if (check_state(eStateHearHelpSound)) {
			state_id = eStateHearHelpSound;
		} else if (object->hear_interesting_sound) {
			state_id = eStateHearInterestingSound;
		} else if (object->hear_dangerous_sound) {
			state_id = eStateHearDangerousSound;	
		} else {
			if (can_eat())	state_id = eStateEat;
			else			state_id = eStateRest;

		}
	} else state_id = eStateControlled;

	select_state(state_id); 

	// ��������� ������� ���������
	get_state_current()->execute();

	prev_substate = current_substate;
}
