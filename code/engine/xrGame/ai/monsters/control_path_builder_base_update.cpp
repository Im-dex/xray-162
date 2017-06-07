#include "stdafx.h"
#include "control_path_builder_base.h"
#include "BaseMonster/base_monster.h"
#include "../../detail_path_manager.h"
#include "../../profiler.h"

void CControlPathBuilderBase::update_frame()
{	
	START_PROFILE("Base Monster/Path Builder Base/Frame Update");

	// �������� ��������� �������
	update_path_builder_state						();
	
	// �������� / ���������� ������� �������
	update_target_point								();

	// set params
	set_path_builder_params							();	

	STOP_PROFILE;
}

void CControlPathBuilderBase::update_target_point() 
{
	m_reset_actuality = false;
	
	if (!m_enable)											return;
	if (m_path_type != MovementManager::ePathTypeLevelPath) return;

	// ��������� �������, ����� ���� ������� �� �����
	if (!target_point_need_update())						return; 

	STarget saved_target;
	saved_target.set(m_target_found.position(), m_target_found.node());

	if (global_failed())
		find_target_point_failed	();
	else 
		// ������� ���� � ������� � ������������ � ��������� ����� � ��������
		find_target_point_set		();


	//-----------------------------------------------------------------------
	// postprocess target_point
	if (m_target_found.node() == saved_target.node()) {
		// level_path ��������� ���������� - �������� ������������
		m_reset_actuality = true;
	}
	//-----------------------------------------------------------------------

	// ��������� ������� ����� 
	m_last_time_target_set	= Device.dwTimeGlobal;

	// ��������� �����������, �������� ������������
	m_target_actual			= true;
}

void CControlPathBuilderBase::set_path_builder_params()
{
	SControlPathBuilderData	*ctrl_data = (SControlPathBuilderData *)m_man->data(this, ControlCom::eControlPath);
	if (!ctrl_data) return;

	ctrl_data->use_dest_orientation		= m_use_dest_orient;
	ctrl_data->dest_orientation			= m_dest_dir;
	ctrl_data->target_node				= m_target_found.node();
	ctrl_data->target_position			= m_target_found.position();
	ctrl_data->try_min_time				= m_try_min_time;
	ctrl_data->enable					= m_enable;
	ctrl_data->path_type				= m_path_type;
	ctrl_data->extrapolate				= m_extrapolate;
	ctrl_data->velocity_mask			= m_velocity_mask;
	ctrl_data->desirable_mask			= m_desirable_mask;
	ctrl_data->reset_actuality			= m_reset_actuality;
	ctrl_data->game_graph_target_vertex = m_game_graph_target_vertex;
}


void CControlPathBuilderBase::update_path_builder_state()
{
//	u32 state_prev = m_state;
	
	m_state = eStatePathValid;

	// ��� ����
	if (m_man->path_builder().detail().path().empty()) {
		m_state = eStateNoPath; 
	} 
	// �������� �� ����� ����
	else if (m_path_end) {
		m_state = eStatePathEnd;
	}

	// ����� ���� �� ����� �������� ���� (���� ������ ���� �������������� ��������)
	if ((m_last_time_target_set > m_time_path_updated_external) || 
		(!m_man->path_builder().detail().actual() && (m_man->path_builder().detail().time_path_built() < m_last_time_target_set))) {
		m_state |= eStateWaitNewPath;
	}
	
	if (m_failed) {
		// set
		m_state |= eStatePathFailed;
		// clear
		m_state &= ~eStatePathValid;
		m_state &= ~eStateWaitNewPath;

		m_failed						= false;

		m_time_global_failed_started	= time();
	}

}
