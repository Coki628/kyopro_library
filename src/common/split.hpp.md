---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/toint.hpp
    title: src/common/toint.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/toint.hpp\"\
    \n\nll toint(string s) {\n    // \u3053\u3093\u306A\u4FBF\u5229\u306A\u306E\u3042\
    \u3063\u305F\u308F\u2026\u3002\n    return stoll(s);\n}\n\nint toint(char num)\
    \ {\n    return num - '0';\n}\n#line 4 \"src/common/split.hpp\"\n\n// \u203Bint\u5909\
    \u63DB\u306F\u5225\u9014\u5BFE\u5FDC\u3059\u308B\n// vector<ll> split(const string\
    \ &S, char separator) {\n//     int N = S.size();\n//     vector<ll> res;\n//\
    \     string cur;\n//     rep(i, N) {\n//         if (S[i] == separator) {\n//\
    \             res.eb(toint(cur));\n//             cur = \"\";\n//         } else\
    \ {\n//             cur += S[i];\n//         }\n//     }\n//     if (cur.size())\
    \ res.eb(toint(cur));\n//     return res;\n// }\n\n// \u6587\u5B57\u5217\u306E\
    \u307E\u307E\u7248\nvector<string> split(const string &S, char separator) {\n\
    \    int N = S.size();\n    vector<string> res;\n    string cur;\n    rep(i, N)\
    \ {\n        if (S[i] == separator) {\n            res.eb(cur);\n            cur\
    \ = \"\";\n        } else {\n            cur += S[i];\n        }\n    }\n    if\
    \ (cur.size()) res.eb(cur);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"toint.hpp\"\n\n// \u203B\
    int\u5909\u63DB\u306F\u5225\u9014\u5BFE\u5FDC\u3059\u308B\n// vector<ll> split(const\
    \ string &S, char separator) {\n//     int N = S.size();\n//     vector<ll> res;\n\
    //     string cur;\n//     rep(i, N) {\n//         if (S[i] == separator) {\n\
    //             res.eb(toint(cur));\n//             cur = \"\";\n//         } else\
    \ {\n//             cur += S[i];\n//         }\n//     }\n//     if (cur.size())\
    \ res.eb(toint(cur));\n//     return res;\n// }\n\n// \u6587\u5B57\u5217\u306E\
    \u307E\u307E\u7248\nvector<string> split(const string &S, char separator) {\n\
    \    int N = S.size();\n    vector<string> res;\n    string cur;\n    rep(i, N)\
    \ {\n        if (S[i] == separator) {\n            res.eb(cur);\n            cur\
    \ = \"\";\n        } else {\n            cur += S[i];\n        }\n    }\n    if\
    \ (cur.size()) res.eb(cur);\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/toint.hpp
  isVerificationFile: false
  path: src/common/split.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/split.hpp
layout: document
redirect_from:
- /library/src/common/split.hpp
- /library/src/common/split.hpp.html
title: src/common/split.hpp
---