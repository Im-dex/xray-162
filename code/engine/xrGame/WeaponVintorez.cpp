#include "pch_script.h"
#include "weaponvintorez.h"

using namespace luabind;

#pragma optimize("s", on)
void CWeaponVintorez::script_register(lua_State* L) {
    module(L)[class_<CWeaponVintorez, CGameObject>("CWeaponVintorez").def(constructor<>())];
}
