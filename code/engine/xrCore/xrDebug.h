#pragma once

typedef void crashhandler();
typedef void on_dialog(bool before);

class XRCORE_API xrDebug {
    crashhandler* handler = nullptr;
    on_dialog* m_on_dialog = nullptr;

public:
    void _initialize();
    void _destroy();

    crashhandler* get_crashhandler() const { return handler; };
    void set_crashhandler(crashhandler* handler) { this->handler = handler; };

    on_dialog* get_on_dialog() const { return m_on_dialog; }
    void set_on_dialog(on_dialog* on_dialog) { m_on_dialog = on_dialog; }

    const char* error2string(const DWORD code) const;

    void gather_info(const char* expression, const char* description, const char* file,
                     const int line, const char* function, char* assertion_info,
                     const size_t assertion_info_size, std::initializer_list<const char*> args);

    template <size_t count>
    void gather_info(const char* expression, const char* description, const char* file,
                     const int line, const char* function, char (&assertion_info)[count],
                     std::initializer_list<const char*> args) {
        gather_info(expression, description, file, line, function,
                    assertion_info, count, args);
    }

    void fail(const char* expr, const char* file, const int line, const char* function,
              bool& ignore_always);
    void fail(const char* reason, const std::string& expr, const char* file, const int line,
              const char* function, bool& ignore_always);
    void fail(const char* reason, const char* expr, const char* file, const int line,
              const char* function, bool& ignore_always);
    void fail(const char* reason, const char* expr, std::initializer_list<const char*> args,
              const char* file, const int line, const char* function, bool& ignore_always);
    void error(const DWORD code, const char* expr, std::initializer_list<const char*> args,
               const char* file, const int line, const char* function, bool& ignore_always);

    template <typename... Args>
    void fatal(const char* file, const int line, const char* function, const char* format,
               const Args&... args) {
        static constexpr size_t kBufferSize = 1024;
        char buffer[kBufferSize];

        std::snprintf(buffer, kBufferSize, format, args...);
        bool ignore_always = true;

        backend("fatal error", "<no expression>", { buffer }, file, line, function, ignore_always);
    }

    void backend(const char* reason, const char* expression, std::initializer_list<const char*> args,
                 const char* file, const int line, const char* function, bool& ignore_always);
    __declspec(noreturn) static void do_exit(const std::string& message);
};

// warning
// this function can be used for debug purposes only
template <typename... Args>
std::string make_string(const char* format, const Args&... args) {
    static constexpr size_t kBufferSize = 4096;
    char temp[kBufferSize];
    snprintf(temp, kBufferSize, format, args...);
    return std::string(temp);
}

extern XRCORE_API xrDebug Debug;

XRCORE_API void LogStackTrace(const char* header);

#include "xrDebug_macros.h"