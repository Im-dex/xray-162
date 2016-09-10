#pragma once

#if WIN32
# include <windows.h>
#endif

#include <iostream>
#include "proxy_setopt_wrapper.h"

static char* EXECUTENAME  = "simple_app.exe";
static char* OAARG        = NULL;
map<oaCommandType,bool> ResetCmd;

static void ParseArgs(int argc,char *argv[]);
static void InitResetCmd(void);

int main(int argc, char* argv[])
{
  InitResetCmd();
  ParseArgs(argc,argv);

  if (OAARG != NULL)
  {
    ProxyWrapper* Proxy = new ProxyWrapper(7979,NULL,EXECUTENAME);
    Proxy->oaCmdReset = ResetCmd;
    Proxy->OAMainLoop(OAARG);

    delete Proxy;
  }
  
	return 0;
}

void InitResetCmd(void)
{
  ResetCmd[OA_CMD_SET_OPTIONS]          = true;
  ResetCmd[OA_CMD_RUN_BENCHMARK]        = false;
  ResetCmd[OA_CMD_GET_CURRENT_OPTIONS]  = false;
  ResetCmd[OA_CMD_GET_BENCHMARKS]       = false;
  ResetCmd[OA_CMD_GET_ALL_OPTIONS]      = false;
  ResetCmd[OA_CMD_RUN]                  = false;
}

void ParseArgs(int argc,char *argv[])
{

  if (argc == 1)
  {
    fprintf(stderr, 
      "Usage: \nproxy_setopt_wrapper [-execute exe_file.exe] [-resetcmd CMD1;CMD2] [-openautomate oa_args]\n");

    return;
  }

  for (int i=1;i<argc;i++)
  {
    if (!strcmp(argv[i],"-openautomate"))
    {
      i++;
      if ((i>=argc) || (argv[i][0] == '-'))
        fprintf(stderr,"Missing arguments in -openautomate option");
      else
        OAARG = argv[i];
    }
    else if (!strcmp(argv[i],"-execute"))
    {
      i++;
      if ((i>=argc) || (argv[i][0] == '-'))
        fprintf(stderr,"Missing arguments in -execute option");
      else
        EXECUTENAME = argv[i];
    }
    else if (!strcmp(argv[i],"-resetcmd"))
    {
      i++;
      if ((i>=argc) || (argv[i][0] == '-'))
        fprintf(stderr,"Missing arguments in -resetcmd option");
      else
      {
        ResetCmd[OA_CMD_SET_OPTIONS] = false;
        char *cmd[10];
        memset(cmd,0,sizeof(cmd));
        int index = 0;
        cmd[index] = strtok(argv[i],";");
        while (cmd[index])
        {
          if (!strcmp(cmd[index],"OA_CMD_GET_ALL_OPTIONS"))
            ResetCmd[OA_CMD_GET_ALL_OPTIONS] = true;
          else if (!strcmp(cmd[index],"OA_CMD_GET_CURRENT_OPTIONS"))
            ResetCmd[OA_CMD_GET_CURRENT_OPTIONS] = true;
          else if (!strcmp(cmd[index],"OA_CMD_SET_OPTIONS"))
            ResetCmd[OA_CMD_SET_OPTIONS] = true;
          else if (!strcmp(cmd[index],"OA_CMD_GET_BENCHMARKS"))
            ResetCmd[OA_CMD_GET_BENCHMARKS] = true;
          else if (!strcmp(cmd[index],"OA_CMD_RUN_BENCHMARK"))
            ResetCmd[OA_CMD_RUN_BENCHMARK] = true;

          cmd[++index] = strtok(NULL,";");
        }
      }
    }
  }
}

//ProxyWrapper class implementations
ProxyWrapper::ProxyWrapper(const char* client)
{
  oaProxy::oaProxy();
  Init(client);
}

ProxyWrapper::ProxyWrapper(int port, const char *trace_file,const char* client)
{
  oaProxy::oaProxy(port,trace_file);
  Init(client);
}

ProxyWrapper::~ProxyWrapper()
{
}

void ProxyWrapper::Init(const char* client)
{
  pClient.clear();
  pClient.push_back(client);
}

void ProxyWrapper::RunApp(void)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_RUN);
  AddCmd(Cmd);
  RunProxySever(pClient);
}

void ProxyWrapper::GetAllOptions(void)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_GET_ALL_OPTIONS);
  AddCmd(Cmd);
  RunProxySever(pClient);
}

void ProxyWrapper::GetCurrentOptions(void)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_GET_CURRENT_OPTIONS);
  AddCmd(Cmd);
  RunProxySever(pClient);
}

void ProxyWrapper::SetOptions(void)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_SET_OPTIONS);
  AddCmd(Cmd);

  RunProxySever(pClient);
}

void ProxyWrapper::GetBenchmarks(void)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_GET_BENCHMARKS);
  AddCmd(Cmd);
  RunProxySever(pClient);
}

void ProxyWrapper::RunBenchmark(const oaChar *benchmark_name)
{
  ClearCmdList();
  IssueOACmd *Cmd = new IssueOACmd(OA_CMD_RUN_BENCHMARK,benchmark_name);
  AddCmd(Cmd);
  RunProxySever(pClient);
}