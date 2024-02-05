---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/PersistentLazySegmentTree.hpp
    title: src/datastructure/PersistentLazySegmentTree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/util/object_pool.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/datastructure/ObjectPool.hpp\"\n\n// PersistentLazySegmentTree\u306B\
    \u4F7F\u3046\n// \u53C2\u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/util/object_pool.hpp\n\
    template<typename T, bool auto_extend = false>\nstruct ObjectPool {\n    using\
    \ value_type = T;\n    using value_pointer_type = T *;\n\n    template<typename\
    \ U>\n    using container_type =\n        std::conditional_t<auto_extend, std::deque<U>,\
    \ std::vector<U>>;\n\n    container_type<value_type> pool;\n    container_type<value_pointer_type>\
    \ stock;\n    decltype(stock.begin()) it;\n\n    ObjectPool() : ObjectPool(0)\
    \ {\n    }\n    ObjectPool(int siz) : pool(siz), stock(siz) {\n        clear();\n\
    \    }\n\n    int capacity() const {\n        return pool.size();\n    }\n   \
    \ int size() const {\n        return it - stock.begin();\n    }\n\n    value_pointer_type\
    \ alloc() {\n        if constexpr (auto_extend) ensure();\n        return *it++;\n\
    \    }\n\n    void free(value_pointer_type t) {\n        *--it = t;\n    }\n\n\
    \    void clear() {\n        int siz = pool.size();\n        it = stock.begin();\n\
    \        for (int i = 0; i < siz; i++) stock[i] = &pool[i];\n    }\n\n    void\
    \ ensure() {\n        if (it != stock.end()) return;\n        int siz = stock.size();\n\
    \        for (int i = siz; i <= siz * 2; ++i) {\n            stock.push_back(&pool.emplace_back());\n\
    \        }\n        it = stock.begin() + siz;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// PersistentLazySegmentTree\u306B\
    \u4F7F\u3046\n// \u53C2\u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/util/object_pool.hpp\n\
    template<typename T, bool auto_extend = false>\nstruct ObjectPool {\n    using\
    \ value_type = T;\n    using value_pointer_type = T *;\n\n    template<typename\
    \ U>\n    using container_type =\n        std::conditional_t<auto_extend, std::deque<U>,\
    \ std::vector<U>>;\n\n    container_type<value_type> pool;\n    container_type<value_pointer_type>\
    \ stock;\n    decltype(stock.begin()) it;\n\n    ObjectPool() : ObjectPool(0)\
    \ {\n    }\n    ObjectPool(int siz) : pool(siz), stock(siz) {\n        clear();\n\
    \    }\n\n    int capacity() const {\n        return pool.size();\n    }\n   \
    \ int size() const {\n        return it - stock.begin();\n    }\n\n    value_pointer_type\
    \ alloc() {\n        if constexpr (auto_extend) ensure();\n        return *it++;\n\
    \    }\n\n    void free(value_pointer_type t) {\n        *--it = t;\n    }\n\n\
    \    void clear() {\n        int siz = pool.size();\n        it = stock.begin();\n\
    \        for (int i = 0; i < siz; i++) stock[i] = &pool[i];\n    }\n\n    void\
    \ ensure() {\n        if (it != stock.end()) return;\n        int siz = stock.size();\n\
    \        for (int i = siz; i <= siz * 2; ++i) {\n            stock.push_back(&pool.emplace_back());\n\
    \        }\n        it = stock.begin() + siz;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/ObjectPool.hpp
  requiredBy:
  - src/datastructure/PersistentLazySegmentTree.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/ObjectPool.hpp
layout: document
redirect_from:
- /library/src/datastructure/ObjectPool.hpp
- /library/src/datastructure/ObjectPool.hpp.html
title: src/datastructure/ObjectPool.hpp
---
