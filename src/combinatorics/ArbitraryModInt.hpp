#pragma once
#include "../base.hpp"

// 任意ModInt
// 参考：https://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp
// ・ArbitraryModInt::set_mod(mod) のようにstaticメソッドでMODをセットして使う。
// ・idを振って同じコード内で複数MODを作れるようにした。
template<int id = 1>
struct ArbitraryModInt {
    int x = 0;

    ArbitraryModInt() : x(0) {}

    ArbitraryModInt(int64_t y)
        : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

    // 大きい数字文字列からのmint変換
    // see: https://atcoder.jp/contests/abc339/editorial/9206
    ArbitraryModInt(string s) {
        auto res = 0LL;
        for(auto &c : s){
            assert(isdigit(c));
            int d = c - '0';
            res = (res * 10 + d) % get_mod();
        }
        x = res;
    }

    static int &get_mod() {
        static int mod = 0;
        return mod;
    }

    static void set_mod(int md) {
        get_mod() = md;
    }

    ArbitraryModInt &operator++() {
        x++;
        if (x == get_mod()) x = 0;
        return *this;
    }

    ArbitraryModInt &operator--() {
        if (x == 0) x = get_mod();
        x--;
        return *this;
    }

    ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
        x = (int)(1LL * x * p.x % get_mod());
        return *this;
    }

    ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
        *this *= p.inv();
        return *this;
    }

    ArbitraryModInt operator++(int) {
        ArbitraryModInt result = *this;
        ++*this;
        return result;
    }

    ArbitraryModInt operator--(int) {
        ArbitraryModInt result = *this;
        --*this;
        return result;
    }

    ArbitraryModInt operator-() const {
        return ArbitraryModInt(-x);
    }

    ArbitraryModInt operator+(const ArbitraryModInt &p) const {
        return ArbitraryModInt(*this) += p;
    }

    ArbitraryModInt operator-(const ArbitraryModInt &p) const {
        return ArbitraryModInt(*this) -= p;
    }

    ArbitraryModInt operator*(const ArbitraryModInt &p) const {
        return ArbitraryModInt(*this) *= p;
    }

    ArbitraryModInt operator/(const ArbitraryModInt &p) const {
        return ArbitraryModInt(*this) /= p;
    }

    bool operator==(const ArbitraryModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const ArbitraryModInt &p) const {
        return x != p.x;
    }

    // ※ModIntの大小比較に意味はないけど、これ作っとくとmapのキーに使えるようになる
    bool operator<(const ArbitraryModInt &p) const {
        return x < p.x;
    }

    ArbitraryModInt inv() const {
        int a = x, b = get_mod(), u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ArbitraryModInt(u);
    }

    ArbitraryModInt pow(int64_t n) const {
        ArbitraryModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ArbitraryModInt &a) {
        int64_t t;
        is >> t;
        a = ArbitraryModInt<id>(t);
        return (is);
    }

    explicit operator int() const {
        return x;
    }
    explicit operator ll() const {
        return x;
    }
};
// using mint = ArbitraryModInt;
