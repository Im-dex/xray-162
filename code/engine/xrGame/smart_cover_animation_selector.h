////////////////////////////////////////////////////////////////////////////
//	Module 		: smart_cover_animation_selector.h
//	Created 	: 07.09.2007
//	Author		: Alexander Dudin
//	Description : Animation selector for smart covers
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "smart_cover_detail.h"
#include "xrRender/KinematicsAnimated.h"
#include "smart_cover_animation_planner.h"

class CAI_Stalker;
class CPropertyStorage;
class IKinematicsAnimated;
class CScriptGameObject;
class CBlend;

namespace smart_cover {

class action_base;
class wait_after_exit;

class animation_selector final {
    CPropertyStorage* m_storage;
    CAI_Stalker* m_object;
    animation_planner* m_planner;
    IKinematicsAnimated* m_skeleton_animated;
    shared_str m_animation;
    float m_previous_time;
    bool m_first_time;
    bool m_callback_called;

    action_base* current_operator() const;

public:
    animation_selector(CAI_Stalker* object);

    animation_selector(const animation_selector& other) = delete;
    animation_selector& operator=(const animation_selector& other) = delete;
    ~animation_selector();
    void initialize();
    void execute();
    void finalize();
    MotionID xr_stdcall select_animation(bool& animation_movement_controller);
    void xr_stdcall on_animation_end();
    void xr_stdcall modify_animation(CBlend* blend);
    void save(NET_Packet& packet);
    void load(IReader& packet);
    void setup(CAI_Stalker* object, CPropertyStorage* storage);
    IC CPropertyStorage* property_storage();
    IC animation_planner& planner();
};

} // namespace smart_cover

#include "smart_cover_animation_selector_inline.h"
