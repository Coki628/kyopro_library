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
    using namespace std;\n#line 3 \"src/mystl/defaultdict.hpp\"\n\n// map\u3092\u7D99\
    \u627F\u3057\u305Fdefaultdict\ntemplate<typename _Key, typename _Tp>\nstruct defaultdict\
    \ : map<_Key, _Tp> {\n    const _Tp init;\n\n    defaultdict() : init(_Tp()) {};\n\
    \n    defaultdict(_Tp init) : init(init) {}\n\n    _Tp &operator[](const _Key\
    \ &k) {\n        if (this->count(k)) {\n            return map<_Key, _Tp>::operator[](k);\n\
    \        } else {\n            return map<_Key, _Tp>::operator[](k) = init;\n\
    \        }\n    }\n\n    _Tp &operator[](_Key &&k) {\n        if (this->count(k))\
    \ {\n            return map<_Key, _Tp>::operator[](k);\n        } else {\n   \
    \         return map<_Key, _Tp>::operator[](k) = init;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// map\u3092\u7D99\u627F\u3057\u305F\
    defaultdict\ntemplate<typename _Key, typename _Tp>\nstruct defaultdict : map<_Key,\
    \ _Tp> {\n    const _Tp init;\n\n    defaultdict() : init(_Tp()) {};\n\n    defaultdict(_Tp\
    \ init) : init(init) {}\n\n    _Tp &operator[](const _Key &k) {\n        if (this->count(k))\
    \ {\n            return map<_Key, _Tp>::operator[](k);\n        } else {\n   \
    \         return map<_Key, _Tp>::operator[](k) = init;\n        }\n    }\n\n \
    \   _Tp &operator[](_Key &&k) {\n        if (this->count(k)) {\n            return\
    \ map<_Key, _Tp>::operator[](k);\n        } else {\n            return map<_Key,\
    \ _Tp>::operator[](k) = init;\n        }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/defaultdict.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-01-22 18:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/defaultdict.hpp
layout: document
redirect_from:
- /library/src/mystl/defaultdict.hpp
- /library/src/mystl/defaultdict.hpp.html
title: src/mystl/defaultdict.hpp
---
