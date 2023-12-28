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
    links:
    - https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../acl/maxflow.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u71C3\u3084\u3059\u57CB\u3081\u308B\n// \u30FB\u76F4\u611F\u7684\u306B\
    \u5206\u304B\u308A\u3065\u3089\u3044\u8AF8\u3005\u3092\u5C11\u3057\u3067\u3082\
    \u4F7F\u3044\u3084\u3059\u304F\u3059\u308B\u3002\n// \u4ED5\u69D8\u8AAC\u660E\n\
    // \u30FB\u4FBF\u5B9C\u4E0A\u3001\u9078\u629E\u80A2\u306E\u3069\u3061\u3089\u5074\
    \u306A\u306E\u304B\u3092\u3001\u59CB\u70B9s\u5074\u3092\u5DE6\u3001\u7D42\u70B9\
    t\u5074\u3092\u53F3\u3068\u8868\u3059\u3002\n// \u30FB\u4F9D\u5B58\u95A2\u4FC2\
    \u306E\u89AA\u5074\u306B\u306A\u308B\u9078\u629E\u80A2\u306F\u57FA\u672C\u7684\
    \u306B\u53F3\u306B\u7F6E\u304F\u3002(\u307E\u3042\u30E1\u30BD\u30C3\u30C9\u540D\
    \u3067\u57FA\u672C\u7684\u306B\u3069\u3063\u3061\u306A\u306E\u304B\u306F\u793A\
    \u3057\u3066\u3042\u308B)\n// \u30FB\u9078\u629E\u80A2\u306E\u30B3\u30B9\u30C8\
    \u8A2D\u5B9Aadd\u306F\u304B\u306A\u308A\u76F4\u611F\u7684\u306B\u3084\u308A\u3084\
    \u3059\u304F\u3057\u305F\u3064\u3082\u308A\u3002\nstruct PSP {\n    int N, s =\
    \ -2, t = -1;\n    // \u3060\u3044\u305F\u3044\u5229\u5F97\u304C\u591A\u3044\u306E\
    \u3067\u30C7\u30D5\u30A9\u30EB\u30C8true,\u30B3\u30B9\u30C8\u306E\u6642\u306F\
    false\u306B\n    bool is_max;\n    ll offset;\n    vector<tuple<int, int, ll>>\
    \ edges;\n    atcoder::mf_graph<ll> mf;\n\n    // \u9078\u629E\u80A2N\u500B\u306E\
    \u71C3\u3084\u3059\u57CB\u3081\u308B\u3092\u4F5C\u6210\n    PSP(int N, bool is_max\
    \ = true) : N(N), is_max(is_max), offset(0) {}\n\n    // i\u500B\u76EE\u306E\u9078\
    \u629E\u80A2\u306E\u5229\u5F97(\u30B3\u30B9\u30C8)\u306B(lval,rval)\u3092\u8A2D\
    \u5B9A\u3059\u308B\n    void add(int i, ll lval, ll rval) {\n        if (is_max)\
    \ {\n            ll mx = max(lval, rval);\n            offset += mx;\n       \
    \     edges.eb(s, i, mx - lval);\n            edges.eb(i, t, mx - rval);\n   \
    \     } else {\n            ll mn = min(lval, rval);\n            edges.eb(s,\
    \ i, lval - mn);\n            edges.eb(i, t, rval - mn);\n        }\n    }\n\n\
    \    // \u9078\u629E\u80A2a\u304C\u53F3\u306A\u3089\u3070\u9078\u629E\u80A2b\u3082\
    \u53F3\u3092\u5F37\u5236\u3059\u308B\n    void a_right_then_b_right(int a, int\
    \ b) {\n        edges.eb(a, b, INF);\n    }\n\n    // \u9078\u629E\u80A2a\u304C\
    \u53F3\u3067\u9078\u629E\u80A2b\u304C\u5DE6\u306A\u3089\u3070\u640D\u5931val\u3092\
    \u8CA0\u3046(\u3053\u3053\u306Fis_max\u304C\u3069\u3061\u3089\u3067\u3082\u640D\
    \u5931)\n    void a_right_and_b_left_then(int a, int b, ll val) {\n        assert(val\
    \ >= 0);\n        edges.eb(a, b, val);\n    }\n\n    // \u8907\u6570\u9078\u629E\
    \u80A2vs\u304C\u5168\u3066\u53F3\u306A\u3089\u3070\u5229\u5F97val\u3092\u5F97\u308B\
    (\u591A\u5206\u5229\u5F97\u306B\u306E\u307F\u6709\u52B9\u3067\u30B3\u30B9\u30C8\
    \u306B\u306F\u9069\u7528\u3067\u304D\u306A\u3044)\n    // see: https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem\n\
    \    void all_right_then(const vector<int> &vs, ll val) {\n        assert(is_max\
    \ ? val >= 0 : val <= 0);\n        int k = N;\n        N++;\n        add(k, 0,\
    \ 1);\n        for (auto v : vs) {\n            a_right_then_b_right(k, v);\n\
    \        }\n    }\n\n    // \u8907\u6570\u9078\u629E\u80A2vs\u304C\u5168\u3066\
    \u5DE6\u306A\u3089\u3070\u5229\u5F97val\u3092\u5F97\u308B(\u591A\u5206\u5229\u5F97\
    \u306B\u306E\u307F\u6709\u52B9\u3067\u30B3\u30B9\u30C8\u306B\u306F\u9069\u7528\
    \u3067\u304D\u306A\u3044)\n    void all_left_then(const vector<int> &vs, ll val)\
    \ {\n        int k = N;\n        N++;\n        add(k, 1, 0);\n        for (auto\
    \ v : vs) {\n            a_right_then_b_right(v, k);\n        }\n    }\n\n   \
    \ ll solve() {\n        mf = atcoder::mf_graph<ll>(N + 2);\n        s = N;\n \
    \       t = N + 1;\n        for (auto &[u, v, c] : edges) {\n            // \u59CB\
    \u70B9\u30FB\u7D42\u70B9\u306E\u78BA\u5B9A\n            if (u < 0) u += N + 2;\n\
    \            if (v < 0) v += N + 2;\n            mf.add_edge(u, v, c);\n     \
    \   }\n        if (is_max) {\n            return offset - mf.flow(s, t);\n   \
    \     } else {\n            return mf.flow(s, t) - offset;\n        }\n    }\n\
    };\n"
  dependsOn:
  - src/acl/maxflow.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/PSP.hpp
  requiredBy: []
  timestamp: '2023-12-12 16:05:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/PSP.hpp
layout: document
redirect_from:
- /library/src/graph/PSP.hpp
- /library/src/graph/PSP.hpp.html
title: src/graph/PSP.hpp
---
