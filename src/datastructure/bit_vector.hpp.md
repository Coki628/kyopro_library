---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/WaveletMatrix.hpp
    title: src/datastructure/WaveletMatrix.hpp
  - icon: ':warning:'
    path: src/datastructure/WeightedWaveletMatrix.hpp
    title: src/datastructure/WeightedWaveletMatrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    \ w));\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include <immintrin.h>\n\nstruct\
    \ bit_vector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
    \ u64 = uint64_t;\n\n    static constexpr u32 w = 64;\n    vector<u64> block;\n\
    \    vector<u32> count;\n    u32 n, zeros;\n\n    inline u32 get(u32 i) const\
    \ { return u32(block[i / w] >> (i % w)) & 1u; }\n    inline void set(u32 i) {\
    \ block[i / w] |= 1LL << (i % w); }\n\n    bit_vector() {}\n    bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n        n = zeros = _n;\n        block.resize(n / w + 1, 0);\n\
    \        count.resize(block.size(), 0);\n    }\n\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for (u32 i = 1; i < block.size(); ++i)\n \
    \           count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n        zeros\
    \ = rank0(n);\n    }\n\n    inline u32 rank0(u32 i) const { return i - rank1(i);\
    \ }\n    __attribute__((target(\"bmi2,popcnt\"))) inline u32 rank1(u32 i) const\
    \ {\n        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i %\
    \ w));\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/bit_vector.hpp
  requiredBy:
  - src/datastructure/WeightedWaveletMatrix.hpp
  - src/datastructure/WaveletMatrix.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/bit_vector.hpp
layout: document
redirect_from:
- /library/src/datastructure/bit_vector.hpp
- /library/src/datastructure/bit_vector.hpp.html
title: src/datastructure/bit_vector.hpp
---
