#pragma once

#include <imdexlib/flat_map.hpp>
#include <imdexlib/flag_set.hpp>

namespace xr {

class XRCORE_API IniRecord final {
public:
    IniRecord(std::string key, std::string value, std::string comment)
        : key_(std::move(key)),
          value_(std::move(value)),
          comment_(std::move(comment))
    {}

    IniRecord(std::string key, std::string value)
        : IniRecord(std::move(key), std::move(value), std::string())
    {}

    std::string_view key() const noexcept {
        return key_;
    }

    std::string_view value() const noexcept {
        return value_;
    }

    std::string_view comment() const noexcept {
        return comment_;
    }

    bool hasComment() const noexcept {
        return !comment_.empty();
    }

private:
    std::string key_;
    std::string value_;
    std::string comment_;
};

class XRCORE_API IniSection final {
public:
    IniSection(std::string name)
        : name_(std::move(name))
    {}

    std::string_view name() const noexcept {
        return name_;
    }

    bool contains(const std::string_view key) const {
        return records.contains(key);
    }

    void begin() const {
        records.begin()
    }
private:
    std::string name_;
    imdex::FlatMap<std::string_view, IniRecord> records;
};

class XRCORE_API IniFile final {
public:

private:
    
};

} // xr namespace
