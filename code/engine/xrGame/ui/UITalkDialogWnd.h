#pragma once


#include "UIStatic.h"
#include "UI3tButton.h"
#include "UIFrameLineWnd.h"

#include "../InfoPortion.h"

#include "UICharacterInfo.h"
#include "UIItemInfo.h"

#include "UIWndCallback.h"

class CUIScrollView;
class CUIXml;
class CUITalkWnd;

class CUITalkDialogWnd: public CUIWindow, public CUIWndCallback
{
private:
	typedef CUIWindow inherited;
	CUIXml*			m_uiXml;
public:
				CUITalkDialogWnd		();
	virtual		~CUITalkDialogWnd		();
	

			void InitTalkDialogWnd		();
	
	virtual void SendMessage			(CUIWindow* pWnd, s16 msg, void* pData = NULL);

	virtual void Show();
	virtual void Hide();
	CUITalkWnd*	m_pParent;
	u32			GetHeaderColor()		{ return m_iNameTextColor; }
	CGameFont *	GetHeaderFont()			{ return m_pNameTextFont; }
	u32			GetOurReplicsColor()	{ return m_uOurReplicsColor; }

	bool				mechanic_mode; // for inventory upgrades
	
	//����� ���������� �������
	shared_str			m_ClickedQuestionID;

	//������ ��������, ������� �� ����� �������� ���������

//	Fvector2			m_btn_pos[3];
	CUI3tButton			UIToTradeButton;
//	CUI3tButton			UIToExitButton;

	CUICharacterInfo	UICharacterInfoLeft;
	CUICharacterInfo	UICharacterInfoRight;

	void				AddQuestion			(LPCSTR str, LPCSTR value, int number, bool b_finalizer);
	void				AddAnswer			(LPCSTR SpeakerName, const char* str, bool bActor);
	void				AddIconedAnswer		(LPCSTR caption, LPCSTR text, LPCSTR texture_name, LPCSTR templ_name);
	void				ClearAll			();
	void				ClearQuestions		();

	void				SetOsoznanieMode	(bool b);
	void				SetTradeMode		();
	void				UpdateButtonsLayout	(bool b_disable_break, bool trade_enabled);

private:
	CUIScrollView*			UIQuestionsList;
	CUIScrollView*			UIAnswersList;

	// ����� � ���� ������ � ������ ���������
	CGameFont			*m_pNameTextFont;
	u32					m_iNameTextColor;
	// ���� �e���� � ����� ����� ������
	u32					m_uOurReplicsColor;

	void __stdcall		OnTradeClicked			(CUIWindow* w, void*);
	void __stdcall		OnUpgradeClicked		(CUIWindow* w, void*);
	void __stdcall		OnQuestionClicked		(CUIWindow* w, void*);
	void __stdcall		OnExitClicked			(CUIWindow* w, void*);
};


class CUIQuestionItem :public CUIWindow, public CUIWndCallback
{
	typedef CUIWindow inherited;
	float			m_min_height;
public:
	CUITextWnd*		m_num_text;
	CUI3tButton*	m_text;
	shared_str		m_s_value;
					CUIQuestionItem			(CUIXml* xml_doc, LPCSTR path);
	void			Init					(LPCSTR val, LPCSTR text);

	virtual void	SendMessage				(CUIWindow* pWnd, s16 msg, void* pData = NULL);
	void __stdcall	OnTextClicked			(CUIWindow* w, void*);
};

class CUIAnswerItem :public CUIWindow
{
	typedef CUIWindow inherited;

	float			m_min_height;
	float			m_bottom_footer;
	CUITextWnd*		m_text;
	CUITextWnd*		m_name;
public:
					CUIAnswerItem			(CUIXml* xml_doc, LPCSTR path);
	void			Init					(LPCSTR text, LPCSTR name);
};

class CUIAnswerItemIconed :public CUIAnswerItem
{
	typedef CUIAnswerItem inherited;
	CUIStatic*		m_icon;

public:
					CUIAnswerItemIconed		(CUIXml* xml_doc, LPCSTR path);
	void			Init					(LPCSTR text, LPCSTR name, LPCSTR texture_name);

};
