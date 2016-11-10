#ifndef _STL_EXT_internal
#define _STL_EXT_internal

#include <memory>

using std::swap;

template <class T>
class xalloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;

    template <class Other>
    struct rebind
    {
        using other = xalloc<Other>;
    };

    pointer address(reference _Val) const { return (&_Val); }
    const_pointer address(const_reference _Val) const { return (&_Val); }
    xalloc() {}
    xalloc(const xalloc<T>&) {}
    template <class Other>
    xalloc(const xalloc<Other>&) {}
    template <class Other>
    xalloc<T>& operator=(const xalloc<Other>&) { return (*this); }
    pointer allocate(size_type n, const void* p = nullptr) const { return xr_alloc<T>((u32)n); }
    char* _charalloc(size_type n) { return (char*)allocate(n); }
    void deallocate(pointer p, size_type n) const { xr_free(p); }
    void deallocate(void* p, size_type n) const { xr_free(p); }
    void construct(pointer p, const T& _Val) { std::_Construct(p, _Val); }
    void destroy(pointer p) { std::_Destroy(p); }
    size_type max_size() const
    {
        size_type _Count = (size_type)(-1) / sizeof(T);
        return (0 < _Count ? _Count : 1);
    }
};

struct xr_allocator {
    template <typename T>
    struct helper {
        typedef xalloc<T> result;
    };

    static void* alloc(const u32& n) { return xr_malloc((u32)n); }
    template <typename T>
    static void dealloc(T*& p) { xr_free(p); }
};

template <class _Ty, class _Other>
inline bool operator==(const xalloc<_Ty>&, const xalloc<_Other>&) { return (true); }
template <class _Ty, class _Other>
inline bool operator!=(const xalloc<_Ty>&, const xalloc<_Other>&) { return (false); }

namespace std {
template <class _Tp1, class _Tp2>
inline xalloc<_Tp2>& __stl_alloc_rebind(xalloc<_Tp1>& __a, const _Tp2*) { return (xalloc<_Tp2>&)(__a); }
template <class _Tp1, class _Tp2>
inline xalloc<_Tp2> __stl_alloc_create(xalloc<_Tp1>&, const _Tp2*) { return xalloc<_Tp2>(); }
};

// string(char)
typedef std::basic_string<char, std::char_traits<char>, xalloc<char>> xr_string;

// vector
template <typename T, typename allocator = xalloc<T>>
class xr_vector : public std::vector<T, allocator> {
private:
    typedef std::vector<T, allocator> inherited;

public:
    typedef allocator allocator_type;

public:
    xr_vector()
        : inherited()
    {
    }
    xr_vector(size_t _count, const T& _value)
        : inherited(_count, _value)
    {
    }
    explicit xr_vector(size_t _count)
        : inherited(_count)
    {
    }
    u32 size() const { return (u32)inherited::size(); }

    void clear_and_free() { inherited::clear(); }
    void clear_not_free() { erase(begin(), end()); }
    void clear_and_reserve()
    {
        if (capacity() <= (size() + size() / 4))
            clear_not_free();
        else {
            u32 old = size();
            clear_and_free();
            reserve(old);
        }
    }

    void clear()
    {
        clear_and_free();
    }

    const_reference operator[](size_type _Pos) const
    {
        {
            VERIFY2(_Pos < size(), make_string("index is out of range: index requested[%d], size of container[%d]", _Pos, size()).c_str());
        }
        return (*(begin() + _Pos));
    }
    reference operator[](size_type _Pos)
    {
        {
            VERIFY2(_Pos < size(), make_string("index is out of range: index requested[%d], size of container[%d]", _Pos, size()).c_str());
        }
        return (*(begin() + _Pos));
    }
};

// vector<bool>
template <>
class xr_vector<bool, xalloc<bool>> : public std::vector<bool, xalloc<bool>> {
private:
    typedef std::vector<bool, xalloc<bool>> inherited;

public:
    u32 size() const { return (u32)inherited::size(); }
    void clear() { erase(begin(), end()); }
};

template <typename allocator>
class xr_vector<bool, allocator> : public std::vector<bool, allocator> {
private:
    typedef std::vector<bool, allocator> inherited;

public:
    u32 size() const { return (u32)inherited::size(); }
    void clear() { erase(begin(), end()); }
};

// deque
template <typename T, typename allocator = xalloc<T>>
class xr_deque : public std::deque<T, allocator> {
public:
    typedef typename allocator allocator_type;
    typedef typename allocator_type::value_type value_type;
    typedef typename allocator_type::size_type size_type;
    u32 size() const { return (u32) __super ::size(); }
};

// stack
template <typename _Ty, class _C = xr_vector<_Ty>>
class xr_stack {
public:
    typedef typename _C::allocator_type allocator_type;
    typedef typename allocator_type::value_type value_type;
    typedef typename allocator_type::size_type size_type;

    //explicit			stack(const allocator_type& _Al = allocator_type()) : c(_Al) {}
    allocator_type get_allocator() const { return (c.get_allocator()); }
    bool empty() const { return (c.empty()); }
    u32 size() const { return c.size(); }
    value_type& top() { return (c.back()); }
    const value_type& top() const { return (c.back()); }
    void push(const value_type& _X) { c.push_back(_X); }
    void pop() { c.pop_back(); }
    bool operator==(const xr_stack<_Ty, _C>& _X) const { return (c == _X.c); }
    bool operator!=(const xr_stack<_Ty, _C>& _X) const { return (!(*this == _X)); }
    bool operator<(const xr_stack<_Ty, _C>& _X) const { return (c < _X.c); }
    bool operator>(const xr_stack<_Ty, _C>& _X) const { return (_X < *this); }
    bool operator<=(const xr_stack<_Ty, _C>& _X) const { return (!(_X < *this)); }
    bool operator>=(const xr_stack<_Ty, _C>& _X) const { return (!(*this < _X)); }

protected:
    _C c;
};

template <typename T, typename allocator = xalloc<T>>
class xr_list : public std::list<T, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};
template <typename K, class P = std::less<K>, typename allocator = xalloc<K>>
class xr_set : public std::set<K, P, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};
template <typename K, class P = std::less<K>, typename allocator = xalloc<K>>
class xr_multiset : public std::multiset<K, P, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};
template <typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V>>>
class xr_map : public std::map<K, V, P, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};
template <typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V>>>
class xr_multimap : public std::multimap<K, V, P, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};

template <typename K, class V, class _Traits = std::equal_to<K>, typename allocator = xalloc<std::pair<K, V>>>
class xr_hash_map : public std::unordered_map<K, V, std::hash<K>, _Traits, allocator> {
public:
    u32 size() const { return (u32) __super ::size(); }
};

struct pred_str : public std::binary_function<char*, char*, bool> {
    bool operator()(const char* x, const char* y) const { return xr_strcmp(x, y) < 0; }
};
struct pred_stri : public std::binary_function<char*, char*, bool> {
    bool operator()(const char* x, const char* y) const { return stricmp(x, y) < 0; }
};

#include "FixedVector.h"
#include "buffer_vector.h"

// auxilary definition
using FvectorVec = xr_vector<Fvector>;
using LPSTRVec = xr_vector<LPSTR>;
using SStringVec = xr_vector<xr_string>;
using U16Vec = xr_vector<u16>;
using U32Vec = xr_vector<u32>;
using FloatVec = xr_vector<float>;
using IntVec = xr_vector<int>;

template <typename T>
using xr_box = std::unique_ptr<T>;

template <typename T>
using xr_arc = std::shared_ptr<T>;

template <typename T, typename... Args>
xr_box<T> xr_new_box(Args&&... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
xr_arc<T> xr_new_arc(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

#endif