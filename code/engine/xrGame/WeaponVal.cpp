#include "pch_script.h"
#include "weaponval.h"

using namespace luabind;

#pragma optimize("s", on)
void CWeaponVal::script_register(lua_State* L) {
    module(L)[class_<CWeaponVal, CGameObject>("CWeaponVal").def(constructor<>())];
}
