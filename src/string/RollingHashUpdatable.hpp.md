---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/pow.hpp
    title: src/common/pow.hpp
  - icon: ':warning:'
    path: src/datastructure/AbstractBIT.hpp
    title: src/datastructure/AbstractBIT.hpp
  - icon: ':warning:'
    path: src/datastructure/BIT.hpp
    title: src/datastructure/BIT.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/string/RollingHash.hpp
    title: src/string/RollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/pow.hpp\"\
    \n\nll pow(ll x, ll n) {\n    ll res = 1;\n    rep(_, n) res *= x;\n    return\
    \ res;\n}\n\nll pow(int x, ll n) {\n    return pow((ll)x, n);\n}\n\nll pow(ll\
    \ x, int n) {\n    return pow(x, (ll)n);\n}\n\nll pow(int x, int n) {\n    return\
    \ pow((ll)x, (ll)n);\n}\n\ntemplate<typename T1, typename T2, typename M>\nT1\
    \ pow(T1 x, T2 n, M mod) {\n    x %= mod;\n    T1 res = 1;\n    while (n > 0)\
    \ {\n        if (n & 1) {\n            assert(not mul_overflow(res, x));\n   \
    \         res = (res * x) % mod;\n        }\n        assert(not mul_overflow(x,\
    \ x));\n        x = (x * x) % mod;\n        n >>= 1;\n    }\n    return res;\n\
    }\n#line 3 \"src/datastructure/BIT.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename\
    \ T>\nclass BIT {\nprotected:\n    int n;\n    vector<T> dat;\n\npublic:\n   \
    \ BIT() = default;\n\n    explicit BIT(int n) : n(n) {\n        dat.assign(n +\
    \ 1, T());\n    }\n\n    explicit BIT(const vector<T> &v) : BIT((int)v.size())\
    \ {\n        build(v);\n    }\n\n    virtual void build(const vector<T> &v) {\n\
    \        assert(n == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n\
    \            dat[i] = v[i - 1];\n        }\n        for (int i = 1; i <= n; i++)\
    \ {\n            int j = i + (i & -i);\n            if (j <= n) dat[j] += dat[i];\n\
    \        }\n    }\n\n    // [0, r)\u3092\u5408\u8A08\u3059\u308B\n    virtual\
    \ T sum(int r) {\n        T s = T();\n        for (; r > 0; r -= r & -r) {\n \
    \           s += dat[r];\n        }\n        return s;\n    }\n\n    virtual void\
    \ add(int k, const T &x) {\n        for (++k; k <= n; k += k & -k) {\n       \
    \     dat[k] += x;\n        }\n    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97\
    \ [l, r)\n    T query(int l, int r) {\n        if (l >= r) return T();\n     \
    \   return sum(r) - sum(l);\n    }\n\n    virtual T get(int i) {\n        // return\
    \ query(i, i + 1);\n        // BIT\u306E\u9AD8\u901F\u306A1\u70B9\u53D6\u5F97\n\
    \        // see: https://twitter.com/KakurenboUni/status/1643832177690550273\n\
    \        T s = this->dat[i + 1];\n        if (i & 1) {\n            int j = i;\n\
    \            i++;\n            i -= i & -i;\n            for (; j > i; j -= j\
    \ & -j) {\n                s -= this->dat[j];\n            }\n        }\n    \
    \    return s;\n    }\n\n    void update(int i, T x) {\n        add(i, x - this->get(i));\n\
    \    }\n\n    T operator[](int i) {\n        return this->get(i);\n    }\n\n \
    \   int size() {\n        return n;\n    }\n\n    // log2\u3064\u306E\u65E7\u4ED5\
    \u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\u308B\u7A0B\u5EA6\u78BA\u8A8D\u304C\
    \u53D6\u308C\u305F\u3089\u524A\u9664\u3002\n    // ll bisearch_fore(int l, int\
    \ r, ll x) {\n    //     if (l > r) return -1;\n    //     ll l_sm = sum(l);\n\
    \    //     int ok = r + 1;\n    //     int ng = l - 1;\n    //     while (ng+1\
    \ < ok) {\n    //         int mid = (ok+ng) / 2;\n    //         if (sum(mid+1)\
    \ - l_sm >= x) {\n    //             ok = mid;\n    //         } else {\n    //\
    \             ng = mid;\n    //         }\n    //     }\n    //     if (ok !=\
    \ r+1) {\n    //         return ok;\n    //     } else {\n    //         return\
    \ -1;\n    //     }\n    // }\n    // ll bisearch_back(int l, int r, ll x) {\n\
    \    //     if (l > r) return -1;\n    //     ll r_sm = sum(r+1);\n    //    \
    \ int ok = l - 1;\n    //     int ng = r + 1;\n    //     while (ok+1 < ng) {\n\
    \    //         int mid = (ok+ng) / 2;\n    //         if (r_sm - sum(mid) >=\
    \ x) {\n    //             ok = mid;\n    //         } else {\n    //        \
    \     ng = mid;\n    //         }\n    //     }\n    //     if (ok != l-1) {\n\
    \    //         return ok;\n    //     } else {\n    //         return -1;\n \
    \   //     }\n    // }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\
    \u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\
    \u7F6E(log1\u3064\u7248)\n    int bisearch_fore(int l, int r, T x) {\n       \
    \ if (l > r) return -1;\n        assert(l >= 0 and r < n);\n        x += query(0,\
    \ l);\n        T k = lower_bound(x);\n        assert(l <= k);\n        if (k >=\
    \ n) {\n            return -1;\n        } else {\n            return k;\n    \
    \    }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\
    \u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\
    (log1\u3064\u7248)\n    int bisearch_back(int l, int r, T x) {\n        if (l\
    \ > r) return -1;\n        assert(l >= 0 and r < n);\n        T total = query(0,\
    \ r + 1);\n        if (total - x < 0) {\n            return -1;\n        }\n \
    \       T k = upper_bound(total - x);\n        assert(k <= r);\n        if (k\
    \ < l) {\n            return -1;\n        } else {\n            return k;\n  \
    \      }\n    }\n\n    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp\n\
    \    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ // (log\u304C1\u3064\u306A\u306E\u3067\u3001TL\u53B3\u3057\u3044\u6642\u306F\
    \u3053\u3061\u3089\u3092\u4F7F\u3046\u3002)\n    int lower_bound(T x) const {\n\
    \        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1)\
    \ {\n            if (i + k <= n && dat[i + k] < x) {\n                x -= dat[i\
    \ + k];\n                i += k;\n            }\n        }\n        return i;\n\
    \    }\n\n    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u3092\u4E0A\u56DE\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ int upper_bound(T x) const {\n        int i = 0;\n        for (int k = 1 <<\
    \ (__lg(n) + 1); k > 0; k >>= 1) {\n            if (i + k <= n && dat[i + k] <=\
    \ x) {\n                x -= dat[i + k];\n                i += k;\n          \
    \  }\n        }\n        return i;\n    }\n};\n\ntemplate<typename T>\nostream\
    \ &operator<<(ostream &os, BIT<T> &bit) {\n    rep(i, bit.size()) {\n        os\
    \ << bit[i];\n        if (i != bit.size() - 1) {\n            os << ' ';\n   \
    \     }\n    }\n    return os;\n}\n#line 4 \"src/datastructure/AbstractBIT.hpp\"\
    \n\n// \u62BD\u8C61\u5316BIT\n// \u30FBxor\u304F\u3089\u3044\u3057\u304B\u4F7F\
    \u3044\u9053\u304C\u601D\u3044\u3064\u304B\u305A\u9577\u3089\u304F\u7740\u624B\
    \u305B\u305A\u653E\u7F6E\u3060\u3063\u305F\u3051\u3069\u3001\n// \u3000\u30ED\u30EA\
    \u30CF\u7528\u306E\u3067\u304BMOD\u6574\u6570\u3092\u4E57\u305B\u308C\u308B\u304B\
    \u3082\u3068\u3044\u3046\u3053\u3068\u3067\u4F5C\u3063\u305F\u3002\ntemplate<typename\
    \ T, typename F, typename G>\nclass AbstractBIT : public BIT<T> {\nprivate:\n\
    \    const F f;\n    const G g;\n\n    // \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u5F15\u6570\u304C\u3042\u308B\u3068\u3001\u89AA\u306E\u30E1\u30F3\u30D0\u5909\
    \u6570\u304C\u660E\u793A\u3057\u306A\u3044\u3068\u898B\u3048\u306A\u3044\u306E\
    \u3060\u305D\u3046\n    // see: https://teratail.com/questions/179231\n    int\
    \ n = BIT<T>::n;\n    vector<T> dat = BIT<T>::dat;\n\npublic:\n    AbstractBIT()\
    \ = default;\n\n    explicit AbstractBIT(int n, F f, G g) : BIT<T>(n), f(f), g(g)\
    \ {}\n\n    explicit AbstractBIT(const vector<T> &v, F f, G g)\n        : AbstractBIT((int)v.size(),\
    \ f, g) {\n        build(v);\n    }\n\n    void build(const vector<T> &v) override\
    \ {\n        assert(n == (int)v.size());\n        for (int i = 1; i <= n; i++)\
    \ {\n            dat[i] = v[i - 1];\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            int j = i + (i & -i);\n            if (j <= n) dat[j] =\
    \ f(dat[j], dat[i]);\n        }\n    }\n\n    // [0, r)\u3092\u5408\u8A08\u3059\
    \u308B\n    T sum(int r) override {\n        T s = T();\n        for (; r > 0;\
    \ r -= r & -r) {\n            s = f(s, dat[r]);\n        }\n        return s;\n\
    \    }\n\n    void add(int k, const T &x) override {\n        for (++k; k <= n;\
    \ k += k & -k) {\n            dat[k] = f(dat[k], x);\n        }\n    }\n\n   \
    \ // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n    T query(int l, int r) {\n\
    \        if (l >= r) return T();\n        return g(sum(r), sum(l));\n    }\n\n\
    \    void update(int i, T x) {\n        add(i, g(x, this->get(i)));\n    }\n\n\
    \    T get(int i) override {\n        // return query(i, i + 1);\n        // BIT\u306E\
    \u9AD8\u901F\u306A1\u70B9\u53D6\u5F97\n        // see: https://twitter.com/KakurenboUni/status/1643832177690550273\n\
    \        T s = dat[i + 1];\n        if (i & 1) {\n            int j = i;\n   \
    \         i++;\n            i -= i & -i;\n            for (; j > i; j -= j & -j)\
    \ {\n                s = g(s, dat[j]);\n            }\n        }\n        return\
    \ s;\n    }\n};\n#line 3 \"src/string/RollingHash.hpp\"\n\n// \u30ED\u30EA\u30CF\
    \n// see: https://ei1333.github.io/library/string/rolling-hash.hpp\nstruct RollingHash\
    \ {\n    static const ull mod = (1ull << 61ull) - 1;\n    using uint128_t = __uint128_t;\n\
    \    vector<ull> power;\n    const ull base;\n\n    static inline ull add(ull\
    \ a, ull b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n   \
    \ }\n\n    static inline ull sub(ull a, ull b) {\n        return add(a, mod -\
    \ b);\n    }\n\n    static inline ull mul(ull a, ull b) {\n        uint128_t c\
    \ = (uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n    //\
    \ 2^61-1\u4EE5\u4E0B\u306E\u4E71\u6570\u3092\u8FD4\u3059\u3002\u3053\u308C\u3092\
    base\u3068\u3059\u308B\u3068Hack\u3055\u308C\u306B\u304F\u3044\n    static inline\
    \ ull generate_base() {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull> rand(1, RollingHash::mod - 1);\n      \
    \  return rand(mt);\n    }\n\n    inline void expand(size_t sz) {\n        if\
    \ (power.size() < sz + 1) {\n            int pre_sz = (int)power.size();\n   \
    \         power.resize(sz + 1);\n            for (int i = pre_sz - 1; i < sz;\
    \ i++) {\n                power[i + 1] = mul(power[i], base);\n            }\n\
    \        }\n    }\n\n    // \u57FA\u6570base\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\u3092\u69CB\u7BC9\u3059\u308B\n    explicit RollingHash(ull\
    \ base = generate_base()) : base(base), power{1} {}\n\n    // \u6587\u5B57\u5217\
    s\u306E\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\uFF1A\
    O(n)\n    vector<ull> build(const string &s) const {\n        int sz = s.size();\n\
    \        vector<ull> table(sz + 1);\n        for (int i = 0; i < sz; i++) {\n\
    \            table[i + 1] = add(mul(table[i], base), s[i]);\n        }\n     \
    \   return table;\n    }\n\n    template<typename T>\n    vector<ull> build(const\
    \ vector<T> &s) const {\n        int sz = s.size();\n        vector<ull> table(sz\
    \ + 1);\n        for (int i = 0; i < sz; i++) {\n            table[i + 1] = add(mul(table[i],\
    \ base), s[i]);\n        }\n        return table;\n    }\n\n    // table\u306E\
    \u533A\u9593[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8FD4\u3059\uFF1A\
    O(1)\n    ull query(const vector<ull> &table, int l, int r) {\n        expand(r\
    \ - l);\n        return sub(table[r], mul(table[l], power[r - l]));\n    }\n\n\
    \    // \u30CF\u30C3\u30B7\u30E5\u5024h1\u3068\u9577\u3055h2len\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024h2\u3092\u7D50\u5408\u3059\u308B\n    ull combine(ull h1, ull\
    \ h2, size_t h2len) {\n        expand(h2len);\n        return add(mul(h1, power[h2len]),\
    \ h2);\n    }\n\n    // \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EBa\u306E\
    \u533A\u9593[l1,r1)\u3068\u3001\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\
    b\u306E\u533A\u9593[l2,r2)\u306E\u6587\u5B57\u5217\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u8FD4\u3059\uFF1AO(logn)\n    int lcp(\n\
    \        const vector<ull> &a, int l1, int r1,\n        const vector<ull> &b,\
    \ int l2, int r2\n    ) {\n        int len = min(r1 - l1, r2 - l2);\n        int\
    \ low = 0, high = len + 1;\n        while (high - low > 1) {\n            int\
    \ mid = (low + high) / 2;\n            if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid)) low = mid;\n            else high = mid;\n        }\n       \
    \ return low;\n    }\n\n    ull get_hash(const string &s, int l, int r) {\n  \
    \      auto table = build(s);\n        return query(table, l, r);\n    }\n\n \
    \   template<typename T>\n    ull get_hash(const vector<T> &s, int l, int r) {\n\
    \        auto table = build(s);\n        return query(table, l, r);\n    }\n\n\
    \    ull get_hash(const string &s) {\n        auto table = build(s);\n       \
    \ return query(table, 0, s.size());\n    }\n\n    template<typename T>\n    ull\
    \ get_hash(const vector<T> &s) {\n        auto table = build(s);\n        return\
    \ query(table, 0, s.size());\n    }\n\n    // \u9577\u3055len\u306E\u6587\u5B57\
    \u5217\u306Ehash\u306Ex\u6587\u5B57\u76EE(0-indexed)\u3092a\u304B\u3089b\u306B\
    \u5909\u3048\u308B\n    template<typename T>\n    ull update(ull &hash, int len,\
    \ int x, T a, T b) {\n        return hash = add(hash, mul(sub(b, a), power[len\
    \ - x - 1]));\n    }\n\n    // \u30C6\u30FC\u30D6\u30EBa\u306E\u533A\u9593[l,r)\u306E\
    \u56DE\u6587\u5224\u5B9A(a\u3092\u53CD\u8EE2\u3055\u305B\u305F\u30C6\u30FC\u30D6\
    \u30EBrev\u3082\u6E21\u3059)\n    bool is_palindrome(\n        const vector<ull>\
    \ &a, const vector<ull> &rev, int l, int r\n    ) {\n        int n = (int)a.size()\
    \ - 1;\n        assert(r <= n);\n        int len = r - l;\n        int sl = len\
    \ % 2 == 0 ? l + len / 2 : l + len / 2 + 1;\n        int sr = r;\n        int\
    \ tl = n - (l + len / 2);\n        int tr = n - l;\n        return query(a, sl,\
    \ sr) == query(rev, tl, tr);\n    }\n};\n#line 6 \"src/string/RollingHashUpdatable.hpp\"\
    \n\n// \u66F4\u65B0\u3042\u308A\u30ED\u30EA\u30CF\n// \u30FBvector\u3067\u6301\
    \u3063\u3066\u3044\u305F\u30C6\u30FC\u30D6\u30EB\u3092BIT\u3067\u6301\u3064\u3053\
    \u3068\u30671\u70B9\u66F4\u65B0\u3092\u53EF\u80FD\u306B\u3057\u3066\u3044\u308B\
    \u3002\n// \u30FB\u7D2F\u7A4D\u306E\u5024\u3092\u8ABF\u6574\u3059\u308B\u305F\u3081\
    \u306B\u57FA\u6570\u51AA\u3067\u306E\u9664\u7B97\u304C\u5FC5\u8981\u306B\u306A\
    \u308A\u3001\u524D\u8A08\u7B97\u306E\u9006\u5143\u3092\u7528\u610F\u3057\u305F\
    \u3002\nstruct RollingHashUpdatable : public RollingHash {\n    using RollingHash::RollingHash;\n\
    \    using HashTable = AbstractBIT<ull, decltype(&add), decltype(&sub)>;\n\n \
    \   vector<ull> pinv = {1};\n\n    inline void expand(size_t sz) {\n        RollingHash::expand(sz);\n\
    \        // query\u6642\u306B\u4F7F\u3046power\u9006\u5143\u306E\u524D\u8A08\u7B97\
    \n        if (pinv.size() < sz + 1) {\n            int pre_sz = (int)pinv.size();\n\
    \            pinv.resize(sz + 1);\n            // pow\u306F\u305D\u306E\u307E\u307E\
    \u3084\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\n   \
    \         pinv[sz] = pow((uint128_t)power[sz], mod - 2, mod);\n            for\
    \ (int i = sz - 1; i >= pre_sz; i--) {\n                pinv[i] = mul(pinv[i +\
    \ 1], base);\n            }\n        }\n    }\n\n    // \u6587\u5B57\u5217s\u306E\
    \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\uFF1AO(nlogn)\n\
    \    HashTable build(const string &s) {\n        int sz = s.size();\n        expand(sz);\n\
    \        HashTable table(sz, &add, &sub);\n        for (int i = 0; i < sz; i++)\
    \ {\n            table.add(i, mul(power[sz - i - 1], s[i]));\n        }\n    \
    \    return table;\n    }\n\n    template<typename T>\n    HashTable build(const\
    \ vector<T> &s) {\n        int sz = s.size();\n        expand(sz);\n        HashTable\
    \ table(sz, &add, &sub);\n        for (int i = 0; i < sz; i++) {\n           \
    \ table.add(i, mul(power[sz - i - 1], s[i]));\n        }\n        return table;\n\
    \    }\n\n    // table\u306E\u533A\u9593[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \u3092\u8FD4\u3059\uFF1AO(logn)\n    ull query(HashTable &table, int l, int r)\
    \ {\n        expand(r - l);\n        int sz = table.size();\n        expand(abs(sz\
    \ - r - l));\n        return mul(table.query(l, r), pinv[sz - r]);\n    }\n\n\
    \    // \u69CB\u7BC9\u6E08\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EBtable\u306E\
    i\u6587\u5B57\u76EE\u3092c\u306B\u5909\u3048\u308B\uFF1AO(logn)\n    template<typename\
    \ T>\n    void update(HashTable &table, int i, T c) {\n        int sz = table.size();\n\
    \        table.update(i, mul(power[sz - i - 1], c));\n    }\n\n    // \u30CF\u30C3\
    \u30B7\u30E5\u30C6\u30FC\u30D6\u30EBa\u306E\u533A\u9593[l1,r1)\u3068\u3001\u30CF\
    \u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EBb\u306E\u533A\u9593[l2,r2)\u306E\u6587\
    \u5B57\u5217\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\
    \u3092\u8FD4\u3059\uFF1AO(log2\u3064)\n    int lcp(\n        HashTable &a, int\
    \ l1, int r1,\n        HashTable &b, int l2, int r2\n    ) {\n        int len\
    \ = min(r1 - l1, r2 - l2);\n        int low = 0, high = len + 1;\n        while\
    \ (high - low > 1) {\n            int mid = (low + high) / 2;\n            if\
    \ (query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;\n            else\
    \ high = mid;\n        }\n        return low;\n    }\n\n    // \u30C6\u30FC\u30D6\
    \u30EBa\u306E\u533A\u9593[l,r)\u306E\u56DE\u6587\u5224\u5B9A(a\u3092\u53CD\u8EE2\
    \u3055\u305B\u305F\u30C6\u30FC\u30D6\u30EBrev\u3082\u6E21\u3059)\n    bool is_palindrome(\n\
    \        HashTable &a, HashTable &rev, int l, int r\n    ) {\n        int n =\
    \ a.size();\n        assert(r <= n);\n        int len = r - l;\n        int sl\
    \ = len % 2 == 0 ? l + len / 2 : l + len / 2 + 1;\n        int sr = r;\n     \
    \   int tl = n - (l + len / 2);\n        int tr = n - l;\n        return query(a,\
    \ sl, sr) == query(rev, tl, tr);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../common/pow.hpp\"\n\
    #include \"../datastructure/AbstractBIT.hpp\"\n#include \"RollingHash.hpp\"\n\n\
    // \u66F4\u65B0\u3042\u308A\u30ED\u30EA\u30CF\n// \u30FBvector\u3067\u6301\u3063\
    \u3066\u3044\u305F\u30C6\u30FC\u30D6\u30EB\u3092BIT\u3067\u6301\u3064\u3053\u3068\
    \u30671\u70B9\u66F4\u65B0\u3092\u53EF\u80FD\u306B\u3057\u3066\u3044\u308B\u3002\
    \n// \u30FB\u7D2F\u7A4D\u306E\u5024\u3092\u8ABF\u6574\u3059\u308B\u305F\u3081\u306B\
    \u57FA\u6570\u51AA\u3067\u306E\u9664\u7B97\u304C\u5FC5\u8981\u306B\u306A\u308A\
    \u3001\u524D\u8A08\u7B97\u306E\u9006\u5143\u3092\u7528\u610F\u3057\u305F\u3002\
    \nstruct RollingHashUpdatable : public RollingHash {\n    using RollingHash::RollingHash;\n\
    \    using HashTable = AbstractBIT<ull, decltype(&add), decltype(&sub)>;\n\n \
    \   vector<ull> pinv = {1};\n\n    inline void expand(size_t sz) {\n        RollingHash::expand(sz);\n\
    \        // query\u6642\u306B\u4F7F\u3046power\u9006\u5143\u306E\u524D\u8A08\u7B97\
    \n        if (pinv.size() < sz + 1) {\n            int pre_sz = (int)pinv.size();\n\
    \            pinv.resize(sz + 1);\n            // pow\u306F\u305D\u306E\u307E\u307E\
    \u3084\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\n   \
    \         pinv[sz] = pow((uint128_t)power[sz], mod - 2, mod);\n            for\
    \ (int i = sz - 1; i >= pre_sz; i--) {\n                pinv[i] = mul(pinv[i +\
    \ 1], base);\n            }\n        }\n    }\n\n    // \u6587\u5B57\u5217s\u306E\
    \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\uFF1AO(nlogn)\n\
    \    HashTable build(const string &s) {\n        int sz = s.size();\n        expand(sz);\n\
    \        HashTable table(sz, &add, &sub);\n        for (int i = 0; i < sz; i++)\
    \ {\n            table.add(i, mul(power[sz - i - 1], s[i]));\n        }\n    \
    \    return table;\n    }\n\n    template<typename T>\n    HashTable build(const\
    \ vector<T> &s) {\n        int sz = s.size();\n        expand(sz);\n        HashTable\
    \ table(sz, &add, &sub);\n        for (int i = 0; i < sz; i++) {\n           \
    \ table.add(i, mul(power[sz - i - 1], s[i]));\n        }\n        return table;\n\
    \    }\n\n    // table\u306E\u533A\u9593[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \u3092\u8FD4\u3059\uFF1AO(logn)\n    ull query(HashTable &table, int l, int r)\
    \ {\n        expand(r - l);\n        int sz = table.size();\n        expand(abs(sz\
    \ - r - l));\n        return mul(table.query(l, r), pinv[sz - r]);\n    }\n\n\
    \    // \u69CB\u7BC9\u6E08\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EBtable\u306E\
    i\u6587\u5B57\u76EE\u3092c\u306B\u5909\u3048\u308B\uFF1AO(logn)\n    template<typename\
    \ T>\n    void update(HashTable &table, int i, T c) {\n        int sz = table.size();\n\
    \        table.update(i, mul(power[sz - i - 1], c));\n    }\n\n    // \u30CF\u30C3\
    \u30B7\u30E5\u30C6\u30FC\u30D6\u30EBa\u306E\u533A\u9593[l1,r1)\u3068\u3001\u30CF\
    \u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EBb\u306E\u533A\u9593[l2,r2)\u306E\u6587\
    \u5B57\u5217\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\
    \u3092\u8FD4\u3059\uFF1AO(log2\u3064)\n    int lcp(\n        HashTable &a, int\
    \ l1, int r1,\n        HashTable &b, int l2, int r2\n    ) {\n        int len\
    \ = min(r1 - l1, r2 - l2);\n        int low = 0, high = len + 1;\n        while\
    \ (high - low > 1) {\n            int mid = (low + high) / 2;\n            if\
    \ (query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;\n            else\
    \ high = mid;\n        }\n        return low;\n    }\n\n    // \u30C6\u30FC\u30D6\
    \u30EBa\u306E\u533A\u9593[l,r)\u306E\u56DE\u6587\u5224\u5B9A(a\u3092\u53CD\u8EE2\
    \u3055\u305B\u305F\u30C6\u30FC\u30D6\u30EBrev\u3082\u6E21\u3059)\n    bool is_palindrome(\n\
    \        HashTable &a, HashTable &rev, int l, int r\n    ) {\n        int n =\
    \ a.size();\n        assert(r <= n);\n        int len = r - l;\n        int sl\
    \ = len % 2 == 0 ? l + len / 2 : l + len / 2 + 1;\n        int sr = r;\n     \
    \   int tl = n - (l + len / 2);\n        int tr = n - l;\n        return query(a,\
    \ sl, sr) == query(rev, tl, tr);\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/common/pow.hpp
  - src/macros.hpp
  - src/datastructure/AbstractBIT.hpp
  - src/datastructure/BIT.hpp
  - src/string/RollingHash.hpp
  isVerificationFile: false
  path: src/string/RollingHashUpdatable.hpp
  requiredBy: []
  timestamp: '2023-12-06 04:35:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/RollingHashUpdatable.hpp
layout: document
redirect_from:
- /library/src/string/RollingHashUpdatable.hpp
- /library/src/string/RollingHashUpdatable.hpp.html
title: src/string/RollingHashUpdatable.hpp
---
