#pragma once

#include <vector>
#include <map>
#include "oaProxy.h"
#include "oaProxyCmdBase.h"

using namespace std;

class ProxyWrapper : public oaProxy
{
public:
  ProxyWrapper(const char* client);
  ProxyWrapper(int port,const char* trace_file,const char* client);
  ~ProxyWrapper();

  virtual void Init(const char* client);

  virtual void RunApp(void);
  virtual void GetAllOptions(void);
  virtual void GetCurrentOptions(void);
  virtual void SetOptions(void);
  virtual void GetBenchmarks(void);
  virtual void RunBenchmark(const oaChar *benchmark_name);

protected:
  vector<std::string> pClient;
};

class IssueOACmd : public oaProxyCmdBase
{
public:
  IssueOACmd(oaCommandType Command,const oaChar* bench = NULL); 

  virtual void Run(void);
  virtual oaNamedOption *GetNextOption(void);

protected:
  oaCommandType CMD;
  const oaChar* Benchmark;
  
};

IssueOACmd::IssueOACmd(oaCommandType Command,const oaChar* bench)
{
  CMD = Command;
  Benchmark = bench;
}

void IssueOACmd::Run(void)
{
  oaCommand Command;
  oaInitCommand(&Command);
  Command.Type = CMD;
  Command.BenchmarkName = Benchmark;

  Proxy()->IssueCommand(&Command);

  if (Proxy()->oaCmdReset[CMD])
    Proxy()->IssueExitAndRestart();
}

oaNamedOption *IssueOACmd::GetNextOption(void)
{
  return oaGetNextOption();
}