#pragma once
#include "../base.hpp"
#include "gcd.hpp"
#include "lcm.hpp"

template<typename T>
struct Fraction {
    T numerator, denominator;

    Fraction() : numerator((T)1), denominator((T)1) {}

    Fraction(T nu) : numerator(nu), denominator((T)1) {}

    Fraction(T nu, T de) : numerator(nu), denominator(de) {
        assert(de != (T)0);
        // マイナスを分子側に
        if (de < (T)0) {
            numerator *= -1;
            denominator *= -1;
        }
        simplify();
    }

    Fraction(const Fraction<T> &a)
        : numerator(a.numerator),
          denominator(a.denominator) {
        assert(a.denominator != (T)0);
    }

    // 通分
    void reduce(Fraction<T> &a) {
        T l = lcm(denominator, a.denominator);
        numerator = l / denominator * numerator;
        a.numerator = l / a.denominator * a.numerator;
        denominator = a.denominator = l;
    }

    // 約分
    void simplify() {
        if (denominator == (T)1) return;
        assert(denominator >= 1);
        // gcdやる時は正数に(in128でabsが動かなかったので三項演算子)
        T g = gcd(numerator >= 0 ? numerator : -numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    Fraction<T> &operator+=(Fraction<T> a) {
        // reduce(a);
        // numerator += a.numerator;
        numerator = numerator * a.denominator + a.numerator * denominator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator-=(Fraction<T> a) {
        // reduce(a);
        // numerator -= a.numerator;
        numerator = numerator * a.denominator - a.numerator * denominator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator*=(const Fraction<T> &a) {
        numerator *= a.numerator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator/=(const Fraction<T> &a) {
        assert(a.numerator != (T)0);
        numerator *= a.denominator;
        denominator *= a.numerator;
        // マイナスを分子側に
        if (a.numerator < (T)0) {
            numerator *= -1;
            denominator *= -1;
        }
        simplify();
        return *this;
    }

    Fraction<T> &operator++() {
        *this += 1;
        return *this;
    }

    Fraction<T> &operator--() {
        *this -= 1;
        return *this;
    }

    Fraction<T> operator++(int) {
        Fraction<T> result = *this;
        ++*this;
        return result;
    }

    Fraction<T> operator--(int) {
        Fraction<T> result = *this;
        --*this;
        return result;
    }

    Fraction<T> operator-() const {
        return {-numerator, denominator};
    }

    Fraction<T> operator+(const Fraction<T> &a) const {
        return Fraction<T>(*this) += a;
    }

    Fraction<T> operator-(const Fraction<T> &a) const {
        return Fraction<T>(*this) -= a;
    }

    Fraction<T> operator*(const Fraction<T> &a) const {
        return Fraction<T>(*this) *= a;
    }

    Fraction<T> operator/(const Fraction<T> &a) const {
        return Fraction<T>(*this) /= a;
    }

    bool operator==(const Fraction<T> &a) const {
        return numerator == a.numerator and denominator == a.denominator;
    }

    bool operator!=(const Fraction<T> &a) const {
        return numerator != a.numerator or denominator != a.denominator;
    }

    bool operator<(const Fraction<T> &a) const {
        return numerator * a.denominator < a.numerator * denominator;
    }

    bool operator<=(const Fraction<T> &a) const {
        return numerator * a.denominator <= a.numerator * denominator;
    }

    bool operator>(const Fraction<T> &a) const {
        return numerator * a.denominator > a.numerator * denominator;
    }

    bool operator>=(const Fraction<T> &a) const {
        return numerator * a.denominator >= a.numerator * denominator;
    }

    friend istream &operator>>(istream &is, Fraction<T> &a) {
        is >> a.numerator;
        a.denominator = 1;
        return (is);
    }

    friend ostream &operator<<(ostream &os, const Fraction<T> &a) {
        return os << a.numerator << "/" << a.denominator;
    }
};
