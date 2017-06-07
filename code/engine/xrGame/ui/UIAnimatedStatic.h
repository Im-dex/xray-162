
#ifndef UI_ANIMATED_STATIC_H_
#define UI_ANIMATED_STATIC_H_

#pragma once

#include "UIStatic.h"

class CUIAnimatedStatic: public CUIStatic
{
	typedef CUIStatic inherited;
	// ����������� ������ ��������
	u32		m_uFrameCount;
	// ������� �����
	u32		m_uCurFrame;
	// ������� �������� � ��������� � ������
	u32		m_uAnimRows, m_uAnimCols;
	// ������� ����� �� �������
	float	m_uFrameWidth, m_uFrameHeight;
	// ����� ������ ���� �������� � ms.
	u32		m_uAnimationDuration;
	// ����� ��������� � ������ ��������
	u32		m_uTimeElapsed;
	// ����-������� ������������� ��������� ��������� ���������� ��������
	bool	m_bParamsChanged;
	// ������� ������������ ��������
	bool	m_bPlaying;

	Fvector2 m_pos;

	u32		m_prevTime;

	// ������������� ������� �����
	// Params:	frameNum	- ����� �����: [0..m_uFrameCount)
	void SetFrame(const u32 frameNum);
public:
	CUIAnimatedStatic();
	
	// ������������� ���������
	void SetOffset(float x, float y)					{m_pos.set(x,y);};
	void SetFramesCount(u32 frameCnt)					{ m_uFrameCount = frameCnt; m_bParamsChanged = true; }
	void SetAnimCols(u32 animCols)						{ m_uAnimCols = animCols; m_bParamsChanged = true; }
	void SetAnimationDuration(u32 animDur)				{ m_uAnimationDuration = animDur; m_bParamsChanged = true; }
	void SetFrameDimentions(float frameW, float frameH)	{ m_uFrameHeight = frameH; m_uFrameWidth = frameW; m_bParamsChanged = true; }
	// ����������
	void Play()											{ m_bPlaying = true; m_prevTime = Device.dwTimeContinual;}
	void Stop()											{ m_bPlaying = false; }
	void Rewind(u32 delta = 0)							{ m_uCurFrame = 0xffffffff; m_uTimeElapsed = delta; }
	void SetAnimPos(float pos);
	// ����-������� ������������ ������������
	bool m_bCyclic;

	virtual void Update();
};

class CUISleepStatic: public CUIStatic
{
private:
	typedef			CUIStatic inherited;

	int				m_cur_time;
	CUIStaticItem	m_UIStaticItem2;
public:
					CUISleepStatic();
	virtual	void	Draw				();
	virtual	void	Update				();
	virtual void	InitTextureEx		(LPCSTR tex_name, LPCSTR sh_name="hud\\default");
};
#endif	//UI_ANIMATED_STATIC_H_