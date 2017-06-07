///////////////////////////////////////////////////////////////
// GraviArtifact.h
// GraviArtefact - �������������� ��������, ������� �� �����
// � ����� ��� ������
///////////////////////////////////////////////////////////////

#pragma once
#include "artefact.h"

class CGraviArtefact : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CGraviArtefact(void);
	virtual ~CGraviArtefact(void);

	virtual void Load				(LPCSTR section);

protected:
	virtual void	UpdateCLChild	();
	//��������� ���������
	float m_fJumpHeight;
	float m_fEnergy;
};
