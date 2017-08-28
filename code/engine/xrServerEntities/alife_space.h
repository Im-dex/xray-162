////////////////////////////////////////////////////////////////////////////
//	Module 		: alife_space.h
//	Created 	: 08.01.2002
//  Modified 	: 08.01.2003
//	Author		: Dmitriy Iassenev
//	Description : ALife space
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_ALIFE_SPACE
#define XRAY_ALIFE_SPACE
//#include "../xrcore/_std_extensions.h"

// ALife objects, events and tasks
#define ALIFE_VERSION 0x0006
#define ALIFE_CHUNK_DATA 0x0000
#define SPAWN_CHUNK_DATA 0x0001
#define OBJECT_CHUNK_DATA 0x0002
#define GAME_TIME_CHUNK_DATA 0x0005
#define REGISTRY_CHUNK_DATA 0x0009
#define SECTION_HEADER "location_"
#define SAVE_EXTENSION ".scop"
#define SPAWN_NAME "game.spawn"
// inventory rukzak size
#define MAX_ITEM_VOLUME 100
#define INVALID_STORY_ID ALife::_STORY_ID(-1)
#define INVALID_SPAWN_STORY_ID ALife::_SPAWN_STORY_ID(-1)

class CSE_ALifeDynamicObject;
class CSE_ALifeMonsterAbstract;
class CSE_ALifeTrader;
class CSE_ALifeInventoryItem;
class CSE_ALifeItemWeapon;
class CSE_ALifeSchedulable;
class CGameGraph;

namespace ALife {
typedef u64 _CLASS_ID;       // Class ID
typedef u16 _OBJECT_ID;      // Object ID
typedef u64 _TIME_ID;        // Time  ID
typedef u32 _EVENT_ID;       // Event ID
typedef u32 _TASK_ID;        // Event ID
typedef u16 _SPAWN_ID;       // Spawn ID
typedef u16 _TERRAIN_ID;     // Terrain ID
typedef u32 _STORY_ID;       // Story ID
typedef u32 _SPAWN_STORY_ID; // Spawn Story ID

struct SSumStackCell {
    int i1;
    int i2;
    int iCurrentSum;
};

enum ECombatResult {
    eCombatResultRetreat1 = u32(0),
    eCombatResultRetreat2,
    eCombatResultRetreat12,
    eCombatResult1Kill2,
    eCombatResult2Kill1,
    eCombatResultBothKilled,
    eCombatDummy = u32(-1),
};

enum ECombatAction {
    eCombatActionAttack = u32(0),
    eCombatActionRetreat,
    eCombatActionDummy = u32(-1),
};

enum EMeetActionType {
    eMeetActionTypeAttack = u32(0),
    eMeetActionTypeInteract,
    eMeetActionTypeIgnore,
    eMeetActionSmartTerrain,
    eMeetActionTypeDummy = u32(-1),
};

enum ERelationType {
    eRelationTypeFriend = u32(0),
    eRelationTypeNeutral,
    eRelationTypeEnemy,
    eRelationTypeWorstEnemy,
    eRelationTypeLast,
    eRelationTypeDummy = u32(-1),
};

enum EHitType {
    eHitTypeBurn = u32(0),
    eHitTypeShock,
    eHitTypeChemicalBurn,
    eHitTypeRadiation,
    eHitTypeTelepatic,
    eHitTypeWound,
    eHitTypeFireWound,
    eHitTypeStrike,
    eHitTypeExplosion,
    eHitTypeWound_2, // knife's alternative fire
    //		eHitTypePhysicStrike,
    eHitTypeLightBurn,
    eHitTypeMax,
};

enum EInfluenceType {
    infl_rad = u32(0),
    infl_fire,
    infl_acid,
    infl_psi,
    infl_electra,
    infl_max_count
};

enum EConditionRestoreType {
    eHealthRestoreSpeed = u32(0),
    eSatietyRestoreSpeed,
    ePowerRestoreSpeed,
    eBleedingRestoreSpeed,
    eRadiationRestoreSpeed,
    eRestoreTypeMax,
};

enum ETakeType {
    eTakeTypeAll,
    eTakeTypeMin,
    eTakeTypeRest,
};

enum EWeaponPriorityType {
    eWeaponPriorityTypeKnife = u32(0),
    eWeaponPriorityTypeSecondary,
    eWeaponPriorityTypePrimary,
    eWeaponPriorityTypeGrenade,
    eWeaponPriorityTypeDummy = u32(-1),
};

enum ECombatType {
    eCombatTypeMonsterMonster = u32(0),
    eCombatTypeMonsterAnomaly,
    eCombatTypeAnomalyMonster,
    eCombatTypeSmartTerrain,
    eCombatTypeDummy = u32(-1),
};

//����������� ����������� �������
enum EWeaponAddonStatus {
    eAddonDisabled = 0,  //������ ������������
    eAddonPermanent = 1, //��������� ���������� �� ���������
    eAddonAttachable = 2 //����� ������������
};

IC EHitType g_tfString2HitType(LPCSTR caHitType) {
    if (!_stricmp(caHitType, "burn"))
        return (eHitTypeBurn);
    else if (!_stricmp(caHitType, "light_burn"))
        return (eHitTypeLightBurn);
    else if (!_stricmp(caHitType, "shock"))
        return (eHitTypeShock);
    else if (!_stricmp(caHitType, "strike"))
        return (eHitTypeStrike);
    else if (!_stricmp(caHitType, "wound"))
        return (eHitTypeWound);
    else if (!_stricmp(caHitType, "radiation"))
        return (eHitTypeRadiation);
    else if (!_stricmp(caHitType, "telepatic"))
        return (eHitTypeTelepatic);
    else if (!_stricmp(caHitType, "fire_wound"))
        return (eHitTypeFireWound);
    else if (!_stricmp(caHitType, "chemical_burn"))
        return (eHitTypeChemicalBurn);
    else if (!_stricmp(caHitType, "explosion"))
        return (eHitTypeExplosion);
    else if (!_stricmp(caHitType, "wound_2"))
        return (eHitTypeWound_2);
    else
        FATAL("Unsupported hit type!");
    NODEFAULT;
#ifdef DEBUG
    return (eHitTypeMax);
#endif
}
#ifndef _EDITOR
xr_token hit_types_token[];

IC LPCSTR g_cafHitType2String(EHitType tHitType) {
    return get_token_name(hit_types_token, tHitType);
}
#endif
using INT_VECTOR = xr_vector<int>;
using OBJECT_VECTOR = xr_vector<_OBJECT_ID>;
using OBJECT_IT = OBJECT_VECTOR::iterator;
using ITEM_P_VECTOR = xr_vector<CSE_ALifeInventoryItem*>;
using WEAPON_P_VECTOR = xr_vector<CSE_ALifeItemWeapon*>;
using SCHEDULE_P_VECTOR = xr_vector<CSE_ALifeSchedulable*>;

using D_OBJECT_P_MAP = xr_map<_OBJECT_ID, CSE_ALifeDynamicObject*>;
using STORY_P_MAP = xr_map<_STORY_ID, CSE_ALifeDynamicObject*>;
}; // namespace ALife

#endif // XRAY_ALIFE_SPACE