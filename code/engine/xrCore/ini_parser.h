#pragma once

#include <boost/variant.hpp>
#include <imdexlib/try.hpp>
#include "ini_error.h"

namespace xr::ini {
namespace ast {

using Key = std::string;
using Value = std::string;
using FullRecord = std::pair<Key, Value>;
using ValueRecord = std::string;
using Record = boost::variant<FullRecord, ValueRecord>;
using Records = std::vector<Record>;
using Inheritance = std::vector<std::string>;
using Includes = std::vector<std::string>;

struct XRCORE_API SectionHeader {
    std::string name;
    Inheritance inheritance;
};

struct XRCORE_API Section {
    SectionHeader header;
    Records records;
};

using Sections = std::vector<Section>;

struct XRCORE_API File {
    Includes includes;
    Sections sections;
};

} // ast namespace

template <typename Err>
using ParseResult = imdex::Try<ast::File, Err>;

XRCORE_API ParseResult<SyntaxError> parse(const std::string_view source) noexcept;
XRCORE_API ParseResult<SyntaxError> parse(IReader& reader) noexcept;
XRCORE_API ParseResult<Error::Cause> parse(const stdfs::path& path) noexcept;

} // xr::ini namespace
