---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/input.hpp
    title: src/common/input.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #include \"base.hpp\"\n\nconstexpr long long INF = 1e18;\n// constexpr long long\
    \ INF = LONG_LONG_MAX;\nconstexpr int MOD = 1000000007;\n// constexpr int MOD\
    \ = 998244353;\nconstexpr long double EPS = 1e-10;\nconstexpr long double PI =\
    \ M_PI;\n\n#include \"macros.hpp\"\n#include \"common/input.hpp\"\n#include \"\
    common/print.hpp\"\n\n#include \"common/bisect.hpp\"\n\nvoid solve() {\n    ll\
    \ N, M;\n    cin >> N;\n    auto A = LIST(N);\n    cin >> M;\n    auto B = LIST(M);\n\
    \n    UNIQUE(A);\n    ll ans = 0;\n    for (ll b : B) {\n        ll i = bisect_left(A,\
    \ b);\n        ll j = bisect_right(A, b);\n        ans += (j-i);\n    }\n    print(ans);\n\
    }\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout\
    \ << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\n \
    \   // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--) solve();\n\
    \n    return 0;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/input.hpp
  - src/common/print.hpp
  - src/common/bisect.hpp
  isVerificationFile: true
  path: test/common/bisect.test.cpp
  requiredBy: []
  timestamp: '2022-10-04 01:47:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/common/bisect.test.cpp
layout: document
redirect_from:
- /verify/test/common/bisect.test.cpp
- /verify/test/common/bisect.test.cpp.html
title: test/common/bisect.test.cpp
---
