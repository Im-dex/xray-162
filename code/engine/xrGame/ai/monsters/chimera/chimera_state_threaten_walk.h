#pragma once
#include "../state.h"

template<typename _Object>
class CStateChimeraThreatenWalk : public CStateMonsterMoveToPointEx<_Object> {
	typedef CStateMonsterMoveToPointEx<_Object>		inherited;

public:
	IC					CStateChimeraThreatenWalk	(_Object *obj) : inherited(obj){}
	virtual	void		initialize					();	
	virtual	void		execute						();
	virtual bool		check_completion			();
	virtual bool		check_start_conditions		();
	
};

#include "chimera_state_threaten_walk_inline.h"
