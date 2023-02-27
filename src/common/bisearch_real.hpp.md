---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/bisearch_real.hpp\"\
    \n\n// \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u5024\u3092\u898B\u3064\
    \u3051\u308B\u4E8C\u5206\u63A2\u7D22(\u5B9F\u6570)\ntemplate<typename F>\nld bisearch_min(ld\
    \ mn, ld mx, const F &func, ll times) {\n    ld ok = mx;\n    ld ng = mn;\n  \
    \  rep(_, times) {\n        ld mid = (ok+ng) / 2;\n        if (func(mid)) {\n\
    \            // \u4E0B\u3092\u63A2\u3057\u306B\u884C\u304F\n            ok = mid;\n\
    \        } else {\n            // \u4E0A\u3092\u63A2\u3057\u306B\u884C\u304F\n\
    \            ng = mid;\n        }\n    }\n    return ok;\n}\n\n// \u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6700\u5927\u5024\u3092\u898B\u3064\u3051\u308B\u4E8C\
    \u5206\u63A2\u7D22(\u5B9F\u6570)\ntemplate<typename F>\nld bisearch_max(ld mn,\
    \ ld mx, const F &func, ll times) {\n    ld ok = mn;\n    ld ng = mx;\n    rep(_,\
    \ times) {\n        ld mid = (ok+ng) / 2;\n        if (func(mid)) {\n        \
    \    // \u4E0A\u3092\u63A2\u3057\u306B\u884C\u304F\n            ok = mid;\n  \
    \      } else {\n            // \u4E0B\u3092\u63A2\u3057\u306B\u884C\u304F\n \
    \           ng = mid;\n        }\n    }\n    return ok;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u5024\u3092\u898B\u3064\u3051\u308B\u4E8C\u5206\u63A2\u7D22(\u5B9F\u6570\
    )\ntemplate<typename F>\nld bisearch_min(ld mn, ld mx, const F &func, ll times)\
    \ {\n    ld ok = mx;\n    ld ng = mn;\n    rep(_, times) {\n        ld mid = (ok+ng)\
    \ / 2;\n        if (func(mid)) {\n            // \u4E0B\u3092\u63A2\u3057\u306B\
    \u884C\u304F\n            ok = mid;\n        } else {\n            // \u4E0A\u3092\
    \u63A2\u3057\u306B\u884C\u304F\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n\n// \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5927\u5024\u3092\u898B\
    \u3064\u3051\u308B\u4E8C\u5206\u63A2\u7D22(\u5B9F\u6570)\ntemplate<typename F>\n\
    ld bisearch_max(ld mn, ld mx, const F &func, ll times) {\n    ld ok = mn;\n  \
    \  ld ng = mx;\n    rep(_, times) {\n        ld mid = (ok+ng) / 2;\n        if\
    \ (func(mid)) {\n            // \u4E0A\u3092\u63A2\u3057\u306B\u884C\u304F\n \
    \           ok = mid;\n        } else {\n            // \u4E0B\u3092\u63A2\u3057\
    \u306B\u884C\u304F\n            ng = mid;\n        }\n    }\n    return ok;\n\
    }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/bisearch_real.hpp
  requiredBy: []
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/bisearch_real.hpp
layout: document
redirect_from:
- /library/src/common/bisearch_real.hpp
- /library/src/common/bisearch_real.hpp.html
title: src/common/bisearch_real.hpp
---
