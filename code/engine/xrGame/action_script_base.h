////////////////////////////////////////////////////////////////////////////
//	Module 		: action_script_base.h
//	Created 	: 28.03.2004
//  Modified 	: 28.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Base action with script support
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "action_base.h"

class CScriptGameObject;

template <typename ObjectType>
class CActionScriptBase : public CScriptActionBase {
protected:
    using inherited = CScriptActionBase;

public:
    ObjectType* m_object;

    CActionScriptBase(const std::vector<COperatorCondition>& conditions,
                      const std::vector<COperatorCondition>& effects, ObjectType* object = nullptr,
                      LPCSTR action_name = "")
        : inherited(conditions, effects, object ? object->lua_game_object() : nullptr, action_name),
          m_object(object)
    {}

    CActionScriptBase(ObjectType* object = nullptr, LPCSTR action_name = "")
        : inherited(object ? object->lua_game_object() : nullptr, action_name),
          m_object(object)
    {}

    virtual ~CActionScriptBase() = default;

    virtual void setup(ObjectType* object, CPropertyStorage* storage) {
        VERIFY(object);
        m_object = object;
    }

    virtual void setup(CScriptGameObject* object, CPropertyStorage* storage) {
        VERIFY(object);
        inherited::setup(object, storage);
        setup(smart_cast<ObjectType*>(&object->object()), storage);
    }
};
