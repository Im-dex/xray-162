#pragma once

#include <vector>
#include <algorithm>

#include "traits.hpp"

namespace imdex {

enum class InsertResult {
    New,
    Update
};

template <typename Key,
          typename Value,
          typename Comp = std::less<Key>,
          typename Alloc = std::allocator<std::pair<Key, Value>>>
class FlatMap {
public:
    using value_type = std::pair<Key, Value>;
private:
    using Storage = std::vector<value_type, Alloc>;
public:
    using size_type = size_t;
    using iterator = typename Storage::iterator;
    using const_iterator = typename Storage::const_iterator;
    using reverse_iterator = typename Storage::reverse_iterator;
    using const_reverse_iterator = typename Storage::const_reverse_iterator;

    FlatMap() = default;
    FlatMap(std::initializer_list<value_type> list)
        : storage() {
        insert(list);
    }

    template <typename Sequence>
    FlatMap(Sequence&& seq)
        : storage() {
        insert(std::forward<Sequence>(seq));
    }

    FlatMap(const FlatMap&) = default;
    FlatMap(FlatMap&&) = default;

    FlatMap& operator= (const FlatMap&) = default;
    FlatMap& operator= (FlatMap&&) = default;

    iterator begin() {
        return storage.begin();
    }

    iterator end() {
        return storage.end();
    }

    const_iterator begin() const {
        return storage.begin();
    }

    const_iterator end() const {
        return storage.end();
    }

    const_iterator cbegin() {
        return storage.cbegin();
    }

    const_iterator cend() {
        return storage.cend();
    }

    reverse_iterator rbegin() {
        return storage.rbegin();
    }

    reverse_iterator rend() {
        return storage.rend();
    }

    const_reverse_iterator rbegin() const {
        return storage.rbegin();
    }

    const_reverse_iterator rend() const {
        return storage.rend();
    }

    const_reverse_iterator crbegin() {
        return storage.crbegin();
    }

    const_reverse_iterator crend() {
        return storage.crend();
    }

    iterator find(const Key& key) {
        return find(key, Comp());
    }

    template <typename KeyT, typename KeysComp>
    iterator find(const KeyT& key, KeysComp comp) {
        const auto iter = lower_bound(key, comp);

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
    const_iterator find(const KeyT& key, KeysComp comp) const {
        const auto iter = lower_bound(key, comp);

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
    bool contains(const KeyT& key, KeysComp comp) const {
        return find(key, comp) != end();
    }

    size_t size() const {
        return storage.size();
    }

    bool empty() const {
        return storage.empty();
    }

    bool nonEmpty() const {
        return !empty();
    }

    void insert(std::initializer_list<value_type> list) {
        storage.reserve(list.size());
        insertImpl(list.begin(), list.end());
    }

    template <typename Sequence>
    void insert(Sequence&& seq) {
        if constexpr(is_sequence_v<Sequence&&>) {
            using SeqIter = typename std::decay_t<Sequence>::iterator;
            using SeqIterCategory = typename std::iterator_traits<SeqIter>::iterator_category;

            if constexpr (std::is_same_v<SeqIterCategory, std::random_access_iterator_tag>) {
                const auto seqSize = std::distance(seq.begin(), seq.end());
                storage.reserve(static_cast<size_t>(seqSize));
            }

            if constexpr (std::is_rvalue_reference_v<Sequence&&>) {
                insertImpl(std::make_move_iterator(seq.begin()),
                           std::make_move_iterator(seq.end()));
            } else {
                insertImpl(seq.begin(), seq.end());
            }
        } else {
            static_assert(false, "Argument is not a sequence");
        }
    }

    InsertResult insert(value_type value) {
        return insert(std::move(value.first), std::move(value.second));
    }

    InsertResult insert(Key key, Value value) {
        const auto iter = lower_bound(key, Comp());
        if (iter != end() && iter->first == key) {
            iter->second = std::move(value);
            return InsertResult::Update;
        } else {
            storage.insert(iter, std::make_pair(std::move(key), std::move(value)));
            return InsertResult::New;
        }
    }

    void erase(const iterator elem) {
        storage.erase(elem);
    }

    void clear() {
        storage.clear();
    }

    void reserve(const size_t capacity) {
        storage.reserve(capacity);
    }

    void swap(FlatMap& that) {
        using std::swap;
        swap(storage, that.storage);
    }

private:
    template <typename KeyT, typename KeyComp>
    iterator lower_bound(const KeyT& key, KeyComp comp) {
        return std::lower_bound(begin(), end(), key, [&comp](const auto& node, const KeyT& key) {
            return comp(node.first, key);
        });
    }

    template <typename KeyT, typename KeyComp>
    const_iterator lower_bound(const KeyT& key, KeyComp comp) const {
        return std::lower_bound(begin(), end(), key, [&comp](const auto& node, const KeyT& key) {
            return comp(node.first, key);
        });
    }

    template <typename BeginIter, typename EndIter>
    void insertImpl(BeginIter iter, EndIter endIter) {
        for (; iter != endIter; ++iter) {
            const auto elementIter = find(iter->first);
            if (elementIter != end()) {
                elementIter->second = iter->second;
            } else {
                storage.push_back(*iter);
            }
        }

        std::sort(begin(), end(), [](const auto& lhs, const auto& rhs) {
            return Comp()(lhs.first, rhs.first);
        });
    }

    Storage storage;
};

template <typename Key, typename Value, typename Comp, typename Alloc>
auto begin(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.begin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto end(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.end();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto cbegin(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.cbegin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto cend(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.cend();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto begin(const FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.begin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto end(const FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.end();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rbegin(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rbegin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rend(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rend();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rcbegin(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rcbegin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rcend(FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rcend();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rbegin(const FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rbegin();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
auto rend(const FlatMap<Key, Value, Comp, Alloc>& map) {
    return map.rend();
}

template <typename Key, typename Value, typename Comp, typename Alloc>
void swap(FlatMap<Key, Value, Comp, Alloc>& lhs, FlatMap<Key, Value, Comp, Alloc>& rhs) {
    lhs.swap(rhs);
}

} // imdex namespace
