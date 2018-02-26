#pragma once

#include "traits.hpp"

namespace imdex {

template <typename Iterator>
class range final {
    using traits = std::iterator_traits<Iterator>;
    static_assert(is_iterator_v<Iterator>, "Begin type is not an iterator");
public:
    using value_type = typename traits::value_type;
    using iterator = Iterator;
    using const_iterator = Iterator; // NOTE: just for gtest

    range(Iterator begin, Iterator end)
        : begin_(begin),
          end_(end)
    {}

    Iterator begin() const {
        return begin_;
    }

    Iterator end() const {
        return end_;
    }
private:
    Iterator begin_;
    Iterator end_;
};

template <typename Iterator>
range<remove_cvr_t<Iterator>> make_range(Iterator begin, Iterator end) {
    return range<remove_cvr_t<Iterator>>(begin, end);
}

// TODO: opaque range

} // imdex namespace
