---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/mincostflow.hpp
    title: src/acl/mincostflow.hpp
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  - icon: ':warning:'
    path: src/graph/bellman_ford.hpp
    title: src/graph/bellman_ford.hpp
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
    - https://ikatakos.com/pot/programming_algorithm/graph_theory/minimum_cost_flow
    - https://niuez.hatenablog.com/entry/2019/03/04/142903
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: acl/mincostflow.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../base.hpp\"\n#include \"acl/mincostflow.hpp\"\n#include \"bellman_ford.hpp\"\
    \n\n// \u6700\u5C0F\u8CBB\u7528\u6D41\n// \u4F7F\u3044\u65B9\n// \u30FB\u5FA9\u5143\
    \u306Fedges\u3092\u547C\u3073\u51FA\u3057\u3066\u9802\u70B9\u756A\u53F7\u3068\u304B\
    \u6D41\u91CF\u78BA\u8A8D\u3057\u306A\u304C\u3089\u30B4\u30CB\u30E7\u30B4\u30CB\
    \u30E7\u3084\u308B\u3002(practice2_e\u306A\u3069)\n// \u30FB\u6700\u7D42\u7684\
    \u306A\u6D41\u91CF\u3060\u3051\u3067\u306A\u304F\u9014\u4E2D\u7D4C\u904E\u3082\
    \u6B32\u3057\u3044\u5834\u5408\u306Fslope\u304C\u4F7F\u3048\u308B\u3002\n// \u3000\
    \u6298\u308C\u7DDA\u30B0\u30E9\u30D5\u304C\u8FD4\u3055\u308C\u308B\u306E\u3067\
    \u3001\u5FC5\u8981\u306B\u5FDC\u3058\u3066\u9593\u306E\u5024\u306F\u8A08\u7B97\
    \u3059\u308B\u3002(abc247_g)\n// \u30FB\u57FA\u672C\u7684\u306BACL\u306B\u6E96\
    \u3058\u3066\u3044\u308B\u306E\u3067\u3001ACL\u306E\u3068\u540C\u3058\u3088\u3046\
    \u306B\u4F7F\u3048\u308B\u3002\n// \u30FB\u8FFD\u52A0\u70B9\u3068\u3057\u3066\u306F\
    \u3001\u3069\u3046\u4E0B\u99C4\u3092\u5C65\u304B\u305B\u308B\u304B\u8003\u3048\
    \u305A\u306B\u8CA0\u8FBA\u3042\u308A\u3092\u305D\u306E\u307E\u307E\u6E21\u305B\
    \u308B\u3088\u3046\u306B\u3057\u3066\u3042\u308B\u3002\n// \u3000\u5185\u90E8\u3067\
    \u306F\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u3092\u56DE\u3057\u3066\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8A08\u7B97\u3057\u3066\u308B\u3002\
    \n// \u3000\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u306F2\u4E57\u30AA\
    \u30FC\u30C0\u30FC\u3060\u3051\u3069\u3001\u305D\u3082\u305D\u3082\u6700\u5C0F\
    \u8CBB\u7528\u6D41\u81EA\u4F53\u304C\u7DDA\u5F62log\u3068\u304B\u7121\u7406\u3060\
    \u3068\u601D\u3046\u306E\u3067\u3001\n// \u3000\u5927\u6982\u306E\u5834\u5408\u306F\
    \u3053\u308C\u3067\u554F\u984C\u306A\u3044\u3068\u601D\u3046\u3002\n// \u3000\u3067\
    \u3082\u30D5\u30ED\u30FC\u3067\u69CB\u7BC9\u3059\u308B\u30B0\u30E9\u30D5\u306F\
    \u307B\u307C\u9589\u8DEF\u306A\u3057\u306EDAG\u3060\u3068\u601D\u3046\u306E\u3067\
    \u3001\n// \u3000DAG\u3067\u3042\u308C\u3070DP\u3067\u3082\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u306F\u6C42\u307E\u308B\u3068\u306E\u3053\u3068\u3002\n// \u53C2\u8003\
    \uFF1Ahttps://niuez.hatenablog.com/entry/2019/03/04/142903\n// \u3000\u3000\u3000\
    https://ikatakos.com/pot/programming_algorithm/graph_theory/minimum_cost_flow\n\
    // \u6700\u5C0F\u8CBB\u7528\u6D41\u95A2\u4FC2\u306E\u7528\u8A9E\u306B\u3064\u3044\
    \u3066\n// \u30FB\u6700\u5C0F\u8CBB\u7528\u6700\u5927\u6D41(AOJ1088\u306A\u3069\
    )\n// \u3000\u300C\u6D41\u91CF\u512A\u5148\u3067\u4E00\u756A\u591A\u304F\u6D41\
    \u3057\u3066\u3001\u305D\u306E\u6642\u306E\u6D41\u91CF\u3068\u30B3\u30B9\u30C8\
    \u300D\u3092\u53D6\u5F97\u3059\u308B\u3002\n// \u3000ACL\u306E\u5834\u5408\u306F\
    \u6D41\u91CF\u6307\u5B9A\u306B\u5BFE\u3057\u3066\u3001\u305D\u308C\u306B\u9054\
    \u3059\u308B\u307E\u3067\u3067\u304D\u308B\u9650\u308A\u6700\u5927\u9650\u6D41\
    \u3057\u3066\u3001\n// \u3000\u7121\u7406\u306A\u3089\u305D\u308C\u306B\u8FD1\u3044\
    \u6700\u5927\u307E\u3067\u6D41\u3059\u3088\u3046\u306A\u4ED5\u69D8\u306A\u306E\
    \u3067\u3001\u7279\u306B\u6C17\u306B\u3057\u306A\u304F\u3066\u3082\u3053\u308C\
    \u304C\u53D6\u5F97\u3067\u304D\u308B\u3002\n// \u3000\u306A\u304A\u3001flow\u3092\
    \u547C\u3076\u6642\u306B\u7B2C\u4E09\u5F15\u6570\u3092\u7701\u7565\u3059\u308C\
    \u3070\u52DD\u624B\u306Bnumeric_limits::max()\u307E\u3067\u6D41\u3057\u3066\u304F\
    \u308C\u308B\u306E\u3067\u3001\n// \u3000\u305D\u308C\u3067\u3082\u3044\u3044\u3057\
    \u3001\u3082\u3061\u308D\u3093\u81EA\u5206\u3067\u60F3\u5B9A\u3055\u308C\u308B\
    \u6700\u5927\u6D41\u91CF\u3092\u6307\u5B9A\u3057\u3066\u3082\u3044\u3044\u3002\
    \n// \u30FB\u4EFB\u610F\u6D41\u91CF\u306E\u6700\u5C0F\u8CBB\u7528\u6D41(AOJ2293\u3001\
    practice2_e\u306A\u3069)\n// \u3000\u300C\u6D41\u91CF\u306F\u4EFB\u610F\u3001\u30B3\
    \u30B9\u30C8\u512A\u5148\u3067\u6D41\u3057\u3066\u3001\u305D\u306E\u6642\u306E\
    \u6D41\u91CF\u3068\u30B3\u30B9\u30C8\u300D\u3092\u53D6\u5F97\u3059\u308B\u3002\
    \n// \u3000\u6D41\u91CF\u306F\u4F55\u3067\u3082\u3044\u3044\u304B\u3089\u5229\u5F97\
    \u6700\u5927\u304C\u53D6\u308A\u305F\u3044\u3001\u307F\u305F\u3044\u306A\u6642\
    \u306B\u4F7F\u3046\u3002\n// \u3000\u3053\u308C\u3092\u3084\u308B\u305F\u3081\u306B\
    \u306F\u3001\u59CB\u70B9\u304B\u3089\u7D42\u70B9\u3078\u6D41\u91CF\u7121\u5236\
    \u9650\u306E\u76F4\u901A\u8FBA\u3092\u5F35\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n// \u3000\u305D\u3046\u3059\u308C\u3070\u672C\u6765\u306E\u8FBA\u3067\u6D41\
    \u3057\u5207\u308C\u306A\u3044\u5206\u306F\u5168\u3066\u3053\u3061\u3089\u306B\
    \u6D41\u308C\u308B\u306E\u3067\u3001\n// \u3000\u6D41\u91CF\u306F\u5E38\u306B\u6700\
    \u5927\u3001\u305D\u306E\u4E2D\u3067\u5229\u5F97\u304C\u9AD8\u3044\u3082\u306E\
    \u304C\u9078\u3070\u308C\u3066\u3001\u3053\u308C\u304C\u53D6\u5F97\u3067\u304D\
    \u308B\u3002\n// \u3000\u6D41\u91CF\u7121\u5236\u9650\u306F\u9069\u5F53\u306B\
    INF\u3067\u3082\u69CB\u308F\u306A\u3044\u304C\u3001\u6CE8\u610F\u70B9\u3068\u3057\
    \u3066\u3001\n// \u3000flow\u3092\u547C\u3076\u6642\u306B\u76F4\u901A\u8FBA\u306E\
    \u6D41\u91CF\u3088\u308A\u5927\u304D\u3044\u5024\u3092\u6307\u5B9A\u3057\u306A\
    \u3044\u3053\u3068\u304C\u3042\u308B\u3002\n// \u3000\u3053\u308C\u304C\u5927\u304D\
    \u3044\u3068\u6D41\u91CF\u304C\u512A\u5148\u3055\u308C\u3066\u3057\u307E\u3044\
    \u3001\u5229\u5F97\u6700\u5927\u304C\u53D6\u308C\u306A\u3044\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u3002\ntemplate<typename Cap, typename Cost>\nstruct MinCostFlow\
    \ : atcoder::mcf_graph<Cap, Cost> {\n    using base_type = atcoder::mcf_graph<Cap,\
    \ Cost>;\n\n    int N;\n    bool has_negative = false;\n    vector<tuple<int,\
    \ int, Cost>> temp_edges;\n    vector<Cap> caps;\n    vector<Cost> potential;\n\
    \n    MinCostFlow(int N) : base_type(N), N(N), has_negative(false) {\n       \
    \ potential.assign(N, 0);\n    }\n\n    int add_edge(int from, int to, Cap cap,\
    \ Cost cost) {\n        if (cost < 0) {\n            has_negative = true;\n  \
    \      }\n        int m = temp_edges.size();\n        temp_edges.emplace_back(from,\
    \ to, cost);\n        caps.emplace_back(cap);\n        return m;\n    }\n\n  \
    \  void build(int s) {\n        if (has_negative) {\n            potential = bellman_ford(N,\
    \ temp_edges, s);\n            for (int i = 0; i < N; i++) {\n               \
    \ // s\u304B\u3089\u5230\u9054\u4E0D\u53EF\u306E\u70B9\u306E\u3053\u3068\u306F\
    \u8003\u3048\u3066\u306A\u304F\u3066\u3044\u3044\n                if (potential[i]\
    \ >= INF) {\n                    potential[i] = 0;\n                }\n      \
    \          // \u8CA0\u9589\u8DEF\u306F\u306A\u3044\u3082\u306E\u3068\u3059\u308B\
    \n                assert(potential[i] > -INF);\n            }\n        }\n   \
    \     for (int i = 0; i < temp_edges.size(); i++) {\n            auto [from, to,\
    \ cost] = temp_edges[i];\n            base_type::add_edge(from, to, caps[i], cost\
    \ + potential[from] - potential[to]);\n        }\n    }\n\n    pair<Cap, Cost>\
    \ flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n    pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n        return\
    \ slope(s, t, flow_limit).back();\n    }\n    vector<pair<Cap, Cost>> slope(int\
    \ s, int t) {\n        return slope(s, t, numeric_limits<Cap>::max());\n    }\n\
    \    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {\n        build(s);\n\
    \        auto result = base_type::slope(s, t, flow_limit);\n        if (has_negative)\
    \ {\n            for (auto &[flow, cost] : result) {\n                cost +=\
    \ (potential[t] - potential[s]) * flow;\n            }\n        }\n        return\
    \ result;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/acl/mincostflow.hpp
  - src/graph/bellman_ford.hpp
  - src/common/chmin.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/graph/MinCostFlow.hpp
  requiredBy: []
  timestamp: '2024-06-13 19:20:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/MinCostFlow.hpp
layout: document
redirect_from:
- /library/src/graph/MinCostFlow.hpp
- /library/src/graph/MinCostFlow.hpp.html
title: src/graph/MinCostFlow.hpp
---
