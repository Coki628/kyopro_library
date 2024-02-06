#pragma once
#include "../base.hpp"

// 動的ModInt
// 参考：https://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp
// ・DynamicModInt::set_mod(mod) のようにstaticメソッドでMODをセットして使う。
// ・idを振って同じコード内で複数MODを作れるようにした。
template<int id = 1>
struct DynamicModInt {
    int x = 0;

    DynamicModInt() : x(0) {}

    DynamicModInt(int64_t y)
        : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

    // 大きい数字文字列からのmint変換
    // see: https://atcoder.jp/contests/abc339/editorial/9206
    DynamicModInt(string s) {
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

    DynamicModInt &operator++() {
        x++;
        if (x == get_mod()) x = 0;
        return *this;
    }

    DynamicModInt &operator--() {
        if (x == 0) x = get_mod();
        x--;
        return *this;
    }

    DynamicModInt &operator+=(const DynamicModInt &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    DynamicModInt &operator-=(const DynamicModInt &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    DynamicModInt &operator*=(const DynamicModInt &p) {
        x = (int)(1LL * x * p.x % get_mod());
        return *this;
    }

    DynamicModInt &operator/=(const DynamicModInt &p) {
        *this *= p.inv();
        return *this;
    }

    DynamicModInt operator++(int) {
        DynamicModInt result = *this;
        ++*this;
        return result;
    }

    DynamicModInt operator--(int) {
        DynamicModInt result = *this;
        --*this;
        return result;
    }

    DynamicModInt operator-() const {
        return DynamicModInt(-x);
    }

    DynamicModInt operator+(const DynamicModInt &p) const {
        return DynamicModInt(*this) += p;
    }

    DynamicModInt operator-(const DynamicModInt &p) const {
        return DynamicModInt(*this) -= p;
    }

    DynamicModInt operator*(const DynamicModInt &p) const {
        return DynamicModInt(*this) *= p;
    }

    DynamicModInt operator/(const DynamicModInt &p) const {
        return DynamicModInt(*this) /= p;
    }

    bool operator==(const DynamicModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const DynamicModInt &p) const {
        return x != p.x;
    }

    // ※ModIntの大小比較に意味はないけど、これ作っとくとmapのキーに使えるようになる
    bool operator<(const DynamicModInt &p) const {
        return x < p.x;
    }

    DynamicModInt inv() const {
        int a = x, b = get_mod(), u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return DynamicModInt(u);
    }

    DynamicModInt pow(int64_t n) const {
        DynamicModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const DynamicModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, DynamicModInt &a) {
        int64_t t;
        is >> t;
        a = DynamicModInt<id>(t);
        return (is);
    }

    explicit operator int() const {
        return x;
    }
    explicit operator ll() const {
        return x;
    }
};
// using mint = DynamicModInt;
