#include "stdafx.h"
#include "UIMoneyIndicator.h"
#include "xrUIXmlParser.h"
#include "UIXmlInit.h"
#include "UIGameLog.h"

CUIMoneyIndicator::CUIMoneyIndicator(){
	AttachChild(&m_back);
	AttachChild(&m_money_amount);
	AttachChild(&m_money_change);
//	m_pAnimChange = xr_new<CUIColorAnimatorWrapper>("ui_mp_chat");
//	m_pAnimChange->Cyclic(false);
//	m_pAnimChange->SetDone(true);
}

CUIMoneyIndicator::~CUIMoneyIndicator(){
}

void CUIMoneyIndicator::InitFromXML(CUIXml& xml_doc)
{
	CUIXmlInit::InitWindow		(xml_doc, "money_wnd", 0,	this);
	CUIXmlInit::InitStatic		(xml_doc, "money_wnd:money_indicator",0, &m_back);
	CUIXmlInit::InitTextWnd		(xml_doc, "money_wnd:money_indicator:total_money",0, &m_money_amount);
	CUIXmlInit::InitTextWnd		(xml_doc, "money_wnd:money_change", 0, &m_money_change);
	CGameFont* pF;
	u32 color;
	CUIXmlInit::InitFont		(xml_doc, "money_wnd:money_bonus_list:font", 0, color, pF);
	m_money_change.SetVisible	(false);

	m_money_change.SetColorAnimation("ui_mp_chat", LA_ONLYALPHA|LA_TEXTCOLOR);
}

void CUIMoneyIndicator::SetMoneyAmount(LPCSTR money){
	m_money_amount.SetText(money);
}

void CUIMoneyIndicator::SetMoneyChange(LPCSTR money)
{
	m_money_change.SetText				(money);
	m_money_change.ResetColorAnimation	();
}

void CUIMoneyIndicator::Update()
{
	CUIWindow::Update();
}

