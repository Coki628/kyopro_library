---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/RangeEdgedSCC.hpp
    title: src/graph/RangeEdgedSCC.hpp
  - icon: ':warning:'
    path: src/graph/SCC.hpp
    title: src/graph/SCC.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/document_ja/scc.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/scc: line\
    \ -1: no such header\n"
  code: "#pragma once\n\n// SCC(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n// \u4F7F\
    \u7528\u65B9\u6CD5\uFF1Ahttps://atcoder.github.io/ac-library/document_ja/scc.html\n\
    #include \"atcoder/scc\"\n"
  dependsOn: []
  isVerificationFile: false
  path: src/acl/scc.hpp
  requiredBy:
  - src/graph/RangeEdgedSCC.hpp
  - src/graph/SCC.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/acl/scc.hpp
layout: document
redirect_from:
- /library/src/acl/scc.hpp
- /library/src/acl/scc.hpp.html
title: src/acl/scc.hpp
---
