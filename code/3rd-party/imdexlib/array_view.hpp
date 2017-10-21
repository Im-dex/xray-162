#pragma once

#include <imdexlib/traits.hpp>

#include <cassert>
#include <array>

namespace imdex {

template <typename T>
class ArrayView {
    static_assert(!std::is_reference_v<T>, "T needs to be non reference type");
    static_assert(!std::is_pointer_v<T>, "T needs to be non pointer type");
    static_assert(!std::is_const_v<T>, "T needs to be non const type");
public:
    using value_type = T;
    using size_type = size_t;
    using iterator = const T*;

    ArrayView() noexcept : ArrayView(nullptr, 0) {}

    explicit ArrayView(const T* ptr, const size_t size) noexcept
        : ptr(ptr),
          size_(size)
    {}

    template <size_t Size>
    ArrayView(const T (&array)[Size]) noexcept : ArrayView(&array[0], Size) {}

    template <size_t Size>
    ArrayView(const std::array<T, Size>& array) noexcept : ArrayView(array.data(), array.size()) {}

    size_t size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    bool non_empty() const noexcept {
        return size_ != 0;
    }

    const T& operator[] (const size_t index) const {
        assert(index < size_ && "Index out of bounds");
        return ptr[index];
    }

    template <typename U>
    bool operator== (const ArrayView<U> that) const noexcept {
        if constexpr (is_comparable_to_v<T, U>) {
            return equals(*this, that);
        } else {
            static_assert(false, "Types is not comparable");
            return false;
        }
    }

    template <typename U>
    bool operator!= (const ArrayView<U> that) const noexcept {
        return !(*this == that);
    }

    template <typename U, size_t Size>
    bool operator== (const std::array<U, Size>& that) const noexcept {
        if constexpr (is_comparable_to_v<T, U>) {
            return equals(*this, that);
        } else {
            static_assert(false, "Types is not comparable");
            return false;
        }
    }

    template <typename U, size_t Size>
    bool operator!= (const std::array<U, Size>& that) const noexcept {
        return !(*this == that);
    }

    const T* data() const noexcept {
        return ptr;
    }

    iterator begin() const noexcept {
        return ptr;
    }

    iterator end() const noexcept {
        return ptr + size_;
    }

    ArrayView slice(const size_t offset, const size_t size) const noexcept {
        assert((offset + size <= size_) && "Out of bounds");
        return ArrayView(ptr + offset, size);
    }

private:
    template <typename Lhs, typename Rhs>
    static bool equals(const Lhs& lhs, const Rhs& rhs) {
        using std::begin;
        using std::end;
        using std::size;

        if (size(lhs) != size(rhs)) {
            return false;
        }
        return std::equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
    }

    const T* ptr;
    size_t size_;
};

template <typename T>
typename ArrayView<T>::iterator begin(const ArrayView<T> view) noexcept {
    return view.begin();
}

template <typename T>
typename ArrayView<T>::iterator end(const ArrayView<T> view) noexcept {
    return view.end();
}

template <typename T>
typename ArrayView<T>::size_type size(const ArrayView<T> view) noexcept {
    return view.size();
}

template <typename T, typename U, size_t Size>
bool operator== (const std::array<U, Size>& array, const ArrayView<T> view) noexcept {
    return view == array;
}

template <typename T, typename U, size_t Size>
bool operator!= (const std::array<U, Size>& array, const ArrayView<T> view) noexcept {
    return view != array;
}

} // imdex namespace
