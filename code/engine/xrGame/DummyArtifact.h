///////////////////////////////////////////////////////////////
// DummyArtifact.h
// DummyArtefact - �������� ��������
///////////////////////////////////////////////////////////////

#pragma once
#include "artefact.h"

class CDummyArtefact : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CDummyArtefact(void);
	virtual ~CDummyArtefact(void);

	virtual void Load				(LPCSTR section);

protected:
};