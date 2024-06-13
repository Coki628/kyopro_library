---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/bit_vector.hpp
    title: src/datastructure/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc281/submissions/37200871
    - https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp
    - https://twitter.com/US_kyopro/status/1601792850886242304
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/datastructure/bit_vector.hpp\"\n#include <immintrin.h>\n\
    \nstruct bit_vector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n \
    \   using u64 = uint64_t;\n\n    static constexpr u32 w = 64;\n    vector<u64>\
    \ block;\n    vector<u32> count;\n    u32 n, zeros;\n\n    inline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n    inline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\n\n    bit_vector() {}\n    bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n        n = zeros = _n;\n        block.resize(n / w + 1, 0);\n\
    \        count.resize(block.size(), 0);\n    }\n\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for (u32 i = 1; i < block.size(); ++i)\n \
    \           count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n        zeros\
    \ = rank0(n);\n    }\n\n    inline u32 rank0(u32 i) const { return i - rank1(i);\
    \ }\n    __attribute__((target(\"bmi2,popcnt\"))) inline u32 rank1(u32 i) const\
    \ {\n        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i %\
    \ w));\n    }\n};\n#line 5 \"src/datastructure/WaveletMatrix.hpp\"\n\n// Wavelet\
    \ Matrix\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp\n\
    // \u4F7F\u7528\u4E0A\u306E\u6CE8\u610F\u70B9\n// \u30FB\u8CA0\u6570\u304C\u3042\
    \u308B\u6642\u306F\u5EA7\u5727\u304B\u4E0B\u99C4\u5C65\u304B\u3059\u304B\u3059\
    \u308B\u3002\n// \u4EE5\u524D\u306E(\u3046\u3057\u3055\u3093\u7248)\u304B\u3089\
    \u306E\u5909\u66F4\u70B9\n// \u30FB\u6700\u5927\u30D3\u30C3\u30C8\u6307\u5B9A\u3057\
    \u306A\u304F\u3066\u3088\u304F\u306A\u3063\u305F\u3002\n// \u30FB\u521D\u671F\u5316\
    \u306F\u914D\u5217\u6E21\u3059\u4EE5\u5916\u306B\u3001\u30B5\u30A4\u30BA\u6307\
    \u5B9A\u3057\u3066\u5F8C\u304B\u3089set\u3057\u3066build\u306E\u65B9\u3082\u3067\
    \u304D\u308B\u3088\u3046\u306B\u306A\u3063\u305F\u3002\n// \u30FB\u3053\u3063\u3061\
    \u306E\u304C\u3061\u3087\u3063\u3068\u901F\u3044\u3002(\u591A\u5206)\ntemplate\
    \ <typename T>\nstruct WaveletMatrix {\n    using u32 = uint32_t;\n    using i64\
    \ = int64_t;\n    using u64 = uint64_t;\n\n    int n, lg;\n    vector<T> a;\n\
    \    vector<bit_vector> bv;\n    vector<vector<T>> sum;\n\n    WaveletMatrix(u32\
    \ _n) : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const vector<T>& _a) :\
    \ n(_a.size()), a(_a) { build(); }\n\n    __attribute__((optimize(\"O3\"))) void\
    \ build() {\n        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n\
    \        bv.assign(lg, n);\n        sum.assign(lg + 1, vector<T>(n + 1, (T)0));\n\
    \        vector<T> l(n), r(n), cur = a;\n        for (int h = lg - 1; h >= 0;\
    \ --h) {\n            int left = 0, right = 0;\n            for (int i = 0; i\
    \ < n; ++i) {\n                if ((cur[i] >> h) & 1) {\n                    bv[h].set(i);\n\
    \                    r[right++] = cur[i];\n                } else {\n        \
    \            l[left++] = cur[i];\n                }\n            }\n         \
    \   bv[h].build();\n            swap(cur, l);\n            copy(r.begin(), r.begin()\
    \ + right, cur.begin() + left);\n            for (int i = 0; i < n; i++) {\n \
    \               sum[h][i + 1] = sum[h][i] + cur[i];\n            }\n        }\n\
    \        // \u5168\u4F53\u306E\u7D2F\u7A4D\u548C\u3092\u6301\u3063\u3066\u304A\
    \u304F\n        for (int i = 0; i < n; i++) {\n            sum[lg][i + 1] = sum[lg][i]\
    \ + a[i];\n        }\n        return;\n    }\n\n    void set(u32 i, const T& x)\
    \ { \n        assert(x >= 0);\n        a[i] = x; \n    }\n\n    inline pair<u32,\
    \ u32> succ0(int l, int r, int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n\n    inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\n        u32 l0 = bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n\
    \        u32 zeros = bv[h].zeros;\n        return make_pair(l + zeros - l0, r\
    \ + zeros - r0);\n    }\n\n    // return a[k]\n    T access(u32 k) const {\n \
    \       T ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            u32\
    \ f = bv[h].get(k);\n            ret |= f ? T(1) << h : 0;\n            k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n        }\n        return\
    \ ret;\n    }\n\n    // k-th (0-indexed) smallest number in a[l, r)\n    T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n        T res = 0;\n        for (int h = lg - 1; h\
    \ >= 0; --h) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n  \
    \          if (k < r0 - l0)\n                l = l0, r = r0;\n            else\
    \ {\n                k -= r0 - l0;\n                res |= (T)1 << h;\n      \
    \          l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n  \
    \          }\n        }\n        return res;\n    }\n\n    // k-th (0-indexed)\
    \ largest number in a[l, r)\n    T kth_largest(int l, int r, int k) {\n      \
    \  return kth_smallest(l, r, r - l - k - 1);\n    }\n\n    // \u53C2\u8003\uFF1A\
    https://twitter.com/US_kyopro/status/1601792850886242304\n    // \u3000\u3000\u3000\
    https://atcoder.jp/contests/abc281/submissions/37200871\n    // sum of [0,k)th\
    \ smallest elements([l, r))\n    T kth_smallest_sum(int l, int r, int k) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k && k <=\
    \ r - l);\n        T res = 0;\n        for(int h = lg - 1; h >= 0; h--) {\n  \
    \          u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if (k <\
    \ r0 - l0) {\n                l = l0, r = r0;\n            } else {\n        \
    \        k -= r0 - l0;\n                res += sum[h][r0] - sum[h][l0];\n    \
    \            l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            }\n        }\n        if (k) res += sum[0][l + k] - sum[0][l];\n\
    \        return res;\n    }\n\n    // sum of [0,k)th largest elements([l, r))\n\
    \    T kth_largest_sum(int l, int r, int k) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        assert(0 <= k && k <= r - l);\n        return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\n    }\n\n    // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int r, T upper) {\n\
    \        if (upper >= (T(1) << lg)) return r - l;\n        int ret = 0;\n    \
    \    for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) &\
    \ 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if\
    \ (f) {\n                ret += r0 - l0;\n                l += bv[h].zeros - l0;\n\
    \                r += bv[h].zeros - r0;\n            } else {\n              \
    \  l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    T range_freq_sum(int l, int r, T upper) {\n        if (upper\
    \ >= (T(1) << lg)) return sum[lg][r] - sum[lg][l];\n        T ret = 0;\n     \
    \   for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) & 1;\n\
    \            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if (f)\
    \ {\n                l += bv[h].zeros - l0;\n                r += bv[h].zeros\
    \ - r0;\n                ret += sum[h][r0] - sum[h][l0];\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return ret;\n    }\n\n    // l <= x < r and lower <= y < upper \u306A\
    \u8981\u7D20\u306E\u500B\u6570\n    int range_freq(int l, int r, T lower, T upper)\
    \ {\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\
    \n    // l <= x < r and lower <= y < upper \u306A\u8981\u7D20\u306E\u7DCF\u548C\
    \n    T range_freq_sum(int l, int r, T lower, T upper) {\n        return range_freq_sum(l,\
    \ r, upper) - range_freq_sum(l, r, lower);\n    }\n\n    // max v[i] s.t. (l <=\
    \ i < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n      \
    \  int cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"bit_vector.hpp\"\n#include\
    \ <immintrin.h>\n\n// Wavelet Matrix\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp\n\
    // \u4F7F\u7528\u4E0A\u306E\u6CE8\u610F\u70B9\n// \u30FB\u8CA0\u6570\u304C\u3042\
    \u308B\u6642\u306F\u5EA7\u5727\u304B\u4E0B\u99C4\u5C65\u304B\u3059\u304B\u3059\
    \u308B\u3002\n// \u4EE5\u524D\u306E(\u3046\u3057\u3055\u3093\u7248)\u304B\u3089\
    \u306E\u5909\u66F4\u70B9\n// \u30FB\u6700\u5927\u30D3\u30C3\u30C8\u6307\u5B9A\u3057\
    \u306A\u304F\u3066\u3088\u304F\u306A\u3063\u305F\u3002\n// \u30FB\u521D\u671F\u5316\
    \u306F\u914D\u5217\u6E21\u3059\u4EE5\u5916\u306B\u3001\u30B5\u30A4\u30BA\u6307\
    \u5B9A\u3057\u3066\u5F8C\u304B\u3089set\u3057\u3066build\u306E\u65B9\u3082\u3067\
    \u304D\u308B\u3088\u3046\u306B\u306A\u3063\u305F\u3002\n// \u30FB\u3053\u3063\u3061\
    \u306E\u304C\u3061\u3087\u3063\u3068\u901F\u3044\u3002(\u591A\u5206)\ntemplate\
    \ <typename T>\nstruct WaveletMatrix {\n    using u32 = uint32_t;\n    using i64\
    \ = int64_t;\n    using u64 = uint64_t;\n\n    int n, lg;\n    vector<T> a;\n\
    \    vector<bit_vector> bv;\n    vector<vector<T>> sum;\n\n    WaveletMatrix(u32\
    \ _n) : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const vector<T>& _a) :\
    \ n(_a.size()), a(_a) { build(); }\n\n    __attribute__((optimize(\"O3\"))) void\
    \ build() {\n        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n\
    \        bv.assign(lg, n);\n        sum.assign(lg + 1, vector<T>(n + 1, (T)0));\n\
    \        vector<T> l(n), r(n), cur = a;\n        for (int h = lg - 1; h >= 0;\
    \ --h) {\n            int left = 0, right = 0;\n            for (int i = 0; i\
    \ < n; ++i) {\n                if ((cur[i] >> h) & 1) {\n                    bv[h].set(i);\n\
    \                    r[right++] = cur[i];\n                } else {\n        \
    \            l[left++] = cur[i];\n                }\n            }\n         \
    \   bv[h].build();\n            swap(cur, l);\n            copy(r.begin(), r.begin()\
    \ + right, cur.begin() + left);\n            for (int i = 0; i < n; i++) {\n \
    \               sum[h][i + 1] = sum[h][i] + cur[i];\n            }\n        }\n\
    \        // \u5168\u4F53\u306E\u7D2F\u7A4D\u548C\u3092\u6301\u3063\u3066\u304A\
    \u304F\n        for (int i = 0; i < n; i++) {\n            sum[lg][i + 1] = sum[lg][i]\
    \ + a[i];\n        }\n        return;\n    }\n\n    void set(u32 i, const T& x)\
    \ { \n        assert(x >= 0);\n        a[i] = x; \n    }\n\n    inline pair<u32,\
    \ u32> succ0(int l, int r, int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n\n    inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\n        u32 l0 = bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n\
    \        u32 zeros = bv[h].zeros;\n        return make_pair(l + zeros - l0, r\
    \ + zeros - r0);\n    }\n\n    // return a[k]\n    T access(u32 k) const {\n \
    \       T ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            u32\
    \ f = bv[h].get(k);\n            ret |= f ? T(1) << h : 0;\n            k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n        }\n        return\
    \ ret;\n    }\n\n    // k-th (0-indexed) smallest number in a[l, r)\n    T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n        T res = 0;\n        for (int h = lg - 1; h\
    \ >= 0; --h) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n  \
    \          if (k < r0 - l0)\n                l = l0, r = r0;\n            else\
    \ {\n                k -= r0 - l0;\n                res |= (T)1 << h;\n      \
    \          l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n  \
    \          }\n        }\n        return res;\n    }\n\n    // k-th (0-indexed)\
    \ largest number in a[l, r)\n    T kth_largest(int l, int r, int k) {\n      \
    \  return kth_smallest(l, r, r - l - k - 1);\n    }\n\n    // \u53C2\u8003\uFF1A\
    https://twitter.com/US_kyopro/status/1601792850886242304\n    // \u3000\u3000\u3000\
    https://atcoder.jp/contests/abc281/submissions/37200871\n    // sum of [0,k)th\
    \ smallest elements([l, r))\n    T kth_smallest_sum(int l, int r, int k) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k && k <=\
    \ r - l);\n        T res = 0;\n        for(int h = lg - 1; h >= 0; h--) {\n  \
    \          u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if (k <\
    \ r0 - l0) {\n                l = l0, r = r0;\n            } else {\n        \
    \        k -= r0 - l0;\n                res += sum[h][r0] - sum[h][l0];\n    \
    \            l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            }\n        }\n        if (k) res += sum[0][l + k] - sum[0][l];\n\
    \        return res;\n    }\n\n    // sum of [0,k)th largest elements([l, r))\n\
    \    T kth_largest_sum(int l, int r, int k) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        assert(0 <= k && k <= r - l);\n        return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\n    }\n\n    // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int r, T upper) {\n\
    \        if (upper >= (T(1) << lg)) return r - l;\n        int ret = 0;\n    \
    \    for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) &\
    \ 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if\
    \ (f) {\n                ret += r0 - l0;\n                l += bv[h].zeros - l0;\n\
    \                r += bv[h].zeros - r0;\n            } else {\n              \
    \  l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    T range_freq_sum(int l, int r, T upper) {\n        if (upper\
    \ >= (T(1) << lg)) return sum[lg][r] - sum[lg][l];\n        T ret = 0;\n     \
    \   for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper >> h) & 1;\n\
    \            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if (f)\
    \ {\n                l += bv[h].zeros - l0;\n                r += bv[h].zeros\
    \ - r0;\n                ret += sum[h][r0] - sum[h][l0];\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return ret;\n    }\n\n    // l <= x < r and lower <= y < upper \u306A\
    \u8981\u7D20\u306E\u500B\u6570\n    int range_freq(int l, int r, T lower, T upper)\
    \ {\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\
    \n    // l <= x < r and lower <= y < upper \u306A\u8981\u7D20\u306E\u7DCF\u548C\
    \n    T range_freq_sum(int l, int r, T lower, T upper) {\n        return range_freq_sum(l,\
    \ r, upper) - range_freq_sum(l, r, lower);\n    }\n\n    // max v[i] s.t. (l <=\
    \ i < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n      \
    \  int cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n};"
  dependsOn:
  - src/base.hpp
  - src/datastructure/bit_vector.hpp
  isVerificationFile: false
  path: src/datastructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/src/datastructure/WaveletMatrix.hpp
- /library/src/datastructure/WaveletMatrix.hpp.html
title: src/datastructure/WaveletMatrix.hpp
---
