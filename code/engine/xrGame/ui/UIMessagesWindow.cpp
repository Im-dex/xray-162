// File:		UIMessagesWindow.h
// Description:	Window with MP chat and Game Log ( with PDA messages in single and Kill Messages
// in MP) Created:		22.04.2005 Author:		Serge Vynnychenko Mail:
// narrator@gsc-game.kiev.ua
//
// Copyright 2005 GSC Game World

#include "StdAfx.h"
bool IsGameTypeSingle();
#include "UIMessagesWindow.h"
#include "UIGameLog.h"
#include "xrUIXmlParser.h"
#include "UIXmlInit.h"
#include "UIInventoryUtilities.h"
#include "../game_news.h"
#include "UIPdaMsgListItem.h"

CUIMessagesWindow::CUIMessagesWindow() : m_pGameLog(nullptr) {
    Init(0, 0, UI_BASE_WIDTH, UI_BASE_HEIGHT);
}

CUIMessagesWindow::~CUIMessagesWindow() {}

void CUIMessagesWindow::AddLogMessage(const shared_str& msg) { m_pGameLog->AddLogMessage(*msg); }

void CUIMessagesWindow::PendingMode(bool const is_pending_mode) {
    if (is_pending_mode) {
        if (m_in_pending_mode)
            return;

        m_in_pending_mode = true;
        return;
    }
    if (!m_in_pending_mode)
        return;

    m_in_pending_mode = false;
}

#define CHAT_LOG_LIST_PENDING "chat_log_list_pending"
void CUIMessagesWindow::Init(float x, float y, float width, float height) {

    CUIXml xml;
    xml.Load(CONFIG_PATH, UI_PATH, "messages_window.xml");
    m_pGameLog = xr_new<CUIGameLog>();
    m_pGameLog->SetAutoDelete(true);
    m_pGameLog->Show(true);
    AttachChild(m_pGameLog);
    if (IsGameTypeSingle()) {
        CUIXmlInit::InitScrollView(xml, "sp_log_list", 0, m_pGameLog);
    } else {
        u32 color;
        CGameFont* pFont;

        CUIXmlInit::InitScrollView(xml, "mp_log_list", 0, m_pGameLog);
        CUIXmlInit::InitFont(xml, "mp_log_list:font", 0, color, pFont);
        m_pGameLog->SetTextAtrib(pFont, color);

        m_in_pending_mode = false;

        XML_NODE pending_chat_list = xml.NavigateToNode(CHAT_LOG_LIST_PENDING);

        if (pending_chat_list) {
            m_pending_chat_log_rect.x1 = xml.ReadAttribFlt(CHAT_LOG_LIST_PENDING, 0, "x");
            m_pending_chat_log_rect.y1 = xml.ReadAttribFlt(CHAT_LOG_LIST_PENDING, 0, "y");
            m_pending_chat_log_rect.x2 = xml.ReadAttribFlt(CHAT_LOG_LIST_PENDING, 0, "width");
            m_pending_chat_log_rect.y2 = xml.ReadAttribFlt(CHAT_LOG_LIST_PENDING, 0, "height");
            m_pending_chat_log_rect.rb.add(m_pending_chat_log_rect.lt);

        } else
            m_pending_chat_log_rect = m_inprogress_chat_log_rect;

        CUIXmlInit::InitFont(xml, "chat_log_list:font", 0, color, pFont);
    }
}

void CUIMessagesWindow::AddIconedPdaMessage(GAME_NEWS_DATA* news) {
    CUIPdaMsgListItem* pItem = m_pGameLog->AddPdaMessage();

    LPCSTR time_str = InventoryUtilities::GetTimeAsString(news->receive_time,
                                                          InventoryUtilities::etpTimeToMinutes)
                          .c_str();
    pItem->UITimeText.SetText(time_str);
    pItem->UITimeText.AdjustWidthToText();
    Fvector2 p = pItem->UICaptionText.GetWndPos();
    p.x = pItem->UITimeText.GetWndPos().x + pItem->UITimeText.GetWidth() + 3.0f;
    pItem->UICaptionText.SetWndPos(p);
    pItem->UICaptionText.SetTextST(news->news_caption.c_str());
    pItem->UIMsgText.SetTextST(news->news_text.c_str());
    pItem->UIMsgText.AdjustHeightToText();

    pItem->SetColorAnimation("ui_main_msgs_short", LA_ONLYALPHA | LA_TEXTCOLOR | LA_TEXTURECOLOR,
                             float(news->show_time));
    pItem->UIIcon.InitTexture(news->texture_name.c_str());

    float h1 = std::max(pItem->UIIcon.GetHeight(),
                        pItem->UIMsgText.GetWndPos().y + pItem->UIMsgText.GetHeight());
    pItem->SetHeight(h1 + 3.0f);

    m_pGameLog->SendMessage(pItem, CHILD_CHANGED_SIZE);
}

void CUIMessagesWindow::AddChatMessage(shared_str, shared_str) {}

void CUIMessagesWindow::Show(bool show) {
    if (m_pGameLog)
        m_pGameLog->Show(show);
}
