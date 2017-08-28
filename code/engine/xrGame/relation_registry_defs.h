//////////////////////////////////////////////////////////////////////////
// relation_registry_defs.h:	������ ��� �������� ������ �� ��������� ��������� �
//								������ ����������
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "object_interfaces.h"

//���������, ����������� ��������� ������ ��������� � ������� ��� � �����������
struct SRelation {
    SRelation();
    ~SRelation();
    CHARACTER_GOODWILL Goodwill() const { return m_iGoodwill; };
    void SetGoodwill(CHARACTER_GOODWILL new_goodwill) { m_iGoodwill = new_goodwill; };

private:
    //���������������
    CHARACTER_GOODWILL m_iGoodwill;
};

using PERSONAL_RELATION_MAP = xr_map<u16, SRelation>;
using COMMUNITY_RELATION_MAP = xr_map<CHARACTER_COMMUNITY_INDEX, SRelation>;

//���������, ���������� ��� ������� ��������� � ����
struct RELATION_DATA : public IPureSerializeObject<IReader, IWriter> {
    virtual void clear();

    virtual void load(IReader&);
    virtual void save(IWriter&);

    //������ ���������
    PERSONAL_RELATION_MAP personal;
    //��������� � �������������
    COMMUNITY_RELATION_MAP communities;
};
