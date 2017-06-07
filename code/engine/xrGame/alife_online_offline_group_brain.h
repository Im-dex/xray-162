////////////////////////////////////////////////////////////////////////////
//	Module 		: alife_online_offline_group_brain.h
//	Created 	: 25.10.2005
//  Modified 	: 25.10.2005
//	Author		: Dmitriy Iassenev
//	Description : ALife Online Offline Group brain class
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "game_graph_space.h"
#include "xrserver_space.h"
#include "alife_space.h"
#include "script_export_space.h"

class CSE_ALifeOnlineOfflineGroup;
class CALifeMonsterMovementManager;
class CSE_ALifeSmartZone;
class NET_Packet;

class CALifeOnlineOfflineGroupBrain {
public:
	typedef CSE_ALifeOnlineOfflineGroup						object_type;
	typedef CALifeMonsterMovementManager					movement_manager_type;

private:
	object_type					*m_object;
	movement_manager_type		*m_movement_manager;
	
public:
						CALifeOnlineOfflineGroupBrain	(object_type *object);
	virtual				~CALifeOnlineOfflineGroupBrain	();

public:
	void						on_state_write			(NET_Packet &packet);
	void						on_state_read			(NET_Packet &packet);
	void						on_register				();
	void						on_unregister			();
	void						on_location_change		();
	void						on_switch_online		();
	void						on_switch_offline		();

public:
	void						update					();
public:
	IC		object_type				&object				() const;
	IC		movement_manager_type	&movement			() const;

	DECLARE_SCRIPT_REGISTER_FUNCTION
};
add_to_type_list(CALifeOnlineOfflineGroupBrain)
#undef script_type_list
#define script_type_list save_type_list(CALifeOnlineOfflineGroupBrain)

#include "alife_online_offline_group_brain_inline.h"
