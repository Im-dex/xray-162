#pragma once

#include <string>
#include <string_view>

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

    string_ref() noexcept
        : str("")
    {}

    string_ref(const char* str) noexcept
        : str(str ? str : "")
    {}

    template <typename Alloc>
    string_ref(const std::basic_string<char, std::char_traits<char>, Alloc>& str) noexcept
        : str(str.c_str())
    {}

    template <typename Alloc>
    string_ref(std::basic_string<char, std::char_traits<char>, Alloc>&&) = delete;

    string_ref(const std::string_view&) = delete;
    string_ref(const string_ref&) = default;

    string_ref& operator= (const string_ref&) = default;
    string_ref& operator= (const std::string_view&) = delete;

    string_ref& operator= (const char* str) noexcept {
        this->str = str;
        return *this;
    }

    template <typename Alloc>
    string_ref& operator= (const std::basic_string<char, std::char_traits<char>, Alloc>& str) noexcept {
        this->str = str.c_str();
        return *this;
    }

    template <typename Alloc>
    string_ref& operator= (std::basic_string<char, std::char_traits<char>, Alloc>&& str) = delete;

    bool operator== (const char* str) const noexcept {
        return std::strcmp(this->str, str) == 0;
    }

    bool operator!= (const char* str) const noexcept {
        return !(*this == str);
    }

    template <typename Alloc>
    bool operator== (const std::basic_string<char, std::char_traits<char>, Alloc>& str) const noexcept {
        return this->str == str;
    }

    template <typename Alloc>
    bool operator!= (const std::basic_string<char, std::char_traits<char>, Alloc>& str) const noexcept {
        return this->str != str;
    }

    bool empty() const noexcept {
        return str[0] == 0;
    }

    bool nonEmpty() const noexcept {
        return !empty();
    }

    iterator begin() const noexcept {
        return str;
    }

    iterator end() const noexcept {
        return iterator();
    }

    const char* c_str() const noexcept {
        return str;
    }

    operator const char*() const noexcept {
        return str;
    }

    operator std::string() const {
        return str;
    }

    operator std::string_view() const noexcept {
        return str;
    }

    void swap(string_ref& that) noexcept {
        std::swap(str, that.str);
    }

private:
    const char* str;
};

inline void swap(string_ref& lhs, string_ref& rhs) noexcept {
    lhs.swap(rhs);
}

inline string_ref operator ""_sr(const char* str, size_t) noexcept {
    return str;
}

} // namespace imdex

namespace std {

template <>
struct hash<imdex::string_ref> {
    size_t operator()(const imdex::string_ref value) const {
        return std::hash<const char*>()(value);
    }
};

} // std namespace
