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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: acl/scc.hpp: line\
    \ -1: no such header\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"acl/scc.hpp\"\n\n//\
    \ \u533A\u9593\u8FBASCC\nstruct RangeEdgedSCC {\n    int N, N2, N3, n;\n    vector<pii>\
    \ edges, edges2, edges3;\n    vvi groups;\n    vector<int> N2toN, N2toN3, sz;\n\
    \    bool built = false;\n    bool constructed = false;\n\n    RangeEdgedSCC(int\
    \ N) : N(N) {\n        // 2\u51AA\u30B5\u30A4\u30BA\u306B\u3057\u306A\u304F\u3066\
    \u3082\u3061\u3083\u3093\u3068\u52D5\u304F\u307F\u305F\u3044\n        // n = 1;\n\
    \        // while (n < N) n <<= 1;\n        n = N;\n        N2 = 2 * n;\n    \
    \    for (int i = 1; i < n; i++) {\n            int cl = i * 2, cr = i * 2 + 1;\n\
    \            _add_edge(i, cl);\n            _add_edge(i, cr);\n        }\n   \
    \     N2toN.assign(N2, -1);\n        rep(i, N) {\n            N2toN[n + i] = i;\n\
    \        }\n    }\n\n    void _add_edge(int u, int v) {\n        edges2.eb(u,\
    \ v);\n    }\n\n    // \u6709\u5411\u8FBA\u306E\u8FFD\u52A0\n    void add_edge(int\
    \ u, int v) {\n        _add_edge(n + u, n + v);\n    }\n\n    // \u533A\u9593\u8FBA\
    \ u -> [l,r) \u306E\u8FFD\u52A0\n    void add_edges(int u, int l, int r) {\n \
    \       u += n;\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n   \
    \         if (l & 1) _add_edge(u, l++);\n            if (r & 1) _add_edge(u, --r);\n\
    \        }\n    }\n\n    // SCC\u306E\u5B9F\u884C\u3001\u666E\u901A\u306BACL\u306E\
    SCC\u3092\u3084\u308B\n    vvi build() {\n        atcoder::scc_graph scc(N2);\n\
    \        for (auto [u, v] : edges2) {\n            scc.add_edge(u, v);\n     \
    \   }\n        built = true;\n        return groups = scc.scc();\n    }\n\n  \
    \  // \u7E2E\u7D04\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\n    void construct() {\n\
    \        assert(built);\n        N3 = groups.size();\n        N2toN3.assign(N2,\
    \ -1);\n        sz.assign(N3, 0);\n        rep(i, N3) {\n            if (groups[i].size())\
    \ {\n                for (auto u : groups[i]) {\n                    N2toN3[u]\
    \ = i;\n                    if (N2toN[u] != -1) {\n                        //\
    \ \u5143\u30B0\u30E9\u30D5\u306B\u5B58\u5728\u3059\u308B\u9802\u70B9\u3060\u3051\
    \u6210\u5206\u6570\u306B\u30AB\u30A6\u30F3\u30C8\u3057\u3066\u304A\u304F\n   \
    \                     sz[i]++;\n                    }\n                }\n   \
    \         }\n        }\n        for (auto [u, v] : edges2) {\n            int\
    \ i = N2toN3[u];\n            int j = N2toN3[v];\n            edges3.eb(i, j);\n\
    \        }\n        UNIQUE(edges3);\n        constructed = true;\n    }\n\n  \
    \  // \u5F37\u9023\u7D50\u6210\u5206u\u306E\u5143\u30B0\u30E9\u30D5\u3067\u306E\
    \u9802\u70B9\u6570\n    int size(int u) {\n        assert(constructed);\n    \
    \    return sz[u];\n    }\n\n    // \u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\
    \u6570\n    int size() {\n        assert(built);\n        return groups.size();\n\
    \    }\n\n    // \u5143\u30B0\u30E9\u30D5\u306E\u8FBA\u5217\u6319(\u305D\u3082\
    \u305D\u3082\u3053\u308C\u306F\u967D\u306B\u3067\u304D\u306A\u304F\u306A\u308B\
    )\n    vector<pii> get_edges() {\n        assert(constructed);\n        return\
    \ edges;\n    }\n\n    // \u533A\u9593\u8FBA\u30B0\u30E9\u30D5\u306E\u8FBA\u5217\
    \u6319\n    vector<pii> get_edges2() {\n        assert(constructed);\n       \
    \ return edges2;\n    }\n\n    // \u7E2E\u7D04\u30B0\u30E9\u30D5\u306E\u8FBA\u5217\
    \u6319\n    vector<pii> get_edges3() {\n        assert(constructed);\n       \
    \ return edges3;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/acl/scc.hpp
  isVerificationFile: false
  path: src/graph/RangeEdgedSCC.hpp
  requiredBy: []
  timestamp: '2024-01-04 14:20:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgedSCC.hpp
layout: document
redirect_from:
- /library/src/graph/RangeEdgedSCC.hpp
- /library/src/graph/RangeEdgedSCC.hpp.html
title: src/graph/RangeEdgedSCC.hpp
---
