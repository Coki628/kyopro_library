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
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/segment/Mo.hpp\"\n\nstruct Mo {\n    int n;\n\
    \    vector< pair< int, int > > lr;\n\n    explicit Mo(int n) : n(n) {}\n\n  \
    \  // \u30AF\u30A8\u30EA\u3092\u534A\u958B\u533A\u9593[l,r)\u3067\u9806\u756A\u306B\
    \u8FFD\u52A0\n    void add(int l, int r) {\n        lr.emplace_back(l, r);\n \
    \   }\n\n    template< typename AL, typename AR, typename EL, typename ER, typename\
    \ O >\n    void build(const AL &add_left, const AR &add_right, const EL &erase_left,\
    \ const ER &erase_right, const O &out) {\n        int q = (int) lr.size();\n \
    \       int bs = n / min< int >(n, sqrt(q));\n        vector< int > ord(q);\n\
    \        iota(begin(ord), end(ord), 0);\n        sort(begin(ord), end(ord), [&](int\
    \ a, int b) {\n            int ablock = lr[a].first / bs, bblock = lr[b].first\
    \ / bs;\n            if(ablock != bblock) return ablock < bblock;\n          \
    \  return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n\
    \        });\n        int l = 0, r = 0;\n        for(auto idx : ord) {\n     \
    \       while(l > lr[idx].first) add_left(--l);\n            while(r < lr[idx].second)\
    \ add_right(r++);\n            while(l < lr[idx].first) erase_left(l++);\n   \
    \         while(r > lr[idx].second) erase_right(--r);\n            out(idx);\n\
    \        }\n    }\n\n    // add:   \u533A\u9593\u304C\u4F38\u3073\u308B\u6642\u306E\
    \u51E6\u7406(\u5F15\u6570\u306Fmo\u306Eindex)\n    // erase: \u533A\u9593\u304C\
    \u7E2E\u3080\u6642\u306E\u51E6\u7406(\u5F15\u6570\u306Fmo\u306Eindex)\n    //\
    \ out:   \u30AF\u30A8\u30EA\u306B\u56DE\u7B54\u3059\u308B\u51E6\u7406(\u5F15\u6570\
    \u306F\u30AF\u30A8\u30EA\u306Eindex)\n    // \u4F38\u7E2E\u6642\u306B\u5DE6\u53F3\
    \u3067\u51E6\u7406\u306B\u9055\u3044\u304C\u306A\u3051\u308C\u3070add,erase\u306F\
    1\u3064\u305A\u3064\u3067OK\n    template< typename A, typename E, typename O\
    \ >\n    void build(const A &add, const E &erase, const O &out) {\n        build(add,\
    \ add, erase, erase, out);\n    }\n};\n// auto add = [&](int i) -> void {\n//\
    \ };\n// auto erase = [&](int i) -> void {\n// };\n// auto out = [&](int i) ->\
    \ void {\n// };\n\n// \u5DE6\u53F3\u306B\u533A\u5225\u304C\u3042\u308B\u6642\u306F\
    \u3053\u3063\u3061\n// auto add_left = [&](int i) -> void {\n// };\n// auto erase_left\
    \ = [&](int i) -> void {\n// };\n// auto add_right = [&](int i) -> void {\n//\
    \ };\n// auto erase_right = [&](int i) -> void {\n// };\n// auto out = [&](int\
    \ i) -> void {\n// };\n"
  code: "#include \"../base.hpp\"\n\nstruct Mo {\n    int n;\n    vector< pair< int,\
    \ int > > lr;\n\n    explicit Mo(int n) : n(n) {}\n\n    // \u30AF\u30A8\u30EA\
    \u3092\u534A\u958B\u533A\u9593[l,r)\u3067\u9806\u756A\u306B\u8FFD\u52A0\n    void\
    \ add(int l, int r) {\n        lr.emplace_back(l, r);\n    }\n\n    template<\
    \ typename AL, typename AR, typename EL, typename ER, typename O >\n    void build(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const O &out) {\n        int q = (int) lr.size();\n        int bs = n / min<\
    \ int >(n, sqrt(q));\n        vector< int > ord(q);\n        iota(begin(ord),\
    \ end(ord), 0);\n        sort(begin(ord), end(ord), [&](int a, int b) {\n    \
    \        int ablock = lr[a].first / bs, bblock = lr[b].first / bs;\n         \
    \   if(ablock != bblock) return ablock < bblock;\n            return (ablock &\
    \ 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n        });\n\
    \        int l = 0, r = 0;\n        for(auto idx : ord) {\n            while(l\
    \ > lr[idx].first) add_left(--l);\n            while(r < lr[idx].second) add_right(r++);\n\
    \            while(l < lr[idx].first) erase_left(l++);\n            while(r >\
    \ lr[idx].second) erase_right(--r);\n            out(idx);\n        }\n    }\n\
    \n    // add:   \u533A\u9593\u304C\u4F38\u3073\u308B\u6642\u306E\u51E6\u7406(\u5F15\
    \u6570\u306Fmo\u306Eindex)\n    // erase: \u533A\u9593\u304C\u7E2E\u3080\u6642\
    \u306E\u51E6\u7406(\u5F15\u6570\u306Fmo\u306Eindex)\n    // out:   \u30AF\u30A8\
    \u30EA\u306B\u56DE\u7B54\u3059\u308B\u51E6\u7406(\u5F15\u6570\u306F\u30AF\u30A8\
    \u30EA\u306Eindex)\n    // \u4F38\u7E2E\u6642\u306B\u5DE6\u53F3\u3067\u51E6\u7406\
    \u306B\u9055\u3044\u304C\u306A\u3051\u308C\u3070add,erase\u306F1\u3064\u305A\u3064\
    \u3067OK\n    template< typename A, typename E, typename O >\n    void build(const\
    \ A &add, const E &erase, const O &out) {\n        build(add, add, erase, erase,\
    \ out);\n    }\n};\n// auto add = [&](int i) -> void {\n// };\n// auto erase =\
    \ [&](int i) -> void {\n// };\n// auto out = [&](int i) -> void {\n// };\n\n//\
    \ \u5DE6\u53F3\u306B\u533A\u5225\u304C\u3042\u308B\u6642\u306F\u3053\u3063\u3061\
    \n// auto add_left = [&](int i) -> void {\n// };\n// auto erase_left = [&](int\
    \ i) -> void {\n// };\n// auto add_right = [&](int i) -> void {\n// };\n// auto\
    \ erase_right = [&](int i) -> void {\n// };\n// auto out = [&](int i) -> void\
    \ {\n// };\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/segment/Mo.hpp
  requiredBy: []
  timestamp: '2022-05-22 00:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/segment/Mo.hpp
layout: document
redirect_from:
- /library/src/segment/Mo.hpp
- /library/src/segment/Mo.hpp.html
title: src/segment/Mo.hpp
---
