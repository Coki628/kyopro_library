---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/toint.hpp
    title: src/common/toint.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/toint.hpp\"\n\nll toint(string s) {\n    assert(s.size() < 20);\n \
    \   ll res = 0;\n    for (char &c : s) {\n        res *= 10;\n        res += c\
    \ - '0';\n    }\n    return res;\n}\n\nint toint(char num) {\n    return num -\
    \ '0';\n}\n#line 3 \"src/common/split.hpp\"\n\nvector<ll> split(const string &S,\
    \ char separator) {\n    int N = S.size();\n    vector<ll> res;\n    string cur;\n\
    \    rep(i, N) {\n        if (S[i] == separator) {\n            res.eb(toint(cur));\n\
    \            cur = \"\";\n        } else {\n            cur += S[i];\n       \
    \ }\n    }\n    if (cur.size()) res.eb(toint(cur));\n    return res;\n}\n\n//\
    \ \u6587\u5B57\u5217\u306E\u307E\u307E\u7248(\u5F15\u6570\u4E00\u7DD2\u306A\u306E\
    \u3067\u5171\u5B58\u3067\u304D\u306A\u3044)\n// vector<string> split(const string\
    \ &S, char separator) {\n//     int N = S.size();\n//     vector<string> res;\n\
    //     string cur;\n//     rep(i, N) {\n//         if (S[i] == separator) {\n\
    //             res.eb(cur);\n//             cur = \"\";\n//         } else {\n\
    //             cur += S[i];\n//         }\n//     }\n//     if (cur.size()) res.eb(cur);\n\
    //     return res;\n// }\n"
  code: "#include \"../macros.hpp\"\n#include \"toint.hpp\"\n\nvector<ll> split(const\
    \ string &S, char separator) {\n    int N = S.size();\n    vector<ll> res;\n \
    \   string cur;\n    rep(i, N) {\n        if (S[i] == separator) {\n         \
    \   res.eb(toint(cur));\n            cur = \"\";\n        } else {\n         \
    \   cur += S[i];\n        }\n    }\n    if (cur.size()) res.eb(toint(cur));\n\
    \    return res;\n}\n\n// \u6587\u5B57\u5217\u306E\u307E\u307E\u7248(\u5F15\u6570\
    \u4E00\u7DD2\u306A\u306E\u3067\u5171\u5B58\u3067\u304D\u306A\u3044)\n// vector<string>\
    \ split(const string &S, char separator) {\n//     int N = S.size();\n//     vector<string>\
    \ res;\n//     string cur;\n//     rep(i, N) {\n//         if (S[i] == separator)\
    \ {\n//             res.eb(cur);\n//             cur = \"\";\n//         } else\
    \ {\n//             cur += S[i];\n//         }\n//     }\n//     if (cur.size())\
    \ res.eb(cur);\n//     return res;\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/toint.hpp
  isVerificationFile: false
  path: src/common/split.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/split.hpp
layout: document
redirect_from:
- /library/src/common/split.hpp
- /library/src/common/split.hpp.html
title: src/common/split.hpp
---
