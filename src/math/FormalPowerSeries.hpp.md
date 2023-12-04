---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/math/ArbitraryModConvolution.hpp
    title: src/math/ArbitraryModConvolution.hpp
  - icon: ':warning:'
    path: src/math/FastFourierTransform.hpp
    title: src/math/FastFourierTransform.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/fps/pow.hpp
    title: src/math/fps/pow.hpp
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/math/fps/formal-power-series.hpp
    - https://judge.yosupo.jp/problem/convolution_mod
    - https://judge.yosupo.jp/problem/division_of_polynomials
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    - https://yukicoder.me/problems/no/215
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/print.hpp\"\
    \n\n// pair\ntemplate<typename T1, typename T2>\nostream &operator<<(ostream &os,\
    \ const pair<T1, T2> &p) {\n    return os << p.first << ' ' << p.second;\n}\n\n\
    // tuple\n// see: https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150\n\
    template<class T, size_t... Is>\nvoid print_tuple(ostream &os, const T &arg, index_sequence<Is...>)\
    \ {\n    static_cast<void>(((os << (Is == 0 ? \"\" : \" \"), os << get<Is>(arg)),\
    \ ...));\n}\ntemplate<class... Ts>\nostream &operator<<(ostream &os, const tuple<Ts...>\
    \ &arg) {\n    print_tuple(os, arg, make_index_sequence<sizeof...(Ts)>());\n \
    \   return os;\n}\n\n// \u65E7\u4ED5\u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\
    \u308B\u7A0B\u5EA6\u52D5\u4F5C\u554F\u984C\u306A\u3044\u78BA\u8A8D\u304C\u53D6\
    \u308C\u305F\u3089\u524A\u9664\n// template<typename T1, typename T2, typename\
    \ T3>\n// ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {\n//\
    \     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n// }\n\
    // template<typename T1, typename T2, typename T3, typename T4>\n// ostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n//     return os << get<0>(tp) << '\
    \ ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n// }\n// template<typename\
    \ T1, typename T2, typename T3>\n// void print(const tuple<T1, T2, T3> &tp) {\n\
    //     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\\n';\n\
    // }\n// template<typename T1, typename T2, typename T3, typename T4>\n// void\
    \ print(const tuple<T1, T2, T3, T4> &tp) {\n//     cout << get<0>(tp) << ' ' <<\
    \ get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n// }\n\n// vector\n\
    template<typename T>\nostream &operator<<(ostream &os, const vector<T> &vec) {\n\
    \    rep(i, vec.size()) {\n        os << vec[i];\n        if (i != (int)vec.size()\
    \ - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n}\ntemplate<typename\
    \ T>\nvoid print(const vector<T> &vec, string sep = \" \") {\n    rep(i, vec.size())\
    \ {\n        cout << vec[i];\n        if (i != (int)vec.size() - 1) cout << sep;\n\
    \    }\n    cout << '\\n';\n}\n\n// array\ntemplate<typename T, size_t N>\nostream\
    \ &operator<<(ostream &os, const array<T, N> &arr) {\n    rep(i, N) {\n      \
    \  os << arr[i];\n        if (i != (int)N - 1) {\n            os << ' ';\n   \
    \     }\n    }\n    return os;\n}\ntemplate<typename T, size_t N>\nvoid print(const\
    \ array<T, N> &arr, string sep = \" \") {\n    rep(i, N) {\n        cout << arr[i];\n\
    \        if (i != (int)N - 1) cout << sep;\n    }\n    cout << '\\n';\n}\n\n//\
    \ deque\ntemplate<typename T>\nvoid print(const deque<T> &que, string sep = \"\
    \ \") {\n    vector<T> vec(ALL(que));\n    print(vec, sep);\n}\n\n// set\ntemplate<typename\
    \ T>\nvoid print(const set<T> &se, string sep = \" \") {\n    vector<T> vec(ALL(se));\n\
    \    print(vec, sep);\n}\n\n// set, multiset, deque, etc...\n// \u203B\u3068\u3066\
    \u3082\u6C4E\u7528\u6027\u9AD8\u3044\u3093\u3060\u3051\u3069\u3001string\u307E\
    \u3067\u53D6\u308A\u8FBC\u307E\u308C\u3066vector\u306B\u3055\u308C\u3066\u3057\
    \u307E\u3046\u306E\u3067\u4F7F\u308F\u306A\u3044\n// template<template<typename\
    \ T>class Container, typename T>\n// void print(const Container<T>& con, string\
    \ sep=\" \") {\n//     vector<T> V(ALL(con));\n//     print(V, sep);\n// }\n\n\
    // initializer_list (\u300Cprint({1, 2, 3, 4});\u300D\u3068\u304B\u3067\u304D\u308B\
    )\ntemplate<typename T>\nvoid print(const initializer_list<T> &li, string sep\
    \ = \" \") {\n    vector<T> V(ALL(li));\n    print(V, sep);\n}\n\n// \u53EF\u5909\
    \u9577\u5F15\u6570\u3002operator<<\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3055\u3048\
    \u3044\u308C\u3070\u3001\u578B\u304C\u9055\u3046\u540C\u58EB\u3067\u3082\u96D1\
    \u591A\u306B\u4E26\u3079\u3066\u51FA\u529B\u3067\u304D\u308B\n// \u203Bprint(vector,\
    \ \"\\n\")\u3068\u304B\u3082\u3053\u3053\u306B\u6765\u3066\u3057\u307E\u3063\u305F\
    \u306E\u3067\u4E00\u65E6\u4E2D\u6B62\n// template<typename T, typename... Ts>\n\
    // void print(const T val, Ts... ts) {\n//     if constexpr (sizeof...(Ts) ==\
    \ 0) {\n//         cout << val << '\\n';\n//     } else {\n//         cout <<\
    \ val << ' ';\n//         print(ts...);\n//     }\n// }\n\n// \u6539\u884C\u306E\
    \u307F\nvoid print() {\n    cout << '\\n';\n}\n\n// \u305D\u306E\u4ED6 (pair,tuple,string\u7B49\
    \u3082\u3053\u3053\u306B\u6765\u3066operator<<\u306B\u6E21\u3055\u308C\u308B)\n\
    template<typename T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\n//\
    \ debug (\u5909\u6570\u540D\u4ED8\u304D\u3067\u51FA\u529B\u3001stderr\u306A\u306E\
    \u3067\u63D0\u51FA\u3092\u90AA\u9B54\u3057\u306A\u3044)\n// #define debug(x) (cerr\
    \ << #x << \": \" << x << endl);\n// \u53EF\u5909\u9577\u5F15\u6570\u5BFE\u5FDC\
    \u7248\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n#define debug(...)\
    \ multi_debug(#__VA_ARGS__, __VA_ARGS__)\ntemplate<class Tp, class... Ts>\nvoid\
    \ multi_debug(string names, Tp arg, Ts... args) {\n    // args...\u306E\u30D1\u30E9\
    \u30E1\u30FC\u30BF\u304C0\u500B\u306E\u3068\u304D\u3001\u5358\u306Barg\u3060\u3051\
    \u3092\u51FA\u529B\u3057\u3066\u7D42\u4E86\n    if constexpr (sizeof...(Ts) ==\
    \ 0) {\n        while (names.back() == ' ') {\n            names.pop_back();\n\
    \        }\n        cerr << names << \": \" << arg << endl;\n    } else {\n  \
    \      // names\u306B\u306F\u5168\u90E8\u306E\u5909\u6570\u306E\u540D\u524D\u304C\
    \u683C\u7D0D\u3055\u308C\u3066\u3044\u308B\u306E\u3067\u30011\u3064\u76EE\u306E\
    \u5909\u6570\u540D\u306E\u7D42\u308F\u308A\u306E','\u306E\u4F4D\u7F6E\u3092\u63A2\
    \u3059\n        int n = names.size(), comma_pos = -1, paren_depth = 0,\n     \
    \       inside_quote = false;\n        rep(i, n) {\n            if (not inside_quote\
    \ and paren_depth == 0 and names[i] == ',') {\n                comma_pos = i;\n\
    \                break;\n            }\n            if (names[i] == '\\\"' or\
    \ names[i] == '\\'') {\n                if (i > 0 and names[i - 1] == '\\\\')\
    \ continue;\n                inside_quote ^= true;\n            }\n          \
    \  if (not inside_quote and names[i] == '(') {\n                paren_depth++;\n\
    \            }\n            if (not inside_quote and names[i] == ')') {\n    \
    \            paren_depth--;\n            }\n        }\n        assert(comma_pos\
    \ != -1);\n        string name = names.substr(0, comma_pos);\n        while (name.back()\
    \ == ' ') {\n            name.pop_back();\n        }\n        cerr << name <<\
    \ \": \" << arg << endl;\n\n        int next_begin_at = comma_pos + 1;\n     \
    \   while (names[next_begin_at] == ' ') {\n            next_begin_at++;\n    \
    \    }\n        names = names.substr(next_begin_at);\n        // \u3053\u306E\u95A2\
    \u6570\u3092\u518D\u5E30\u7684\u306B\u547C\u3093\u3067\u6B8B\u308A\u306E\u5909\
    \u6570\u3082\u51FA\u529B\u3059\u308B\n        multi_debug(names, args...);\n \
    \   }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>\nvoid print(const\
    \ vector<T> &V, char sep) {\n    print(V, string{sep});\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, char sep) {\n    print(arr,\
    \ string{sep});\n}\n\n// TODO\uFF1A\u305D\u306E\u3046\u3061\u81EA\u52D5\u5B9F\u884C\
    \u3068\u304B\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\u3002\n// test cases\
    \ for print() and cout <<\n// pair<char, int> p = {'a', 1};\n// cout << p << '\\\
    n';\n// print(p);\n// tuple<char, int, ll, string> tp = {'a', 1, 2, \"abc\"};\n\
    // cout << tp << '\\n';\n// print(tp);\n// vector<ll> vec = {1, 2, 3, 4, 5};\n\
    // cout << vec << '\\n';\n// print(vec);\n// print(vec, \"\\n\");\n// array<ll,\
    \ 5> arr = {1, 2, 3, 4, 5};\n// cout << arr << '\\n';\n// print(arr);\n// print(arr,\
    \ \"\\n\");\n// deque<ll> que = {1, 2, 3, 4, 5};\n// print(que);\n// print(que,\
    \ \"\\n\");\n// set<ll> se = {1, 2, 3, 4, 5};\n// print(se);\n// print(se, \"\\\
    n\");\n// print({1, 2, 3, 4, 5});\n// print({1, 2, 3, 4, 5}, \"\\n\");\n// print();\n\
    // ll a = 100;\n// cout << a << '\\n';\n// print(a);\n// print(100);\n// string\
    \ S = \"abc\";\n// cout << S << '\\n';\n// print(S);\n// print(\"abc\");\n// char\
    \ c = 'a';\n// cout << c << '\\n';\n// print(c);\n// print('a');\n// // print(1,\
    \ \"abc\", 22LL);\n// // print(s, c);\n\n// test cases for debug()\n// int a =\
    \ 2;\n// string b = \"agc\";\n// char c = 'z';\n// ll d = 10000;\n// debug(a,\
    \  b, \"aaa\", 'y', c,d, max((ll)a, d));\n#line 3 \"src/math/FastFourierTransform.hpp\"\
    \n\nnamespace FastFourierTransform {\nusing real = double;\n\nstruct C {\n   \
    \ real x, y;\n\n    C() : x(0), y(0) {}\n\n    C(real x, real y) : x(x), y(y)\
    \ {\n    }\n\n    inline C operator+(const C &c) const {\n        return C(x +\
    \ c.x, y + c.y);\n    }\n\n    inline C operator-(const C &c) const {\n      \
    \  return C(x - c.x, y - c.y);\n    }\n\n    inline C operator*(const C &c) const\
    \ {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n    }\n\n    inline\
    \ C conj() const {\n        return C(x, -y);\n    }\n};\n\nconst real PI = acosl(-1);\n\
    int base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\n\
    void ensure_base(int nbase) {\n    if (nbase <= base) return;\n    rev.resize(1\
    \ << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0; i < (1 << nbase);\
    \ i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  \
    \  }\n    while (base < nbase) {\n        real angle = PI * 2.0 / (1 << (base\
    \ + 1));\n        for (int i = 1 << (base - 1); i < (1 << base); i++) {\n    \
    \        rts[i << 1] = rts[i];\n            real angle_i = angle * (2 * i + 1\
    \ - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \        }\n        ++base;\n    }\n}\n\nvoid fft(vector<C> &a, int n) {\n   \
    \ assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n    ensure_base(zeros);\n\
    \    int shift = base - zeros;\n    for (int i = 0; i < n; i++) {\n        if\
    \ (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i] >> shift]);\n   \
    \     }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n        for (int i = 0;\
    \ i < n; i += 2 * k) {\n            for (int j = 0; j < k; j++) {\n          \
    \      C z = a[i + j + k] * rts[j + k];\n                a[i + j + k] = a[i +\
    \ j] - z;\n                a[i + j] = a[i + j] + z;\n            }\n        }\n\
    \    }\n}\n\nvector<int64_t> multiply(const vector<int> &a, const vector<int>\
    \ &b) {\n    int need = (int)a.size() + (int)b.size() - 1;\n    int nbase = 1;\n\
    \    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n    int sz\
    \ = 1 << nbase;\n    vector<C> fa(sz);\n    for (int i = 0; i < sz; i++) {\n \
    \       int x = (i < (int)a.size() ? a[i] : 0);\n        int y = (i < (int)b.size()\
    \ ? b[i] : 0);\n        fa[i] = C(x, y);\n    }\n    fft(fa, sz);\n    C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0; i <= (sz >> 1);\
    \ i++) {\n        int j = (sz - i) & (sz - 1);\n        C z = (fa[j] * fa[j] -\
    \ (fa[i] * fa[i]).conj()) * r;\n        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\n        fa[i] = z;\n    }\n    for (int i = 0; i < (sz >> 1); i++) {\n\
    \        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n        C A1 = (fa[i] - fa[i\
    \ + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n        fa[i] = A0 + A1 * s;\n    }\n\
    \    fft(fa, sz >> 1);\n    vector<int64_t> ret(need);\n    for (int i = 0; i\
    \ < need; i++) {\n        ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n\
    \    }\n    return ret;\n}\n}; // namespace FastFourierTransform\n#line 4 \"src/math/ArbitraryModConvolution.hpp\"\
    \n\n// \u4EFB\u610FMOD\u7573\u307F\u8FBC\u307F\n// see: https://ei1333.github.io/library/math/fft/arbitrary-mod-convolution.hpp\n\
    template<typename T>\nstruct ArbitraryModConvolution {\n    using real = FastFourierTransform::real;\n\
    \    using C = FastFourierTransform::C;\n\n    ArbitraryModConvolution() = default;\n\
    \n    static vector<T> multiply(const vector<T> &a, const vector<T> &b, int need\
    \ = -1) {\n        if (need == -1) need = a.size() + b.size() - 1;\n        int\
    \ nbase = 0;\n        while ((1 << nbase) < need) nbase++;\n        FastFourierTransform::ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        vector<C> fa(sz);\n        for (int i =\
    \ 0; i < a.size(); i++) {\n            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x\
    \ >> 15);\n        }\n        fft(fa, sz);\n        vector<C> fb(sz);\n      \
    \  if (a == b) {\n            fb = fa;\n        } else {\n            for (int\
    \ i = 0; i < b.size(); i++) {\n                fb[i] = C(b[i].x & ((1 << 15) -\
    \ 1), b[i].x >> 15);\n            }\n            fft(fb, sz);\n        }\n   \
    \     real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0), r4(0, -ratio),\
    \ r5(0, 1);\n        for (int i = 0; i <= (sz >> 1); i++) {\n            int j\
    \ = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n       \
    \     C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] + fb[j].conj())\
    \ * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n            if (i !=\
    \ j) {\n                C c1 = (fa[j] + fa[i].conj());\n                C c2 =\
    \ (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j] + fb[i].conj())\
    \ * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n               \
    \ fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 * d2 + c2 * d1;\n\
    \            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n            fb[j]\
    \ = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n        fft(fb, sz);\n\
    \        vector<T> ret(need);\n        for (int i = 0; i < need; i++) {\n    \
    \        int64_t aa = llround(fa[i].x);\n            int64_t bb = llround(fb[i].x);\n\
    \            int64_t cc = llround(fa[i].y);\n            aa = T(aa).x, bb = T(bb).x,\
    \ cc = T(cc).x;\n            ret[i] = aa + (bb << 15) + (cc << 30);\n        }\n\
    \        return ret;\n    }\n};\n#line 5 \"src/math/FormalPowerSeries.hpp\"\n\n\
    // see: https://ei1333.github.io/library/math/fps/formal-power-series.hpp\ntemplate<typename\
    \ T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n \
    \   using P = FormalPowerSeries;\n    using Conv = ArbitraryModConvolution<T>;\n\
    \n    P pre(int deg) const {\n        return P(begin(*this), begin(*this) + min((int)this->size(),\
    \ deg));\n    }\n\n    P rev(int deg = -1) const {\n        P ret(*this);\n  \
    \      if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\u304C0\u306A\u90E8\
    \u5206\u3092\u524A\u308B\n    void shrink() {\n        while (this->size() &&\
    \ this->back() == T(0)) this->pop_back();\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\
    \u304C0 or deg\u3088\u308A\u5927\u304D\u3044\u90E8\u5206\u3092\u524A\u308B\n \
    \   void shrink(int deg) {\n        while (this->size() && this->back() == T(0)\
    \ or this->size() > deg)\n            this->pop_back();\n    }\n\n    P operator+(const\
    \ P &r) const {\n        return P(*this) += r;\n    }\n\n    P operator+(const\
    \ T &v) const {\n        return P(*this) += v;\n    }\n\n    P operator-(const\
    \ P &r) const {\n        return P(*this) -= r;\n    }\n\n    P operator-(const\
    \ T &v) const {\n        return P(*this) -= v;\n    }\n\n    P operator*(const\
    \ P &r) const {\n        return P(*this) *= r;\n    }\n\n    P operator*(const\
    \ T &v) const {\n        return P(*this) *= v;\n    }\n\n    P operator/(const\
    \ P &r) const {\n        return P(*this) /= r;\n    }\n\n    P operator%(const\
    \ P &r) const {\n        return P(*this) %= r;\n    }\n\n    P operator>>(const\
    \ int r) const {\n        return P(*this) >>= r;\n    }\n\n    P operator<<(const\
    \ int r) const {\n        return P(*this) <<= r;\n    }\n\n    P &operator+=(const\
    \ P &r) {\n        if (r.size() > this->size()) this->resize(r.size());\n    \
    \    for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return *this;\n\
    \    }\n\n    P &operator-=(const P &r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (int i = 0; i < r.size(); i++) (*this)[i]\
    \ -= r[i];\n        return *this;\n    }\n\n    // https://judge.yosupo.jp/problem/convolution_mod\n\
    \    P &operator*=(const P &r) {\n        if (this->empty() || r.empty()) {\n\
    \            this->clear();\n            return *this;\n        }\n        auto\
    \ ret = Conv::multiply(*this, r);\n        return *this = {begin(ret), end(ret)};\n\
    \    }\n\n    // \u3053\u306E\u9664\u7B97\u306F\u672C\u5F53\u306E\u300C\u591A\u9805\
    \u5F0F\u306E\u9664\u7B97\u300D\u3092\u3084\u3063\u3066\u308B\u307D\u3044\u306E\
    \u3067\u3001\u666E\u6BB5\u306F\u9006\u5143\u306E\u65B9\u3092\u4F7F\u3046\n   \
    \ P &operator/=(const P &r) {\n        if (this->size() < r.size()) {\n      \
    \      this->clear();\n            return *this;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P &operator%=(const P &r) {\n        return *this -= *this / r *\
    \ r;\n    }\n\n    // https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \    pair<P, P> div_mod(const P &r) {\n        P q = *this / r;\n        return\
    \ make_pair(q, *this - q * r);\n    }\n\n    P operator-() const {\n        P\
    \ ret(this->size());\n        for (int i = 0; i < this->size(); i++) ret[i] =\
    \ -(*this)[i];\n        return ret;\n    }\n\n    P &operator+=(const T &r) {\n\
    \        if (this->empty()) this->resize(1);\n        (*this)[0] += r;\n     \
    \   return *this;\n    }\n\n    P &operator-=(const T &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n\n\
    \    P &operator*=(const T &v) {\n        for (int i = 0; i < this->size(); i++)\
    \ (*this)[i] *= v;\n        return *this;\n    }\n\n    P dot(P r) const {\n \
    \       P ret(min(this->size(), r.size()));\n        for (int i = 0; i < ret.size();\
    \ i++) ret[i] = (*this)[i] * r[i];\n        return ret;\n    }\n\n    // \u30B7\
    \u30D5\u30C8\u306E\u5411\u304D\u304C\u306A\u3093\u304B\u76F4\u611F\u3068\u9006\
    \u306A\u306E\u3067\u6CE8\u610F(\u6570\u5217\u3092\u53F3\u30B7\u30D5\u30C8\u3059\
    \u308B\u3001\u3058\u3083\u306A\u304F\u3066sz\u500B\u6B21\u6570\u304C\u4E0B\u304C\
    \u308B\u3001\u307F\u305F\u3044\u306A\u6C17\u6301\u3061\u306A\u306E\u304B\u3082\
    )\n    P &operator>>=(int sz) {\n        if (this->size() <= sz) {\n         \
    \   this->clear();\n        } else {\n            this->erase(this->begin(), this->begin()\
    \ + sz);\n        }\n        return *this;\n    }\n\n    P &operator<<=(int sz)\
    \ {\n        this->insert(this->begin(), sz, T(0));\n        return *this;\n \
    \   }\n\n    // P operator>>(int sz) const {\n    //     if(this->size() <= sz)\
    \ return {};\n    //     P ret(*this);\n    //     ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    //     return ret;\n    // }\n\n    // P operator<<(int sz) const\
    \ {\n    //     P ret(*this);\n    //     ret.insert(ret.begin(), sz, T(0));\n\
    \    //     return ret;\n    // }\n\n    T operator()(T x) const {\n        T\
    \ r = 0, w = 1;\n        for (auto &v : *this) {\n            r += w * v;\n  \
    \          w *= x;\n        }\n        return r;\n    }\n\n    P diff() const\
    \ {\n        const int n = (int)this->size();\n        P ret(max(0, n - 1));\n\
    \        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n       \
    \ return ret;\n    }\n\n    P integral() const {\n        const int n = (int)this->size();\n\
    \        P ret(n + 1);\n        ret[0] = T(0);\n        for (int i = 0; i < n;\
    \ i++) ret[i + 1] = (*this)[i] / T(i + 1);\n        return ret;\n    }\n\n   \
    \ // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n    // F(0) must\
    \ not be 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // https://judge.yosupo.jp/problem/log_of_formal_power_series\n\
    \    // F(0) must be 1\n    P log(int deg = -1) const {\n        assert((*this)[0]\
    \ == T(1));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \    P sqrt(\n        int deg = -1, const function<T(T)> &get_sqrt = [](T) { return\
    \ T(1); }\n    ) const {\n        const int n = (int)this->size();\n        if\
    \ (deg == -1) deg = n;\n        if ((*this)[0] == T(0)) {\n            for (int\
    \ i = 1; i < n; i++) {\n                if ((*this)[i] != T(0)) {\n          \
    \          if (i & 1) return {};\n                    if (deg - i / 2 <= 0) break;\n\
    \                    auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n  \
    \                  if (ret.empty()) return {};\n                    ret = ret\
    \ << (i / 2);\n                    if (ret.size() < deg) ret.resize(deg, T(0));\n\
    \                    return ret;\n                }\n            }\n         \
    \   return P(deg, 0);\n        }\n        auto sqr = T(get_sqrt((*this)[0]));\n\
    \        if (sqr * sqr != (*this)[0]) return {};\n        P ret{sqr};\n      \
    \  T inv2 = T(1) / T(2);\n        for (int i = 1; i < deg; i <<= 1) {\n      \
    \      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n      \
    \  return ret.pre(deg);\n    }\n\n    P sqrt(const function<T(T)> &get_sqrt, int\
    \ deg = -1) const {\n        return sqrt(deg, get_sqrt);\n    }\n\n    // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \    // F(0) must be 0\n    P exp(int deg = -1) const {\n        if (deg == -1)\
    \ deg = this->size();\n        assert((*this)[0] == T(0));\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        P ret({T(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n\
    \    P pow(int64_t k, int deg = -1) const {\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        for (int i = 0; i < n; i++) {\n    \
    \        if ((*this)[i] != T(0)) {\n                T rev = T(1) / (*this)[i];\n\
    \                P ret = (((*this * rev) >> i).log() * k).exp() *\n          \
    \              ((*this)[i].pow(k));\n                if (i * k > deg) return P(deg,\
    \ T(0));\n                ret = (ret << (i * k)).pre(deg);\n                if\
    \ (ret.size() < deg) ret.resize(deg, T(0));\n                return ret;\n   \
    \         }\n        }\n        return *this;\n    }\n\n    // https://yukicoder.me/problems/no/215\n\
    \    P mod_pow(int64_t k, P g) const {\n        P modinv = g.rev().inv();\n  \
    \      auto get_div = [&](P base) {\n            if (base.size() < g.size()) {\n\
    \                base.clear();\n                return base;\n            }\n\
    \            int n = base.size() - g.size() + 1;\n            return (base.rev().pre(n)\
    \ * modinv.pre(n)).pre(n).rev(n);\n        };\n        P x(*this), ret{1};\n \
    \       while (k > 0) {\n            if (k & 1) {\n                ret *= x;\n\
    \                ret -= get_div(ret) * g;\n                ret.shrink();\n   \
    \         }\n            x *= x;\n            x -= get_div(x) * g;\n         \
    \   x.shrink();\n            k >>= 1;\n        }\n        return ret;\n    }\n\
    \n    // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n    P taylor_shift(T\
    \ c) const {\n        int n = (int)this->size();\n        vector<T> fact(n), rfact(n);\n\
    \        fact[0] = rfact[0] = T(1);\n        for (int i = 1; i < n; i++) fact[i]\
    \ = fact[i - 1] * T(i);\n        rfact[n - 1] = T(1) / fact[n - 1];\n        for\
    \ (int i = n - 1; i > 1; i--) rfact[i - 1] = rfact[i] * T(i);\n        P p(*this);\n\
    \        for (int i = 0; i < n; i++) p[i] *= fact[i];\n        p = p.rev();\n\
    \        P bs(n, T(1));\n        for (int i = 1; i < n; i++)\n            bs[i]\
    \ = bs[i - 1] * c * rfact[i] * fact[i - 1];\n        p = (p * bs).pre(n);\n  \
    \      p = p.rev();\n        for (int i = 0; i < n; i++) p[i] *= rfact[i];\n \
    \       return p;\n    }\n\n    // sparse (from opt\u3055\u3093)\n    // \u5F15\
    \u6570\uFF1Apair(\u6B21\u6570, \u4FC2\u6570)\u3067\u5FC5\u8981\u306A\u9805\u306E\
    \u307F\u5217\u6319\u3057\u305Fvector\n    P &operator*=(vector<pair<ll, T>> g)\
    \ {\n        int n = (*this).size();\n        auto [d, c] = g.front();\n     \
    \   if (d == 0) g.erase(g.begin());\n        else c = 0;\n        rep(i, n - 1,\
    \ -1, -1) {\n            (*this)[i] *= c;\n            for (auto &[j, b] : g)\
    \ {\n                if (j > i) break;\n                (*this)[i] += (*this)[i\
    \ - j] * b;\n            }\n        }\n        return *this;\n    }\n    P &operator/=(vector<pair<ll,\
    \ T>> g) {\n        int n = (*this).size();\n        auto [d, c] = g.front();\n\
    \        assert(d == 0 && c != T(0));\n        T ic = c.inv();\n        g.erase(g.begin());\n\
    \        rep(i, n) {\n            for (auto &[j, b] : g) {\n                if\
    \ (j > i) break;\n                (*this)[i] -= (*this)[i - j] * b;\n        \
    \    }\n            (*this)[i] *= ic;\n        }\n        return *this;\n    }\n\
    \    P operator*(const vector<pair<ll, T>> &g) const {\n        return P(*this)\
    \ *= g;\n    }\n    P operator/(const vector<pair<ll, T>> &g) const {\n      \
    \  return P(*this) /= g;\n    }\n};\ntemplate<typename Mint>\nusing FPS = FormalPowerSeries<Mint>;\n\
    // Sparse FPS\ntemplate<typename Mint>\nusing SFPS = vector<pair<ll, Mint>>;\n\
    \ntemplate<typename T>\nvoid print(const FPS<T> &F) {\n    vector<T> A(F.begin(),\
    \ F.end());\n    print(A);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../common/print.hpp\"\n\
    #include \"ArbitraryModConvolution.hpp\"\n\n// see: https://ei1333.github.io/library/math/fps/formal-power-series.hpp\n\
    template<typename T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n\
    \    using P = FormalPowerSeries;\n    using Conv = ArbitraryModConvolution<T>;\n\
    \n    P pre(int deg) const {\n        return P(begin(*this), begin(*this) + min((int)this->size(),\
    \ deg));\n    }\n\n    P rev(int deg = -1) const {\n        P ret(*this);\n  \
    \      if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\u304C0\u306A\u90E8\
    \u5206\u3092\u524A\u308B\n    void shrink() {\n        while (this->size() &&\
    \ this->back() == T(0)) this->pop_back();\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\
    \u304C0 or deg\u3088\u308A\u5927\u304D\u3044\u90E8\u5206\u3092\u524A\u308B\n \
    \   void shrink(int deg) {\n        while (this->size() && this->back() == T(0)\
    \ or this->size() > deg)\n            this->pop_back();\n    }\n\n    P operator+(const\
    \ P &r) const {\n        return P(*this) += r;\n    }\n\n    P operator+(const\
    \ T &v) const {\n        return P(*this) += v;\n    }\n\n    P operator-(const\
    \ P &r) const {\n        return P(*this) -= r;\n    }\n\n    P operator-(const\
    \ T &v) const {\n        return P(*this) -= v;\n    }\n\n    P operator*(const\
    \ P &r) const {\n        return P(*this) *= r;\n    }\n\n    P operator*(const\
    \ T &v) const {\n        return P(*this) *= v;\n    }\n\n    P operator/(const\
    \ P &r) const {\n        return P(*this) /= r;\n    }\n\n    P operator%(const\
    \ P &r) const {\n        return P(*this) %= r;\n    }\n\n    P operator>>(const\
    \ int r) const {\n        return P(*this) >>= r;\n    }\n\n    P operator<<(const\
    \ int r) const {\n        return P(*this) <<= r;\n    }\n\n    P &operator+=(const\
    \ P &r) {\n        if (r.size() > this->size()) this->resize(r.size());\n    \
    \    for (int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return *this;\n\
    \    }\n\n    P &operator-=(const P &r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (int i = 0; i < r.size(); i++) (*this)[i]\
    \ -= r[i];\n        return *this;\n    }\n\n    // https://judge.yosupo.jp/problem/convolution_mod\n\
    \    P &operator*=(const P &r) {\n        if (this->empty() || r.empty()) {\n\
    \            this->clear();\n            return *this;\n        }\n        auto\
    \ ret = Conv::multiply(*this, r);\n        return *this = {begin(ret), end(ret)};\n\
    \    }\n\n    // \u3053\u306E\u9664\u7B97\u306F\u672C\u5F53\u306E\u300C\u591A\u9805\
    \u5F0F\u306E\u9664\u7B97\u300D\u3092\u3084\u3063\u3066\u308B\u307D\u3044\u306E\
    \u3067\u3001\u666E\u6BB5\u306F\u9006\u5143\u306E\u65B9\u3092\u4F7F\u3046\n   \
    \ P &operator/=(const P &r) {\n        if (this->size() < r.size()) {\n      \
    \      this->clear();\n            return *this;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P &operator%=(const P &r) {\n        return *this -= *this / r *\
    \ r;\n    }\n\n    // https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \    pair<P, P> div_mod(const P &r) {\n        P q = *this / r;\n        return\
    \ make_pair(q, *this - q * r);\n    }\n\n    P operator-() const {\n        P\
    \ ret(this->size());\n        for (int i = 0; i < this->size(); i++) ret[i] =\
    \ -(*this)[i];\n        return ret;\n    }\n\n    P &operator+=(const T &r) {\n\
    \        if (this->empty()) this->resize(1);\n        (*this)[0] += r;\n     \
    \   return *this;\n    }\n\n    P &operator-=(const T &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n\n\
    \    P &operator*=(const T &v) {\n        for (int i = 0; i < this->size(); i++)\
    \ (*this)[i] *= v;\n        return *this;\n    }\n\n    P dot(P r) const {\n \
    \       P ret(min(this->size(), r.size()));\n        for (int i = 0; i < ret.size();\
    \ i++) ret[i] = (*this)[i] * r[i];\n        return ret;\n    }\n\n    // \u30B7\
    \u30D5\u30C8\u306E\u5411\u304D\u304C\u306A\u3093\u304B\u76F4\u611F\u3068\u9006\
    \u306A\u306E\u3067\u6CE8\u610F(\u6570\u5217\u3092\u53F3\u30B7\u30D5\u30C8\u3059\
    \u308B\u3001\u3058\u3083\u306A\u304F\u3066sz\u500B\u6B21\u6570\u304C\u4E0B\u304C\
    \u308B\u3001\u307F\u305F\u3044\u306A\u6C17\u6301\u3061\u306A\u306E\u304B\u3082\
    )\n    P &operator>>=(int sz) {\n        if (this->size() <= sz) {\n         \
    \   this->clear();\n        } else {\n            this->erase(this->begin(), this->begin()\
    \ + sz);\n        }\n        return *this;\n    }\n\n    P &operator<<=(int sz)\
    \ {\n        this->insert(this->begin(), sz, T(0));\n        return *this;\n \
    \   }\n\n    // P operator>>(int sz) const {\n    //     if(this->size() <= sz)\
    \ return {};\n    //     P ret(*this);\n    //     ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    //     return ret;\n    // }\n\n    // P operator<<(int sz) const\
    \ {\n    //     P ret(*this);\n    //     ret.insert(ret.begin(), sz, T(0));\n\
    \    //     return ret;\n    // }\n\n    T operator()(T x) const {\n        T\
    \ r = 0, w = 1;\n        for (auto &v : *this) {\n            r += w * v;\n  \
    \          w *= x;\n        }\n        return r;\n    }\n\n    P diff() const\
    \ {\n        const int n = (int)this->size();\n        P ret(max(0, n - 1));\n\
    \        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n       \
    \ return ret;\n    }\n\n    P integral() const {\n        const int n = (int)this->size();\n\
    \        P ret(n + 1);\n        ret[0] = T(0);\n        for (int i = 0; i < n;\
    \ i++) ret[i + 1] = (*this)[i] / T(i + 1);\n        return ret;\n    }\n\n   \
    \ // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n    // F(0) must\
    \ not be 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int)this->size();\n        if (deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // https://judge.yosupo.jp/problem/log_of_formal_power_series\n\
    \    // F(0) must be 1\n    P log(int deg = -1) const {\n        assert((*this)[0]\
    \ == T(1));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \    P sqrt(\n        int deg = -1, const function<T(T)> &get_sqrt = [](T) { return\
    \ T(1); }\n    ) const {\n        const int n = (int)this->size();\n        if\
    \ (deg == -1) deg = n;\n        if ((*this)[0] == T(0)) {\n            for (int\
    \ i = 1; i < n; i++) {\n                if ((*this)[i] != T(0)) {\n          \
    \          if (i & 1) return {};\n                    if (deg - i / 2 <= 0) break;\n\
    \                    auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n  \
    \                  if (ret.empty()) return {};\n                    ret = ret\
    \ << (i / 2);\n                    if (ret.size() < deg) ret.resize(deg, T(0));\n\
    \                    return ret;\n                }\n            }\n         \
    \   return P(deg, 0);\n        }\n        auto sqr = T(get_sqrt((*this)[0]));\n\
    \        if (sqr * sqr != (*this)[0]) return {};\n        P ret{sqr};\n      \
    \  T inv2 = T(1) / T(2);\n        for (int i = 1; i < deg; i <<= 1) {\n      \
    \      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n      \
    \  return ret.pre(deg);\n    }\n\n    P sqrt(const function<T(T)> &get_sqrt, int\
    \ deg = -1) const {\n        return sqrt(deg, get_sqrt);\n    }\n\n    // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \    // F(0) must be 0\n    P exp(int deg = -1) const {\n        if (deg == -1)\
    \ deg = this->size();\n        assert((*this)[0] == T(0));\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        P ret({T(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n\
    \    P pow(int64_t k, int deg = -1) const {\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        for (int i = 0; i < n; i++) {\n    \
    \        if ((*this)[i] != T(0)) {\n                T rev = T(1) / (*this)[i];\n\
    \                P ret = (((*this * rev) >> i).log() * k).exp() *\n          \
    \              ((*this)[i].pow(k));\n                if (i * k > deg) return P(deg,\
    \ T(0));\n                ret = (ret << (i * k)).pre(deg);\n                if\
    \ (ret.size() < deg) ret.resize(deg, T(0));\n                return ret;\n   \
    \         }\n        }\n        return *this;\n    }\n\n    // https://yukicoder.me/problems/no/215\n\
    \    P mod_pow(int64_t k, P g) const {\n        P modinv = g.rev().inv();\n  \
    \      auto get_div = [&](P base) {\n            if (base.size() < g.size()) {\n\
    \                base.clear();\n                return base;\n            }\n\
    \            int n = base.size() - g.size() + 1;\n            return (base.rev().pre(n)\
    \ * modinv.pre(n)).pre(n).rev(n);\n        };\n        P x(*this), ret{1};\n \
    \       while (k > 0) {\n            if (k & 1) {\n                ret *= x;\n\
    \                ret -= get_div(ret) * g;\n                ret.shrink();\n   \
    \         }\n            x *= x;\n            x -= get_div(x) * g;\n         \
    \   x.shrink();\n            k >>= 1;\n        }\n        return ret;\n    }\n\
    \n    // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n    P taylor_shift(T\
    \ c) const {\n        int n = (int)this->size();\n        vector<T> fact(n), rfact(n);\n\
    \        fact[0] = rfact[0] = T(1);\n        for (int i = 1; i < n; i++) fact[i]\
    \ = fact[i - 1] * T(i);\n        rfact[n - 1] = T(1) / fact[n - 1];\n        for\
    \ (int i = n - 1; i > 1; i--) rfact[i - 1] = rfact[i] * T(i);\n        P p(*this);\n\
    \        for (int i = 0; i < n; i++) p[i] *= fact[i];\n        p = p.rev();\n\
    \        P bs(n, T(1));\n        for (int i = 1; i < n; i++)\n            bs[i]\
    \ = bs[i - 1] * c * rfact[i] * fact[i - 1];\n        p = (p * bs).pre(n);\n  \
    \      p = p.rev();\n        for (int i = 0; i < n; i++) p[i] *= rfact[i];\n \
    \       return p;\n    }\n\n    // sparse (from opt\u3055\u3093)\n    // \u5F15\
    \u6570\uFF1Apair(\u6B21\u6570, \u4FC2\u6570)\u3067\u5FC5\u8981\u306A\u9805\u306E\
    \u307F\u5217\u6319\u3057\u305Fvector\n    P &operator*=(vector<pair<ll, T>> g)\
    \ {\n        int n = (*this).size();\n        auto [d, c] = g.front();\n     \
    \   if (d == 0) g.erase(g.begin());\n        else c = 0;\n        rep(i, n - 1,\
    \ -1, -1) {\n            (*this)[i] *= c;\n            for (auto &[j, b] : g)\
    \ {\n                if (j > i) break;\n                (*this)[i] += (*this)[i\
    \ - j] * b;\n            }\n        }\n        return *this;\n    }\n    P &operator/=(vector<pair<ll,\
    \ T>> g) {\n        int n = (*this).size();\n        auto [d, c] = g.front();\n\
    \        assert(d == 0 && c != T(0));\n        T ic = c.inv();\n        g.erase(g.begin());\n\
    \        rep(i, n) {\n            for (auto &[j, b] : g) {\n                if\
    \ (j > i) break;\n                (*this)[i] -= (*this)[i - j] * b;\n        \
    \    }\n            (*this)[i] *= ic;\n        }\n        return *this;\n    }\n\
    \    P operator*(const vector<pair<ll, T>> &g) const {\n        return P(*this)\
    \ *= g;\n    }\n    P operator/(const vector<pair<ll, T>> &g) const {\n      \
    \  return P(*this) /= g;\n    }\n};\ntemplate<typename Mint>\nusing FPS = FormalPowerSeries<Mint>;\n\
    // Sparse FPS\ntemplate<typename Mint>\nusing SFPS = vector<pair<ll, Mint>>;\n\
    \ntemplate<typename T>\nvoid print(const FPS<T> &F) {\n    vector<T> A(F.begin(),\
    \ F.end());\n    print(A);\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/print.hpp
  - src/macros.hpp
  - src/math/ArbitraryModConvolution.hpp
  - src/math/FastFourierTransform.hpp
  isVerificationFile: false
  path: src/math/FormalPowerSeries.hpp
  requiredBy:
  - src/math/fps/pow.hpp
  - src/math/fps/pow_term2.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/src/math/FormalPowerSeries.hpp
- /library/src/math/FormalPowerSeries.hpp.html
title: src/math/FormalPowerSeries.hpp
---
