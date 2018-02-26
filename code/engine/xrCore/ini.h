#pragma once

#include <imdexlib/flat_map.hpp>
#include <imdexlib/flag_set.hpp>
#include <imdexlib/try.hpp>

#include "ini_error.h"

namespace xr::ini {

class XRCORE_API Record final {
public:
    Record(std::string key, std::string value)
        : key_(std::move(key)),
          value_(std::move(value))
    {}

    std::string_view key() const noexcept {
        return key_;
    }

    std::string_view value() const noexcept {
        return value_;
    }

private:
    std::string key_;
    std::string value_;
};

class XRCORE_API Section final {
public:
    using Records = imdex::FlatMap<std::string_view, Record>;

    Section(std::string name, Records records)
        : name_(std::move(name)),
          records(std::move(records))
    {}

    std::string_view name() const noexcept {
        return name_;
    }

    bool contains(const std::string_view key) const {
        return records.contains(key);
    }

    Records::const_iterator begin() const {
        return records.begin();
    }

    Records::const_iterator end() const {
        return records.end();
    }
private:
    std::string name_;
    Records records;
};

class XRCORE_API File final {
    using Sections = imdex::FlatMap<std::string_view, Section>;
public:
    enum class Flag {
        SaveAtEnd = 1 << 0,
        ReadOnly  = 1 << 1
    };

    using LoadResult = imdex::Try<File, imdex::ErrorChain<Error>>;

    // TODO: flags

    // 0. Load from text with path - private
    static LoadResult load(const std::string_view text, const stdfs::path& path);

    // 1. Load from file path
    static LoadResult load(const stdfs::path& file);

    // 2. Load from IReader + folder path -- fixed flags here
    static LoadResult load(const IReader& reader, const stdfs::path& path = stdfs::path());

    // 3. Create empty with save path
    File(stdfs::path file);

    // TODO: remove
    File(const IReader& reader, stdfs::path parentFolder = stdfs::path());
private:
    imdex::FlagSet<Flag> flags;
    stdfs::path path;
    Sections sections;
};

} // xr::ini namespace
