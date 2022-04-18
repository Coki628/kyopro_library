#include "../base.hpp"
#include "gcd.hpp"
#include "lcm.hpp"

template<typename T>
struct Fraction {
    T numerator, denominator;

    Fraction() : numerator((T)1), denominator((T)1) {}

    Fraction(T nu) : numerator(nu), denominator((T)1) {}

    Fraction(T nu, T de) : numerator(nu), denominator(de) {
        assert(de != 0);
    }

    Fraction(const Fraction<T> &a) : numerator(a.numerator), denominator(a.denominator) {
        assert(a.denominator != 0);
    }

    // 通分
    void reduce(Fraction<T>& a) {
        T l = lcm(denominator, a.denominator);
        numerator = l / denominator * numerator;
        a.numerator = l / a.denominator * a.numerator;
        denominator = a.denominator = l;
    }

    // 約分
    void simplify() {
        if (denominator == (T)1) return;
        T g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    Fraction<T> &operator+=(Fraction<T> a) {
        // reduce(a);
        // numerator += a.numerator;
        numerator = numerator*a.denominator + a.numerator*denominator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator-=(Fraction<T> a) {
        // reduce(a);
        // numerator -= a.numerator;
        numerator = numerator*a.denominator - a.numerator*denominator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator*=(const Fraction<T>& a) {
        numerator *= a.numerator;
        denominator *= a.denominator;
        simplify();
        return *this;
    }

    Fraction<T> &operator/=(const Fraction<T>& a) {
        assert(a.numerator != (T)0);
        numerator *= a.denominator;
        denominator *= a.numerator;
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

    Fraction<T> operator-() const { return {-numerator, denominator}; }

    Fraction<T> operator+(const Fraction<T>& a) const { return Fraction<T>(*this) += a; }

    Fraction<T> operator-(const Fraction<T>& a) const { return Fraction<T>(*this) -= a; }

    Fraction<T> operator*(const Fraction<T>& a) const { return Fraction<T>(*this) *= a; }

    Fraction<T> operator/(const Fraction<T>& a) const { return Fraction<T>(*this) /= a; }

    bool operator==(const Fraction<T>& a) const {
        return numerator == a.numerator and denominator == a.denominator;
    }

    bool operator!=(const Fraction<T>& a) const {
        return numerator != a.numerator or denominator != a.denominator;
    }

    bool operator<(const Fraction<T>& a) const {
        return numerator*a.denominator < a.numerator*denominator;
    }

    friend ostream& operator<<(ostream& os, const Fraction<T>& a) {
        return os << a.numerator << "/" << a.denominator;
    }
};
