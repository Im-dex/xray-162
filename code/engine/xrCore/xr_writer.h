#pragma once

#include <memory>

template <typename Char, size_t StaticSize, typename Allocator = std::allocator<Char>>
class BasicXrWriter : public fmt::BasicWriter<Char> {
    using Base = fmt::BasicWriter<Char>;
public:
    explicit BasicXrWriter(const Allocator& alloc = Allocator())
        : fmt::BasicWriter<Char>(buffer),
          buffer(alloc)
    {}

    std::string_view strView() const {
        return std::string_view(Base::data(), Base::size());
    }

private:
    fmt::internal::MemoryBuffer<Char, StaticSize, std::allocator<Char>> buffer;
};

// TODO: [imdex] add type
template <size_t StaticSize>
using XrWriter = BasicXrWriter<char, StaticSize>;

// TODO: [imdex] add type
template <typename BaseArray>
using XrWriterAs = XrWriter<std::extent_v<BaseArray>>;
