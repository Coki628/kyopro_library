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
  bundledCode: "#line 1 \"src/combinatorics/bell.hpp\"\n// \u30D9\u30EB\u6570(\u7389\
    \u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\u306A\u3057\u3001\u5236\u9650\
    \u306A\u3057) \u203B\u672AVerify\nll bell(int N, int K) {\n    ll ans = 0;\n \
    \   rep(i, K+1) {\n        ans += stirling(N, i)[N][i];\n    }\n    return ans;\n\
    }\n\n// \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\
    \u306A\u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672AVerify\nmint bell(int\
    \ N, int K) {\n\n    ModTools<mint> mt(max(N, K));\n\n    // \u524D\u8A08\u7B97\
    \u3057\u3066\u304A\u304F\n    vector<mint> prev(K+1);\n    rep(i, K+1) {\n   \
    \     prev[i] = (mint)1/mt.fact[i];\n    }\n    // \u7D2F\u7A4D\u548C\n    rep(i,\
    \ 1, K+1) {\n        prev[i] += prev[i-1];\n    }\n\n    mint ans = 0;\n    rep(i,\
    \ K+1) {\n        ans += (mint)pow(i, N, MOD)/mt.fact[i]*prev[K-i];\n    }\n \
    \   return ans;\n}\n"
  code: "// \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\
    \u306A\u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672AVerify\nll bell(int N,\
    \ int K) {\n    ll ans = 0;\n    rep(i, K+1) {\n        ans += stirling(N, i)[N][i];\n\
    \    }\n    return ans;\n}\n\n// \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\
    \u3001\u7BB1\u533A\u5225\u306A\u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672A\
    Verify\nmint bell(int N, int K) {\n\n    ModTools<mint> mt(max(N, K));\n\n   \
    \ // \u524D\u8A08\u7B97\u3057\u3066\u304A\u304F\n    vector<mint> prev(K+1);\n\
    \    rep(i, K+1) {\n        prev[i] = (mint)1/mt.fact[i];\n    }\n    // \u7D2F\
    \u7A4D\u548C\n    rep(i, 1, K+1) {\n        prev[i] += prev[i-1];\n    }\n\n \
    \   mint ans = 0;\n    rep(i, K+1) {\n        ans += (mint)pow(i, N, MOD)/mt.fact[i]*prev[K-i];\n\
    \    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/combinatorics/bell.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/bell.hpp
layout: document
redirect_from:
- /library/src/combinatorics/bell.hpp
- /library/src/combinatorics/bell.hpp.html
title: src/combinatorics/bell.hpp
---
