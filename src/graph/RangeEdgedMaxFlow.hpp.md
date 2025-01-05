---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/maxflow.hpp
    title: src/acl/maxflow.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: acl/maxflow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"acl/maxflow.hpp\"\n\n\
    // \u533A\u9593\u8FBA\u6700\u5927\u6D41(\u672Averify)\ntemplate<typename T>\n\
    struct RangeEdgedMaxFlow {\n    int N, N2, n;\n    atcoder::mf_graph<T> mf;\n\n\
    \    RangeEdgedMaxFlow(int N) : N(N), N2(N * 2), n(N), mf(N * 2) {\n        for\
    \ (int i = 1; i < n; i++) {\n            int cl = i * 2, cr = i * 2 + 1;\n   \
    \         _add_edge(i, cl);\n            _add_edge(i, cr);\n        }\n      \
    \  N2toN.assign(N2, -1);\n        rep(i, N) {\n            N2toN[n + i] = i;\n\
    \        }\n    }\n\n    void _add_edge(int u, int v, T cap) {\n        mf.add_edge(u,\
    \ v, cap);\n    }\n\n    // \u6709\u5411\u8FBA\u306E\u8FFD\u52A0\n    void add_edge(int\
    \ u, int v, T cap) {\n        _add_edge(n + u, n + v, cap);\n    }\n\n    // \u533A\
    \u9593\u8FBA u -> [l,r) \u306E\u8FFD\u52A0\n    void add_edges(int u, int l, int\
    \ r, T cap) {\n        u += n;\n        for (l += n, r += n; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) _add_edge(u, l++, cap);\n            if (r\
    \ & 1) _add_edge(u, --r, cap);\n        }\n    }\n\n    T flow(int s, int t) {\n\
    \        return mf.flow(s, t);\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/acl/maxflow.hpp
  isVerificationFile: false
  path: src/graph/RangeEdgedMaxFlow.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgedMaxFlow.hpp
layout: document
redirect_from:
- /library/src/graph/RangeEdgedMaxFlow.hpp
- /library/src/graph/RangeEdgedMaxFlow.hpp.html
title: src/graph/RangeEdgedMaxFlow.hpp
---
