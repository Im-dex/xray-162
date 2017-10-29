#include "stdafx.h"
#include "ai_rat.h"
#include "../../../movement_manager.h"

void CAI_Rat::init_state_under_fire() {
    if (!switch_if_enemy() && get_if_dw_time() && m_tLastSound.dwTime >= m_dwLastUpdateTime) {
        Fvector tTemp;
        tTemp.setHP(-movement().m_body.current.yaw, -movement().m_body.current.pitch);
        tTemp.normalize_safe();
        tTemp.mul(m_fUnderFireDistance);
        m_tSpawnPosition.add(Position(), tTemp);
    }
    m_tGoalDir = m_tSpawnPosition;
}

void CAI_Rat::init_free_recoil() {
    m_dwLostRecoilTime = Device.dwTimeGlobal;
    m_tRecoilPosition = m_tLastSound.tSavedPosition;
    if (!switch_if_enemy() && !switch_if_time()) {
        Fvector tTemp;
        tTemp.setHP(-movement().m_body.current.yaw, -movement().m_body.current.pitch);
        tTemp.normalize_safe();
        tTemp.mul(m_fUnderFireDistance);
        m_tSpawnPosition.add(Position(), tTemp);
    }
}

void CAI_Rat::init_free_active() {
    if (bfCheckIfGoalChanged()) {
        if (Position().distance_to(m_home_position) > m_fMaxHomeRadius)
            m_fSpeed = m_fSafeSpeed = m_fMaxSpeed;
        vfChooseNewSpeed();
    }
}