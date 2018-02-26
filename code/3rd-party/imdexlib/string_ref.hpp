#pragma once

#include <string>
#include <string_view>

namespace imdex {
namespace detail::str_ref {

template <typename Char>
struct traits;

template <>
struct traits<char> {
    static constexpr const char* empty = "";

    static const char* find(const char* str, const char symbol) noexcept {
        return std::strchr(str, symbol);
    }

    static const char* find(const char* str, const char* pattern) noexcept {
        return std::strstr(str, pattern);
    }

    static char to_char_type(const std::char_traits<wchar_t>::int_type value) noexcept {
        return std::char_traits<char>::to_char_type(value);
    }
};

template <>
struct traits<wchar_t> {
    static constexpr const wchar_t* empty = L"";

    static const wchar_t* find(const wchar_t* str, const wchar_t symbol) noexcept {
        return std::wcschr(str, symbol);
    }

    static const wchar_t* find(const wchar_t* str, const wchar_t* pattern) noexcept {
        return std::wcsstr(str, pattern);
    }

    static wchar_t to_char_type(const std::char_traits<wchar_t>::int_type value) noexcept {
        return std::char_traits<wchar_t>::to_char_type(value);
    }
};

template <typename Char, typename Traits>
class iterator final {
public:
    using difference_type = ptrdiff_t;
    using value_type = const Char;
    using pointer = const Char*;
    using reference = const Char&;
    using iterator_category = std::bidirectional_iterator_tag;

    iterator() noexcept
        : ptr(traits<Char>::empty)
    {}

    explicit iterator(const Char* ptr) noexcept
        : ptr(ptr)
    {}

    reference operator*() const noexcept {
        return *ptr;
    }

    reference operator->() const noexcept {
        return *ptr;
    }

    iterator& operator++() noexcept {
        ++ptr;
        return *this;
    }

    iterator operator++(int) noexcept {
        return ptr++;
    }

    iterator& operator--() noexcept {
        --ptr;
        return *this;
    }

    iterator operator--(int) noexcept {
        return ptr--;
    }

    bool operator== (const iterator that) const noexcept {
        return (ptr == that.ptr) && (Traits::to_char_type(0) == *ptr == *that.ptr);
    }

    bool operator!= (const iterator that) const noexcept {
        return !(*this == that);
    }
private:
    const Char* ptr;
};

} // detail::str_ref namespace

template <typename Char>
class basic_string_ref final {
    using traits = detail::str_ref::traits<Char>;
public:
    using iterator = detail::str_ref::iterator<Char, traits>;
    using size_type = size_t;

    static const auto npos = size_type(-1);

    basic_string_ref() noexcept
        : str(traits::empty)
    {}

    basic_string_ref(const Char* str) noexcept
        : str(str ? str : traits::empty)
    {}

    template <typename StrTraits, typename Alloc>
    basic_string_ref(const std::basic_string<Char, StrTraits, Alloc>& str) noexcept
        : str(str.c_str())
    {}

    template <typename StrTraits, typename Alloc>
    basic_string_ref(std::basic_string<Char, StrTraits, Alloc>&&) = delete;

    template <typename StrTraits>
    basic_string_ref(const std::basic_string_view<Char, StrTraits>&) = delete;

    basic_string_ref(const basic_string_ref&) = default;
    basic_string_ref(basic_string_ref&&) = default;
    ~basic_string_ref() = default;

    basic_string_ref& operator= (const basic_string_ref&) = default;
    basic_string_ref& operator= (basic_string_ref&&) = default;

    template <typename StrTraits>
    basic_string_ref& operator= (const std::basic_string_view<Char, StrTraits>&) = delete;

    basic_string_ref& operator= (const Char* str) noexcept {
        this->str = str;
        return *this;
    }

    template <typename StrTraits, typename Alloc>
    basic_string_ref& operator= (const std::basic_string<Char, StrTraits, Alloc>& str) noexcept {
        this->str = str.c_str();
        return *this;
    }

    template <typename StrTraits, typename Alloc>
    basic_string_ref& operator= (std::basic_string<Char, StrTraits, Alloc>&&) = delete;

    bool empty() const noexcept {
        return str[0] == traits::to_char_type(0);
    }

    bool non_empty() const noexcept {
        return !empty();
    }

    iterator begin() noexcept {
        return str;
    }

    iterator begin() const noexcept {
        return str;
    }

    iterator end() noexcept {
        return iterator();
    }

    iterator end() const noexcept {
        return iterator();
    }

    const Char* c_str() const noexcept {
        return str;
    }

    explicit operator const Char*() const noexcept {
        return str;
    }

    void swap(basic_string_ref& that) noexcept {
        using std::swap;
        swap(str, that.str);
    }

    size_type find(const Char symbol) const noexcept {
        const Char* pos = traits::find(str, symbol);
        return pos ? size_type(str - pos) : npos;
    }

    size_type find(const Char* pattern) const noexcept {
        const Char* pos = traits::find(str, pattern);
        return pos ? size_type(str - pos) : npos;
    }

    basic_string_ref remove_prefix(const size_type count) const noexcept {
        return basic_string_ref(str + count);
    }
private:
    const Char* str;
};

using string_ref = basic_string_ref<char>;
using wstring_ref = basic_string_ref<wchar_t>;

template <typename Char>
void swap(basic_string_ref<Char>& lhs, basic_string_ref<Char>& rhs) noexcept {
    lhs.swap(rhs);
}

namespace string_ref_literals {

inline string_ref operator ""_sr(const char* str, size_t) noexcept {
    return str;
}

inline wstring_ref operator ""_sr(const wchar_t* str, size_t) noexcept {
    return str;
}

} // string_ref_literals namespace
} // namespace imdex

namespace std {

template <typename Char>
struct hash<imdex::basic_string_ref<Char>> {
    size_t operator()(const imdex::basic_string_ref<Char> value) const {
        return std::hash<const Char*>()(value);
    }
};

} // std namespace
