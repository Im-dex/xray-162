#pragma once

#include <memory>

template <typename Char, size_t StaticSize, typename Allocator = std::allocator<Char>>
class BasicXrWriter : public fmt::BasicWriter<Char> {
public:
    explicit BasicXrWriter(const Allocator& alloc = Allocator())
        : fmt::BasicWriter<Char>(buffer),
          buffer(alloc)
    {}

    BasicXrWriter(BasicXrWriter&& other)
        : fmt::BasicWriter<Char>(buffer),
          buffer(std::move(other.buffer))
    {}

    BasicXrWriter& operator= (BasicXrWriter&& other) {
        buffer = std::move(other.buffer);
        return *this;
    }

private:
    fmt::internal::MemoryBuffer<Char, StaticSize, Allocator> buffer;
};

template <size_t StaticSize>
using XrWriter = BasicXrWriter<char, StaticSize>;

template <typename BaseArray>
using XrWriterAs = XrWriter<std::extent_v<BaseArray>>;
