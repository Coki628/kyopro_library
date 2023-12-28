---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/RollingHash2D.hpp
    title: src/string/RollingHash2D.hpp
  - icon: ':warning:'
    path: src/string/RollingHashUpdatable.hpp
    title: src/string/RollingHashUpdatable.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/string/rolling-hash.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/string/RollingHash.hpp\"\n\n// \u30ED\u30EA\
    \u30CF\n// see: https://ei1333.github.io/library/string/rolling-hash.hpp\nstruct\
    \ RollingHash {\n    static const ull mod = (1ull << 61ull) - 1;\n    using uint128_t\
    \ = __uint128_t;\n    vector<ull> power;\n    const ull base;\n\n    static inline\
    \ ull add(ull a, ull b) {\n        if ((a += b) >= mod) a -= mod;\n        return\
    \ a;\n    }\n\n    static inline ull sub(ull a, ull b) {\n        return add(a,\
    \ mod - b);\n    }\n\n    static inline ull mul(ull a, ull b) {\n        uint128_t\
    \ c = (uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n    //\
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
    \ sr) == query(rev, tl, tr);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u30ED\u30EA\u30CF\n// see:\
    \ https://ei1333.github.io/library/string/rolling-hash.hpp\nstruct RollingHash\
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
    \ sr) == query(rev, tl, tr);\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/RollingHash.hpp
  requiredBy:
  - src/string/RollingHashUpdatable.hpp
  - src/string/RollingHash2D.hpp
  timestamp: '2023-12-06 04:35:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/RollingHash.hpp
layout: document
redirect_from:
- /library/src/string/RollingHash.hpp
- /library/src/string/RollingHash.hpp.html
title: src/string/RollingHash.hpp
---
