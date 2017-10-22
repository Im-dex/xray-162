#include "stdafx.h"

#include "xrdebug.h"
#include "os_clipboard.h"

#include <sal.h>

#pragma warning(push)
#pragma warning(disable : 4995)
#include <malloc.h>
#include <direct.h>
#pragma warning(pop)

extern bool shared_str_initialized;

#define DEBUG_INVOKE __debugbreak()
static BOOL bException = FALSE;

#include <dbghelp.h> // MiniDump flags

#include <new.h>    // for _set_new_mode
#include <signal.h> // for signals

#ifdef DEBUG
#define USE_OWN_ERROR_MESSAGE_WINDOW
#else // DEBUG
#define USE_OWN_MINI_DUMP
#endif // DEBUG

XRCORE_API xrDebug Debug;

static bool error_after_dialog = false;

#include "stacktrace_collector.h"

static thread_local StackTraceInfo stackTrace;

void LogStackTrace(const char* header) {
    if (!shared_str_initialized)
        return;

    BuildStackTrace(stackTrace);

    Msg("%s", header);

    for (size_t i = 1; i < stackTrace.count; ++i)
        Msg("%s", stackTrace[i]);
}

void xrDebug::gather_info(const std::string_view expression, const std::string_view description,
                          const std::string_view file, const int line, const std::string_view function,
                          char* assertion_info, const size_t assertion_info_size,
                          std::initializer_list<const std::string_view> args) {
    auto endline = "\n"sv;
    auto prefix = "[error]"sv;

    fmt::ArrayWriter writer{ assertion_info, assertion_info_size };
    const bool extended_description = !description.empty() && (args.size() == 0) &&
                                      (description.find('\n') != std::string_view::npos);
    for (size_t i = 0; i < 2; ++i) {
        if (!i)
            writer.write("{0}FATAL ERROR{0}{0}", endline);
        writer.write("{0}Expression    : {1}{2}", prefix, expression, endline);
        writer.write("{0}Function      : {1}{2}", prefix, function, endline);
        writer.write("{0}File          : {1}{2}", prefix, file, endline);
        writer.write("{0}Line          : {1}{2}", prefix, line, endline);

        if (extended_description) {
            writer.write("{0}{1}{0}", endline, description);
        } else {
            writer.write("{0}Description   : {1}{2}", prefix, description, endline);
            size_t index = 0;
            for (const auto arg : args) {
                writer.write("{0}Argument {1}    : {2}{3}", prefix, index++, arg, endline);
            }
        }

        writer.write("{0}", endline);
        if (!i) {
            if (shared_str_initialized) {
                LogMsg("{}", std::string_view(assertion_info, assertion_info_size));
                FlushLog();
            }
            writer.clear();
            endline = "\r\n"sv;
            prefix = ""sv;
        }
    }

#ifdef USE_MEMORY_MONITOR
    memory_monitor::flush_each_time(true);
    memory_monitor::flush_each_time(false);
#endif // USE_MEMORY_MONITOR

    if (!IsDebuggerPresent() && !strstr(GetCommandLine(), "-no_call_stack_assert")) {
        if (shared_str_initialized)
            Log("stack trace:\n");

#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
        buffer += xr_sprintf(buffer, assertion_info_size - size_t(buffer - buffer_base), "stack trace:%s%s",
                             endline, endline);
#endif // USE_OWN_ERROR_MESSAGE_WINDOW

        BuildStackTrace(stackTrace);

        for (size_t i = 2; i < stackTrace.count; ++i) {
            if (shared_str_initialized)
                LogMsg("{}", stackTrace[i]);

#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
            writer.write("{0}{1}", stackTrace[i], endline);
#endif // USE_OWN_ERROR_MESSAGE_WINDOW
        }

        if (shared_str_initialized)
            FlushLog();

        // TODO: [imdex] use string_view
        os_clipboard::copy_to_clipboard(writer.c_str());
    }
}

[[noreturn]] void xrDebug::do_exit(const std::string& message) {
    FlushLog();
    MessageBox(nullptr, message.c_str(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
    TerminateProcess(GetCurrentProcess(), 1);
}

void xrDebug::backend(const std::string_view expression, const std::string_view description,
                      std::initializer_list<const std::string_view> args,
                      const std::string_view file, const int line, const std::string_view function,
                      bool& ignore_always) {
    static std::mutex CS;
    std::lock_guard<decltype(CS)> lock(CS);

    error_after_dialog = true;

    string4096 assertion_info;

    gather_info(expression, description, file, line, function, assertion_info,
                sizeof(assertion_info), args);

#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
    constexpr auto endline = "\r\n"sv;

    const auto used = std::strlen(assertion_info);
    char* buffer = assertion_info + used;
    fmt::ArrayWriter writer{ buffer, sizeof(assertion_info) - used };

    writer.write("{0}Press CANCEL to abort execution{0}", endline);
    writer.write("Press TRY AGAIN to continue execution{0}", endline);
    writer.write("Press CONTINUE to continue execution and ignore all the errors of this type{0}{0}", endline);
#endif // USE_OWN_ERROR_MESSAGE_WINDOW

    if (handler)
        handler();

    if (get_on_dialog())
        get_on_dialog()(true);

    FlushLog();

#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
    const auto result = MessageBox(
        /*GetTopWindow(NULL)*/ nullptr, assertion_info, "Fatal Error",
        MB_CANCELTRYCONTINUE | MB_ICONERROR | MB_SYSTEMMODAL);

    switch (result) {
    case IDCANCEL: {
        DEBUG_INVOKE;
        break;
    }
    case IDTRYAGAIN: {
        error_after_dialog = false;
        break;
    }
    case IDCONTINUE: {
        error_after_dialog = false;
        ignore_always = true;
        break;
    }
    default:
        NODEFAULT;
    }
#else  // USE_OWN_ERROR_MESSAGE_WINDOW
    DEBUG_INVOKE;
#endif // USE_OWN_ERROR_MESSAGE_WINDOW

    if (get_on_dialog())
        get_on_dialog()(false);
}

const char* xrDebug::error2string(const DWORD code) const {
    const char* result = nullptr;
    static string1024 desc_storage;

    if (nullptr == result) {
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, code, 0, desc_storage,
                      sizeof(desc_storage) - 1, nullptr);
        result = desc_storage;
    }
    return result;
}

void xrDebug::error(const DWORD code, const std::string_view expr, std::initializer_list<const std::string_view> args,
                    const std::string_view file, const int line, const std::string_view function, bool& ignore_always) {
    backend(error2string(code), expr, args, file, line, function, ignore_always);
}

void xrDebug::fail(const std::string_view expr, const std::string_view file, const int line,
                   const std::string_view function, bool& ignore_always) {
    backend("assertion failed"sv, expr, {}, file, line, function, ignore_always);
}

void xrDebug::fail(const std::string_view reason, const std::string_view expr, const std::string_view file,
                   const int line, const std::string_view function, bool& ignore_always) {
    backend(reason, expr, {}, file, line, function, ignore_always);
}

void xrDebug::fail(const std::string_view reason, const std::string_view expr,
                   std::initializer_list<const std::string_view> args, const std::string_view file,
                   const int line, const std::string_view function, bool& ignore_always) {
    backend(reason, expr, args, file, line, function, ignore_always);
}

typedef void (*full_memory_stats_callback_type)();
XRCORE_API full_memory_stats_callback_type g_full_memory_stats_callback = 0;

int out_of_memory_handler(size_t size) {
    if (g_full_memory_stats_callback)
        g_full_memory_stats_callback();
    else {
        Memory.mem_compact();
        u32 process_heap = mem_usage_impl(nullptr, nullptr);
        int eco_strings = (int)g_pStringContainer->stat_economy();
        int eco_smem = (int)g_pSharedMemoryContainer->stat_economy();
        LogMsg("* [x-ray]: process heap[{} K]", process_heap / 1024);
        LogMsg("* [x-ray]: economy: strings[{0} K], smem[{1} K]", eco_strings / 1024, eco_smem);
    }

    Debug.fatal(DEBUG_INFO, "Out of memory. Memory request: %d K", size / 1024);
    return 1;
}

extern LPCSTR log_name();

XRCORE_API string_path g_bug_report_file;

extern void BuildStackTrace(struct _EXCEPTION_POINTERS* pExceptionInfo);
typedef LONG WINAPI UnhandledExceptionFilterType(struct _EXCEPTION_POINTERS* pExceptionInfo);
typedef LONG(__stdcall* PFNCHFILTFN)(EXCEPTION_POINTERS* pExPtrs);
extern "C" BOOL __stdcall SetCrashHandlerFilter(PFNCHFILTFN pFn);

static UnhandledExceptionFilterType* previous_filter = nullptr;

#ifdef USE_OWN_MINI_DUMP
typedef BOOL(WINAPI* MINIDUMPWRITEDUMP)(HANDLE hProcess, DWORD dwPid, HANDLE hFile,
                                        MINIDUMP_TYPE DumpType,
                                        CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
                                        CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
                                        CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam);

void save_mini_dump(_EXCEPTION_POINTERS* pExceptionInfo) {
    // firstly see if dbghelp.dll is around and has the function we need
    // look next to the EXE first, as the one in System32 might be old
    // (e.g. Windows 2000)
    HMODULE hDll = nullptr;
    string_path szDbgHelpPath;

    if (GetModuleFileName(nullptr, szDbgHelpPath, _MAX_PATH)) {
        char* pSlash = strchr(szDbgHelpPath, '\\');
        if (pSlash) {
            xr_strcpy(pSlash + 1, sizeof(szDbgHelpPath) - (pSlash - szDbgHelpPath), "DBGHELP.DLL");
            hDll = ::LoadLibrary(szDbgHelpPath);
        }
    }

    if (!hDll) {
        // load any version we can
        hDll = ::LoadLibrary("DBGHELP.DLL");
    }

    LPCTSTR szResult = NULL;

    if (hDll) {
        MINIDUMPWRITEDUMP pDump = (MINIDUMPWRITEDUMP)::GetProcAddress(hDll, "MiniDumpWriteDump");
        if (pDump) {
            string_path szDumpPath;
            string_path szScratch;
            string64 t_stemp;

            timestamp(t_stemp);
            xr_strcpy(szDumpPath, Core.ApplicationName);
            xr_strcat(szDumpPath, "_");
            xr_strcat(szDumpPath, Core.UserName);
            xr_strcat(szDumpPath, "_");
            xr_strcat(szDumpPath, t_stemp);
            xr_strcat(szDumpPath, ".mdmp");

            __try {
                if (FS.path_exist("$logs$"))
                    FS.update_path(szDumpPath, "$logs$", szDumpPath);
            } __except (EXCEPTION_EXECUTE_HANDLER) {
                string_path temp;
                xr_strcpy(temp, szDumpPath);
                xr_strcpy(szDumpPath, "logs/");
                xr_strcat(szDumpPath, temp);
            }

            // create the file
            HANDLE hFile = ::CreateFile(szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
                                        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            if (INVALID_HANDLE_VALUE == hFile) {
                // try to place into current directory
                MoveMemory(szDumpPath, szDumpPath + 5, strlen(szDumpPath));
                hFile = ::CreateFile(szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
                                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            }
            if (hFile != INVALID_HANDLE_VALUE) {
                _MINIDUMP_EXCEPTION_INFORMATION ExInfo;

                ExInfo.ThreadId = ::GetCurrentThreadId();
                ExInfo.ExceptionPointers = pExceptionInfo;
                ExInfo.ClientPointers = NULL;

                // write the dump
                MINIDUMP_TYPE dump_flags =
                    MINIDUMP_TYPE(MiniDumpNormal | MiniDumpFilterMemory | MiniDumpScanMemory);

                BOOL bOK = pDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, dump_flags,
                                 &ExInfo, nullptr, nullptr);
                if (bOK) {
                    xr_sprintf(szScratch, "Saved dump file to '%s'", szDumpPath);
                    szResult = szScratch;
                    //					retval = EXCEPTION_EXECUTE_HANDLER;
                } else {
                    xr_sprintf(szScratch, "Failed to save dump file to '%s' (error %d)", szDumpPath,
                               GetLastError());
                    szResult = szScratch;
                }
                ::CloseHandle(hFile);
            } else {
                xr_sprintf(szScratch, "Failed to create dump file '%s' (error %d)", szDumpPath,
                           GetLastError());
                szResult = szScratch;
            }
        } else {
            szResult = "DBGHELP.DLL too old";
        }
    } else {
        szResult = "DBGHELP.DLL not found";
    }
}
#endif // USE_OWN_MINI_DUMP

void format_message(LPSTR buffer, const u32& buffer_size) {
    LPVOID message;
    DWORD error_code = GetLastError();

    if (!error_code) {
        *buffer = 0;
        return;
    }

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, error_code,
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message, 0, NULL);

    xr_sprintf(buffer, buffer_size, "[error][%8d]    : %s", error_code, message);
    LocalFree(message);
}

#include <errorrep.h>

LONG WINAPI UnhandledFilter(_EXCEPTION_POINTERS* pExceptionInfo) {
    string256 error_message;
    format_message(error_message, sizeof(error_message));

    if (!error_after_dialog && !strstr(GetCommandLine(), "-no_call_stack_assert")) {
        CONTEXT save = *pExceptionInfo->ContextRecord;
        BuildStackTrace(pExceptionInfo, stackTrace);
        *pExceptionInfo->ContextRecord = save;

        if (shared_str_initialized)
            Log("stack trace:\n");

        if (!IsDebuggerPresent()) {
            os_clipboard::copy_to_clipboard("stack trace:\r\n\r\n");
        }

        string4096 buffer;
        for (int i = 0; i < stackTrace.count; ++i) {
            if (shared_str_initialized)
                LogMsg("{}", stackTrace[i]);
            xr_sprintf(buffer, sizeof(buffer), "%s\r\n", stackTrace[i]);
#ifdef DEBUG
            if (!IsDebuggerPresent())
                os_clipboard::update_clipboard(buffer);
#endif // #ifdef DEBUG
        }

        if (*error_message) {
            if (shared_str_initialized)
                LogMsg("\n{}", error_message);

            xr_strcat(error_message, sizeof(error_message), "\r\n");
#ifdef DEBUG
            if (!IsDebuggerPresent())
                os_clipboard::update_clipboard(buffer);
#endif // #ifdef DEBUG
        }
    }

    if (shared_str_initialized)
        FlushLog();

#ifndef USE_OWN_ERROR_MESSAGE_WINDOW
#ifdef USE_OWN_MINI_DUMP
    save_mini_dump(pExceptionInfo);
#endif // USE_OWN_MINI_DUMP
#else  // USE_OWN_ERROR_MESSAGE_WINDOW
    if (!error_after_dialog) {
        if (Debug.get_on_dialog())
            Debug.get_on_dialog()(true);

        MessageBox(NULL, "Fatal error occured\n\nPress OK to abort program execution",
                   "Fatal error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
    }
#endif // USE_OWN_ERROR_MESSAGE_WINDOW

    ReportFault(pExceptionInfo, 0);

#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
    if (Debug.get_on_dialog())
        Debug.get_on_dialog()(false);
#endif // USE_OWN_ERROR_MESSAGE_WINDOW

    return EXCEPTION_EXECUTE_HANDLER;
}

//////////////////////////////////////////////////////////////////////
typedef int(__cdecl* _PNH)(size_t);

void _terminate() {
    if (strstr(GetCommandLine(), "-silent_error_mode"))
        exit(-1);

    string4096 assertion_info;

    Debug.gather_info("<no expression>", "Unexpected application termination", DEBUG_INFO,
                      assertion_info, {});

    LPCSTR endline = "\r\n";
    LPSTR buffer = assertion_info + xr_strlen(assertion_info);
    buffer += xr_sprintf(buffer, xr_strlen(assertion_info), "Press OK to abort execution%s", endline);

    MessageBox(GetTopWindow(nullptr), assertion_info, "Fatal Error",
               MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);

    exit(-1);
}

static void handler_base(const char* reason_string) {
    bool ignore_always = false;
    Debug.backend("error handler is invoked!", reason_string, {}, DEBUG_INFO, ignore_always);
}

static void invalid_parameter_handler(const wchar_t* expression, const wchar_t* function,
                                      const wchar_t* file, unsigned int line, uintptr_t reserved) {
    bool ignore_always = false;

    string4096 expression_;
    string4096 function_;
    string4096 file_;
    size_t converted_chars = 0;

    if (expression)
        wcstombs_s(&converted_chars, expression_, sizeof(expression_), expression,
                   (wcslen(expression) + 1) * 2 * sizeof(char));
    else
        xr_strcpy(expression_, "");

    if (function)
        wcstombs_s(&converted_chars, function_, sizeof(function_), function,
                   (wcslen(function) + 1) * 2 * sizeof(char));
    else
        xr_strcpy(function_, __FUNCTION__);

    if (file)
        wcstombs_s(&converted_chars, file_, sizeof(file_), file,
                   (wcslen(file) + 1) * 2 * sizeof(char));
    else {
        line = __LINE__;
        xr_strcpy(file_, __FILE__);
    }

    Debug.backend("error handler is invoked!", expression_, {}, file_, line, function_,
                  ignore_always);
}

static void pure_call_handler() { handler_base("pure virtual function call"); }

#ifdef XRAY_USE_EXCEPTIONS
static void unexpected_handler() { handler_base("unexpected program termination"); }
#endif // XRAY_USE_EXCEPTIONS

static void abort_handler(int signal) { handler_base("application is aborting"); }

static void floating_point_handler(int signal) { handler_base("floating point error"); }

static void illegal_instruction_handler(int signal) { handler_base("illegal instruction"); }

//	static void storage_access_handler		(int signal)
//	{
//		handler_base					("illegal storage access");
//	}

static void termination_handler(int signal) { handler_base("termination with exit code 3"); }

void debug_on_thread_spawn() {
    //std::set_terminate				(_terminate);

    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    signal(SIGABRT, abort_handler);
    signal(SIGABRT_COMPAT, abort_handler);
    signal(SIGFPE, floating_point_handler);
    signal(SIGILL, illegal_instruction_handler);
    signal(SIGINT, 0);
    //		signal							(SIGSEGV,
    //storage_access_handler);
    signal(SIGTERM, termination_handler);

    _set_invalid_parameter_handler(&invalid_parameter_handler);

    _set_new_mode(1);
    _set_new_handler(&out_of_memory_handler);
    //		std::set_new_handler			(&std_out_of_memory_handler);

    _set_purecall_handler(&pure_call_handler);
}

void xrDebug::_initialize() {
    *g_bug_report_file = 0;

    debug_on_thread_spawn();

    previous_filter = ::SetUnhandledExceptionFilter(
        UnhandledFilter); // exception handler to all "unhandled" exceptions
}
