#pragma once
#include "base.hpp"

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
template<typename T>
using vv = vector<vector<T>>;
using vvl = vv<ll>;
using vvi = vv<int>;
using vvpll = vv<pll>;
using vvpli = vv<pli>;
using vvpil = vv<pil>;
#define name4(i, a, b, c, d, e, ...) e
#define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(i, a) for (ll i = 0, _aa = a; i < _aa; i++)
#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)
#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)
#define rrep(i, a, b) for (ll i=(a); i>(b); i--)
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define ALL(A) begin(A), end(A)
#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)), A.end())
#define elif else if
#define tostr to_string

#ifndef CONSTANTS
    constexpr ll INF = 1e18;
    constexpr int MOD = 1000000007;
    constexpr ld EPS = 1e-10;
    constexpr ld PI = M_PI;
#endif
