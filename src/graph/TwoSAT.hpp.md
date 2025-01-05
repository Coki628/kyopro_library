---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/twosat.hpp
    title: src/acl/twosat.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/RangeEdgedTwoSAT.hpp
    title: src/graph/RangeEdgedTwoSAT.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/algorithm/two_sat.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/twosat:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../acl/twosat.hpp\"\n\n// 2-SAT\n// \u53C2\u8003\
    \uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/algorithm/two_sat.hpp\n\
    // \u30FBACL\u3092\u30E9\u30C3\u30D7\u3057\u3066\u3001\u76F4\u611F\u7684\u306A\
    \u30E1\u30BD\u30C3\u30C9\u3092\u305F\u304F\u3055\u3093\u751F\u3084\u3057\u3066\
    \u304A\u3044\u305F\u3002\nstruct TwoSAT : public atcoder::two_sat {\n    using\
    \ base_type = atcoder::two_sat;\n    using base_type::base_type;\n\n    virtual\
    \ void add_clause(int i, bool f, int j, bool g) {\n        base_type::add_clause(i,\
    \ f, j, g);\n    }\n\n    // A or B\n    void a_or_b(int a, int b) {\n       \
    \ add_clause(a, true, b, true);\n    }\n\n    // A and B\n    void a_and_b(int\
    \ a, int b) {\n        add_clause(a, true, a, true);\n        add_clause(b, true,\
    \ b, true);\n    }\n\n    // A xor B\n    void a_xor_b(int a, int b) {\n     \
    \   add_clause(a, true, b, true);\n        add_clause(a, false, b, false);\n \
    \   }\n\n    // A\u304B\u3064B\u3001\u304C\u30C0\u30E1\n    // not (A and B)\n\
    \    void not_a_and_b(int a, int b) {\n        add_clause(a, false, b, false);\n\
    \    }\n\n    // A\u304B\u3064B\u3067\u306F\u306A\u3044\u3001\u304C\u30C0\u30E1\
    \n    // not (A and !B)\n    void not_a_and_nb(int a, int b) {\n        add_clause(a,\
    \ false, b, true);\n    }\n\n    // A\u3067\u306F\u306A\u3044\u304B\u3064B\u3001\
    \u304C\u30C0\u30E1\n    // not (A! and B)\n    void not_na_and_b(int a, int b)\
    \ {\n        add_clause(a, true, b, false);\n    }\n\n    // A\u3067\u306F\u306A\
    \u3044\u304B\u3064B\u3067\u306F\u306A\u3044\u3001\u304C\u30C0\u30E1\n    // not\
    \ (!A and !B)\n    void not_na_and_nb(int a, int b) {\n        add_clause(a, true,\
    \ b, true);\n    }\n\n    // A\u306A\u3089\u3070B\n    void a_then_b(int a, int\
    \ b) {\n        not_a_and_nb(a, b);\n    }\n\n    // a=f\u304C\u5FC5\u9808\n \
    \   void a_is_f(int a, bool f) {\n        add_clause(a, f, a, f);\n    }\n};\n"
  dependsOn:
  - src/acl/twosat.hpp
  isVerificationFile: false
  path: src/graph/TwoSAT.hpp
  requiredBy:
  - src/graph/RangeEdgedTwoSAT.hpp
  timestamp: '2023-12-12 16:05:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/TwoSAT.hpp
layout: document
redirect_from:
- /library/src/graph/TwoSAT.hpp
- /library/src/graph/TwoSAT.hpp.html
title: src/graph/TwoSAT.hpp
---
