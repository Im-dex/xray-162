#pragma once

#include "vert.h"

struct st_FACE {
	int		v[3];
	u32		m_id;
	u32		sm_group;
public:
	void	_VSet(int id, int idx){v[id]=idx;}
};

using ExpFaceVec = xr_vector<st_FACE*>;
