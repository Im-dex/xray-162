#pragma once

typedef void crashhandler();
typedef void on_dialog(bool before);

class XRCORE_API xrDebug {
private:
    crashhandler* handler;
    on_dialog* m_on_dialog;

public:
    void _initialize();
    void _destroy();

public:
    crashhandler* get_crashhandler() { return handler; };
    void set_crashhandler(crashhandler* _handler) { handler = _handler; };

    on_dialog* get_on_dialog() { return m_on_dialog; }
    void set_on_dialog(on_dialog* on_dialog) { m_on_dialog = on_dialog; }

    const char* error2string(const DWORD code);

    void gather_info(const char* expression, const char* description, const char* argument0,
                     const char* argument1, const char* file, int line, const char* function,
                     LPSTR assertion_info, unsigned int assertion_info_size);
    template <size_t count>
    inline void gather_info(const char* expression, const char* description, const char* argument0,
                            const char* argument1, const char* file, int line, const char* function,
                            char (&assertion_info)[count]) {
        gather_info(expression, description, argument0, argument1, file, line, function,
                    assertion_info, count);
    }

    void fail(const char* e1, const char* file, int line, const char* function,
              bool& ignore_always);
    void fail(const char* e1, const std::string& e2, const char* file, int line,
              const char* function, bool& ignore_always);
    void fail(const char* e1, const char* e2, const char* file, int line, const char* function,
              bool& ignore_always);
    void fail(const char* e1, const char* e2, const char* e3, const char* file, int line,
              const char* function, bool& ignore_always);
    void fail(const char* e1, const char* e2, const char* e3, const char* e4, const char* file,
              int line, const char* function, bool& ignore_always);
    void error(long code, const char* e1, const char* file, int line, const char* function,
               bool& ignore_always);
    void error(long code, const char* e1, const char* e2, const char* file, int line,
               const char* function, bool& ignore_always);
    void _cdecl fatal(const char* file, int line, const char* function, const char* F, ...);
    void backend(const char* reason, const char* expression, const char* argument0,
                 const char* argument1, const char* file, int line, const char* function,
                 bool& ignore_always);
    void do_exit(const std::string& message);
};

// warning
// this function can be used for debug purposes only
template <typename... Args>
std::string make_string(const char* format, const Args&... args) {
    static constexpr size_t bufferSize = 4096;
    char temp[bufferSize];
    snprintf(temp, bufferSize, format, args...);
    return std::string(temp);
}

extern XRCORE_API xrDebug Debug;

XRCORE_API void LogStackTrace(LPCSTR header);

#include "xrDebug_macros.h"