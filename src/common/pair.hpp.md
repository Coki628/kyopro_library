---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \u8A08\u7B97\ntemplate<class T, class U>\ninline pair<T, U> &operator+=(pair<T,\
    \ U> &a, const pair<T, U> &b) {\n    a.fi += b.fi;\n    a.se += b.se;\n    return\
    \ a;\n}\ntemplate<class T, class U>\ninline pair<T, U> &operator-=(pair<T, U>\
    \ &a, const pair<T, U> &b) {\n    a.fi -= b.fi;\n    a.se -= b.se;\n    return\
    \ a;\n}\ntemplate<class T, class U>\ninline pair<T, U> &operator*=(pair<T, U>\
    \ &a, const pair<T, U> &b) {\n    a.fi *= b.fi;\n    a.se *= b.se;\n    return\
    \ a;\n}\ntemplate<class T, class U>\ninline pair<T, U> &operator/=(pair<T, U>\
    \ &a, const pair<T, U> &b) {\n    a.fi /= b.fi;\n    a.se /= b.se;\n    return\
    \ a;\n}\n\n// \u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u30FB\u30C7\u30AF\u30EA\
    \u30E1\u30F3\u30C8\ntemplate<class T, class U>\nconstexpr void operator++(pair<T,\
    \ U> &a, int) noexcept {\n    a.first++;\n    a.second++;\n}\ntemplate<class T,\
    \ class U>\nconstexpr void operator--(pair<T, U> &a, int) noexcept {\n    a.first--;\n\
    \    a.second--;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// pair\u306E\u56DB\u5247\u8A08\
    \u7B97\ntemplate<class T, class U>\ninline pair<T, U> &operator+=(pair<T, U> &a,\
    \ const pair<T, U> &b) {\n    a.fi += b.fi;\n    a.se += b.se;\n    return a;\n\
    }\ntemplate<class T, class U>\ninline pair<T, U> &operator-=(pair<T, U> &a, const\
    \ pair<T, U> &b) {\n    a.fi -= b.fi;\n    a.se -= b.se;\n    return a;\n}\ntemplate<class\
    \ T, class U>\ninline pair<T, U> &operator*=(pair<T, U> &a, const pair<T, U> &b)\
    \ {\n    a.fi *= b.fi;\n    a.se *= b.se;\n    return a;\n}\ntemplate<class T,\
    \ class U>\ninline pair<T, U> &operator/=(pair<T, U> &a, const pair<T, U> &b)\
    \ {\n    a.fi /= b.fi;\n    a.se /= b.se;\n    return a;\n}\n\n// \u30A4\u30F3\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u30FB\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\ntemplate<class\
    \ T, class U>\nconstexpr void operator++(pair<T, U> &a, int) noexcept {\n    a.first++;\n\
    \    a.second++;\n}\ntemplate<class T, class U>\nconstexpr void operator--(pair<T,\
    \ U> &a, int) noexcept {\n    a.first--;\n    a.second--;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/pair.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/pair.hpp
layout: document
redirect_from:
- /library/src/common/pair.hpp
- /library/src/common/pair.hpp.html
title: src/common/pair.hpp
---
