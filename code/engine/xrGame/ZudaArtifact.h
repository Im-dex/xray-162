///////////////////////////////////////////////////////////////
// ZudaArtifact.h
// ZudaArtefact - �������� ����
///////////////////////////////////////////////////////////////

#pragma once
#include "artefact.h"

class CZudaArtefact : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CZudaArtefact(void);
	virtual ~CZudaArtefact(void);

	virtual void Load				(LPCSTR section);

protected:
};