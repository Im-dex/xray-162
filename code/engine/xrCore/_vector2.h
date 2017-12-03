#pragma once

template <class T>
struct _vector2 {
    typedef T TYPE;
    typedef _vector2<T> Self;
    typedef Self& SelfRef;
    typedef const Self& SelfCRef;

    T x, y;

    SelfRef set(float _u, float _v) {
        x = T(_u);
        y = T(_v);
        return *this;
    }
    SelfRef set(double _u, double _v) {
        x = T(_u);
        y = T(_v);
        return *this;
    }
    SelfRef set(int _u, int _v) {
        x = T(_u);
        y = T(_v);
        return *this;
    }
    SelfRef set(const Self& p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    SelfRef abs(const Self& p) {
        x = xr::abs(p.x);
        y = xr::abs(p.y);
        return *this;
    }
    SelfRef min(const Self& p) {
        x = std::min(x, p.x);
        y = std::min(y, p.y);
        return *this;
    }
    SelfRef min(T _x, T _y) {
        x = std::min(x, _x);
        y = std::min(y, _y);
        return *this;
    }
    SelfRef max(const Self& p) {
        x = std::max(x, p.x);
        y = std::max(y, p.y);
        return *this;
    }
    SelfRef max(T _x, T _y) {
        x = std::max(x, _x);
        y = std::max(y, _y);
        return *this;
    }
    SelfRef sub(const T p) {
        x -= p;
        y -= p;
        return *this;
    }
    SelfRef sub(const Self& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    SelfRef sub(const Self& p1, const Self& p2) {
        x = p1.x - p2.x;
        y = p1.y - p2.y;
        return *this;
    }
    SelfRef sub(const Self& p, float d) {
        x = p.x - d;
        y = p.y - d;
        return *this;
    }
    SelfRef add(const T p) {
        x += p;
        y += p;
        return *this;
    }
    SelfRef add(const Self& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    SelfRef add(const Self& p1, const Self& p2) {
        x = p1.x + p2.x;
        y = p1.y + p2.y;
        return *this;
    }
    SelfRef add(const Self& p, float d) {
        x = p.x + d;
        y = p.y + d;
        return *this;
    }
    SelfRef mul(const T s) {
        x *= s;
        y *= s;
        return *this;
    }
    SelfRef mul(const Self& p) {
        x *= p.x;
        y *= p.y;
        return *this;
    }
    SelfRef div(const T s) {
        x /= s;
        y /= s;
        return *this;
    }
    SelfRef div(const Self& p) {
        x /= p.x;
        y /= p.y;
        return *this;
    }
    SelfRef rot90() {
        float t = -x;
        x = y;
        y = t;
        return *this;
    }
    SelfRef cross(const Self& D) {
        x = D.y;
        y = -D.x;
        return *this;
    }
    T dot(Self& p) const { return x * p.x + y * p.y; }
    T dot(const Self& p) const { return x * p.x + y * p.y; }
    SelfRef norm() {
        float m = std::sqrt(x * x + y * y);
        x /= m;
        y /= m;
        return *this;
    }
    SelfRef norm_safe() {
        float m = std::sqrt(x * x + y * y);
        if (m) {
            x /= m;
            y /= m;
        }
        return *this;
    }
    T distance_to(const Self& p) const {
        return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    T square_magnitude() const { return x * x + y * y; }
    T magnitude() const { return std::sqrt(square_magnitude()); }

    SelfRef mad(const Self& p, const Self& d, T r) {
        x = p.x + d.x * r;
        y = p.y + d.y * r;
        return *this;
    }
    Self Cross() {
        // vector3 orthogonal to (x,y) is (y,-x)
        Self kCross;
        kCross.x = y;
        kCross.y = -x;
        return kCross;
    }

    bool similar(Self& p, T eu, T ev) const { return xr::abs(x - p.x) < eu && xr::abs(y - p.y) < ev; }

    bool similar(const Self& p, float E = EPS_L) const {
        return xr::abs(x - p.x) < E && xr::abs(y - p.y) < E;
    }

    // average arithmetic
    SelfRef averageA(Self& p1, Self& p2) {
        x = (p1.x + p2.x) * .5f;
        y = (p1.y + p2.y) * .5f;
        return *this;
    }
    // average geometric
    SelfRef averageG(Self& p1, Self& p2) {
        x = std::sqrt(p1.x * p2.x);
        y = std::sqrt(p1.y * p2.y);
        return *this;
    }

    T& operator[](int i) const {
        // assert:  0 <= i < 2; x and y are packed into 2*sizeof(float) bytes
        return (T&)*(&x + i);
    }

    SelfRef normalize() { return norm(); }
    SelfRef normalize_safe() { return norm_safe(); }
    SelfRef normalize(const Self& v) {
        const float m = std::sqrt(v.x * v.x + v.y * v.y);
        x = v.x / m;
        y = v.y / m;
        return *this;
    }
    SelfRef normalize_safe(const Self& v) {
        const float m = std::sqrt(v.x * v.x + v.y * v.y);
        if (m) {
            x = v.x / m;
            y = v.y / m;
        }
        return *this;
    }
    float dotproduct(const Self& p) const { return dot(p); }
    float crossproduct(const Self& p) const { return y * p.x - x * p.y; }
    float getH() const {
        if (fis_zero(y))
            if (fis_zero(x))
                return 0.f;
            else
                return ((x > 0.0f) ? -PI_DIV_2 : PI_DIV_2);
        else if (y < 0.f)
            return (-(std::atan(x / y) - PI));
        else
            return (-std::atan(x / y));
    }
};

typedef _vector2<float> Fvector2;
typedef _vector2<double> Dvector2;
typedef _vector2<int> Ivector2;

namespace xr {

template <class T>
bool valid(const _vector2<T>& v) {
    return valid(v.x) && valid(v.y);
}

} // xr namespace
