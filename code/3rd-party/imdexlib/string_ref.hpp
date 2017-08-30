#pragma once

#include <string>
#include <filesystem>

namespace imdex {
namespace detail {

class string_ref_iterator final {
public:
    using difference_type = ptrdiff_t;
    using value_type = const char;
    using pointer = const char*;
    using reference = const char&;
    using iterator_category = std::bidirectional_iterator_tag;

    string_ref_iterator() = default;
    string_ref_iterator(const char* ptr) : ptr(ptr) {}

    reference operator*() const noexcept {
        return *ptr;
    }

    reference operator->() const noexcept {
        return *ptr;
    }

    string_ref_iterator& operator++() noexcept {
        ++ptr;
        return *this;
    }

    string_ref_iterator operator++(int) noexcept {
        ++ptr;
        return ptr - 1;
    }

    string_ref_iterator& operator--() noexcept {
        --ptr;
        return *this;
    }

    string_ref_iterator operator--(int) noexcept {
        --ptr;
        return ptr + 1;
    }

    bool operator==(const string_ref_iterator that) const noexcept {
        return (ptr == that.ptr) || (*ptr == *that.ptr == '\0');
    }

    bool operator!= (const string_ref_iterator that) const noexcept {
        return !(*this == that);
    }

private:
    const char* ptr = "";
};

} // detail namespace

class string_ref final {
public:
    using iterator = detail::string_ref_iterator;

    string_ref()
        : str("")
    {}

    string_ref(const char* str)
        : str(str ? str : "")
    {}

    template <typename Alloc>
    string_ref(const std::basic_string<char, std::char_traits<char>, Alloc>& str)
        : str(str.c_str())
    {}

    template <typename Alloc>
    string_ref(std::basic_string<char, std::char_traits<char>, Alloc>&&) = delete;

    bool empty() const {
        return str[0] == 0;
    }

    bool nonEmpty() const {
        return !empty();
    }

    iterator begin() const {
        return str;
    }

    iterator end() const {
        return iterator();
    }

    operator const char*() const noexcept {
        return str;
    }

    operator std::string() const {
        return str;
    }

private:
    const char* str;
};

} // namespace imdex
