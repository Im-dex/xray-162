///////////////////////////////////////////////////////////////
// PhraseScript.h
// ������ ��� ����� �������� �� ���������
///////////////////////////////////////////////////////////////

#include "InfoPortionDefs.h"

#pragma once

class CGameObject;
class CInventoryOwner;
class XML_NODE;
class CUIXml;

class CDialogScriptHelper {
public:
    void Load(CUIXml* ui_xml, XML_NODE phrase_node);

    bool Precondition(const CGameObject* pSpeaker, LPCSTR dialog_id, LPCSTR phrase_id) const;
    void Action(const CGameObject* pSpeaker, LPCSTR dialog_id, LPCSTR phrase_id) const;

    bool Precondition(const CGameObject* pSpeaker1, const CGameObject* pSpeaker2, LPCSTR dialog_id,
                      LPCSTR phrase_id, LPCSTR next_phrase_id) const;
    void Action(const CGameObject* pSpeaker1, const CGameObject* pSpeaker2, LPCSTR dialog_id,
                LPCSTR phrase_id) const;

    using PRECONDITION_VECTOR = xr_vector<shared_str>;
    const PRECONDITION_VECTOR& Preconditions() const { return m_Preconditions; }

    using ACTION_NAME_VECTOR = xr_vector<shared_str>;
    const ACTION_NAME_VECTOR& Actions() const { return m_ScriptActions; }

    void AddPrecondition(LPCSTR str);
    void AddAction(LPCSTR str);
    void AddHasInfo(LPCSTR str);
    void AddDontHasInfo(LPCSTR str);
    void AddGiveInfo(LPCSTR str);
    void AddDisableInfo(LPCSTR str);
    void SetScriptText(LPCSTR str) { m_sScriptTextFunc = str; };
    LPCSTR GetScriptText(LPCSTR str_to_translate, const CGameObject* pSpeakerGO1,
                         const CGameObject* pSpeakerGO2, LPCSTR dialog_id, LPCSTR phrase_id);

protected:
    //�������� ���������� ������������������ ����� � ��������� �����
    template <class T>
    void LoadSequence(CUIXml* ui_xml, XML_NODE phrase_node, LPCSTR tag, T& str_vector);

    //����������� � ����������� �� ����� ������� Precondition � Action
    virtual bool CheckInfo(const CInventoryOwner* pOwner) const;
    virtual void TransferInfo(const CInventoryOwner* pOwner) const;

    //��� ���������� �������, ������� ���������� �����-�� �����
    shared_str m_sScriptTextFunc;

    //���������� ��������, ������� ������������ ����� ���� ���
    //��������� �����
    using ACTION_NAME_VECTOR = xr_vector<shared_str>;
    ACTION_NAME_VECTOR m_ScriptActions;

    using INFO_VECTOR = xr_vector<shared_str>;

    INFO_VECTOR m_GiveInfo;
    INFO_VECTOR m_DisableInfo;

    //������ ���������� ����������, ����������, ������� ����������
    //��� ���� ���� ����� ����� ���������
    using PRECONDITION_VECTOR = xr_vector<shared_str>;

    PRECONDITION_VECTOR m_Preconditions;
    //�������� �������/���������� ����������
    INFO_VECTOR m_HasInfo;
    INFO_VECTOR m_DontHasInfo;
};