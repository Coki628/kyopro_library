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
    path: src/graph/UnionFind.hpp
    title: src/graph/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #include \"base.hpp\"\n\nconstexpr long long INF = 1e18;\n// constexpr long long\
    \ INF = LONG_LONG_MAX;\nconstexpr int MOD = 1000000007;\n// constexpr int MOD\
    \ = 998244353;\nconstexpr long double EPS = 1e-10;\nconstexpr long double PI =\
    \ M_PI;\n\n#include \"macros.hpp\"\n#include \"common/print.hpp\"\n\n#include\
    \ \"graph/UnionFind.hpp\"\n\nvoid solve() {\n    ll N, Q;\n    cin >> N >> Q;\n\
    \n    UnionFind uf(N);\n    rep(_, Q) {\n        ll op;\n        cin >> op;\n\
    \        if (op == 0) {\n            ll x, y;\n            cin >> x >> y;\n  \
    \          uf.merge(x, y);\n        } else {\n            ll x, y;\n         \
    \   cin >> x >> y;\n            int res = uf.same(x, y);\n            print(res);\n\
    \        }\n    }\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\
    \n    // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--)\
    \ solve();\n\n    return 0;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/print.hpp
  - src/graph/UnionFind.hpp
  isVerificationFile: true
  path: test/graph/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2022-10-04 01:47:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/graph/UnionFind.test.cpp
- /verify/test/graph/UnionFind.test.cpp.html
title: test/graph/UnionFind.test.cpp
---
