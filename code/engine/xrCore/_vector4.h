#pragma once

template <class T>
struct _vector4 {
    typedef T TYPE;
    typedef _vector4<T> Self;
    typedef Self& SelfRef;
    typedef const Self& SelfCRef;

    T x, y, z, w;

    T& operator[](int i) { return *((T*)this + i); }
    T& operator[](int i) const { return *((T*)this + i); }

    SelfRef set(T _x, T _y, T _z, T _w = 1) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
        return *this;
    }
    SelfRef set(const Self& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    SelfRef add(const Self& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
    SelfRef add(T s) {
        x += s;
        y += s;
        z += s;
        w += s;
        return *this;
    }
    SelfRef add(const Self& a, const Self& v) {
        x = a.x + v.x;
        y = a.y + v.y;
        z = a.z + v.z;
        w = a.w + v.w;
        return *this;
    }
    SelfRef add(const Self& a, T s) {
        x = a.x + s;
        y = a.y + s;
        z = a.z + s;
        w = a.w + s;
        return *this;
    }

    SelfRef sub(T _x, T _y, T _z, T _w = 1) {
        x -= _x;
        y -= _y;
        z -= _z;
        w -= _w;
        return *this;
    }
    SelfRef sub(const Self& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }
    SelfRef sub(T s) {
        x -= s;
        y -= s;
        z -= s;
        w -= s;
        return *this;
    }
    SelfRef sub(const Self& a, const Self& v) {
        x = a.x - v.x;
        y = a.y - v.y;
        z = a.z - v.z;
        w = a.w - v.w;
        return *this;
    }
    SelfRef sub(const Self& a, T s) {
        x = a.x - s;
        y = a.y - s;
        z = a.z - s;
        w = a.w - s;
        return *this;
    }

    SelfRef mul(T _x, T _y, T _z, T _w = 1) {
        x *= _x;
        y *= _y;
        z *= _z;
        w *= _w;
        return *this;
    }
    SelfRef mul(const Self& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
        return *this;
    }
    SelfRef mul(T s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    SelfRef mul(const Self& a, const Self& v) {
        x = a.x * v.x;
        y = a.y * v.y;
        z = a.z * v.z;
        w = a.w * v.w;
        return *this;
    }
    SelfRef mul(const Self& a, T s) {
        x = a.x * s;
        y = a.y * s;
        z = a.z * s;
        w = a.w * s;
        return *this;
    }

    SelfRef div(const Self& v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        w /= v.w;
        return *this;
    }
    SelfRef div(T s) {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }
    SelfRef div(const Self& a, const Self& v) {
        x = a.x / v.x;
        y = a.y / v.y;
        z = a.z / v.z;
        w = a.w / v.w;
        return *this;
    }
    SelfRef div(const Self& a, T s) {
        x = a.x / s;
        y = a.y / s;
        z = a.z / s;
        w = a.w / s;
        return *this;
    }

    BOOL similar(const Self& v, T E = EPS_L) {
        return xr::abs(x - v.x) < E && xr::abs(y - v.y) < E && xr::abs(z - v.z) < E && xr::abs(w - v.w) < E;
    }

    T magnitude_sqr() const { return x * x + y * y + z * z + w * w; }
    T magnitude() const { return std::sqrt(magnitude_sqr()); }
    SelfRef normalize() { return mul(1 / magnitude()); }

    SelfRef normalize_as_plane() { return mul(1 / std::sqrt(x * x + y * y + z * z)); }

    SelfRef lerp(const Self& p1, const Self& p2, T t) {
        T invt = 1.f - t;
        x = p1.x * invt + p2.x * t;
        y = p1.y * invt + p2.y * t;
        z = p1.z * invt + p2.z * t;
        w = p1.w * invt + p2.w * t;
        return *this;
    }
};

typedef _vector4<float> Fvector4;
typedef _vector4<double> Dvector4;
typedef _vector4<s32> Ivector4;

typedef __declspec(align(16)) _vector4<float> Fvector4a;
typedef __declspec(align(16)) _vector4<double> Dvector4a;
typedef __declspec(align(16)) _vector4<s32> Ivector4a;

namespace xr {

template <class T>
bool valid(const _vector4<T>& v) {
    return valid(v.x) && valid(v.y) && valid(v.z) && valid(v.w);
}

} // xr namespace
