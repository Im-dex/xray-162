#pragma once

#include "PhraseDialogDefs.h"

class CPhraseDialogManager {
public:
    CPhraseDialogManager(void);
    virtual ~CPhraseDialogManager(void);

    virtual void InitDialog(CPhraseDialogManager* dialog_partner, DIALOG_SHARED_PTR& phrase_dialog);
    virtual void AddDialog(DIALOG_SHARED_PTR& phrase_dialog);

    //��������� �����, ����������� �������,
    //������ ���� �������������� ��� ��������� � ������
    virtual void ReceivePhrase(DIALOG_SHARED_PTR& phrase_dialog);
    //�������� �� ��������� ����� � �������
    virtual void SayPhrase(DIALOG_SHARED_PTR& phrase_dialog, const shared_str& phrase_id);

    //����������� �������, ��������� ������, ��� ���������, �������
    //�������� ����� ������������ � ������ ������
    virtual void UpdateAvailableDialogs(CPhraseDialogManager* partner);

    using DIALOG_VECTOR = xr_vector<DIALOG_SHARED_PTR>;
    const DIALOG_VECTOR& AvailableDialogs() { return m_AvailableDialogs; }
    const DIALOG_SHARED_PTR& GetDialogByID(const shared_str& dialog_id) const;
    bool HaveAvailableDialog(const shared_str& dialog_id) const;

protected:
    virtual bool AddAvailableDialog(shared_str dialog_id, CPhraseDialogManager* partner);

    //��������� ������ ��������, ������� ���� ���������
    //�� ����� UpdateAvailableDialogs
    DIALOG_ID_VECTOR m_CheckedDialogs;

    //������ �������� ��������
    DIALOG_VECTOR m_ActiveDialogs;
    //������ ��������� ��������
    DIALOG_VECTOR m_AvailableDialogs;
};