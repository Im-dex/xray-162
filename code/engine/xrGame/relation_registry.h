//////////////////////////////////////////////////////////////////////////
// relation_registry.h: ������ ��� �������� ������ �� ��������� ��������� �
//						������ ����������
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "character_info_defs.h"

class CRelationRegistryWrapper;

class CInventoryOwner;
class CEntityAlive;

//////////////////////////////////////////////////////////////////////////

#define GAME_RELATIONS_SECT "game_relations"
#define ACTIONS_POINTS_SECT "action_points"

//////////////////////////////////////////////////////////////////////////

struct RELATION_REGISTRY {
public:
    RELATION_REGISTRY();
    virtual ~RELATION_REGISTRY();

public:
    template <typename T>
    ALife::ERelationType GetRelationBetween(T char1, T char2) const;

    template <typename T>
    ALife::ERelationType GetRelationType(T from, T to) const;
    template <typename T>
    void SetRelationType(T from, T to, ALife::ERelationType new_relation);

    //����� ���������  ������ ��������� � �������, ����������� �� �������
    //� ������ ���� �������� - �������� ��
    //-100< (������ ����������) �� >100 (����� �����������)

    template <typename T>
    CHARACTER_GOODWILL GetAttitude(T from, T to) const;

    //������ ��������� (���������������) ������ ��������� � ������� -
    //�������� �� -100< (������ ����������) �� >100 (����� �����������)
    CHARACTER_GOODWILL GetGoodwill(u16 from, u16 to) const;
    void SetGoodwill(u16 from, u16 to, CHARACTER_GOODWILL goodwill);
    void ForceSetGoodwill(u16 from, u16 to, CHARACTER_GOODWILL goodwill);
    void ChangeGoodwill(u16 from, u16 to, CHARACTER_GOODWILL delta_goodwill);

    //��������� ����������� � ��������� (������ ���, � �� ��������)
    //�.�. �������� ��� ������, ��� � ���� ����� ����������� ���������
    CHARACTER_GOODWILL GetCommunityGoodwill(CHARACTER_COMMUNITY_INDEX from_community,
                                            u16 to_character) const;
    void SetCommunityGoodwill(CHARACTER_COMMUNITY_INDEX from_community, u16 to_character,
                              CHARACTER_GOODWILL goodwill);
    void ChangeCommunityGoodwill(CHARACTER_COMMUNITY_INDEX from_community, u16 to_character,
                                 CHARACTER_GOODWILL delta_goodwill);

    void ClearRelations(u16 person_id);

    CHARACTER_GOODWILL GetCommunityRelation(CHARACTER_COMMUNITY_INDEX,
                                            CHARACTER_COMMUNITY_INDEX) const;
    void SetCommunityRelation(CHARACTER_COMMUNITY_INDEX index1, CHARACTER_COMMUNITY_INDEX index2,
                              CHARACTER_GOODWILL goodwill);

private:
    CHARACTER_GOODWILL GetRankRelation(CHARACTER_RANK_VALUE, CHARACTER_RANK_VALUE) const;
    CHARACTER_GOODWILL GetReputationRelation(CHARACTER_REPUTATION_VALUE,
                                             CHARACTER_REPUTATION_VALUE) const;

    //�������� �� �������� ���������� � ��������������� ��������� ���������
public:
    //������ �������� ������, �� ������� �����������
    //���� ��������, ��������� ��� �������� ��������� ���������
    //� �����������
    enum ERelationAction {
        KILL = 0x00,               //�������� ���������
        ATTACK = 0x01,             //����� ���������
        FIGHT_HELP_HUMAN = 0x02,   //������ � ����� ��������� � ������ ����������
        FIGHT_HELP_MONSTER = 0x04, //������ � ����� ��������� c ��������
        SOS_HELP = 0x08            //������ �� ������ �� ������� SOS
    };
    void Action(CEntityAlive* from, CEntityAlive* to, ERelationAction action);

public:
    struct FIGHT_DATA {
        FIGHT_DATA();
        u16 attacker;
        u16 defender;
        float total_hit;
        u32 time;
        u32 time_old;

        u32 attack_time; //����� ������������ ������� "�����"
        ALife::ERelationType
            defender_to_attacker; //��� ��������� ���������� � ����������� �� ����� ��������� �����
    };

    struct RELATION_MAP_SPOTS {
        RELATION_MAP_SPOTS();
        shared_str spot_names[ALife::eRelationTypeLast + 1];
        const shared_str& GetSpotName(ALife::ERelationType& type) {
            if (type < ALife::eRelationTypeLast)
                return spot_names[type];
            else
                return spot_names[ALife::eRelationTypeLast];
        };
    };
    //���������������� ����� (������� �� Hit � EntityAlive)
    static void FightRegister(u16 attacker, u16 defender, ALife::ERelationType defender_to_attacker,
                              float hit_amount);
    static void UpdateFightRegister();

private:
    using FIGHT_VECTOR = xr_vector<FIGHT_DATA>;
    static FIGHT_VECTOR* m_fight_registry;
    static FIGHT_VECTOR& fight_registry();

    static FIGHT_DATA* FindFight(u16 object_id, bool by_attacker /* = true*/);
    static RELATION_MAP_SPOTS* m_spot_names;

public:
    const shared_str& GetSpotName(ALife::ERelationType& type);
    static CRelationRegistryWrapper& relation_registry();
    static void clear_relation_registry();

private:
    static CRelationRegistryWrapper* m_relation_registry;
};

#include "relation_registry_inline.h"