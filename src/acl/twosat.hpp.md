---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/RangeEdgedTwoSAT.hpp
    title: src/graph/RangeEdgedTwoSAT.hpp
  - icon: ':warning:'
    path: src/graph/TwoSAT.hpp
    title: src/graph/TwoSAT.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/document_ja/twosat.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/twosat:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n// 2-SAT\n// \u4F7F\u7528\u65B9\u6CD5\uFF1Ahttps://atcoder.github.io/ac-library/document_ja/twosat.html\n\
    // \u30FB\u5143\u3005\u306F\u300CA|B and A|B and...\u300D\u306A\u3093\u3060\u3051\
    \u3069\uFF44\u3001\u5909\u5F62\u3055\u305B\u308B\u3068\u8272\u3005\u306A\u6761\
    \u4EF6\u306B\u5BFE\u5FDC\u3067\u304D\u308B\u3002\n// \u3000\u30FBA or B (cf1903f)\n\
    // \u3000\u3000A|B (\u3053\u308C\u306F\u305D\u306E\u307E\u307E)\n// \u3000\u30FB\
    A xor B (abc327_d,cf1438c)\n// \u3000\u3000A&!B or !A&B -> A|B and !A|!B\n// \u3000\
    \u30FBnot (A and B) (aclpc_h,yukico274)\n// \u3000\u3000!(A&B) -> !A|!B\n// \u3000\
    \u30FBnot (A and !B) (aclpc_h)\n// \u3000\u3000!(A&!B) -> !A|B\n// \u3000\u30FB\
    not (!A and B) (aclpc_h)\n// \u3000\u3000!(!A&B) -> A|!B\n// \u3000\u30FBnot (!A\
    \ and !B) (aclpc_h)\n// \u3000\u3000!(!A&!B) -> A|B\n// \u3000\u30FBA and B (cf1494b)\n\
    // \u3000\u3000A&B -> A|A and B|B\n#include \"atcoder/twosat\"\n"
  dependsOn: []
  isVerificationFile: false
  path: src/acl/twosat.hpp
  requiredBy:
  - src/graph/RangeEdgedTwoSAT.hpp
  - src/graph/TwoSAT.hpp
  timestamp: '2023-12-05 02:34:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/acl/twosat.hpp
layout: document
redirect_from:
- /library/src/acl/twosat.hpp
- /library/src/acl/twosat.hpp.html
title: src/acl/twosat.hpp
---
