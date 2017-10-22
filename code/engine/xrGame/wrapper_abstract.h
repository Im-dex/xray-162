////////////////////////////////////////////////////////////////////////////
//	Module 		: wrapper_abstract.h
//	Created 	: 28.01.2004
//  Modified 	: 10.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Abastract wrapper
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "script_game_object.h"

template <typename ObjectType, template <typename BaseObjectType> class Ancestor,
          typename BaseObjectType = CScriptGameObject>
class CWrapperAbstract : public Ancestor<BaseObjectType> {
protected:
    using inherited = Ancestor<BaseObjectType>;

    ObjectType* m_object;

public:
    template <typename... Ts>
    CWrapperAbstract(Ts&&... ts)
        : inherited(std::forward<Ts>(ts)...),
          m_object(nullptr)
    {}
    virtual ~CWrapperAbstract() = default;

    virtual void setup(ObjectType* object) {
        VERIFY(object);
        inherited::setup(object->lua_game_object());
        m_object = object;
    }

    virtual void setup(CScriptGameObject* object) {
        VERIFY(object);
        inherited::setup(object);
        m_object = smart_cast<ObjectType*>(&object->object());
        VERIFY(m_object);
    }

    ObjectType& object() const {
        VERIFY(m_object);
        return (*m_object);
    }
};

class CPropertyStorage;

template <typename ObjectType, template <typename BaseObjectType> class Ancestor,
          typename BaseObjectType = CScriptGameObject>
class CWrapperAbstract2 : public Ancestor<BaseObjectType> {
protected:
    using inherited = Ancestor<BaseObjectType>;

    ObjectType* m_object;

public:
    template <typename... Ts>
    CWrapperAbstract2(Ts&&... ts)
        : inherited(std::forward<Ts>(ts)...),
          m_object(nullptr)
    {}
    virtual ~CWrapperAbstract2() = default;

    virtual void setup(ObjectType* object, CPropertyStorage* storage) {
        VERIFY(object);
        inherited::setup(object->lua_game_object(), storage);
        m_object = object;
    }

    virtual void setup(CScriptGameObject* object, CPropertyStorage* storage) {
        VERIFY(object);
        inherited::setup(object, storage);
        m_object = smart_cast<ObjectType*>(&object->object());
        VERIFY(m_object);
    }

    ObjectType& object() const {
        VERIFY(m_object);
        return (*m_object);
    }
};
