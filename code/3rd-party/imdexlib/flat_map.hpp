#pragma once

#include <vector>
#include <algorithm>

#include "traits.hpp"

namespace imdex {

template <typename Key,
          typename Value,
          typename Comp = std::less<Key>,
          typename Alloc = std::allocator<std::pair<Key, Value>>>
class FlatMap {
public:
    using Node = std::pair<Key, Value>;
private:
    using Storage = std::vector<Node, Alloc>;
public:
    using iterator = typename Storage::iterator;
    using const_iterator = typename Storage::const_iterator;
    using reverse_iterator = typename Storage::reverse_iterator;
    using const_reverse_iterator = typename Storage::const_reverse_iterator;

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
        const auto iter = lower_bound(key);

        if (iter == end()) {
            return iter;
        } else {
            return Comp()(iter->first, key) ? end() : iter;
        }
    }

    const_iterator find(const Key& key) const {
        const auto iter = lower_bound(key);

        if (iter == end()) {
            return iter;
        } else {
            return Comp()(iter->first, key) ? end() : iter;
        }
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

    bool contains(const Key& key) const {
        return find(key) != end();
    }

    template <typename Sequence>
    void insert(Sequence&& seq) {
        if constexpr(is_sequence_v<Sequence&&>) {
            constexpr bool isRvalue = std::is_rvalue_reference_v<Sequence&&>;

            for (auto& pair : seq) {
                const auto iter = find(pair.first);
                if (iter != end()) {
                    if constexpr(isRvalue) {
                        iter->second = std::move(pair.second);
                    } else {
                        iter->second = pair.second;
                    }
                } else {
                    if constexpr(isRvalue) {
                        storage.push_back(std::move(pair));
                    } else {
                        storage.push_back(pair);
                    }
                }
            }
        } else {
            static_assert(false, "Argument is not a sequence");
        }

        std::sort(begin(), end(), [](const Node& lhs, const Node& rhs) {
            return Comp()(lhs.first, rhs.first);
        });
    }

    void clear() {
        storage.clear();
    }

    void swap(FlatMap& that) {
        using std::swap;
        swap(storage, that.storage);
    }

private:
    iterator lower_bound(const Key& key) {
        return std::lower_bound(begin(), end(), key, [](const Node& node, const Key& key) {
            return Comp()(node.first, key);
        });
    }

    const_iterator lower_bound(const Key& key) const {
        return std::lower_bound(begin(), end(), key, [](const Node& node, const Key& key) {
            return Comp()(node.first, key);
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
