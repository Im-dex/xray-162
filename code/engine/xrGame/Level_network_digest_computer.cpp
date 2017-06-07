#include "stdafx.h"
#include "Level.h"

char const * ComputeClientDigest(string128& dest)
{
    dest[0] = 0;
    return dest;
};

void CLevel::SendClientDigestToServer()
{
	string128 tmp_digest;
	NET_Packet P;
	P.w_begin			(M_SV_DIGEST);
	m_client_digest	=	ComputeClientDigest(tmp_digest);
	P.w_stringZ			(m_client_digest);
	SecureSend			(P, net_flags(TRUE, TRUE, TRUE, TRUE));
}