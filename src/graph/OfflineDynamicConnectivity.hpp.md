---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/HashMap.hpp
    title: src/common/HashMap.hpp
  - icon: ':warning:'
    path: src/common/HashMapImpl.hpp
    title: src/common/HashMapImpl.hpp
  - icon: ':warning:'
    path: src/graph/UnionFindUndo.hpp
    title: src/graph/UnionFindUndo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp
    - https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
    - https://nyaannyaan.github.io/library/graph/offline-dynamic-connectivity.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: common/HashMap.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../base.hpp\"\n#include \"UnionFindUndo.hpp\"\n#include \"common/HashMap.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp\n\
    // \u3000\u3000\u3000https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html\n\
    // \u3000\u3000\u3000https://nyaannyaan.github.io/library/graph/offline-dynamic-connectivity.hpp\n\
    // \u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\nstruct OfflineDynamicConnectivity\
    \ {\n    using edge = pair< int, int >;\n\nprivate:\n    int V, Q, segsz;\n  \
    \  vector< vector< edge > > seg;\n    vector< pair< pair< int, int >, edge > >\
    \ pend;\n    HashMap< edge, int > cnt, appear;\n\n    void add(int l, int r, const\
    \ edge &e) {\n        int L = l + segsz;\n        int R = r + segsz;\n       \
    \ while (L < R) {\n            if (L & 1) seg[L++].push_back(e);\n           \
    \ if (R & 1) seg[--R].push_back(e);\n            L >>= 1, R >>= 1;\n        }\n\
    \    }\n\n    // \u30AF\u30A8\u30EA\u3092\u5168\u3066\u4E0E\u3048\u305F\u5F8C\u306B\
    \u547C\u3073\u51FA\u3059\n    void build() {\n        for (auto &p : cnt) {\n\
    \            if (p.second > 0) pend.emplace_back(make_pair(appear[p.first], Q),\
    \ p.first);\n        }\n        for (auto &s : pend) {\n            add(s.first.first,\
    \ s.first.second, s.second);\n        }\n    }\n\n    template<typename F>\n \
    \   void _run(const F &f, int k, int l, int r) {\n        if (Q <= l) return;\n\
    \        int tmp = 0;\n        for (auto &e : seg[k]) {\n            tmp += uf.merge(e.first,\
    \ e.second);\n        }\n        comp -= tmp;\n        if (l + 1 == r) {\n   \
    \         f(l);\n        } else {\n            _run(f, 2 * k + 0, l, (l+r) >>\
    \ 1);\n            _run(f, 2 * k + 1, (l+r) >> 1, r);\n        }\n        for\
    \ (auto &e : seg[k]) {\n            uf.undo();\n        }\n        comp += tmp;\n\
    \    }\n\npublic:\n    UnionFindUndo uf;\n    // \u9023\u7D50\u6210\u5206\u6570\
    \n    int comp;\n\n    // \u9802\u70B9\u6570V\u3001Q\u500B\u306E\u30AF\u30A8\u30EA\
    \u3067\u521D\u671F\u5316\n    // (\u3053\u306EQ\u500B\u306B\u306F\u3001\u8FBA\u306E\
    \u8FFD\u52A0\u30FB\u524A\u9664\u30FB\u56DE\u7B54\u30AF\u30A8\u30EA\u5168\u3066\
    \u304C\u542B\u307E\u308C\u308B\u3002\u30AF\u30A8\u30EA\u6570\u3068\u8A00\u3046\
    \u3088\u308A\u7D4C\u904E\u6642\u9593\u306E\u6700\u5927\u3002\n    //  \u306A\u304A\
    \u3001\u6B21\u306E\u30AF\u30A8\u30EA\u304C\u6765\u308B\u307E\u3067\u306E\u8FBA\
    \u306E\u8FFD\u52A0\u524A\u9664\u306F\u540C\u6642\u523B\u306B\u307E\u3068\u3081\
    \u3066OK\u3002)\n    OfflineDynamicConnectivity(int V, int Q) : uf(V), V(V), Q(Q),\
    \ comp(V) {\n        segsz = 1;\n        while (segsz < Q) segsz <<= 1;\n    \
    \    seg.resize(2 * segsz);\n    }\n\n    // \u4E00\u5FDC\u4F5C\u3063\u305F\u3093\
    \u3060\u3051\u3069\u3001\u3053\u308C\u3084\u3063\u3066\u3082\u901F\u304F\u306A\
    \u3089\u306A\u304B\u3063\u305F\u3002\n    void reserve(int n) {\n        cnt.reserve(n);\n\
    \        appear.reserve(n);\n    }\n\n    // \u6642\u523Bidx\u306B\u8FBA(s,t)\u3092\
    \u8FFD\u52A0\n    void insert(int idx, int s, int t) {\n        auto e = minmax(s,\
    \ t);\n        if (cnt[e]++ == 0) appear[e] = idx;\n    }\n\n    // \u6642\u523B\
    idx\u306B\u8FBA(s,t)\u3092\u524A\u9664\n    void erase(int idx, int s, int t)\
    \ {\n        auto e = minmax(s, t);\n        if (--cnt[e] == 0) pend.emplace_back(make_pair(appear[e],\
    \ idx), e);\n    }\n\n    // build()\u5B9F\u884C\u5F8C\u306B\u52D5\u4F5C\u3001\
    \u5404i(0<=i<Q)\u306B\u3064\u3044\u3066f(i)\u304C\u547C\u3073\u51FA\u3055\u308C\
    \u308B\n    template<typename F>\n    void run(const F &f) {\n        build();\n\
    \        _run(f, 1, 0, segsz);\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/graph/UnionFindUndo.hpp
  - src/common/HashMap.hpp
  - src/common/HashMapImpl.hpp
  isVerificationFile: false
  path: src/graph/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2022-05-27 01:45:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/OfflineDynamicConnectivity.hpp
layout: document
redirect_from:
- /library/src/graph/OfflineDynamicConnectivity.hpp
- /library/src/graph/OfflineDynamicConnectivity.hpp.html
title: src/graph/OfflineDynamicConnectivity.hpp
---
