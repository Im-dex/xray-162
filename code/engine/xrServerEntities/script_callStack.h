#pragma once

class CScriptDebugger;
struct SPath {
    string_path path;
};

class CScriptCallStack {
public:
    CScriptDebugger* m_debugger;
    void GotoStackTraceLevel(int nLevel);
    void Add(const char* szDesc, const char* szFile, int nLine);
    void Clear();
    CScriptCallStack(CScriptDebugger* d);
    ~CScriptCallStack();

    int GetLevel() { return m_nCurrentLevel; };
    void SetStackTraceLevel(int);

protected:
    int m_nCurrentLevel;
    std::vector<u32> m_levels;
    std::vector<u32> m_lines;
    std::vector<SPath> m_files;
};
