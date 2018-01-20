////////////////////////////////////////////////////////////////////////////
//	Module 		: action_base.h
//	Created 	: 28.01.2004
//  Modified 	: 10.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Base action
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "action_management_config.h"
#include "property_storage.h"
#include "script_export_space.h"
#include "operator_abstract.h"
#include "alife_space.h"
#include "level.h"

class CScriptGameObject;

template <typename _object_type>
class CActionBase : public GraphEngineSpace::CWorldOperator {
protected:
    using inherited = GraphEngineSpace::CWorldOperator;
    using COperatorCondition = GraphEngineSpace::CWorldProperty;
    using _condition_type = GraphEngineSpace::_solver_condition_type;
    using _value_type = GraphEngineSpace::_solver_value_type;

    enum EActionStates {
        eActionStateConstructed = u32(0),
        eActionStateSetup,
        eActionStateInitialized,
        eActionStateExecuted,
        eActionStateFinalized,
        eActionStateDummy = u32(-1),
    };

public:
    _object_type* m_object;
    CPropertyStorage* m_storage;

protected:
    u32 m_start_level_time;
    u32 m_start_game_time;
    u32 m_inertia_time;
    mutable _edge_value_type m_weight;
    bool m_first_time;

#ifdef LOG_ACTION
public:
    LPCSTR m_action_name;
    bool m_use_log;
    bool m_switched;

public:
    virtual void debug_log(const EActionStates state_state) const {
        switch (state_state) {
            case eActionStateConstructed: {
                Msg("[%6d] action %s is constructed", Device.dwTimeGlobal, m_action_name);
                break;
            }
            case eActionStateSetup: {
                Msg("[%6d] action %s is setup", Device.dwTimeGlobal, m_action_name);
                break;
            }
            case eActionStateInitialized: {
                Msg("[%6d] action %s is initialized", Device.dwTimeGlobal, m_action_name);
                break;
            }
            case eActionStateExecuted: {
                Msg("[%6d] action %s is executed", Device.dwTimeGlobal, m_action_name);
                break;
            }
            case eActionStateFinalized: {
                Msg("[%6d] action %s is finalized", Device.dwTimeGlobal, m_action_name);
                break;
            }
            default:
                NODEFAULT;
        }
    }

    virtual void set_use_log(bool value) {
        m_use_log = value;
    }

    virtual void show(LPCSTR offset = "") {}
#endif

public:
    CActionBase(const std::vector<COperatorCondition>& conditions,
                const std::vector<COperatorCondition>& effects, _object_type* object = nullptr,
                LPCSTR action_name = "")
        : inherited(conditions, effects) {
        init(object, action_name);
    }

    CActionBase(_object_type* object, LPCSTR action_name = "") {
        init(object, action_name);
    }

    virtual ~CActionBase() = default;

    void init(_object_type* object, LPCSTR action_name) {
        m_storage = nullptr;
        m_object = object;
        m_weight = _edge_value_type(1);

#ifdef LOG_ACTION
        m_use_log = false;
        m_action_name = action_name;
        m_switched = false;
#endif
    }

    virtual void setup(_object_type* object, CPropertyStorage* storage) {
        VERIFY(object);
        VERIFY(storage);
        m_object = object;
        m_storage = storage;
        m_inertia_time = 0;
#ifdef LOG_ACTION
        m_switched = false;
        if (m_use_log && xr_strlen(m_action_name))
            debug_log(eActionStateSetup);
#endif
    }

    virtual void initialize() {
#ifdef LOG_ACTION
        VERIFY3(!m_switched, m_action_name, "::initialize()");
        m_switched = true;
        if (m_use_log && xr_strlen(m_action_name))
            debug_log(eActionStateInitialized);
#endif
        m_start_level_time = Device.dwTimeGlobal;
        m_first_time = true;
    }

    virtual void execute() {
        m_first_time = false;
#ifdef LOG_ACTION
        if (m_use_log && xr_strlen(m_action_name) && m_switched)
            debug_log(eActionStateExecuted);
        m_switched = false;
#endif
    }

    virtual void finalize() {
#ifdef LOG_ACTION
        VERIFY3(!m_switched, m_action_name, "::finalize()");
        if (m_use_log && xr_strlen(m_action_name))
            debug_log(eActionStateFinalized);
#endif
    }

    _edge_value_type weight(const CSConditionState& condition0,
                            const CSConditionState& condition1) const override {
        const _edge_value_type _min_weight = min_weight();
        if (m_weight < _min_weight)
            m_weight = _min_weight;
        return m_weight;
    }
    void set_inertia_time(u32 inertia_time) { m_inertia_time = inertia_time; }
    u32 start_level_time() const { return m_start_level_time; }
    u32 inertia_time() const { return m_inertia_time; }
    bool completed() const {
        return m_start_level_time + m_inertia_time <= Device.dwTimeGlobal;
    }
    void set_property(const _condition_type& condition_id, const _value_type& value) {
        VERIFY(m_storage);
        m_storage->set_property(condition_id, value);
    }
    const _value_type& property(const _condition_type& condition_id) const {
        VERIFY(m_storage);
        return (m_storage->property(condition_id));
    }
    void set_weight(const _edge_value_type& weight) {
        m_weight = std::max(min_weight(), weight);
    }
    bool first_time() const {
        return m_first_time;
    }

    virtual void save(NET_Packet& packet) {}
    virtual void load(IReader& packet) {}

    DECLARE_SCRIPT_REGISTER_FUNCTION
};

using CScriptActionBase = CActionBase<CScriptGameObject>;
add_to_type_list(CScriptActionBase)
#undef script_type_list
#define script_type_list save_type_list(CScriptActionBase)
