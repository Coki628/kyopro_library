#pragma once
#include "../macros.hpp"

// 任意ModInt64ビット版
template<int id = 1>
struct ArbitraryModInt64 {
    ull x = 0;
    using uint128_t = __uint128_t;

    ArbitraryModInt64() : x(0) {}

    ArbitraryModInt64(int64_t y)
        : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

    // 大きい数字文字列からのmint変換
    // see: https://atcoder.jp/contests/abc339/editorial/9206
    ArbitraryModInt64(string s) {
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

    ArbitraryModInt64 &operator++() {
        x++;
        if (x == get_mod()) x = 0;
        return *this;
    }

    ArbitraryModInt64 &operator--() {
        if (x == 0) x = get_mod();
        x--;
        return *this;
    }

    ArbitraryModInt64 &operator+=(const ArbitraryModInt64 &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ArbitraryModInt64 &operator-=(const ArbitraryModInt64 &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ArbitraryModInt64 &operator*=(const ArbitraryModInt64 &p) {
        x = (ull)((uint128_t)1 * x * p.x % get_mod());
        return *this;
    }

    ArbitraryModInt64 &operator/=(const ArbitraryModInt64 &p) {
        *this *= p.inv();
        return *this;
    }

    ArbitraryModInt64 operator++(int) {
        ArbitraryModInt64 result = *this;
        ++*this;
        return result;
    }

    ArbitraryModInt64 operator--(int) {
        ArbitraryModInt64 result = *this;
        --*this;
        return result;
    }

    ArbitraryModInt64 operator-() const {
        return ArbitraryModInt64(-x);
    }

    ArbitraryModInt64 operator+(const ArbitraryModInt64 &p) const {
        return ArbitraryModInt64(*this) += p;
    }

    ArbitraryModInt64 operator-(const ArbitraryModInt64 &p) const {
        return ArbitraryModInt64(*this) -= p;
    }

    ArbitraryModInt64 operator*(const ArbitraryModInt64 &p) const {
        return ArbitraryModInt64(*this) *= p;
    }

    ArbitraryModInt64 operator/(const ArbitraryModInt64 &p) const {
        return ArbitraryModInt64(*this) /= p;
    }

    bool operator==(const ArbitraryModInt64 &p) const {
        return x == p.x;
    }

    bool operator!=(const ArbitraryModInt64 &p) const {
        return x != p.x;
    }

    // ※ModIntの大小比較に意味はないけど、これ作っとくとmapのキーに使えるようになる
    bool operator<(const ArbitraryModInt64 &p) const {
        return x < p.x;
    }

    ArbitraryModInt64 inv() const {
        ull a = x, b = get_mod(), u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ArbitraryModInt64(u);
    }

    ArbitraryModInt64 pow(int64_t n) const {
        ArbitraryModInt64 ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ArbitraryModInt64 &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ArbitraryModInt64 &a) {
        int64_t t;
        is >> t;
        a = ArbitraryModInt64<id>(t);
        return (is);
    }

    explicit operator ull() const {
        return x;
    }
};
