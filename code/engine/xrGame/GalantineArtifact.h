///////////////////////////////////////////////////////////////
// GalantineArtifact.h
// GalantineArtefact - �������� ������� �������
///////////////////////////////////////////////////////////////

#pragma once
#include "artefact.h"

class CGalantineArtefact : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CGalantineArtefact(void);
	virtual ~CGalantineArtefact(void);

	virtual void Load				(LPCSTR section);

protected:
};