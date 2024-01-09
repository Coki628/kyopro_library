#pragma once
#include "../macros.hpp"

template<ull mod>
struct ModInt64 {
    ull x = 0;
    using uint128_t = __uint128_t;

    ModInt64() : x(0) {}

    ModInt64(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt64 &operator++() {
        x++;
        if (x == mod) x = 0;
        return *this;
    }

    ModInt64 &operator--() {
        if (x == 0) x = mod;
        x--;
        return *this;
    }

    ModInt64 &operator+=(const ModInt64 &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt64 &operator-=(const ModInt64 &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt64 &operator*=(const ModInt64 &p) {
        x = (ull)((uint128_t)1 * x * p.x % mod);
        return *this;
    }

    ModInt64 &operator/=(const ModInt64 &p) {
        *this *= p.inv();
        return *this;
    }

    ModInt64 operator++(int) {
        ModInt64 result = *this;
        ++*this;
        return result;
    }

    ModInt64 operator--(int) {
        ModInt64 result = *this;
        --*this;
        return result;
    }

    ModInt64 operator-() const {
        return ModInt64(-x);
    }

    ModInt64 operator+(const ModInt64 &p) const {
        return ModInt64(*this) += p;
    }

    ModInt64 operator-(const ModInt64 &p) const {
        return ModInt64(*this) -= p;
    }

    ModInt64 operator*(const ModInt64 &p) const {
        return ModInt64(*this) *= p;
    }

    ModInt64 operator/(const ModInt64 &p) const {
        return ModInt64(*this) /= p;
    }

    bool operator==(const ModInt64 &p) const {
        return x == p.x;
    }

    bool operator!=(const ModInt64 &p) const {
        return x != p.x;
    }

    // ※ModIntの大小比較に意味はないけど、これ作っとくとmapのキーに使えるようになる
    bool operator<(const ModInt64 &p) const {
        return x < p.x;
    }

    ModInt64 inv() const {
        ull a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt64(u);
    }

    ModInt64 pow(int64_t n) const {
        ModInt64 ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt64 &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt64 &a) {
        ull t;
        is >> t;
        a = ModInt64<mod>(t);
        return (is);
    }

    static ull get_mod() {
        return mod;
    }

    explicit operator ull() const {
        return x;
    }
};
