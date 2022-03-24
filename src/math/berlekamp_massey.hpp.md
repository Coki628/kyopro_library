---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/BM.hpp
    title: src/math/BM.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Berlekamp Massey
    links: []
  bundledCode: "#line 1 \"src/math/berlekamp_massey.hpp\"\n/**\n * @brief Berlekamp\
    \ Massey\n */\ntemplate< template< typename > class FPS, typename Mint >\nFPS<\
    \ Mint > berlekamp_massey(const FPS< Mint > &s) {\n    const int N = (int) s.size();\n\
    \    FPS< Mint > b = {Mint(-1)}, c = {Mint(-1)};\n    Mint y = Mint(1);\n    for(int\
    \ ed = 1; ed <= N; ed++) {\n        int l = int(c.size()), m = int(b.size());\n\
    \        Mint x = 0;\n        for(int i = 0; i < l; i++) x += c[i] * s[ed - l\
    \ + i];\n        b.emplace_back(0);\n        m++;\n        if(x == Mint(0)) continue;\n\
    \        Mint freq = x / y;\n        if(l < m) {\n            auto tmp = c;\n\
    \            c.insert(begin(c), m - l, Mint(0));\n            for(int i = 0; i\
    \ < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n            b = tmp;\n     \
    \       y = x;\n        } else {\n            for(int i = 0; i < m; i++) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n    return c;\n}\n"
  code: "/**\n * @brief Berlekamp Massey\n */\ntemplate< template< typename > class\
    \ FPS, typename Mint >\nFPS< Mint > berlekamp_massey(const FPS< Mint > &s) {\n\
    \    const int N = (int) s.size();\n    FPS< Mint > b = {Mint(-1)}, c = {Mint(-1)};\n\
    \    Mint y = Mint(1);\n    for(int ed = 1; ed <= N; ed++) {\n        int l =\
    \ int(c.size()), m = int(b.size());\n        Mint x = 0;\n        for(int i =\
    \ 0; i < l; i++) x += c[i] * s[ed - l + i];\n        b.emplace_back(0);\n    \
    \    m++;\n        if(x == Mint(0)) continue;\n        Mint freq = x / y;\n  \
    \      if(l < m) {\n            auto tmp = c;\n            c.insert(begin(c),\
    \ m - l, Mint(0));\n            for(int i = 0; i < m; i++) c[m - 1 - i] -= freq\
    \ * b[m - 1 - i];\n            b = tmp;\n            y = x;\n        } else {\n\
    \            for(int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n\
    \        }\n    }\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/berlekamp_massey.hpp
  requiredBy:
  - src/math/BM.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/math/berlekamp_massey.hpp
- /library/src/math/berlekamp_massey.hpp.html
title: Berlekamp Massey
---
