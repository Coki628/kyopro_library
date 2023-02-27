---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/math/ArbitraryModConvolution.hpp
    title: Arbitrary Mod Convolution
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
    document_title: Formal Power Series
    links:
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
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/print.hpp\"\
    \n\ntemplate<typename T1, typename T2>\nostream &operator<<(ostream &os, const\
    \ pair<T1, T2> &p) {\n    return os << p.first << ' ' << p.second;\n}\n\ntemplate<typename\
    \ T1, typename T2, typename T3>\nostream &operator<<(ostream &os, const tuple<T1,\
    \ T2, T3> &tp) {\n    return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n\
    }\n\ntemplate<typename T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n    return os << get<0>(tp) << ' '\
    \ << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n}\n\ntemplate<typename\
    \ T, size_t SZ>\nostream &operator<<(ostream &os, const array<T, SZ> &arr) {\n\
    \    rep(i, arr.size()) {\n        os << arr[i];\n        if (i != (ll)arr.size()-1)\
    \ {\n            os << ' ';\n        }\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &vec) {\n    rep(i, vec.size())\
    \ {\n        os << vec[i];\n        if (i != (ll)vec.size()-1) {\n           \
    \ os << ' ';\n        }\n    }\n    return os;\n}\n\nvoid print() {\n    cout\
    \ << '\\n';\n}\n\ntemplate<typename T>\nvoid print(T out) {\n    cout << out <<\
    \ '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3>\nvoid print(const\
    \ tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << ' ' << get<1>(tp) << ' '\
    \ << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3,\
    \ typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) { \n    cout << get<0>(tp)\
    \ << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n}\n\
    \ntemplate<typename T>\nvoid print(const vector<T> &V, char sep=' ') {\n    rep(i,\
    \ V.size()) {\n        cout << V[i];\n        if (i != (ll)V.size()-1) cout <<\
    \ sep;\n    }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\nvoid\
    \ print(const array<T, SZ> &arr, char sep=' ') {\n    rep(i, arr.size()) {\n \
    \       cout << arr[i];\n        if (i != (ll)arr.size()-1) cout << sep;\n   \
    \ }\n    cout << '\\n';\n}\n\n// template<typename T, size_t SZ>\n// void print(const\
    \ vector<array<T, SZ>> &V) {\n//     for (auto& arr : V) print(arr);\n// }\n\n\
    template<typename T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n\
    \    print(V);\n}\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n  \
    \  vector<T> V(ALL(se));\n    print(V);\n}\n\n#define debug(x) (cout << #x <<\
    \ \": \" << x << endl);\n#line 3 \"src/math/FastFourierTransform.hpp\"\n\nnamespace\
    \ FastFourierTransform {\n    using real = double;\n\n    struct C {\n       \
    \ real x, y;\n\n        C() : x(0), y(0) {}\n\n        C(real x, real y) : x(x),\
    \ y(y) {}\n\n        inline C operator+(const C &c) const { return C(x + c.x,\
    \ y + c.y); }\n\n        inline C operator-(const C &c) const { return C(x - c.x,\
    \ y - c.y); }\n\n        inline C operator*(const C &c) const { return C(x * c.x\
    \ - y * c.y, x * c.y + y * c.x); }\n\n        inline C conj() const { return C(x,\
    \ -y); }\n    };\n\n    const real PI = acosl(-1);\n    int base = 1;\n    vector<\
    \ C > rts = { {0, 0},\n                        {1, 0} };\n    vector< int > rev\
    \ = {0, 1};\n\n\n    void ensure_base(int nbase) {\n        if(nbase <= base)\
    \ return;\n        rev.resize(1 << nbase);\n        rts.resize(1 << nbase);\n\
    \        for(int i = 0; i < (1 << nbase); i++) {\n            rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n        }\n        while(base < nbase)\
    \ {\n            real angle = PI * 2.0 / (1 << (base + 1));\n            for(int\
    \ i = 1 << (base - 1); i < (1 << base); i++) {\n                rts[i << 1] =\
    \ rts[i];\n                real angle_i = angle * (2 * i + 1 - (1 << base));\n\
    \                rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n        \
    \    }\n            ++base;\n        }\n    }\n\n    void fft(vector< C > &a,\
    \ int n) {\n        assert((n & (n - 1)) == 0);\n        int zeros = __builtin_ctz(n);\n\
    \        ensure_base(zeros);\n        int shift = base - zeros;\n        for(int\
    \ i = 0; i < n; i++) {\n            if(i < (rev[i] >> shift)) {\n            \
    \    swap(a[i], a[rev[i] >> shift]);\n            }\n        }\n        for(int\
    \ k = 1; k < n; k <<= 1) {\n            for(int i = 0; i < n; i += 2 * k) {\n\
    \                for(int j = 0; j < k; j++) {\n                    C z = a[i +\
    \ j + k] * rts[j + k];\n                    a[i + j + k] = a[i + j] - z;\n   \
    \                 a[i + j] = a[i + j] + z;\n                }\n            }\n\
    \        }\n    }\n\n    vector< int64_t > multiply(const vector< int > &a, const\
    \ vector< int > &b) {\n        int need = (int) a.size() + (int) b.size() - 1;\n\
    \        int nbase = 1;\n        while((1 << nbase) < need) nbase++;\n       \
    \ ensure_base(nbase);\n        int sz = 1 << nbase;\n        vector< C > fa(sz);\n\
    \        for(int i = 0; i < sz; i++) {\n            int x = (i < (int) a.size()\
    \ ? a[i] : 0);\n            int y = (i < (int) b.size() ? b[i] : 0);\n       \
    \     fa[i] = C(x, y);\n        }\n        fft(fa, sz);\n        C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\n        for(int i = 0; i <= (sz >> 1); i++)\
    \ {\n            int j = (sz - i) & (sz - 1);\n            C z = (fa[j] * fa[j]\
    \ - (fa[i] * fa[i]).conj()) * r;\n            fa[j] = (fa[i] * fa[i] - (fa[j]\
    \ * fa[j]).conj()) * r;\n            fa[i] = z;\n        }\n        for(int i\
    \ = 0; i < (sz >> 1); i++) {\n            C A0 = (fa[i] + fa[i + (sz >> 1)]) *\
    \ t;\n            C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n\
    \            fa[i] = A0 + A1 * s;\n        }\n        fft(fa, sz >> 1);\n    \
    \    vector< int64_t > ret(need);\n        for(int i = 0; i < need; i++) {\n \
    \           ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n        }\n\
    \        return ret;\n    }\n};\n#line 4 \"src/math/ArbitraryModConvolution.hpp\"\
    \n\n/*\n * @brief Arbitrary Mod Convolution\n */\ntemplate< typename T >\nstruct\
    \ ArbitraryModConvolution {\n    using real = FastFourierTransform::real;\n  \
    \  using C = FastFourierTransform::C;\n\n    ArbitraryModConvolution() = default;\n\
    \n    static vector< T > multiply(const vector< T > &a, const vector< T > &b,\
    \ int need = -1) {\n        if(need == -1) need = a.size() + b.size() - 1;\n \
    \       int nbase = 0;\n        while((1 << nbase) < need) nbase++;\n        FastFourierTransform::ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        vector< C > fa(sz);\n        for(int i\
    \ = 0; i < a.size(); i++) {\n            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x\
    \ >> 15);\n        }\n        fft(fa, sz);\n        vector< C > fb(sz);\n    \
    \    if(a == b) {\n            fb = fa;\n        } else {\n            for(int\
    \ i = 0; i < b.size(); i++) {\n                fb[i] = C(b[i].x & ((1 << 15) -\
    \ 1), b[i].x >> 15);\n            }\n            fft(fb, sz);\n        }\n   \
    \     real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0), r4(0, -ratio),\
    \ r5(0, 1);\n        for(int i = 0; i <= (sz >> 1); i++) {\n            int j\
    \ = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n       \
    \     C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] + fb[j].conj())\
    \ * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n            if(i !=\
    \ j) {\n                C c1 = (fa[j] + fa[i].conj());\n                C c2 =\
    \ (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j] + fb[i].conj())\
    \ * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n               \
    \ fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 * d2 + c2 * d1;\n\
    \            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n            fb[j]\
    \ = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n        fft(fb, sz);\n\
    \        vector< T > ret(need);\n        for(int i = 0; i < need; i++) {\n   \
    \         int64_t aa = llround(fa[i].x);\n            int64_t bb = llround(fb[i].x);\n\
    \            int64_t cc = llround(fa[i].y);\n            aa = T(aa).x, bb = T(bb).x,\
    \ cc = T(cc).x;\n            ret[i] = aa + (bb << 15) + (cc << 30);\n        }\n\
    \        return ret;\n    }\n};\n#line 5 \"src/math/FormalPowerSeries.hpp\"\n\n\
    /**\n * @brief Formal Power Series\n */\ntemplate< typename T >\nstruct FormalPowerSeries\
    \ : vector< T > {\n    using vector< T >::vector;\n    using P = FormalPowerSeries;\n\
    \    using Conv = ArbitraryModConvolution< T >;\n\n    P pre(int deg) const {\n\
    \        return P(begin(*this), begin(*this) + min((int) this->size(), deg));\n\
    \    }\n\n    P rev(int deg = -1) const {\n        P ret(*this);\n        if(deg\
    \ != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n    \
    \    return ret;\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\u304C0\u306A\u90E8\u5206\
    \u3092\u524A\u308B\n    void shrink() {\n        while(this->size() && this->back()\
    \ == T(0)) this->pop_back();\n    }\n\n    // \u9AD8\u3044\u6B21\u6570\u304C0\
    \ or deg\u3088\u308A\u5927\u304D\u3044\u90E8\u5206\u3092\u524A\u308B\n    void\
    \ shrink(int deg) {\n        while(this->size() && this->back() == T(0) or this->size()\
    \ > deg) this->pop_back();\n    }\n\n    P operator+(const P &r) const { return\
    \ P(*this) += r; }\n\n    P operator+(const T &v) const { return P(*this) += v;\
    \ }\n\n    P operator-(const P &r) const { return P(*this) -= r; }\n\n    P operator-(const\
    \ T &v) const { return P(*this) -= v; }\n\n    P operator*(const P &r) const {\
    \ return P(*this) *= r; }\n\n    P operator*(const T &v) const { return P(*this)\
    \ *= v; }\n\n    P operator/(const P &r) const { return P(*this) /= r; }\n\n \
    \   P operator%(const P &r) const { return P(*this) %= r; }\n\n    P operator>>(const\
    \ int r) const { return P(*this) >>= r; }\n\n    P operator<<(const int r) const\
    \ { return P(*this) <<= r; }\n\n    P &operator+=(const P &r) {\n        if(r.size()\
    \ > this->size()) this->resize(r.size());\n        for(int i = 0; i < r.size();\
    \ i++) (*this)[i] += r[i];\n        return *this;\n    }\n\n    P &operator-=(const\
    \ P &r) {\n        if(r.size() > this->size()) this->resize(r.size());\n     \
    \   for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        return *this;\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/convolution_mod\n    P &operator*=(const\
    \ P &r) {\n        if(this->empty() || r.empty()) {\n            this->clear();\n\
    \            return *this;\n        }\n        auto ret = Conv::multiply(*this,\
    \ r);\n        return *this = {begin(ret), end(ret)};\n    }\n\n    // \u3053\u306E\
    \u9664\u7B97\u306F\u672C\u5F53\u306E\u300C\u591A\u9805\u5F0F\u306E\u9664\u7B97\
    \u300D\u3092\u3084\u3063\u3066\u308B\u307D\u3044\u306E\u3067\u3001\u666E\u6BB5\
    \u306F\u9006\u5143\u306E\u65B9\u3092\u4F7F\u3046\n    P &operator/=(const P &r)\
    \ {\n        if(this->size() < r.size()) {\n            this->clear();\n     \
    \       return *this;\n        }\n        int n = this->size() - r.size() + 1;\n\
    \        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n    }\n\
    \n    P &operator%=(const P &r) {\n        return *this -= *this / r * r;\n  \
    \  }\n\n    // https://judge.yosupo.jp/problem/division_of_polynomials\n    pair<\
    \ P, P > div_mod(const P &r) {\n        P q = *this / r;\n        return make_pair(q,\
    \ *this - q * r);\n    }\n\n    P operator-() const {\n        P ret(this->size());\n\
    \        for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];\n       \
    \ return ret;\n    }\n\n    P &operator+=(const T &r) {\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    P &operator-=(const T &r) {\n        if(this->empty()) this->resize(1);\n\
    \        (*this)[0] -= r;\n        return *this;\n    }\n\n    P &operator*=(const\
    \ T &v) {\n        for(int i = 0; i < this->size(); i++) (*this)[i] *= v;\n  \
    \      return *this;\n    }\n\n    P dot(P r) const {\n        P ret(min(this->size(),\
    \ r.size()));\n        for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n\n    // \u30B7\u30D5\u30C8\u306E\u5411\
    \u304D\u304C\u306A\u3093\u304B\u76F4\u611F\u3068\u9006\u306A\u306E\u3067\u6CE8\
    \u610F(\u6570\u5217\u3092\u53F3\u30B7\u30D5\u30C8\u3059\u308B\u3001\u3058\u3083\
    \u306A\u304F\u3066sz\u500B\u6B21\u6570\u304C\u4E0B\u304C\u308B\u3001\u307F\u305F\
    \u3044\u306A\u6C17\u6301\u3061\u306A\u306E\u304B\u3082)\n    P &operator>>=(int\
    \ sz) {\n        if (this->size() <= sz) {\n            this->clear();\n     \
    \   } else {\n            this->erase(this->begin(), this->begin() + sz);\n  \
    \      }\n        return *this;\n    }\n\n    P &operator<<=(int sz) {\n     \
    \   this->insert(this->begin(), sz, T(0));\n        return *this;\n    }\n\n \
    \   // P operator>>(int sz) const {\n    //     if(this->size() <= sz) return\
    \ {};\n    //     P ret(*this);\n    //     ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    //     return ret;\n    // }\n\n    // P operator<<(int sz) const\
    \ {\n    //     P ret(*this);\n    //     ret.insert(ret.begin(), sz, T(0));\n\
    \    //     return ret;\n    // }\n\n    T operator()(T x) const {\n        T\
    \ r = 0, w = 1;\n        for(auto &v : *this) {\n            r += w * v;\n   \
    \         w *= x;\n        }\n        return r;\n    }\n\n    P diff() const {\n\
    \        const int n = (int) this->size();\n        P ret(max(0, n - 1));\n  \
    \      for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    P integral() const {\n        const int n = (int) this->size();\n\
    \        P ret(n + 1);\n        ret[0] = T(0);\n        for(int i = 0; i < n;\
    \ i++) ret[i + 1] = (*this)[i] / T(i + 1);\n        return ret;\n    }\n\n   \
    \ // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n    // F(0) must\
    \ not be 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int) this->size();\n        if(deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for(int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // https://judge.yosupo.jp/problem/log_of_formal_power_series\n\
    \    // F(0) must be 1\n    P log(int deg = -1) const {\n        assert((*this)[0]\
    \ == T(1));\n        const int n = (int) this->size();\n        if(deg == -1)\
    \ deg = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \    P sqrt(int deg = -1, const function< T(T) > &get_sqrt = [](T) { return T(1);\
    \ }) const {\n        const int n = (int) this->size();\n        if(deg == -1)\
    \ deg = n;\n        if((*this)[0] == T(0)) {\n            for(int i = 1; i < n;\
    \ i++) {\n                if((*this)[i] != T(0)) {\n                    if(i &\
    \ 1) return {};\n                    if(deg - i / 2 <= 0) break;\n           \
    \         auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n             \
    \       if(ret.empty()) return {};\n                    ret = ret << (i / 2);\n\
    \                    if(ret.size() < deg) ret.resize(deg, T(0));\n           \
    \         return ret;\n                }\n            }\n            return P(deg,\
    \ 0);\n        }\n        auto sqr = T(get_sqrt((*this)[0]));\n        if(sqr\
    \ * sqr != (*this)[0]) return {};\n        P ret{sqr};\n        T inv2 = T(1)\
    \ / T(2);\n        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret\
    \ + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P sqrt(const function< T(T) > &get_sqrt, int deg = -1) const {\n\
    \        return sqrt(deg, get_sqrt);\n    }\n\n    // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \    // F(0) must be 0\n    P exp(int deg = -1) const {\n        if(deg == -1)\
    \ deg = this->size();\n        assert((*this)[0] == T(0));\n        const int\
    \ n = (int) this->size();\n        if(deg == -1) deg = n;\n        P ret({T(1)});\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (pre(i <<\
    \ 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n\
    \    P pow(int64_t k, int deg = -1) const {\n        const int n = (int) this->size();\n\
    \        if(deg == -1) deg = n;\n        for(int i = 0; i < n; i++) {\n      \
    \      if((*this)[i] != T(0)) {\n                T rev = T(1) / (*this)[i];\n\
    \                P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \                if(i * k > deg) return P(deg, T(0));\n                ret = (ret\
    \ << (i * k)).pre(deg);\n                if(ret.size() < deg) ret.resize(deg,\
    \ T(0));\n                return ret;\n            }\n        }\n        return\
    \ *this;\n    }\n\n    // https://yukicoder.me/problems/no/215\n    P mod_pow(int64_t\
    \ k, P g) const {\n        P modinv = g.rev().inv();\n        auto get_div = [&](P\
    \ base) {\n            if(base.size() < g.size()) {\n                base.clear();\n\
    \                return base;\n            }\n            int n = base.size()\
    \ - g.size() + 1;\n            return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);\n\
    \        };\n        P x(*this), ret{1};\n        while(k > 0) {\n           \
    \ if(k & 1) {\n                ret *= x;\n                ret -= get_div(ret)\
    \ * g;\n                ret.shrink();\n            }\n            x *= x;\n  \
    \          x -= get_div(x) * g;\n            x.shrink();\n            k >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n\
    \    P taylor_shift(T c) const {\n        int n = (int) this->size();\n      \
    \  vector< T > fact(n), rfact(n);\n        fact[0] = rfact[0] = T(1);\n      \
    \  for(int i = 1; i < n; i++) fact[i] = fact[i - 1] * T(i);\n        rfact[n -\
    \ 1] = T(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; i--) rfact[i - 1]\
    \ = rfact[i] * T(i);\n        P p(*this);\n        for(int i = 0; i < n; i++)\
    \ p[i] *= fact[i];\n        p = p.rev();\n        P bs(n, T(1));\n        for(int\
    \ i = 1; i < n; i++) bs[i] = bs[i - 1] * c * rfact[i] * fact[i - 1];\n       \
    \ p = (p * bs).pre(n);\n        p = p.rev();\n        for(int i = 0; i < n; i++)\
    \ p[i] *= rfact[i];\n        return p;\n    }\n\n    // sparse (from opt\u3055\
    \u3093)\n    P &operator*=(vector<pair<ll, T>> g) {\n        int n = (*this).size();\n\
    \        auto [d, c] = g.front();\n        if (d == 0) g.erase(g.begin());\n \
    \       else c = 0;\n        rep(i, n-1, -1, -1) {\n            (*this)[i] *=\
    \ c;\n            for (auto &[j, b] : g) {\n                if (j > i) break;\n\
    \                (*this)[i] += (*this)[i-j] * b;\n            }\n        }\n \
    \       return *this;\n    }\n    P &operator/=(vector<pair<ll, T>> g) {\n   \
    \     int n = (*this).size();\n        auto [d, c] = g.front();\n        assert(d\
    \ == 0 && c != T(0));\n        T ic = c.inv();\n        g.erase(g.begin());\n\
    \        rep(i, n) {\n            for (auto &[j, b] : g) {\n                if\
    \ (j > i) break;\n                (*this)[i] -= (*this)[i-j] * b;\n          \
    \  }\n            (*this)[i] *= ic;\n        }\n        return *this;\n    }\n\
    \    P operator*(const vector<pair<ll, T>>& g) const { return P(*this) *= g; }\n\
    \    P operator/(const vector<pair<ll, T>>& g) const { return P(*this) /= g; }\n\
    };\ntemplate<typename Mint>\nusing FPS = FormalPowerSeries<Mint>;\n// Sparse FPS\n\
    template<typename Mint>\nusing SFPS = vector<pair<ll, Mint>>;\n\ntemplate<typename\
    \ T>\nvoid print(const FPS<T> &F) {\n    vector<T> A(F.begin(), F.end());\n  \
    \  print(A);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../common/print.hpp\"\n\
    #include \"ArbitraryModConvolution.hpp\"\n\n/**\n * @brief Formal Power Series\n\
    \ */\ntemplate< typename T >\nstruct FormalPowerSeries : vector< T > {\n    using\
    \ vector< T >::vector;\n    using P = FormalPowerSeries;\n    using Conv = ArbitraryModConvolution<\
    \ T >;\n\n    P pre(int deg) const {\n        return P(begin(*this), begin(*this)\
    \ + min((int) this->size(), deg));\n    }\n\n    P rev(int deg = -1) const {\n\
    \        P ret(*this);\n        if(deg != -1) ret.resize(deg, T(0));\n       \
    \ reverse(begin(ret), end(ret));\n        return ret;\n    }\n\n    // \u9AD8\u3044\
    \u6B21\u6570\u304C0\u306A\u90E8\u5206\u3092\u524A\u308B\n    void shrink() {\n\
    \        while(this->size() && this->back() == T(0)) this->pop_back();\n    }\n\
    \n    // \u9AD8\u3044\u6B21\u6570\u304C0 or deg\u3088\u308A\u5927\u304D\u3044\u90E8\
    \u5206\u3092\u524A\u308B\n    void shrink(int deg) {\n        while(this->size()\
    \ && this->back() == T(0) or this->size() > deg) this->pop_back();\n    }\n\n\
    \    P operator+(const P &r) const { return P(*this) += r; }\n\n    P operator+(const\
    \ T &v) const { return P(*this) += v; }\n\n    P operator-(const P &r) const {\
    \ return P(*this) -= r; }\n\n    P operator-(const T &v) const { return P(*this)\
    \ -= v; }\n\n    P operator*(const P &r) const { return P(*this) *= r; }\n\n \
    \   P operator*(const T &v) const { return P(*this) *= v; }\n\n    P operator/(const\
    \ P &r) const { return P(*this) /= r; }\n\n    P operator%(const P &r) const {\
    \ return P(*this) %= r; }\n\n    P operator>>(const int r) const { return P(*this)\
    \ >>= r; }\n\n    P operator<<(const int r) const { return P(*this) <<= r; }\n\
    \n    P &operator+=(const P &r) {\n        if(r.size() > this->size()) this->resize(r.size());\n\
    \        for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n\n    P &operator-=(const P &r) {\n        if(r.size() > this->size())\
    \ this->resize(r.size());\n        for(int i = 0; i < r.size(); i++) (*this)[i]\
    \ -= r[i];\n        return *this;\n    }\n\n    // https://judge.yosupo.jp/problem/convolution_mod\n\
    \    P &operator*=(const P &r) {\n        if(this->empty() || r.empty()) {\n \
    \           this->clear();\n            return *this;\n        }\n        auto\
    \ ret = Conv::multiply(*this, r);\n        return *this = {begin(ret), end(ret)};\n\
    \    }\n\n    // \u3053\u306E\u9664\u7B97\u306F\u672C\u5F53\u306E\u300C\u591A\u9805\
    \u5F0F\u306E\u9664\u7B97\u300D\u3092\u3084\u3063\u3066\u308B\u307D\u3044\u306E\
    \u3067\u3001\u666E\u6BB5\u306F\u9006\u5143\u306E\u65B9\u3092\u4F7F\u3046\n   \
    \ P &operator/=(const P &r) {\n        if(this->size() < r.size()) {\n       \
    \     this->clear();\n            return *this;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    P &operator%=(const P &r) {\n        return *this -= *this / r *\
    \ r;\n    }\n\n    // https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \    pair< P, P > div_mod(const P &r) {\n        P q = *this / r;\n        return\
    \ make_pair(q, *this - q * r);\n    }\n\n    P operator-() const {\n        P\
    \ ret(this->size());\n        for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];\n\
    \        return ret;\n    }\n\n    P &operator+=(const T &r) {\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    P &operator-=(const T &r) {\n        if(this->empty()) this->resize(1);\n\
    \        (*this)[0] -= r;\n        return *this;\n    }\n\n    P &operator*=(const\
    \ T &v) {\n        for(int i = 0; i < this->size(); i++) (*this)[i] *= v;\n  \
    \      return *this;\n    }\n\n    P dot(P r) const {\n        P ret(min(this->size(),\
    \ r.size()));\n        for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n\n    // \u30B7\u30D5\u30C8\u306E\u5411\
    \u304D\u304C\u306A\u3093\u304B\u76F4\u611F\u3068\u9006\u306A\u306E\u3067\u6CE8\
    \u610F(\u6570\u5217\u3092\u53F3\u30B7\u30D5\u30C8\u3059\u308B\u3001\u3058\u3083\
    \u306A\u304F\u3066sz\u500B\u6B21\u6570\u304C\u4E0B\u304C\u308B\u3001\u307F\u305F\
    \u3044\u306A\u6C17\u6301\u3061\u306A\u306E\u304B\u3082)\n    P &operator>>=(int\
    \ sz) {\n        if (this->size() <= sz) {\n            this->clear();\n     \
    \   } else {\n            this->erase(this->begin(), this->begin() + sz);\n  \
    \      }\n        return *this;\n    }\n\n    P &operator<<=(int sz) {\n     \
    \   this->insert(this->begin(), sz, T(0));\n        return *this;\n    }\n\n \
    \   // P operator>>(int sz) const {\n    //     if(this->size() <= sz) return\
    \ {};\n    //     P ret(*this);\n    //     ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    //     return ret;\n    // }\n\n    // P operator<<(int sz) const\
    \ {\n    //     P ret(*this);\n    //     ret.insert(ret.begin(), sz, T(0));\n\
    \    //     return ret;\n    // }\n\n    T operator()(T x) const {\n        T\
    \ r = 0, w = 1;\n        for(auto &v : *this) {\n            r += w * v;\n   \
    \         w *= x;\n        }\n        return r;\n    }\n\n    P diff() const {\n\
    \        const int n = (int) this->size();\n        P ret(max(0, n - 1));\n  \
    \      for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    P integral() const {\n        const int n = (int) this->size();\n\
    \        P ret(n + 1);\n        ret[0] = T(0);\n        for(int i = 0; i < n;\
    \ i++) ret[i + 1] = (*this)[i] / T(i + 1);\n        return ret;\n    }\n\n   \
    \ // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n    // F(0) must\
    \ not be 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0]) != T(0));\n\
    \        const int n = (int) this->size();\n        if(deg == -1) deg = n;\n \
    \       P ret({T(1) / (*this)[0]});\n        for(int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    // https://judge.yosupo.jp/problem/log_of_formal_power_series\n\
    \    // F(0) must be 1\n    P log(int deg = -1) const {\n        assert((*this)[0]\
    \ == T(1));\n        const int n = (int) this->size();\n        if(deg == -1)\
    \ deg = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n\
    \    P sqrt(int deg = -1, const function< T(T) > &get_sqrt = [](T) { return T(1);\
    \ }) const {\n        const int n = (int) this->size();\n        if(deg == -1)\
    \ deg = n;\n        if((*this)[0] == T(0)) {\n            for(int i = 1; i < n;\
    \ i++) {\n                if((*this)[i] != T(0)) {\n                    if(i &\
    \ 1) return {};\n                    if(deg - i / 2 <= 0) break;\n           \
    \         auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n             \
    \       if(ret.empty()) return {};\n                    ret = ret << (i / 2);\n\
    \                    if(ret.size() < deg) ret.resize(deg, T(0));\n           \
    \         return ret;\n                }\n            }\n            return P(deg,\
    \ 0);\n        }\n        auto sqr = T(get_sqrt((*this)[0]));\n        if(sqr\
    \ * sqr != (*this)[0]) return {};\n        P ret{sqr};\n        T inv2 = T(1)\
    \ / T(2);\n        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret\
    \ + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    P sqrt(const function< T(T) > &get_sqrt, int deg = -1) const {\n\
    \        return sqrt(deg, get_sqrt);\n    }\n\n    // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \    // F(0) must be 0\n    P exp(int deg = -1) const {\n        if(deg == -1)\
    \ deg = this->size();\n        assert((*this)[0] == T(0));\n        const int\
    \ n = (int) this->size();\n        if(deg == -1) deg = n;\n        P ret({T(1)});\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (pre(i <<\
    \ 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n\n    // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n\
    \    P pow(int64_t k, int deg = -1) const {\n        const int n = (int) this->size();\n\
    \        if(deg == -1) deg = n;\n        for(int i = 0; i < n; i++) {\n      \
    \      if((*this)[i] != T(0)) {\n                T rev = T(1) / (*this)[i];\n\
    \                P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \                if(i * k > deg) return P(deg, T(0));\n                ret = (ret\
    \ << (i * k)).pre(deg);\n                if(ret.size() < deg) ret.resize(deg,\
    \ T(0));\n                return ret;\n            }\n        }\n        return\
    \ *this;\n    }\n\n    // https://yukicoder.me/problems/no/215\n    P mod_pow(int64_t\
    \ k, P g) const {\n        P modinv = g.rev().inv();\n        auto get_div = [&](P\
    \ base) {\n            if(base.size() < g.size()) {\n                base.clear();\n\
    \                return base;\n            }\n            int n = base.size()\
    \ - g.size() + 1;\n            return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);\n\
    \        };\n        P x(*this), ret{1};\n        while(k > 0) {\n           \
    \ if(k & 1) {\n                ret *= x;\n                ret -= get_div(ret)\
    \ * g;\n                ret.shrink();\n            }\n            x *= x;\n  \
    \          x -= get_div(x) * g;\n            x.shrink();\n            k >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n\
    \    P taylor_shift(T c) const {\n        int n = (int) this->size();\n      \
    \  vector< T > fact(n), rfact(n);\n        fact[0] = rfact[0] = T(1);\n      \
    \  for(int i = 1; i < n; i++) fact[i] = fact[i - 1] * T(i);\n        rfact[n -\
    \ 1] = T(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; i--) rfact[i - 1]\
    \ = rfact[i] * T(i);\n        P p(*this);\n        for(int i = 0; i < n; i++)\
    \ p[i] *= fact[i];\n        p = p.rev();\n        P bs(n, T(1));\n        for(int\
    \ i = 1; i < n; i++) bs[i] = bs[i - 1] * c * rfact[i] * fact[i - 1];\n       \
    \ p = (p * bs).pre(n);\n        p = p.rev();\n        for(int i = 0; i < n; i++)\
    \ p[i] *= rfact[i];\n        return p;\n    }\n\n    // sparse (from opt\u3055\
    \u3093)\n    P &operator*=(vector<pair<ll, T>> g) {\n        int n = (*this).size();\n\
    \        auto [d, c] = g.front();\n        if (d == 0) g.erase(g.begin());\n \
    \       else c = 0;\n        rep(i, n-1, -1, -1) {\n            (*this)[i] *=\
    \ c;\n            for (auto &[j, b] : g) {\n                if (j > i) break;\n\
    \                (*this)[i] += (*this)[i-j] * b;\n            }\n        }\n \
    \       return *this;\n    }\n    P &operator/=(vector<pair<ll, T>> g) {\n   \
    \     int n = (*this).size();\n        auto [d, c] = g.front();\n        assert(d\
    \ == 0 && c != T(0));\n        T ic = c.inv();\n        g.erase(g.begin());\n\
    \        rep(i, n) {\n            for (auto &[j, b] : g) {\n                if\
    \ (j > i) break;\n                (*this)[i] -= (*this)[i-j] * b;\n          \
    \  }\n            (*this)[i] *= ic;\n        }\n        return *this;\n    }\n\
    \    P operator*(const vector<pair<ll, T>>& g) const { return P(*this) *= g; }\n\
    \    P operator/(const vector<pair<ll, T>>& g) const { return P(*this) /= g; }\n\
    };\ntemplate<typename Mint>\nusing FPS = FormalPowerSeries<Mint>;\n// Sparse FPS\n\
    template<typename Mint>\nusing SFPS = vector<pair<ll, Mint>>;\n\ntemplate<typename\
    \ T>\nvoid print(const FPS<T> &F) {\n    vector<T> A(F.begin(), F.end());\n  \
    \  print(A);\n}\n"
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
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/src/math/FormalPowerSeries.hpp
- /library/src/math/FormalPowerSeries.hpp.html
title: Formal Power Series
---
