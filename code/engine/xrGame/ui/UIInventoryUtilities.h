#pragma once

#include "../inventory_item.h"
#include "character_info_defs.h"

#include "ui_defs.h"

class CUITextWnd;

//������� ����� � �������� ���������
#define INV_GRID_WIDTH			50.0f
#define INV_GRID_HEIGHT			50.0f

//������� ����� � �������� ������ ����������
#define ICON_GRID_WIDTH			64.0f
#define ICON_GRID_HEIGHT		64.0f
//������ ������ ��������� ��� ��������� � ��������
#define CHAR_ICON_WIDTH			2
#define CHAR_ICON_HEIGHT		2	

//������ ������ ��������� � ������ ����
#define CHAR_ICON_FULL_WIDTH	2
#define CHAR_ICON_FULL_HEIGHT	5

#define TRADE_ICONS_SCALE		(4.f/5.f)

namespace InventoryUtilities
{

//���������� �������� �� ������������ ����������� ��� � �������
//��� ����������
bool GreaterRoomInRuck	(PIItem item1, PIItem item2);
//��� �������� ���������� �����
bool FreeRoom_inBelt	(TIItemContainer& item_list, PIItem item, int width, int height);


// get shader for BuyWeaponWnd
const ui_shader&	GetBuyMenuShader();
//�������� shader �� ������ ���������
const ui_shader& GetEquipmentIconsShader();
// shader �� ������ ���������� � ������������
const ui_shader&	GetMPCharIconsShader();
//get shader for outfit icons in upgrade menu
const ui_shader& GetOutfitUpgradeIconsShader();
//get shader for weapon icons in upgrade menu
const ui_shader& GetWeaponUpgradeIconsShader();
//������� ��� �������
void DestroyShaders();
void CreateShaders();

// �������� �������� ������� � ��������� ����

// �������� ������������� �������� GetGameDateTimeAsString ��������: �� �����, �� �����, �� ������
enum ETimePrecision
{
	etpTimeToHours = 0,
	etpTimeToMinutes,
	etpTimeToSeconds,
	etpTimeToMilisecs,
	etpTimeToSecondsAndDay
};

// �������� ������������� �������� GetGameDateTimeAsString ��������: �� ����, �� ������, �� ���
enum EDatePrecision
{
	edpDateToDay,
	edpDateToMonth,
	edpDateToYear
};

const shared_str GetGameDateAsString(EDatePrecision datePrec, char dateSeparator = ',');
const shared_str GetGameTimeAsString(ETimePrecision timePrec, char timeSeparator = ':');
const shared_str GetDateAsString(ALife::_TIME_ID time, EDatePrecision datePrec, char dateSeparator = ',');
const shared_str GetTimeAsString(ALife::_TIME_ID time, ETimePrecision timePrec, char timeSeparator = ':', bool full_mode = true);
const shared_str GetTimeAndDateAsString(ALife::_TIME_ID time);
const shared_str Get_GameTimeAndDate_AsString();

LPCSTR GetTimePeriodAsString	(LPSTR _buff, u32 buff_sz, ALife::_TIME_ID _from, ALife::_TIME_ID _to);
// ���������� ���, ������� ����� (*pInvOwner)
void UpdateWeightStr(CUITextWnd &wnd, CUITextWnd &wnd_max, CInventoryOwner *pInvOwner);

// ������� ��������� ������-�������������� ����� � ��������� �� �� ��������� ��������������
LPCSTR	GetRankAsText				(CHARACTER_RANK_VALUE		rankID);
LPCSTR	GetReputationAsText			(CHARACTER_REPUTATION_VALUE rankID);
LPCSTR	GetGoodwillAsText			(CHARACTER_GOODWILL			goodwill);

void	ClearCharacterInfoStrings	();

void	SendInfoToActor				(LPCSTR info_id);
void	SendInfoToLuaScripts		(shared_str info);
u32		GetGoodwillColor			(CHARACTER_GOODWILL gw);
u32		GetRelationColor			(ALife::ERelationType r);
u32		GetReputationColor			(CHARACTER_REPUTATION_VALUE rv);
};