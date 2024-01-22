---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/scc.hpp
    title: src/acl/scc.hpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: acl/scc.hpp: line\
    \ -1: no such header\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"acl/scc.hpp\"\n\n//\
    \ SCC\n// \u30FBACL\u3092\u30E9\u30C3\u30D7\u3057\u3066\u308B\u3002\n// \u30FB\
    \u7E2E\u7D04\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\u304C\u3067\u304D\u308B\u3088\
    \u3046\u306B\u3057\u3066\u3042\u308B\u3002\nstruct SCC {\n    int N, N2;\n   \
    \ vector<pii> edges, edges2;\n    vvi groups;\n    vector<int> NtoN2, sz;\n  \
    \  bool built = false;\n    bool constructed = false;\n\n    SCC(int N) : N(N)\
    \ {}\n\n    // \u6709\u5411\u8FBA\u306E\u8FFD\u52A0\n    void add_edge(int u,\
    \ int v) {\n        edges.eb(u, v);\n    }\n\n    // SCC\u306E\u5B9F\u884C\u3001\
    \u666E\u901A\u306BACL\u306ESCC\u3092\u3084\u308B\n    vvi build() {\n        atcoder::scc_graph\
    \ scc(N);\n        for (auto [u, v] : edges) {\n            scc.add_edge(u, v);\n\
    \        }\n        built = true;\n        return groups = scc.scc();\n    }\n\
    \n    // \u7E2E\u7D04\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\n    void construct()\
    \ {\n        assert(built);\n        N2 = groups.size();\n        NtoN2.assign(N,\
    \ -1);\n        sz.assign(N2, 0);\n        rep(i, N2) {\n            sz[i] = groups[i].size();\n\
    \            for (auto u : groups[i]) {\n                NtoN2[u] = i;\n     \
    \       }\n        }\n        for (auto [u, v] : edges) {\n            int i =\
    \ NtoN2[u];\n            int j = NtoN2[v];\n            edges2.eb(i, j);\n   \
    \     }\n        UNIQUE(edges2);\n        constructed = true;\n    }\n\n    //\
    \ \u5F37\u9023\u7D50\u6210\u5206u\u306E\u5143\u30B0\u30E9\u30D5\u3067\u306E\u9802\
    \u70B9\u6570\n    int size(int u) {\n        assert(constructed);\n        return\
    \ sz[u];\n    }\n\n    // \u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\n \
    \   int size() {\n        assert(built);\n        return groups.size();\n    }\n\
    \n    // \u5143\u30B0\u30E9\u30D5\u306E\u8FBA\u5217\u6319\n    vector<pii> get_edges()\
    \ {\n        assert(constructed);\n        return edges;\n    }\n\n    // \u7E2E\
    \u7D04\u30B0\u30E9\u30D5\u306E\u8FBA\u5217\u6319\n    vector<pii> get_edges2()\
    \ {\n        assert(constructed);\n        return edges2;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/acl/scc.hpp
  isVerificationFile: false
  path: src/graph/SCC.hpp
  requiredBy: []
  timestamp: '2024-01-03 03:19:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/SCC.hpp
layout: document
redirect_from:
- /library/src/graph/SCC.hpp
- /library/src/graph/SCC.hpp.html
title: src/graph/SCC.hpp
---
