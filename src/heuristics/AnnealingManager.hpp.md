---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://gasin.hatenadiary.jp/entry/2019/09/03/162613
    - https://shindannin.hatenadiary.com/entry/20121224/1356364040
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/heuristics/AnnealingManager.hpp\"\n\n// \u713C\
    \u304D\u306A\u307E\u3057\u7BA1\u7406\n// \u53C2\u8003\u8CC7\u6599\uFF1Ahttps://gasin.hatenadiary.jp/entry/2019/09/03/162613\n\
    // \u3000\u3000\u3000\u3000\u3000https://shindannin.hatenadiary.com/entry/20121224/1356364040\n\
    // \u30FB\u6E29\u5EA6\u3068\u60AA\u5316\u91CF\u304C\u540C\u3058\u304F\u3089\u3044\
    \u3060\u30681/3\u304F\u3089\u3044\u306E\u78BA\u7387\u3067\u9077\u79FB\u3001\n\
    // \u3000\u60AA\u5316\u91CF\u304C10\u500D\u304F\u3089\u3044\u3042\u308B\u3068\u307B\
    \u307C0\u306B\u306A\u308B\u3002\nstruct AnnealingManager {\n    const int TL;\n\
    \    // \u958B\u59CB\u6E29\u5EA6\uFF1A\u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\
    \u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6\
    \n    const double T0;\n    // \u7D42\u4E86\u6E29\u5EA6\uFF1A\u4E00\u56DE\u306E\
    \u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\
    \u5C0F\u5024\u7A0B\u5EA6\n    const double T1;\n    // \u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306F\u30B9\u30B3\u30A2\u6700\u5927\u5316\u3067\u6700\u5C0F\u5316\u6642\
    \u306Ftrue\n    bool is_min;\n    // \u6E29\u5EA6\u8A08\u7B97\u306E\u30BF\u30A4\
    \u30D7\n    // 1: \u7DDA\u5F62\n    // 2: 2\u6B21\u95A2\u6570\n    int temp_type;\n\
    \n    // T0 = 0, T1 = 0 \u306B\u3059\u308C\u3070\u5C71\u767B\u308A\n    AnnealingManager(\n\
    \        int TL, double T0, double T1, bool is_min = false, int temp_type = 1\n\
    \    )\n        : TL(TL),\n          T0(T0),\n          T1(T1),\n          is_min(is_min),\n\
    \          temp_type(temp_type) {\n    }\n\n    // 0~1\u306E\u4E00\u69D8\u30E9\
    \u30F3\u30C0\u30E0\u306A\u5B9F\u6570\u3092\u8FD4\u3059\n    double rand_double()\
    \ {\n        return 1.0 * rand() / RAND_MAX;\n    }\n\n    // \u713C\u304D\u306A\
    \u307E\u3057\u306B\u4F7F\u3046\u6E29\u5EA6\u306E\u8A08\u7B97\n    double calc_temp(int\
    \ elapsed) {\n        double t = elapsed / (double)TL;\n        if (t > 1) {\n\
    \            // \u6642\u9593\u5207\u308C\u306F\u6E29\u5EA60\u306B\u3057\u3068\u304F\
    \u304B(\u63A1\u75280)\n            return 0;\n        }\n        if (temp_type\
    \ == 1) {\n            // \u7DDA\u5F62\u3063\u307D\u304F\u6E1B\u308B\n       \
    \     return T0 + (T1 - T0) * t;\n        } else if (temp_type == 2) {\n     \
    \       // 2\u6B21\u95A2\u6570\u3063\u307D\u304F\u6E1B\u308B\n            return\
    \ pow(T0, (1 - t)) * pow(T1, t);\n        }\n        assert(0);\n    }\n\n   \
    \ // \u713C\u304D\u306A\u307E\u3057\u3092\u8E0F\u307E\u3048\u305F\u63A1\u7528\u78BA\
    \u7387\u306E\u8A08\u7B97\n    double calc_prob(double diff, double temp) {\n \
    \       if (diff >= 0) {\n            return 1;\n        }\n        return exp(diff\
    \ / temp);\n    }\n\n    // \u63A1\u7528\u3059\u308B\u304B\u5224\u5B9A\n    bool\
    \ judge(double cur_score, double nxt_score, int elapsed) {\n        double temp\
    \ = calc_temp(elapsed);\n        double diff = nxt_score - cur_score;\n      \
    \  if (is_min) {\n            diff = -diff;\n        }\n        double prob =\
    \ calc_prob(diff, temp);\n        return rand_double() < prob;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u713C\u304D\u306A\u307E\u3057\
    \u7BA1\u7406\n// \u53C2\u8003\u8CC7\u6599\uFF1Ahttps://gasin.hatenadiary.jp/entry/2019/09/03/162613\n\
    // \u3000\u3000\u3000\u3000\u3000https://shindannin.hatenadiary.com/entry/20121224/1356364040\n\
    // \u30FB\u6E29\u5EA6\u3068\u60AA\u5316\u91CF\u304C\u540C\u3058\u304F\u3089\u3044\
    \u3060\u30681/3\u304F\u3089\u3044\u306E\u78BA\u7387\u3067\u9077\u79FB\u3001\n\
    // \u3000\u60AA\u5316\u91CF\u304C10\u500D\u304F\u3089\u3044\u3042\u308B\u3068\u307B\
    \u307C0\u306B\u306A\u308B\u3002\nstruct AnnealingManager {\n    const int TL;\n\
    \    // \u958B\u59CB\u6E29\u5EA6\uFF1A\u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\
    \u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6\
    \n    const double T0;\n    // \u7D42\u4E86\u6E29\u5EA6\uFF1A\u4E00\u56DE\u306E\
    \u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\
    \u5C0F\u5024\u7A0B\u5EA6\n    const double T1;\n    // \u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306F\u30B9\u30B3\u30A2\u6700\u5927\u5316\u3067\u6700\u5C0F\u5316\u6642\
    \u306Ftrue\n    bool is_min;\n    // \u6E29\u5EA6\u8A08\u7B97\u306E\u30BF\u30A4\
    \u30D7\n    // 1: \u7DDA\u5F62\n    // 2: 2\u6B21\u95A2\u6570\n    int temp_type;\n\
    \n    // T0 = 0, T1 = 0 \u306B\u3059\u308C\u3070\u5C71\u767B\u308A\n    AnnealingManager(\n\
    \        int TL, double T0, double T1, bool is_min = false, int temp_type = 1\n\
    \    )\n        : TL(TL),\n          T0(T0),\n          T1(T1),\n          is_min(is_min),\n\
    \          temp_type(temp_type) {\n    }\n\n    // 0~1\u306E\u4E00\u69D8\u30E9\
    \u30F3\u30C0\u30E0\u306A\u5B9F\u6570\u3092\u8FD4\u3059\n    double rand_double()\
    \ {\n        return 1.0 * rand() / RAND_MAX;\n    }\n\n    // \u713C\u304D\u306A\
    \u307E\u3057\u306B\u4F7F\u3046\u6E29\u5EA6\u306E\u8A08\u7B97\n    double calc_temp(int\
    \ elapsed) {\n        double t = elapsed / (double)TL;\n        if (t > 1) {\n\
    \            // \u6642\u9593\u5207\u308C\u306F\u6E29\u5EA60\u306B\u3057\u3068\u304F\
    \u304B(\u63A1\u75280)\n            return 0;\n        }\n        if (temp_type\
    \ == 1) {\n            // \u7DDA\u5F62\u3063\u307D\u304F\u6E1B\u308B\n       \
    \     return T0 + (T1 - T0) * t;\n        } else if (temp_type == 2) {\n     \
    \       // 2\u6B21\u95A2\u6570\u3063\u307D\u304F\u6E1B\u308B\n            return\
    \ pow(T0, (1 - t)) * pow(T1, t);\n        }\n        assert(0);\n    }\n\n   \
    \ // \u713C\u304D\u306A\u307E\u3057\u3092\u8E0F\u307E\u3048\u305F\u63A1\u7528\u78BA\
    \u7387\u306E\u8A08\u7B97\n    double calc_prob(double diff, double temp) {\n \
    \       if (diff >= 0) {\n            return 1;\n        }\n        return exp(diff\
    \ / temp);\n    }\n\n    // \u63A1\u7528\u3059\u308B\u304B\u5224\u5B9A\n    bool\
    \ judge(double cur_score, double nxt_score, int elapsed) {\n        double temp\
    \ = calc_temp(elapsed);\n        double diff = nxt_score - cur_score;\n      \
    \  if (is_min) {\n            diff = -diff;\n        }\n        double prob =\
    \ calc_prob(diff, temp);\n        return rand_double() < prob;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/heuristics/AnnealingManager.hpp
  requiredBy: []
  timestamp: '2023-12-11 16:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/heuristics/AnnealingManager.hpp
layout: document
redirect_from:
- /library/src/heuristics/AnnealingManager.hpp
- /library/src/heuristics/AnnealingManager.hpp.html
title: src/heuristics/AnnealingManager.hpp
---
