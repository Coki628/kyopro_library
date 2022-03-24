---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/mystl/defaultdict.hpp\"\n\n// \u6A19\u6E96\
    map\u3092\u7D99\u627F\u3057\u305Fdefaultdict\ntemplate<typename _Key, typename\
    \ _Tp>\nstruct defaultdict : map<_Key, _Tp> {\n    const _Tp init;\n\n    defaultdict()\
    \ : init(_Tp()) {};\n\n    defaultdict(_Tp init) : init(init) {}\n\n    _Tp& operator[](const\
    \ _Key& k) {\n        if (this->count(k)) {\n            return map<_Key, _Tp>::operator[](k);\n\
    \        } else {\n            return map<_Key, _Tp>::operator[](k) = init;\n\
    \        }\n    }\n\n    _Tp& operator[](_Key&& k) {\n        if (this->count(k))\
    \ {\n            return map<_Key, _Tp>::operator[](k);\n        } else {\n   \
    \         return map<_Key, _Tp>::operator[](k) = init;\n        }\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u6A19\u6E96map\u3092\u7D99\u627F\u3057\u305F\
    defaultdict\ntemplate<typename _Key, typename _Tp>\nstruct defaultdict : map<_Key,\
    \ _Tp> {\n    const _Tp init;\n\n    defaultdict() : init(_Tp()) {};\n\n    defaultdict(_Tp\
    \ init) : init(init) {}\n\n    _Tp& operator[](const _Key& k) {\n        if (this->count(k))\
    \ {\n            return map<_Key, _Tp>::operator[](k);\n        } else {\n   \
    \         return map<_Key, _Tp>::operator[](k) = init;\n        }\n    }\n\n \
    \   _Tp& operator[](_Key&& k) {\n        if (this->count(k)) {\n            return\
    \ map<_Key, _Tp>::operator[](k);\n        } else {\n            return map<_Key,\
    \ _Tp>::operator[](k) = init;\n        }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/defaultdict.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/mystl/defaultdict.hpp
layout: document
redirect_from:
- /library/src/mystl/defaultdict.hpp
- /library/src/mystl/defaultdict.hpp.html
title: src/mystl/defaultdict.hpp
---
