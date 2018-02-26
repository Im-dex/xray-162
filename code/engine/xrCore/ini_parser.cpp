#include "stdafx.h"
#include "ini_parser.h"

#include <boost/fusion/adapted/std_pair.hpp>

#include <imdexlib/buffer.hpp>
#include <imdexlib/memory_units.hpp>
#include <imdexlib/scope_guard.hpp>

using namespace imdex::mem_units;

BOOST_FUSION_ADAPT_STRUCT(xr::ini::ast::SectionHeader,
    name,
    inheritance
)

BOOST_FUSION_ADAPT_STRUCT(xr::ini::ast::Section,
    header,
    records
)

BOOST_FUSION_ADAPT_STRUCT(xr::ini::ast::File,
    includes,
    sections
)

namespace x3 = boost::spirit::x3;

namespace xr::ini {

template <typename Iterator>
SyntaxError makeError(const Iterator& where, const Iterator& first, const Iterator& last) {
    const auto findLineBegin = [&] {
        auto iter = where;
        while (iter != first && *iter != '\n')
            --iter;
        return iter;
    };
    
    const auto findLineEnd = [&] {
        auto iter = where;
        while (iter != last && *iter != '\n')
            ++iter;
        return iter;
    };

    XrWriterAs<string4096> writer;
    const auto lineBegin = findLineBegin();
    const auto lineEnd = findLineEnd();
    const auto leftPaddingSize = size_t(std::distance(lineBegin, where));
    const auto lineLength = size_t(std::distance(lineBegin, lineEnd));
    writer.write("Parse error:\n{}\n", std::string_view(&(*lineBegin), lineLength));
    for (size_t i = 0; i < leftPaddingSize; i++)
        writer.write("-");
    writer.write("^");
    for (size_t i = 0; i < lineLength - leftPaddingSize - 1; i++)
        writer.write("-");
    return SyntaxError{ writer.str() };
}

static const x3::rule<struct ident, std::string>
    ident = "identifier";

static const x3::rule<struct quotedString, std::string>
    quotedString = "quoted string";

static const x3::rule<struct include, std::string>
    include = "include";

static const x3::rule<struct basicValue, std::string>
    basicValue = "record key or value";

static const x3::rule<struct inheritance, ast::Inheritance>
    inheritance = "base sections";

static const x3::rule<struct key, ast::Key>
    key = "record key";

static const x3::rule<struct value, ast::Value>
    value = "record value";

static const x3::rule<struct fullRecord, ast::FullRecord>
    fullRecord = "key value record";

static const x3::rule<struct simpleRecord, ast::ValueRecord>
    simpleRecord = "value only record";

static const x3::rule<struct record, ast::Record>
    record = "record";

static const x3::rule<struct sectionHeader, ast::SectionHeader>
    sectionHeader = "section header";

static const x3::rule<struct section, ast::Section>
    section = "section";

static const x3::rule<struct file, ast::File>
    file = "ini file";

static const auto eof = x3::eol | x3::eoi;
static const auto commentStart = x3::omit[x3::char_(';')] | "//";
static const auto comment = x3::lexeme[commentStart >> *(x3::char_ - eof) >> eof];
static const auto skip = x3::space | comment;

static const auto identChar = x3::alpha | x3::char_('_') | x3::char_('$');
static const auto ident_def = x3::lexeme[identChar >> *(identChar | x3::alnum)];
static const auto quotedString_def = x3::lexeme[x3::char_('"') >> *((x3::char_('\\') >> x3::char_) | ~x3::char_('"')) >> x3::char_('"')];
static const auto basicValue_def = x3::lexeme[*(x3::char_ - comment - eof)];

static const auto include_def = "#include" >> quotedString >> x3::omit[*(x3::char_ - eof)] >> eof;

static const auto inheritance_def = ':' >> (ident % ',');
static const auto sectionHeader_def = '[' >> *(x3::char_ - ']' - x3::space) >> ']' >> -inheritance;

static const auto key_def = ident;
static const auto value_def = basicValue | quotedString;
static const auto fullRecord_def = (key >> '=') >> value;
static const auto simpleRecord_def = x3::lexeme[~x3::char_('[') >> basicValue];
static const auto record_def = fullRecord | simpleRecord;
static const auto section_def = sectionHeader >> *record;
static const auto file_def = *include >> *section;

BOOST_SPIRIT_DEFINE(ident, quotedString, basicValue, include, inheritance, key, value,
                    fullRecord, simpleRecord, record, sectionHeader, section, file)

static const auto& grammar = file;

XRCORE_API ParseResult<SyntaxError> parse(const std::string_view source) noexcept {
    ast::File fileAst;
    auto iter = source.begin();

    const bool res = x3::phrase_parse(iter, source.end(), grammar, skip, fileAst);
    if (res && iter == source.end()) {
        return std::move(fileAst);
    } else {
        std::advance(iter, 1); // move to the first error symbol
        return imdex::to_failure(makeError(iter, source.begin(), source.end()));
    }
}

XRCORE_API ParseResult<SyntaxError> parse(IReader& reader) noexcept {
    imdex::MemoryBuffer<8_KB> buf(reader.length());
    reader.r(buf.data(), reader.length());
    return parse(std::string_view(buf.data(), buf.size()));
}

XRCORE_API ParseResult<Error::Cause> parse(
        const stdfs::path& path) noexcept {
    // TODO: [imdex] FS refactoring
    IReader* reader = FS.r_open(path.string().c_str());
    if (!reader)
        return imdex::make_failure<FileNotFoundError>(path);
    IMDEXLIB_SCOPE_EXIT{ FS.r_close(reader); };
    return parse(*reader);
}

} // xr::ini namespace
