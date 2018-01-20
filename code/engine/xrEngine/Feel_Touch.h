#pragma once

#include "pure_relcase.h"

class ENGINE_API CObject;
namespace Feel {
class ENGINE_API Touch : private pure_relcase {
public:
    struct DenyTouch {
        CObject* O;
        DWORD Expire;
    };

protected:
    std::vector<DenyTouch> feel_touch_disable;

public:
    std::vector<CObject*> feel_touch;
    std::vector<CObject*> q_nearest;

public:
    void __stdcall feel_touch_relcase(CObject* O);

public:
    Touch();
    virtual ~Touch();

    virtual BOOL feel_touch_contact(CObject* O);
    virtual void feel_touch_update(Fvector& P, float R);
    virtual void feel_touch_deny(CObject* O, DWORD T);
    virtual void feel_touch_new(CObject* O){};
    virtual void feel_touch_delete(CObject* O){};
};
}; // namespace Feel
