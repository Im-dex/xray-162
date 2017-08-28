///////////////////////////////////////////////////////////////
// BlackGraviArtifact.h
// BlackGraviArtefact - �������������� ��������,
// ����� �� ��� � �������, �� ��� ��������� ����
///////////////////////////////////////////////////////////////

#pragma once
#include "GraviArtifact.h"
#include "../xrEngine/feel_touch.h"
#include "PhysicsShellHolder.h"
using GAME_OBJECT_LIST = xr_vector<CPhysicsShellHolder*>;

class CBlackGraviArtefact : public CGraviArtefact, public Feel::Touch {
private:
    collide::rq_results rq_storage;

private:
    typedef CGraviArtefact inherited;

public:
    CBlackGraviArtefact(void);
    virtual ~CBlackGraviArtefact(void);

    virtual BOOL net_Spawn(CSE_Abstract* DC);

    virtual void Load(LPCSTR section);

    virtual void Hit(SHit* pHDS);

    virtual void feel_touch_new(CObject* O);
    virtual void feel_touch_delete(CObject* O);
    virtual BOOL feel_touch_contact(CObject* O);

protected:
    virtual void net_Relcase(CObject* O);
    virtual void UpdateCLChild();

    //�������������� ���� �� ���� �������� � ���� ������������
    void GraviStrike();

    GAME_OBJECT_LIST m_GameObjectList;

    //�������� �������� ��������������
    float m_fImpulseThreshold;
    //������ �������� ���������
    float m_fRadius;
    //������� ������������ ���������� ���������
    float m_fStrikeImpulse;

    //����, ���� ��� �������� ������� ���
    //� ������ ����� ��������� ������
    bool m_bStrike;

    shared_str m_sParticleName;
};
