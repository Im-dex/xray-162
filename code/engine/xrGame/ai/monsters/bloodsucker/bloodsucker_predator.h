#pragma once
#include "../state.h"

template<typename _Object>
class	CStateBloodsuckerPredator : public CState<_Object> {
	typedef CState<_Object>		inherited;
	typedef CState<_Object>*	state_ptr;

	u32							m_target_node;
	u32							m_time_start_camp;

public:
						CStateBloodsuckerPredator		(_Object *obj);

	virtual void		reinit							();

	virtual void		initialize						();
	virtual	void		reselect_state					();
	virtual	void		finalize						();
	virtual	void		critical_finalize				();
	virtual bool		check_start_conditions			();
	virtual bool		check_completion				();
	virtual void		remove_links					(CObject* object) { inherited::remove_links(object);}

	virtual void		setup_substates					();
	virtual void		check_force_state				();

private:
			void		select_camp_point				();
};

#include "bloodsucker_predator_inline.h"