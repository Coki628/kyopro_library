---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/merge_segment.hpp\"\
    \n\n// 2\u3064\u306E\u9589\u533A\u9593seg1[l,r],seg2[l,r]\u304B\u3089\u3001\u91CD\
    \u8907\u3092\u9664\u3044\u305F\u9577\u3055\u3092\u8FD4\u3059\nll merge_segment(pll\
    \ seg1, pll seg2) {\n    auto &[l1, r1] = seg1;\n    auto &[l2, r2] = seg2;\n\
    \    if (l1 > l2) {\n        swap(l1, l2);\n        swap(r1, r2);\n    }\n   \
    \ ll ln1 = r1 - l1 + 1;\n    ll ln2 = r2 - l2 + 1;\n    if (ln1 <= 0 and ln2 <=\
    \ 0) {\n        return 0;\n    }\n    elif (ln2 <= 0 or l2 <= r1 and r2 <= r1)\
    \ {\n        return ln1;\n    }\n    elif (l2 <= r1 and r2 > r1) {\n        return\
    \ ln1 + ln2 - (r1 - l2 + 1);\n    }\n    else {\n        return ln1 + ln2;\n \
    \   }\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// 2\u3064\u306E\u9589\u533A\u9593\
    seg1[l,r],seg2[l,r]\u304B\u3089\u3001\u91CD\u8907\u3092\u9664\u3044\u305F\u9577\
    \u3055\u3092\u8FD4\u3059\nll merge_segment(pll seg1, pll seg2) {\n    auto &[l1,\
    \ r1] = seg1;\n    auto &[l2, r2] = seg2;\n    if (l1 > l2) {\n        swap(l1,\
    \ l2);\n        swap(r1, r2);\n    }\n    ll ln1 = r1 - l1 + 1;\n    ll ln2 =\
    \ r2 - l2 + 1;\n    if (ln1 <= 0 and ln2 <= 0) {\n        return 0;\n    }\n \
    \   elif (ln2 <= 0 or l2 <= r1 and r2 <= r1) {\n        return ln1;\n    }\n \
    \   elif (l2 <= r1 and r2 > r1) {\n        return ln1 + ln2 - (r1 - l2 + 1);\n\
    \    }\n    else {\n        return ln1 + ln2;\n    }\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/merge_segment.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/merge_segment.hpp
layout: document
redirect_from:
- /library/src/datastructure/merge_segment.hpp
- /library/src/datastructure/merge_segment.hpp.html
title: src/datastructure/merge_segment.hpp
---
