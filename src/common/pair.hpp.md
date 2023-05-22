---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/pair.hpp\"\n\n// pair\u306E\u56DB\u5247\
    \u8A08\u7B97\ntemplate<class T, class U> inline pair<T, U>& operator+=(pair<T,\
    \ U>& a, const pair<T, U>& b) {a.fi += b.fi; a.se += b.se; return a;}\ntemplate<class\
    \ T, class U> inline pair<T, U>& operator-=(pair<T, U>& a, const pair<T, U>& b)\
    \ {a.fi -= b.fi; a.se -= b.se; return a;}\ntemplate<class T, class U> inline pair<T,\
    \ U>& operator*=(pair<T, U>& a, const pair<T, U>& b) {a.fi *= b.fi; a.se *= b.se;\
    \ return a;}\ntemplate<class T, class U> inline pair<T, U>& operator/=(pair<T,\
    \ U>& a, const pair<T, U>& b) {a.fi /= b.fi; a.se /= b.se; return a;}\n\ntemplate<class\
    \ T, class U>\nconstexpr void operator++(pair<T, U>& a, int) noexcept {\n    a.first++;\n\
    \    a.second++;\n}\n\ntemplate<class T, class U>\nconstexpr void operator--(pair<T,\
    \ U>& a, int) noexcept {\n    a.first--;\n    a.second--;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// pair\u306E\u56DB\u5247\u8A08\
    \u7B97\ntemplate<class T, class U> inline pair<T, U>& operator+=(pair<T, U>& a,\
    \ const pair<T, U>& b) {a.fi += b.fi; a.se += b.se; return a;}\ntemplate<class\
    \ T, class U> inline pair<T, U>& operator-=(pair<T, U>& a, const pair<T, U>& b)\
    \ {a.fi -= b.fi; a.se -= b.se; return a;}\ntemplate<class T, class U> inline pair<T,\
    \ U>& operator*=(pair<T, U>& a, const pair<T, U>& b) {a.fi *= b.fi; a.se *= b.se;\
    \ return a;}\ntemplate<class T, class U> inline pair<T, U>& operator/=(pair<T,\
    \ U>& a, const pair<T, U>& b) {a.fi /= b.fi; a.se /= b.se; return a;}\n\ntemplate<class\
    \ T, class U>\nconstexpr void operator++(pair<T, U>& a, int) noexcept {\n    a.first++;\n\
    \    a.second++;\n}\n\ntemplate<class T, class U>\nconstexpr void operator--(pair<T,\
    \ U>& a, int) noexcept {\n    a.first--;\n    a.second--;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/pair.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/pair.hpp
layout: document
redirect_from:
- /library/src/common/pair.hpp
- /library/src/common/pair.hpp.html
title: src/common/pair.hpp
---
