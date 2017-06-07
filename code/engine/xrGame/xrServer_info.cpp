#include "stdafx.h"
#include "level.h"
#include "xrserver.h"

#define SERVER_LOGO_FN	"server_logo.jpg"
#define SERVER_RULES_FN "server_rules.txt"

void xrServer::SendServerInfoToClient(ClientID const & new_client) //WARNING ! this function is thread unsafe !!!
{
	if (IsGameTypeSingle())
	{
		SendConfigFinished(new_client);
		return;
	}

	if (!m_server_logo || !m_server_rules)
	{
		SendConfigFinished(new_client);
	}
}

void xrServer::LoadServerInfo()
{
	if (!FS.exist("$app_data_root$", SERVER_LOGO_FN) ||
		!FS.exist("$app_data_root$", SERVER_RULES_FN))
	{
		return;
	}
	m_server_logo = FS.r_open("$app_data_root$", SERVER_LOGO_FN);
	if (!m_server_logo)
	{
		Msg("! ERROR: failed to open server logo file %s", SERVER_LOGO_FN);
		return;
	}
	m_server_rules = FS.r_open("$app_data_root$", SERVER_RULES_FN);
	if (!m_server_rules)
	{
		Msg("! ERROR: failed to open server rules file %s", SERVER_RULES_FN);
		FS.r_close(m_server_logo);
		m_server_logo = NULL;
		return;
	}
}
