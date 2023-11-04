---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../mystl/my_vector.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../macros.hpp\"\n#include \"HeavyLightDecomposition.hpp\"\n#include\
    \ \"../common/HashMap.hpp\"\n#include \"../mystl/my_vector.hpp\"\n\n// Auxiliary\
    \ Tree\n// \u8AAC\u660E\n// \u30FB\u6307\u5B9A\u3057\u305F\u9802\u70B9\u96C6\u5408\
    S\u3068\u3001\u305D\u308C\u3089\u306ELCA\u306E\u307F\u3067\u69CB\u6210\u3055\u308C\
    \u308B\u30B0\u30E9\u30D5\u3092\u8A08\u7B97\u91CF|S|log|S|\u7A0B\u5EA6\u3067\u69CB\
    \u7BC9\u3059\u308B\u3002\n// \u4F7F\u3044\u65B9\n// \u30FB\u5168\u4F53\u306E\u30B0\
    \u30E9\u30D5\u304C\u78BA\u5B9A\u3057\u305F\u6642\u70B9\u3067\u96A3\u63A5\u30EA\
    \u30B9\u30C8nodes\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n// \u30FB\u5404\u30AF\
    \u30A8\u30EA\u6BCE\u306B\u4F7F\u3046\u9802\u70B9\u96C6\u5408\u306E\u914D\u5217\
    A\u3092\u6E21\u3057\u3066build\n// \u30FB\u623B\u308A\u5024\u306F\u5727\u7E2E\u3055\
    \u308C\u305F\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3002\u91CD\
    \u307F\u4ED8\u304D\u306B\u3057\u3066\u30B3\u30B9\u30C8\u3092\u5143\u30B0\u30E9\
    \u30D5\u4E0A\u3067\u306E\u8DDD\u96E2\u3068\u3057\u3066\u3042\u308B\u3002\n// \u3000\
    \u96A3\u63A5\u30EA\u30B9\u30C8\u306E\u30AD\u30FC\u306FHashMap\u3067\u69CB\u6210\
    \u3057\u3066\u3044\u308B\u306E\u3067\u3001\u9802\u70B9\u756A\u53F7\u306F\u5143\
    \u30B0\u30E9\u30D5\u3068\u540C\u3058\u3082\u306E\u3092\u4F7F\u3048\u308B(\u306E\
    \u3067\u6DFB\u5B57\u304C\u5206\u304B\u308A\u3084\u3059\u3044)\u3002\n// \u3000\
    (\u305D\u306E\u5206\u591A\u5C11\u306F\u901F\u5EA6\u304C\u72A0\u7272\u306B\u306A\
    \u3063\u3066\u3044\u308B\u306F\u305A\u3060\u3051\u3069\u3001\u307E\u3042Nyaan\u3055\
    \u3093\u306EHashMap\u7206\u901F\u3060\u304B\u3089\u5927\u6982\u5927\u4E08\u592B\
    \u3060\u3068\u601D\u3046\u3002)\nstruct AuxiliaryTree {\n    int N;\n    HeavyLightDecomposition\
    \ hld;\n\n    AuxiliaryTree(const vvi& nodes) : hld(nodes), N(nodes.size()) {}\n\
    \n    HashMap<int, vector<pil>> build(const vector<int>& A) {\n        int K =\
    \ A.size();\n        vector<pii> tmp;\n        rep(i, K) {\n            tmp.eb(hld.in[A[i]],\
    \ A[i]);\n        }\n        sort(ALL(tmp));\n        my_vector<int> st = {tmp[0].second};\n\
    \        HashMap<int, vector<pil>> res;\n        rep(i, 1, K) {\n            ll\
    \ u = st.pop();\n            ll v = tmp[i].second;\n            ll lca = hld.lca(u,\
    \ v);\n            while (st.size() and hld.dep[st.back()] > hld.dep[lca]) {\n\
    \                res[st.back()].eb(u, hld.dist(u, st.back()));\n             \
    \   res[u].eb(st.back(), hld.dist(u, st.back()));\n                u = st.pop();\n\
    \            }\n            if (st.empty() or st.back() != lca) {\n          \
    \      st.eb(lca);\n            }\n            if (u != lca) {\n             \
    \   res[lca].eb(u, hld.dist(u, lca));\n                res[u].eb(lca, hld.dist(u,\
    \ lca));\n            }\n            st.eb(v);\n        }\n        while (st.size()\
    \ >= 2) {\n            ll u = st.pop();\n            res[st.back()].eb(u, hld.dist(u,\
    \ st.back()));\n            res[u].eb(st.back(), hld.dist(u, st.back()));\n  \
    \      }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/src/graph/AuxiliaryTree.hpp
- /library/src/graph/AuxiliaryTree.hpp.html
title: src/graph/AuxiliaryTree.hpp
---
