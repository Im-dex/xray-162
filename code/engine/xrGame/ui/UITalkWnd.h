#pragma once

#include "UIDialogWnd.h"
#include "UIStatic.h"
#include "UIButton.h"
#include "UIEditBox.h"
//#include "UIListWnd.h"
#include "UIFrameWindow.h"


#include "../PhraseDialogDefs.h"

class CActor;
class CInventoryOwner;
class CPhraseDialogManager;
class CUITalkDialogWnd;
//class CUITradeWnd;
///////////////////////////////////////
//
///////////////////////////////////////

class CUITalkWnd: public CUIDialogWnd
{
private:
	typedef CUIDialogWnd inherited;
	ref_sound			m_sound;
	void				PlaySnd					(LPCSTR text);
	void				StopSnd					();

public:
						CUITalkWnd();
	virtual				~CUITalkWnd();

	IC		bool		playing_sound			()		 { return !!m_sound._feedback(); }
	IC	CInventoryOwner*OthersInvOwner			() const { return m_pOthersInvOwner;	 };

			void		InitTalkWnd				();

	virtual bool		StopAnyMove				(){return true;}
	virtual void		SendMessage				(CUIWindow* pWnd, s16 msg, void* pData = NULL);

	virtual void		Draw					();
	virtual void		Update					();
		
	virtual void		Show					(bool status);
	
	void				Stop					();					//deffered
	void				StopTalk				();

	void				UpdateQuestions			();
	void				NeedUpdateQuestions		();
	//������������� ���������� ������� �����������
	void				InitOthersStartDialog	();
	virtual bool		OnKeyboardAction				(int dik, EUIMessages keyboard_action);
	void				SwitchToTrade			();
	void				SwitchToUpgrade			();
	void				AddIconedMessage		(LPCSTR caption, LPCSTR text, LPCSTR texture_name, LPCSTR templ_name);

protected:
	//������
	void				InitTalkDialog			();
	void				AskQuestion				();

	void				SayPhrase				(const shared_str& phrase_id);

	// ������� ���������� ����� � ����� �������� � �������
public:
	void				AddQuestion				(const shared_str& text, const shared_str& id, int number, bool b_finalizer);
	void				AddAnswer				(const shared_str& text, LPCSTR SpeakerName);
	bool				b_disable_break;
protected:
	CUITalkDialogWnd*	UITalkDialogWnd;

	CActor*				m_pActor;
	CInventoryOwner*	m_pOurInvOwner;
	CInventoryOwner*	m_pOthersInvOwner;
	
	CPhraseDialogManager* m_pOurDialogManager;
	CPhraseDialogManager* m_pOthersDialogManager;

	bool				m_bNeedToUpdateQuestions;

	//������� ������, ���� NULL, �� ��������� � ����� ������ ����
	DIALOG_SHARED_PTR	m_pCurrentDialog;
	bool				TopicMode				();
	void				ToTopicMode				();
};