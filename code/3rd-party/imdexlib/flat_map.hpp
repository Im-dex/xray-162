#pragma once

#include <vector>
#include <algorithm>

#include "fwd.hpp"
#include "traits.hpp"
#include "utility.hpp"
#include "range.hpp"

namespace imdex {
namespace detail::flat_map {

struct key_comparator final {
    template <typename Key, typename Value>
    bool operator() (const std::pair<Key, Value>& lhs,
                     const std::pair<Key, Value>& rhs) const noexcept {
        return lhs.first == rhs.first;
    }
};

template <typename Iterator>
class default_wrapper final {
    using traits = std::iterator_traits<Iterator>;
public:
    using value_type = typename traits::value_type;
    using reference = typename traits::reference;
    using pointer = typename traits::pointer;
    using comparator = std::equal_to<>;

    static reference unwrap_ref(Iterator iter) {
        return *iter;
    }

    static pointer unwrap_ptr(Iterator iter) {
        return iter.operator->();
    }
};

template <typename Iterator>
class key_wrapper final {
    using traits = std::iterator_traits<Iterator>;
public:
    using value_type = std::tuple_element_t<0, typename traits::value_type>;
    using reference = decltype(std::get<0>(std::declval<typename traits::reference>()));
    using pointer = std::add_pointer_t<std::remove_reference_t<reference>>;
    using comparator = key_comparator;

    static reference unwrap_ref(Iterator iter) {
        return std::get<0>(*iter);
    }

    static pointer unwrap_ptr(Iterator iter) {
        return std::addressof(unwrap_ref(iter));
    }
};

template <typename Iterator,
          typename Wrapper = default_wrapper<Iterator>>
class duplicate_iterator final {
    using traits = std::iterator_traits<Iterator>;
public:
    using value_type = typename Wrapper::value_type;
    using difference_type = typename traits::difference_type;
    using pointer = typename Wrapper::pointer;
    using reference = typename Wrapper::reference;
    using iterator_category = std::input_iterator_tag;

    explicit duplicate_iterator(Iterator first, Iterator last)
        : first(first),
          last(last) {
        advance();
    }

    Iterator base() const {
        return first;
    }

    reference operator* () const noexcept {
        return Wrapper::unwrap_ref(first);
    }

    pointer operator-> () const noexcept {
        return Wrapper::unwrap_ptr(first);
    }

    duplicate_iterator& operator++ () noexcept {
        advance();
        return *this;
    }

    duplicate_iterator operator++ (int) noexcept {
        auto copy = *this;
        advance();
        return copy;
    }

    bool operator== (const duplicate_iterator& that) const noexcept {
        assert(last == that.last);
        return first == that.first;
    }

    bool operator!= (const duplicate_iterator& that) const noexcept {
        assert(last == that.last);
        return first != that.first;
    }

    bool operator== (const Iterator& that) const noexcept {
        return first == that;
    }

    bool operator!= (const Iterator& that) const noexcept {
        return first != that;
    }
private:
    void advance() noexcept {
        first = std::adjacent_find(first, last, typename Wrapper::comparator());
        if (first != last)
            std::advance(first, 1);
    }

    Iterator first;
    Iterator last;
};

template <typename Iterator, typename Wrapper>
bool operator== (const Iterator& lhs, const duplicate_iterator<Iterator, Wrapper>& rhs) noexcept {
    return rhs == lhs;
}

template <typename Iterator, typename Wrapper>
bool operator!= (const Iterator& lhs, const duplicate_iterator<Iterator, Wrapper>& rhs) noexcept {
    return rhs != lhs;
}

} // detail::flat_map namespace

enum class UpsertResult {
    Insert,
    Update
};

#pragma warning(push)
#pragma warning(disable:4521) // multiple copy constructors specified

// Array-based map. Doesn't handle duplicates automagically.
template <typename Key,
          typename Value,
          typename Comp = std::less<Key>,
          typename Alloc = std::allocator<std::pair<Key, Value>>>
class FlatMap final {
public:
    using value_type = std::pair<Key, Value>;
private:
    enum class IsSequence;
    enum class NotASequence;
    enum class IsIterator;
    enum class NotAnIterator;

    template <typename T>
    using detect_sequence = std::conditional_t<is_sequence_v<T>, IsSequence, NotASequence>;

    template <typename T>
    using detect_iterator = std::conditional_t<is_iterator_v<T>, IsIterator, NotAnIterator>;

    using Storage = std::vector<value_type, Alloc>;
public:
    using size_type = typename Storage::size_type;
    using iterator = typename Storage::iterator;
    using const_iterator = typename Storage::const_iterator;
    using reverse_iterator = typename Storage::reverse_iterator;
    using const_reverse_iterator = typename Storage::const_reverse_iterator;
    using duplicate_keys_iterator = detail::flat_map::duplicate_iterator<
        const_iterator, detail::flat_map::key_wrapper<const_iterator>
    >;
    using duplicate_items_iterator = detail::flat_map::duplicate_iterator<
        const_iterator
    >;

    FlatMap() = default;

    explicit FlatMap(std::initializer_list<value_type> init)
        : storage(init) {
        sort();
    }

    template <typename Sequence>
    explicit FlatMap(Sequence&& seq)  // NOLINT
        : FlatMap(IMDEX_FWD(seq), detect_sequence<Sequence>{},
                                  std::is_constructible<Storage, Sequence&&>{})
    {}

    template <typename Iter>
    explicit FlatMap(Iter first, Iter second)
        : FlatMap(first, second, detect_iterator<Iter>{})
    {}

    FlatMap(FlatMap& that)
        : FlatMap(std::as_const(that))
    {}

    FlatMap(const FlatMap& that)
        : storage(that.storage)
    {}

    FlatMap(FlatMap&& that) noexcept
        : storage(std::move(that.storage))
    {}

    ~FlatMap() = default;

    FlatMap& operator= (const FlatMap&) = default;
    FlatMap& operator= (FlatMap&&) = default;

    iterator begin() noexcept {
        return storage.begin();
    }

    iterator end() noexcept {
        return storage.end();
    }

    const_iterator begin() const noexcept {
        return storage.begin();
    }

    const_iterator end() const noexcept {
        return storage.end();
    }

    const_iterator cbegin() noexcept {
        return storage.cbegin();
    }

    const_iterator cend() noexcept {
        return storage.cend();
    }

    reverse_iterator rbegin() noexcept {
        return storage.rbegin();
    }

    reverse_iterator rend() noexcept {
        return storage.rend();
    }

    const_reverse_iterator rbegin() const noexcept {
        return storage.rbegin();
    }

    const_reverse_iterator rend() const noexcept {
        return storage.rend();
    }

    const_reverse_iterator crbegin() noexcept {
        return storage.crbegin();
    }

    const_reverse_iterator crend() noexcept {
        return storage.crend();
    }

    iterator find(const Key& key) {
        return find(key, Comp());
    }

    duplicate_keys_iterator find_duplicate_keys() const noexcept {
        return duplicate_keys_iterator(begin(), end());
    }

    duplicate_items_iterator find_duplicate_items() const noexcept {
        return duplicate_items_iterator(begin(), end());
    }

    range<duplicate_keys_iterator> duplicate_keys() const noexcept {
        return make_range(find_duplicate_keys(), duplicate_keys_iterator(end(), end()));
    }

    range<duplicate_items_iterator> duplicate_items() const noexcept {
        return make_range(find_duplicate_items(), duplicate_items_iterator(end(), end()));
    }

    template <typename KeyT, typename KeysComp>
    iterator find(const KeyT& key, KeysComp&& comp) {
        const auto iter = lower_bound(key, IMDEX_FWD(comp));

        if (iter == end()) {
            return iter;
        } else {
            return (iter->first == key) ? iter : end();
        }
    }

    const_iterator find(const Key& key) const {
        return find(key, Comp());
    }

    template <typename KeyT, typename KeysComp>
    const_iterator find(const KeyT& key, KeysComp&& comp) const {
        const auto iter = lower_bound(key, IMDEX_FWD(comp));

        if (iter == end()) {
            return iter;
        } else {
            return (iter->first == key) ? iter : end();
        }
    }

    bool contains(const Key& key) const {
        return find(key) != end();
    }

    template <typename KeyT, typename KeysComp>
    bool contains(const KeyT& key, KeysComp&& comp) const {
        return find(key, IMDEX_FWD(comp)) != end();
    }

    size_t size() const noexcept {
        return storage.size();
    }

    bool empty() const noexcept {
        return storage.empty();
    }

    bool non_empty() const noexcept {
        return !empty();
    }

    template <typename Sequence>
    void insert(Sequence&& seq) {
        using std::begin;
        using std::end;
        using std::size;

        using Seq = remove_cvr_t<Sequence>;

        if constexpr(is_sequence_v<Seq>) {
            using Iter = remove_cvr_t<decltype(*begin(seq))>;

            if constexpr (is_size_aware_v<Seq>) {
                storage.reserve(this->size() + size(seq));
            } else if constexpr (is_random_access_iterator_v<Iter>) {
                const auto seqSize = std::distance(begin(seq), end(seq));
                storage.reserve(this->size() + seqSize);
            }

            if constexpr (std::is_rvalue_reference_v<Sequence&&>) {
                insert_range_impl(std::make_move_iterator(begin(seq)),
                                  std::make_move_iterator(end(seq)));
            } else {
                insert_range_impl(begin(seq), end(seq));
            }
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Sequence expected");
        }
    }

    iterator insert(const value_type& value) {
        return insert(value.first, value.second);
    }

    iterator insert(value_type&& value) {
        return insert(std::move(value.first), std::move(value.second));
    }

    iterator insert(const Key& key, const Value& value) {
        return insert_impl(key, value);
    }

    iterator insert(Key&& key, Value&& value) {
        return insert_impl(std::move(key), std::move(value));
    }

    std::pair<iterator, UpsertResult> upsert(const value_type& value) {
        return upsert(value.first, value.second);
    }

    std::pair<iterator, UpsertResult> upsert(value_type&& value) {
        return upsert(std::move(value.first), std::move(value.second));
    }

    std::pair<iterator, UpsertResult> upsert(const Key& key, const Value& value) {
        return upsert_impl(key, value);
    }

    std::pair<iterator, UpsertResult> upsert(Key&& key, Value&& value) {
        return upsert_impl(std::move(key), std::move(value));
    }

    void erase(const const_iterator elem) {
        storage.erase(elem);
    }

    void clear() {
        storage.clear();
    }

    void reserve(const size_type capacity) {
        storage.reserve(capacity);
    }

    void swap(FlatMap& that) {
        using std::swap;
        swap(storage, that.storage);
    }
private:
    template <typename Sequence>
    FlatMap(Sequence&& seq, IsSequence, std::true_type /* inplace constructible */)
        : storage(IMDEX_FWD(seq)) {
        sort();
    }

    template <typename Sequence>
    FlatMap(Sequence&& seq, IsSequence, std::false_type /* inplace constructible */)
        : storage(begin(seq), end(seq)) {
        sort();
    }

    template <typename T, bool Val>
    FlatMap(T&&, NotASequence, std::bool_constant<Val>)
        : storage() {
        static_assert(false_v<T>, "Sequence expected");
    }

    template <typename Iter>
    FlatMap(Iter first, Iter last, IsIterator)
        : storage(first, last) {
        sort();
    }

    template <typename Iter>
    FlatMap(Iter, Iter, NotAnIterator)
        : storage() {
        static_assert(false_v<Iter>, "Iterator expected");
    }

    void sort() {
        std::sort(begin(), end(), [](const auto& lhs, const auto& rhs) {
            return Comp()(lhs.first, rhs.first);
        });
    }

    template <typename KeyT, typename KeyComp>
    iterator lower_bound(const KeyT& key, KeyComp&& comp) {
        return std::lower_bound(begin(), end(), key, [&comp](const auto& node, const KeyT& key) {
            return comp(node.first, key);
        });
    }

    template <typename KeyT, typename KeyComp>
    const_iterator lower_bound(const KeyT& key, KeyComp&& comp) const {
        return std::lower_bound(begin(), end(), key, [&comp](const auto& node, const KeyT& key) {
            return comp(node.first, key);
        });
    }

    template <typename K, typename V>
    iterator insert_impl(K&& key, V&& value) {
        const auto iter = lower_bound(key, Comp());
        return storage.insert(iter, std::make_pair(IMDEX_FWD(key), IMDEX_FWD(value)));
    }

    template <typename K, typename V>
    std::pair<iterator, UpsertResult> upsert_impl(K&& key, V&& value) {
        const auto iter = lower_bound(key, Comp());
        if (iter != end() && iter->first == key) {
            iter->second = IMDEX_FWD(value);
            return std::make_pair(iter, UpsertResult::Update);
        } else {
            const auto it = storage.insert(iter, std::make_pair(IMDEX_FWD(key),
                                                                IMDEX_FWD(value)));
            return std::make_pair(it, UpsertResult::Insert);
        }
    }

    template <typename Iter>
    void insert_range_impl(Iter first, Iter last) {
        storage.insert(storage.end(), first, last);
        sort();
    }

    Storage storage;
};

#pragma warning(pop)

template <typename Key, typename Value, typename Comp, typename Alloc>
void swap(FlatMap<Key, Value, Comp, Alloc>& lhs, FlatMap<Key, Value, Comp, Alloc>& rhs) {
    lhs.swap(rhs);
}

} // imdex namespace
