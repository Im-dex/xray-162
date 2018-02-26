#pragma once

#include <xr_error.h>

namespace xr::ini {

struct XRCORE_API SyntaxError {
    std::string msg;

    void print(fmt::BasicWriter<char>& writer) const {
        writer.write("Syntax error\n{}", msg);
    }
};

class XRCORE_API Error {
public:
    using Cause = xr::Error<SyntaxError, FileNotFoundError>;

    explicit Error(stdfs::path file, Cause cause)
        : file(std::move(file)),
          cause(std::move(cause))
    {}

    void print(fmt::BasicWriter<char>& writer) const {
        if (!file.empty())
            writer.write("Error at file '{}': ", file);
        printError(cause, writer);
    }

private:
    stdfs::path file;
    Cause cause;
};

} // xr::ini namespace
