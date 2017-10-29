#include "pch_script.h"
#include "weaponwalther.h"

using namespace luabind;

#pragma optimize("s", on)
void CWeaponWalther::script_register(lua_State* L) {
    module(L)[class_<CWeaponWalther, CGameObject>("CWeaponWalther").def(constructor<>())];
}
