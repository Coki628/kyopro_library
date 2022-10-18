---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/SuccinctIndexableDictionary.hpp
    title: src/datastructure/SuccinctIndexableDictionary.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/datastructure/SuccinctIndexableDictionary.hpp\"\
    \n\n// \u5B8C\u5099\u8F9E\u66F8(Wavelet Matrix\u3068\u30BB\u30C3\u30C8\u3067\u4F7F\
    \u3046)\nstruct SuccinctIndexableDictionary {\n    size_t length;\n    size_t\
    \ blocks;\n    vector< unsigned > bit, sum;\n\n    SuccinctIndexableDictionary()\
    \ = default;\n\n    SuccinctIndexableDictionary(size_t length) : length(length),\
    \ blocks((length + 31) >> 5) {\n        bit.assign(blocks, 0U);\n        sum.assign(blocks,\
    \ 0U);\n    }\n\n    void set(int k) {\n        bit[k >> 5] |= 1U << (k & 31);\n\
    \    }\n\n    void build() {\n        sum[0] = 0U;\n        for(int i = 1; i <\
    \ blocks; i++) {\n        sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n\
    \        }\n    }\n\n    bool operator[](int k) {\n        return (bool((bit[k\
    \ >> 5] >> (k & 31)) & 1));\n    }\n\n    int rank(int k) {\n        return (sum[k\
    \ >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n    }\n\n\
    \    int rank(bool val, int k) {\n        return (val ? rank(k) : k - rank(k));\n\
    \    }\n};\n#line 3 \"src/datastructure/_WaveletMatrix.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp\n\
    // Wavelet Matrix\n// \u4F7F\u7528\u4E0A\u306E\u6CE8\u610F\u70B9\n// \u30FB\u5165\
    \u308C\u308B\u5024\u306F\u8CA0\u6570\u3060\u3068(Compressed\u306E\u65B9\u3092\u4F7F\
    \u3046\u3068\u3057\u3066\u3082)\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\
    \u8CA0\u6570\u304C\u3042\u308B\u6642\u306F\u5FC5\u305A\u4E88\u3081\u5EA7\u5727\
    \u3057\u3066\u304B\u3089\u4F7F\u3046\u3053\u3068\u3002\n\n// Wavelet Matrix\n\
    template< typename T, int MAXLOG >\nstruct WaveletMatrix {\n    size_t length;\n\
    \    SuccinctIndexableDictionary matrix[MAXLOG];\n    int mid[MAXLOG];\n\n   \
    \ WaveletMatrix() = default;\n\n    WaveletMatrix(vector< T > v) : length(v.size())\
    \ {\n        vector< T > l(length), r(length);\n        for(int level = MAXLOG\
    \ - 1; level >= 0; level--) {\n        matrix[level] = SuccinctIndexableDictionary(length\
    \ + 1);\n        int left = 0, right = 0;\n        for(int i = 0; i < length;\
    \ i++) {\n            if(((v[i] >> level) & 1)) {\n            matrix[level].set(i);\n\
    \            r[right++] = v[i];\n            } else {\n            l[left++] =\
    \ v[i];\n            }\n        }\n        mid[level] = left;\n        matrix[level].build();\n\
    \        v.swap(l);\n        for(int i = 0; i < right; i++) {\n            v[left\
    \ + i] = r[i];\n        }\n        }\n    }\n\n    pair< int, int > succ(bool\
    \ f, int l, int r, int level) {\n        return {matrix[level].rank(f, l) + mid[level]\
    \ * f, matrix[level].rank(f, r) + mid[level] * f};\n    }\n\n    // v[k]\n   \
    \ T access(int k) {\n        T ret = 0;\n        for(int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n        bool f = matrix[level][k];\n        if(f) ret |= T(1)\
    \ << level;\n        k = matrix[level].rank(f, k) + mid[level] * f;\n        }\n\
    \        return ret;\n    }\n\n    T operator[](const int &k) {\n        return\
    \ access(k);\n    }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n    int\
    \ rank(const T &x, int r) {\n        int l = 0;\n        for(int level = MAXLOG\
    \ - 1; level >= 0; level--) {\n        tie(l, r) = succ((x >> level) & 1, l, r,\
    \ level);\n        }\n        return r - l;\n    }\n\n    // k-th(0-indexed) smallest\
    \ number in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n        assert(0\
    \ <= k && k < r - l);\n        T ret = 0;\n        for(int level = MAXLOG - 1;\
    \ level >= 0; level--) {\n        int cnt = matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n        bool f = cnt <= k;\n        if(f) {\n            ret |= T(1) <<\
    \ level;\n            k -= cnt;\n        }\n        tie(l, r) = succ(f, l, r,\
    \ level);\n        }\n        return ret;\n    }\n\n    // k-th(0-indexed) largest\
    \ number in v[l,r)\n    T kth_largest(int l, int r, int k) {\n        return kth_smallest(l,\
    \ r, r - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n        assert(upper >= 0);\n  \
    \      int ret = 0;\n        for(int level = MAXLOG - 1; level >= 0; level--)\
    \ {\n        bool f = ((upper >> level) & 1);\n        if(f) ret += matrix[level].rank(false,\
    \ r) - matrix[level].rank(false, l);\n        tie(l, r) = succ(f, l, r, level);\n\
    \        }\n        return ret;\n    }\n\n    // count i s.t. (l <= i < r) &&\
    \ (lower <= v[i] < upper)\n    int range_freq(int l, int r, T lower, T upper)\
    \ {\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\
    \n    // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n    T prev_value(int l,\
    \ int r, T upper) {\n        int cnt = range_freq(l, r, upper);\n        return\
    \ cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n    }\n\n    // min v[i] s.t.\
    \ (l <= i < r) && (lower <= v[i])\n    T next_value(int l, int r, T lower) {\n\
    \        int cnt = range_freq(l, r, lower);\n        return cnt == r - l ? T(-1)\
    \ : kth_smallest(l, r, cnt);\n    }\n};\n\ntemplate< typename T, int MAXLOG >\n\
    struct CompressedWaveletMatrix {\n    WaveletMatrix< int, MAXLOG > mat;\n    vector<\
    \ T > ys;\n\n    CompressedWaveletMatrix(const vector< T > &v) : ys(v) {\n   \
    \     sort(begin(ys), end(ys));\n        ys.erase(unique(begin(ys), end(ys)),\
    \ end(ys));\n        vector< int > t(v.size());\n        for(int i = 0; i < v.size();\
    \ i++) t[i] = get(v[i]);\n        mat = WaveletMatrix< int, MAXLOG >(t);\n   \
    \ }\n\n    inline int get(const T& x) {\n        return lower_bound(begin(ys),\
    \ end(ys), x) - begin(ys);\n    }\n\n    T access(int k) {\n        return ys[mat.access(k)];\n\
    \    }\n\n    T operator[](const int &k) {\n        return access(k);\n    }\n\
    \n    int rank(const T &x, int r) {\n        auto pos = get(x);\n        if(pos\
    \ == ys.size() || ys[pos] != x) return 0;\n        return mat.rank(pos, r);\n\
    \    }\n\n    T kth_smallest(int l, int r, int k) {\n        return ys[mat.kth_smallest(l,\
    \ r, k)];\n    }\n\n    T kth_largest(int l, int r, int k) {\n        return ys[mat.kth_largest(l,\
    \ r, k)];\n    }\n\n    int range_freq(int l, int r, T upper) {\n        return\
    \ mat.range_freq(l, r, get(upper));\n    }\n\n    int range_freq(int l, int r,\
    \ T lower, T upper) {\n        return mat.range_freq(l, r, get(lower), get(upper));\n\
    \    }\n\n    T prev_value(int l, int r, T upper) {\n        auto ret = mat.prev_value(l,\
    \ r, get(upper));\n        return ret == -1 ? T(-1) : ys[ret];\n    }\n\n    T\
    \ next_value(int l, int r, T lower) {\n        auto ret = mat.next_value(l, r,\
    \ get(lower));\n        return ret == -1 ? T(-1) : ys[ret];\n    }\n};\n"
  code: "#include \"../base.hpp\"\n#include \"SuccinctIndexableDictionary.hpp\"\n\n\
    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp\n\
    // Wavelet Matrix\n// \u4F7F\u7528\u4E0A\u306E\u6CE8\u610F\u70B9\n// \u30FB\u5165\
    \u308C\u308B\u5024\u306F\u8CA0\u6570\u3060\u3068(Compressed\u306E\u65B9\u3092\u4F7F\
    \u3046\u3068\u3057\u3066\u3082)\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\
    \u8CA0\u6570\u304C\u3042\u308B\u6642\u306F\u5FC5\u305A\u4E88\u3081\u5EA7\u5727\
    \u3057\u3066\u304B\u3089\u4F7F\u3046\u3053\u3068\u3002\n\n// Wavelet Matrix\n\
    template< typename T, int MAXLOG >\nstruct WaveletMatrix {\n    size_t length;\n\
    \    SuccinctIndexableDictionary matrix[MAXLOG];\n    int mid[MAXLOG];\n\n   \
    \ WaveletMatrix() = default;\n\n    WaveletMatrix(vector< T > v) : length(v.size())\
    \ {\n        vector< T > l(length), r(length);\n        for(int level = MAXLOG\
    \ - 1; level >= 0; level--) {\n        matrix[level] = SuccinctIndexableDictionary(length\
    \ + 1);\n        int left = 0, right = 0;\n        for(int i = 0; i < length;\
    \ i++) {\n            if(((v[i] >> level) & 1)) {\n            matrix[level].set(i);\n\
    \            r[right++] = v[i];\n            } else {\n            l[left++] =\
    \ v[i];\n            }\n        }\n        mid[level] = left;\n        matrix[level].build();\n\
    \        v.swap(l);\n        for(int i = 0; i < right; i++) {\n            v[left\
    \ + i] = r[i];\n        }\n        }\n    }\n\n    pair< int, int > succ(bool\
    \ f, int l, int r, int level) {\n        return {matrix[level].rank(f, l) + mid[level]\
    \ * f, matrix[level].rank(f, r) + mid[level] * f};\n    }\n\n    // v[k]\n   \
    \ T access(int k) {\n        T ret = 0;\n        for(int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n        bool f = matrix[level][k];\n        if(f) ret |= T(1)\
    \ << level;\n        k = matrix[level].rank(f, k) + mid[level] * f;\n        }\n\
    \        return ret;\n    }\n\n    T operator[](const int &k) {\n        return\
    \ access(k);\n    }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n    int\
    \ rank(const T &x, int r) {\n        int l = 0;\n        for(int level = MAXLOG\
    \ - 1; level >= 0; level--) {\n        tie(l, r) = succ((x >> level) & 1, l, r,\
    \ level);\n        }\n        return r - l;\n    }\n\n    // k-th(0-indexed) smallest\
    \ number in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n        assert(0\
    \ <= k && k < r - l);\n        T ret = 0;\n        for(int level = MAXLOG - 1;\
    \ level >= 0; level--) {\n        int cnt = matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n        bool f = cnt <= k;\n        if(f) {\n            ret |= T(1) <<\
    \ level;\n            k -= cnt;\n        }\n        tie(l, r) = succ(f, l, r,\
    \ level);\n        }\n        return ret;\n    }\n\n    // k-th(0-indexed) largest\
    \ number in v[l,r)\n    T kth_largest(int l, int r, int k) {\n        return kth_smallest(l,\
    \ r, r - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n        assert(upper >= 0);\n  \
    \      int ret = 0;\n        for(int level = MAXLOG - 1; level >= 0; level--)\
    \ {\n        bool f = ((upper >> level) & 1);\n        if(f) ret += matrix[level].rank(false,\
    \ r) - matrix[level].rank(false, l);\n        tie(l, r) = succ(f, l, r, level);\n\
    \        }\n        return ret;\n    }\n\n    // count i s.t. (l <= i < r) &&\
    \ (lower <= v[i] < upper)\n    int range_freq(int l, int r, T lower, T upper)\
    \ {\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\
    \n    // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n    T prev_value(int l,\
    \ int r, T upper) {\n        int cnt = range_freq(l, r, upper);\n        return\
    \ cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n    }\n\n    // min v[i] s.t.\
    \ (l <= i < r) && (lower <= v[i])\n    T next_value(int l, int r, T lower) {\n\
    \        int cnt = range_freq(l, r, lower);\n        return cnt == r - l ? T(-1)\
    \ : kth_smallest(l, r, cnt);\n    }\n};\n\ntemplate< typename T, int MAXLOG >\n\
    struct CompressedWaveletMatrix {\n    WaveletMatrix< int, MAXLOG > mat;\n    vector<\
    \ T > ys;\n\n    CompressedWaveletMatrix(const vector< T > &v) : ys(v) {\n   \
    \     sort(begin(ys), end(ys));\n        ys.erase(unique(begin(ys), end(ys)),\
    \ end(ys));\n        vector< int > t(v.size());\n        for(int i = 0; i < v.size();\
    \ i++) t[i] = get(v[i]);\n        mat = WaveletMatrix< int, MAXLOG >(t);\n   \
    \ }\n\n    inline int get(const T& x) {\n        return lower_bound(begin(ys),\
    \ end(ys), x) - begin(ys);\n    }\n\n    T access(int k) {\n        return ys[mat.access(k)];\n\
    \    }\n\n    T operator[](const int &k) {\n        return access(k);\n    }\n\
    \n    int rank(const T &x, int r) {\n        auto pos = get(x);\n        if(pos\
    \ == ys.size() || ys[pos] != x) return 0;\n        return mat.rank(pos, r);\n\
    \    }\n\n    T kth_smallest(int l, int r, int k) {\n        return ys[mat.kth_smallest(l,\
    \ r, k)];\n    }\n\n    T kth_largest(int l, int r, int k) {\n        return ys[mat.kth_largest(l,\
    \ r, k)];\n    }\n\n    int range_freq(int l, int r, T upper) {\n        return\
    \ mat.range_freq(l, r, get(upper));\n    }\n\n    int range_freq(int l, int r,\
    \ T lower, T upper) {\n        return mat.range_freq(l, r, get(lower), get(upper));\n\
    \    }\n\n    T prev_value(int l, int r, T upper) {\n        auto ret = mat.prev_value(l,\
    \ r, get(upper));\n        return ret == -1 ? T(-1) : ys[ret];\n    }\n\n    T\
    \ next_value(int l, int r, T lower) {\n        auto ret = mat.next_value(l, r,\
    \ get(lower));\n        return ret == -1 ? T(-1) : ys[ret];\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/datastructure/SuccinctIndexableDictionary.hpp
  isVerificationFile: false
  path: src/datastructure/_WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/_WaveletMatrix.hpp
layout: document
redirect_from:
- /library/src/datastructure/_WaveletMatrix.hpp
- /library/src/datastructure/_WaveletMatrix.hpp.html
title: src/datastructure/_WaveletMatrix.hpp
---
