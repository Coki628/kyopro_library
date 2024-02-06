#pragma once
#include "../macros.hpp"

// 動的ModInt64ビット版
template<int id = 1>
struct DynamicModInt64 {
    ull x = 0;
    using uint128_t = __uint128_t;

    DynamicModInt64() : x(0) {}

    DynamicModInt64(int64_t y)
        : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

    // 大きい数字文字列からのmint変換
    // see: https://atcoder.jp/contests/abc339/editorial/9206
    DynamicModInt64(string s) {
        uint128_t res = 0;
        for(auto &c : s){
            assert(isdigit(c));
            int d = c - '0';
            res = (res * 10 + d) % get_mod();
        }
        x = res;
    }

    static ull &get_mod() {
        static ull mod = 0;
        return mod;
    }

    static void set_mod(ull md) {
        get_mod() = md;
    }

    DynamicModInt64 &operator++() {
        x++;
        if (x == get_mod()) x = 0;
        return *this;
    }

    DynamicModInt64 &operator--() {
        if (x == 0) x = get_mod();
        x--;
        return *this;
    }

    DynamicModInt64 &operator+=(const DynamicModInt64 &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    DynamicModInt64 &operator-=(const DynamicModInt64 &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    DynamicModInt64 &operator*=(const DynamicModInt64 &p) {
        x = (ull)((uint128_t)1 * x * p.x % get_mod());
        return *this;
    }

    DynamicModInt64 &operator/=(const DynamicModInt64 &p) {
        *this *= p.inv();
        return *this;
    }

    DynamicModInt64 operator++(int) {
        DynamicModInt64 result = *this;
        ++*this;
        return result;
    }

    DynamicModInt64 operator--(int) {
        DynamicModInt64 result = *this;
        --*this;
        return result;
    }

    DynamicModInt64 operator-() const {
        return DynamicModInt64(-x);
    }

    DynamicModInt64 operator+(const DynamicModInt64 &p) const {
        return DynamicModInt64(*this) += p;
    }

    DynamicModInt64 operator-(const DynamicModInt64 &p) const {
        return DynamicModInt64(*this) -= p;
    }

    DynamicModInt64 operator*(const DynamicModInt64 &p) const {
        return DynamicModInt64(*this) *= p;
    }

    DynamicModInt64 operator/(const DynamicModInt64 &p) const {
        return DynamicModInt64(*this) /= p;
    }

    bool operator==(const DynamicModInt64 &p) const {
        return x == p.x;
    }

    bool operator!=(const DynamicModInt64 &p) const {
        return x != p.x;
    }

    // ※ModIntの大小比較に意味はないけど、これ作っとくとmapのキーに使えるようになる
    bool operator<(const DynamicModInt64 &p) const {
        return x < p.x;
    }

    DynamicModInt64 inv() const {
        ull a = x, b = get_mod(), u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return DynamicModInt64(u);
    }

    DynamicModInt64 pow(int64_t n) const {
        DynamicModInt64 ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const DynamicModInt64 &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, DynamicModInt64 &a) {
        int64_t t;
        is >> t;
        a = DynamicModInt64<id>(t);
        return (is);
    }

    explicit operator ull() const {
        return x;
    }
};
