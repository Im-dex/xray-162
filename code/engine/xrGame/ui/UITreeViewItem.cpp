//=============================================================================
//  Filename:   UITreeViewItem.cpp
//	Created by Roman E. Marchenko, vortex@gsc-game.kiev.ua
//	Copyright 2004. GSC Game World
//	---------------------------------------------------------------------------
//  TreeView Item class
//=============================================================================

#include "stdafx.h"
#include "UITreeViewItem.h"
//#include "UIListWnd.h"
#include "../string_table.h"


#define UNREAD_COLOR	0xff00ff00
#define READ_COLOR		0xffffffff

//////////////////////////////////////////////////////////////////////////

// �������� ������������ ��������
const int				subShift					= 1;
const char * const		treeItemBackgroundTexture	= "ui\\ui_pda_over_list";
// ���� �������������� ��������
static const u32		unreadColor					= 0xff00ff00;

//////////////////////////////////////////////////////////////////////////

CUITreeViewItem::CUITreeViewItem()
	:	isRoot				(false),
		isOpened			(false),
		iTextShift			(0),
		pOwner				(NULL),
		m_uUnreadedColor	(UNREAD_COLOR),
		m_uReadedColor		(READ_COLOR)
{
	AttachChild(&UIBkg);
	UIBkg.InitTexture(treeItemBackgroundTexture);
	UIBkg.TextureOff();
	UIBkg.SetTextureOffset(-20, 0);
	UIBkg.EnableTextHighlighting(false);

	m_bManualSetColor = false;
}

//////////////////////////////////////////////////////////////////////////

CUITreeViewItem::~CUITreeViewItem()
{
	DeleteAllSubItems();
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::OnRootChanged()
{
	xr_string str;
	if (isRoot)
	{
		// ��������� ����� ���������� ������� ����� ������� ���� + ��� -
		str = GetText(GetSelectedIDX());

		xr_string::size_type pos = str.find_first_not_of(" ");
		if (xr_string::npos == pos) pos = 0;

		if (pos == 0)
		{
			++iTextShift;
			str.insert(0, " ");
		}
		else
			--pos;

		if (isOpened)
			// Add minus sign
			str.replace(pos, 1, "-");
		else
			// Add plus sign
			str.replace(pos, 1, "+");

//		inherited::SetText(str.c_str());
		GetSelectedItem()->m_text.SetText(str.c_str());
	}
	else
	{
		str = GetText(GetSelectedIDX());
		// Remove "+/-" sign
		xr_string::size_type pos = str.find_first_of("+-");

		if (pos == 0)
		{
			for (int i = 0; i < iTextShift; ++i)
				str.insert(pos, " ");
		}
		else
			str.replace(pos, 1, " ");

//		inherited::SetText(str.c_str());
		GetSelectedItem()->m_text.SetText(str.c_str());
	}
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::OnOpenClose()
{
	// ���� �� �� �������� ����� ������, ������ ������ �� ������
	if (!isRoot) return;

	xr_string str;

	str = GetText(GetSelectedIDX());
	xr_string::size_type pos = str.find_first_of("+-");

	if (xr_string::npos != pos)
	{
		if (isOpened)
			// Change minus sign to plus
			str.replace(pos, 1, "-");
		else
			// Change plus sign to minus
			str.replace(pos, 1, "+");
	}

//	inherited::SetText(str.c_str());
	GetSelectedItem()->m_text.SetText(str.c_str());
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::Open()
{
	// ���� �� ��� ��� ��� �������, �� ������ �� ������
	if (!isRoot || isOpened) return;
	isOpened = true;

	// �������� ���������
	OnOpenClose();
	
	// ������� ��� ����������� � ������������ ���������
//	CUIListWnd *pList = smart_cast<CUIListWnd*>(GetParent());
	CUIListBox *pList = smart_cast<CUIListBox*>(GetParent());
	
	R_ASSERT(pList);
	if (!pList) return;

//	int pos = pList->GetItemPos(this);

	for (SubItems_it it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
//		pList->AddItem(*it, ++pos);
		pList->AddWindow(*it, true);
	}
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::Close()
{
	// ���� �� ��� ��� ��� �������, �� ������ �� ������
	if (!isRoot || !isOpened) return;
	isOpened = false;

	// �������� ���������
	OnOpenClose();

	// ������� ��� �����������
//	CUIListWnd *pList = smart_cast<CUIListWnd*>(GetParent());
	CUIListBox *pList = smart_cast<CUIListBox*>(GetParent());

	R_ASSERT(pList);
	if (!pList) return;

//	int pos;

	// ������� ��� �������
	for (SubItems_it it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
		(*it)->Close();
	}

	// ����� ��� �������
	for (SubItems_it it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
//		pos = pList->GetItemPos(*it);
//		pList->RemoveItem(pos);
		pList->RemoveWindow(*it);
	}
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::AddItem(CUITreeViewItem *pItem)
{
	R_ASSERT(pItem);
	if (!pItem) return;

	pItem->SetTextShift(subShift + iTextShift);

	vSubItems.push_back(pItem);
	pItem->SetAutoDelete(false);

	pItem->SetOwner(this);
//	pItem->SetText(pItem->GetText());
	pItem->SetText(pItem->GetSelectedText());
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::DeleteAllSubItems()
{
	for (SubItems_it it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
		CUIWindow *pWindow = (*it)->GetParent();

		if (pWindow)
			pWindow->DetachChild(*it);

		xr_delete(*it);
	}

	vSubItems.clear();
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::SetRoot(bool set)
{
	if (isRoot) return;

	isRoot = set;
	OnRootChanged();
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::SetText(LPCSTR str)
{
	xr_string s = str;
	xr_string::size_type pos = s.find_first_not_of(" +-");

	if (pos < static_cast<xr_string::size_type>(iTextShift))
	{
		for (u32 i = 0; i < iTextShift - pos; ++i)
			s.insert(0, " ");
	}
	else if (pos > static_cast<xr_string::size_type>(iTextShift))
	{
		s.erase(0, pos - iTextShift);
	}

//	inherited::SetText(s.c_str());
	GetSelectedItem()->m_text.SetText(s.c_str());
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::SendMessage(CUIWindow* pWnd, s16 msg, void* pData)
{
	static CUITreeViewItem *pPrevFocusedItem = NULL;

	if (pWnd == this && BUTTON_CLICKED == msg)
	{
		if (IsRoot())
		{
			IsOpened() ? Close() : Open();
		}
		else
		{
			MarkArticleAsRead(true);
		}
	}
	else if (pWnd == this && STATIC_FOCUS_RECEIVED == msg)
	{
		UIBkg.TextureOn();

		if (pPrevFocusedItem)
		{
			pPrevFocusedItem->UIBkg.TextureOff();
		}
		pPrevFocusedItem = this;
	}
	else if (pWnd == this && STATIC_FOCUS_LOST == msg)
	{
		UIBkg.TextureOff();
		pPrevFocusedItem = NULL;
	}
	else
		inherited::SendMessage(pWnd, msg, pData);
}

//////////////////////////////////////////////////////////////////////////

CUITreeViewItem * CUITreeViewItem::Find(LPCSTR text) const
{
	// ����������� �� ������ ����������� ���������, � ���� ������� � �������� �������
	// ���� ����� ����. ��-��� ���� root'�, �� ���� ���������� � ���
	CUITreeViewItem *pResult = NULL;
	xr_string caption;

	for (SubItems::const_iterator it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
//		caption = (*it)->GetText();
		caption = (*it)->GetSelectedText();
		xr_string::size_type pos = caption.find_first_not_of(" +-");
		if (pos != xr_string::npos)
		{
			caption.erase(0, pos);
		}

		if (xr_strcmp(caption.c_str(), text) == 0)
			pResult = *it;

		if ((*it)->IsRoot() && !pResult)
			pResult = (*it)->Find(text);

		if (pResult) break;
	}

	return pResult;
}

//////////////////////////////////////////////////////////////////////////

CUITreeViewItem * CUITreeViewItem::Find(int value) const
{
	CUITreeViewItem *pResult = NULL;

	for (SubItems::const_iterator it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
//		if ((*it)->GetValue() == value) pResult = *it;
		if ((*it)->GetSelectedItem()->GetTAG() == (u32)value) pResult = *it;

		if ((*it)->IsRoot() && !pResult)
			pResult = (*it)->Find(value);

		if (pResult) break;
	}

	return pResult;
}

//////////////////////////////////////////////////////////////////////////

CUITreeViewItem * CUITreeViewItem::Find(CUITreeViewItem * pItem) const
{
	CUITreeViewItem *pResult = NULL;

	for (SubItems::const_iterator it = vSubItems.begin(); it != vSubItems.end(); ++it)
	{
		if ((*it)->IsRoot() && !pResult)
			pResult = (*it)->Find(pItem);
		else
			if (pItem == *it) pResult = *it;

		if (pResult) break;
	}

	return pResult;
}

//////////////////////////////////////////////////////////////////////////

xr_string CUITreeViewItem::GetHierarchyAsText()
{
	xr_string name;

	if (GetOwner())
	{
		name = GetOwner()->GetHierarchyAsText();
	}

	xr_string::size_type prevPos = name.size() + 1;
//	name += static_cast<xr_string>("/") + static_cast<xr_string>(GetText());
	name += static_cast<xr_string>("/") + static_cast<xr_string>(GetSelectedText());

	// ������� �����: [ +-]
	xr_string::size_type pos = name.find_first_not_of("/ +-", prevPos);
	if (xr_string::npos != pos)
	{
		name.erase(prevPos, pos - prevPos);
	}

	return name;
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::MarkArticleAsRead(bool value)
{
	// ���� ������� �������, �� �� ��� ������� ���, � ��� �����
	if (IsRoot())
	{
		m_bArticleRead = value;
		if(!m_bManualSetColor)
			SetItemColor();

		for (SubItems_it it = vSubItems.begin(); it != vSubItems.end(); ++it)
		{
			(*it)->m_bArticleRead = value;
			(*it)->SetItemColor();
			if ((*it)->IsRoot())
				(*it)->MarkArticleAsRead(value);
		}
	}
	else
	{
		// ���� �� ���, �� ������� ���� � ������� ��������� ���� ���������� �������
		m_bArticleRead	= value;
		if(!m_bManualSetColor)
			SetItemColor();
		CheckParentMark(GetOwner());
	}
}

//////////////////////////////////////////////////////////////////////////

void CUITreeViewItem::CheckParentMark(CUITreeViewItem *pOwner)
{
	// ����� ����, ������� �� ��� ������, � ���� ����� ��� ���� ���� 1
	// �������������, �� ������� ���� ��� �������������, �  ������� ����������� ����.
	bool f = false;
	if (pOwner && pOwner->IsRoot())
	{
		for (SubItems_it it = pOwner->vSubItems.begin(); it != pOwner->vSubItems.end(); ++it)
		{
			if (!(*it)->IsArticleReaded())
			{
				pOwner->m_bArticleRead = false;
				pOwner->SetItemColor();
				f = true;
			}
		}

		if (!f)
		{
			// ���� �� ���, �� ��� ������� ����������, � ����� �������� ���� ��� ����������� �����
			pOwner->m_bArticleRead = true;
			pOwner->SetItemColor();
		}

		pOwner->CheckParentMark(pOwner->GetOwner());
	}
}

//////////////////////////////////////////////////////////////////////////
// Standalone function for tree hierarchy creation
//////////////////////////////////////////////////////////////////////////

void CreateTreeBranch(shared_str nesting, shared_str leafName, CUIListBox *pListToAdd, int leafProperty,
					  CGameFont *pRootFont, u32 rootColor, CGameFont *pLeafFont, u32 leafColor, bool markRead)
{
	// Nested function emulation
	class AddTreeTail_
	{
	private:
		CGameFont	*pRootFnt;
		u32			rootItemColor;
	public:
		AddTreeTail_(CGameFont *f, u32 cl)
			:	pRootFnt		(f),
				rootItemColor	(cl)
		{}

		CUITreeViewItem * operator () (GroupTree_it it, GroupTree &cont, CUITreeViewItem *pItemToIns)
		{
			// ��������� �������� �������� � ������������
			CUITreeViewItem *pNewItem = NULL;

			for (GroupTree_it it2 = it; it2 != cont.end(); ++it2)
			{
				pNewItem = xr_new<CUITreeViewItem>();
				pItemToIns->AddItem(pNewItem);
				pNewItem->SetFont(pRootFnt);
				pNewItem->SetText(*(*it2));
				pNewItem->SetReadedColor(rootItemColor);
				pNewItem->SetRoot(true);
				pItemToIns = pNewItem;
			}

			return pNewItem;
		}
	} AddTreeTail(pRootFont, rootColor);

	//-----------------------------------------------------------------------------
	//  Function body
	//-----------------------------------------------------------------------------

	// �������� �������� ����������� ������ ���� � �������� ������������
	R_ASSERT(*nesting);
	R_ASSERT(pListToAdd);
	R_ASSERT(pLeafFont);
	R_ASSERT(pRootFont);
	xr_string group = *nesting;

	// ������ ������ ������ ��� ����������� �����������
	GroupTree					groupTree;

	xr_string::size_type		pos;
	xr_string					oneLevel;

	while (true)
	{
		pos = group.find('/');
		if (pos != xr_string::npos)
		{
			oneLevel.assign(group, 0, pos);
			shared_str str(oneLevel.c_str());
			groupTree.push_back(CStringTable().translate(str));
			group.erase(0, pos + 1);
		}
		else
		{
			groupTree.push_back(CStringTable().translate(group.c_str()));
			break;
		}
	}

	// ������ ���� ��� �� ������������� ����� ��� � �������
	CUITreeViewItem *pTVItem = NULL, *pTVItemChilds = NULL;
	bool status = false;

	// ��� ���� ������� ���������
//	for (int i = 0; i < pListToAdd->GetItemsCount(); ++i)
	for (u32 i = 0; i < pListToAdd->GetSize(); ++i)
	{
		pTVItem = smart_cast<CUITreeViewItem*>(pListToAdd->GetItem(i));
		R_ASSERT(pTVItem);

		pTVItem->Close();

//		xr_string	caption = pTVItem->GetText();
		xr_string	caption = pTVItem->GetText(i);
		// Remove "+" sign
		caption.erase(0, 1);

		// ���� �� �������� �� �� ������ �������� � ��������� ����� �������� ���� �� �������
		if (0 == xr_strcmp(caption.c_str(), *groupTree.front()))
		{
			// ��� ��������. ���� ������ ������
			pTVItemChilds = pTVItem;
			for (GroupTree_it it = groupTree.begin() + 1; it != groupTree.end(); ++it)
			{
				pTVItem = pTVItemChilds->Find(*(*it));
				// �� �����, ���� ��������� ����� ������ �����������
				if (!pTVItem)
				{
					pTVItemChilds = AddTreeTail(it, groupTree, pTVItemChilds);
					status = true;
					break;
				}
				pTVItemChilds = pTVItem;
			}
		}

		if (status) break;
	}

	// ������ ��� ������������ ������, � �� �����? ����� ��������� ����� ��������
	if (!pTVItemChilds)
	{
		pTVItemChilds = xr_new<CUITreeViewItem>();
		pTVItemChilds->SetFont(pRootFont);
		pTVItemChilds->SetText(*groupTree.front());
		pTVItemChilds->SetReadedColor(rootColor);
		pTVItemChilds->SetRoot(true);
//		pListToAdd->AddItem<CUITreeViewItem>(pTVItemChilds);
		pListToAdd->AddWindow(pTVItemChilds, true);

		// ���� � ������ ����������� 1 �������, �� ������ ���, � �������������� ������ �� ���������
		if (groupTree.size() > 1)
			pTVItemChilds = AddTreeTail(groupTree.begin() + 1, groupTree, pTVItemChilds);
	}

	// � ����� ������� pTVItemChilds ����������� ������ ���� �� NULL
	R_ASSERT(pTVItemChilds);

	// C������ ��������� ��� �� ������ � ����� ���������, � ��������� ���� ���
	//	if (!pTVItemChilds->Find(*name))
	//	{
	pTVItem		= xr_new<CUITreeViewItem>();
	pTVItem->SetFont(pLeafFont);
	pTVItem->SetReadedColor(leafColor);
	pTVItem->SetText(*CStringTable().translate(*leafName));
//	pTVItem->SetValue(leafProperty);
	pTVItem->SetSelectedTAG(leafProperty);
	pTVItemChilds->AddItem(pTVItem);
	pTVItem->MarkArticleAsRead(markRead);
	//	}
}