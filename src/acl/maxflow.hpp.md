---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/PSP.hpp
    title: src/graph/PSP.hpp
  - icon: ':warning:'
    path: src/graph/RangeEdgedMaxFlow.hpp
    title: src/graph/RangeEdgedMaxFlow.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/document_ja/maxflow.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n// \u6700\u5927\u6D41\n// \u4F7F\u7528\u65B9\u6CD5\uFF1A\
    https://atcoder.github.io/ac-library/document_ja/maxflow.html\n// \u203B\u6709\
    \u5411\u8FBA\u306A\u306E\u3067\u3001\u884C\u304D\u6765\u3067\u304D\u308B\u6642\
    \u306F\u8FBA2\u672C\u4ED8\u3051\u308B\u3053\u3068\uFF01\uFF01(\u305D\u308C\u306F\
    \u305D\u3046\u2026)\n// \u203B\u6D41\u91CF\u306FINF\u3088\u308A\u5927\u304D\u304F\
    \u306A\u3063\u3066\u8FD4\u308B\u3053\u3068\u3082\u3042\u308B\u3088\u3046\u306E\
    \u3067\u3001\u5224\u5B9A\u306F == INF \u3067\u306F\u306A\u304F < INF \u3067\u898B\
    \u308B\u3053\u3068\uFF01\n#include \"atcoder/maxflow\"\n"
  dependsOn: []
  isVerificationFile: false
  path: src/acl/maxflow.hpp
  requiredBy:
  - src/graph/RangeEdgedMaxFlow.hpp
  - src/graph/PSP.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/acl/maxflow.hpp
layout: document
redirect_from:
- /library/src/acl/maxflow.hpp
- /library/src/acl/maxflow.hpp.html
title: src/acl/maxflow.hpp
---