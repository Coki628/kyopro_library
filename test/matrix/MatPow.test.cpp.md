---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/combinatorics/ModInt.hpp
    title: src/combinatorics/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/input.hpp
    title: src/common/input.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/sum.hpp
    title: src/common/sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':heavy_check_mark:'
    path: src/matrix/MatPow.hpp
    title: src/matrix/MatPow.hpp
  - icon: ':heavy_check_mark:'
    path: src/matrix/mat_dot.hpp
    title: src/matrix/mat_dot.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1299
    links:
    - https://yukicoder.me/problems/no/1299
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1299\"\n\n// #pragma GCC\
    \ target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n#include \"\
    base.hpp\"\n\nconstexpr long long INF = 1e18;\n// constexpr long long INF = LONG_LONG_MAX;\n\
    // constexpr int MOD = 1000000007;\nconstexpr int MOD = 998244353;\nconstexpr\
    \ long double EPS = 1e-10;\nconstexpr long double PI = M_PI;\n\n#include \"macros.hpp\"\
    \n#include \"common/input.hpp\"\n#include \"common/print.hpp\"\n#include \"common/sum.hpp\"\
    \n#include \"combinatorics/ModInt.hpp\"\nusing mint = ModInt<MOD>;\n\n#include\
    \ \"matrix/MatPow.hpp\"\n\nvoid solve() {\n    ll N, K;\n    cin >> N >> K;\n\
    \    auto A = LIST(N);\n\n    mint invN = (mint)1/(mint)N;\n    vector<vector<mint>>\
    \ mat = {\n        {1, N},\n        {invN, 1},\n    };\n    vector<mint> init\
    \ = { sum(A), (mint)sum(A)*invN };\n    MatPow<mint> mp;\n    auto res = mp.solve(mat,\
    \ init, K);\n    print(res[0]);\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\
    \n    // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--)\
    \ solve();\n\n    return 0;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/input.hpp
  - src/common/print.hpp
  - src/common/sum.hpp
  - src/combinatorics/ModInt.hpp
  - src/matrix/MatPow.hpp
  - src/matrix/mat_dot.hpp
  - src/common/listnd.hpp
  isVerificationFile: true
  path: test/matrix/MatPow.test.cpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix/MatPow.test.cpp
layout: document
redirect_from:
- /verify/test/matrix/MatPow.test.cpp
- /verify/test/matrix/MatPow.test.cpp.html
title: test/matrix/MatPow.test.cpp
---
