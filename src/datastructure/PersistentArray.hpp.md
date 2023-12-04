---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/PersistentUnionFind.hpp
    title: src/graph/PersistentUnionFind.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/others/persistent-array.cpp
    - https://qiita.com/hotman78/items/9c643feae1de087e6fc5#%E3%81%9D%E3%82%82%E3%81%9D%E3%82%82%E9%85%8D%E5%88%97%E3%81%A8%E3%81%AF
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/datastructure/PersistentArray.hpp\"\n\n//\
    \ \u6C38\u7D9A\u914D\u5217\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/others/persistent-array.cpp\n\
    // \u3000\u3000\u3000https://qiita.com/hotman78/items/9c643feae1de087e6fc5#%E3%81%9D%E3%82%82%E3%81%9D%E3%82%82%E9%85%8D%E5%88%97%E3%81%A8%E3%81%AF\n\
    // \u7279\u5FB4\n// \u30FB\u5143\u306E\u8981\u7D20\u6570\u304CN\u3042\u308B\u914D\
    \u5217\u3067\u3082\u30B3\u30D4\u30FC\u306Blog(N)\u304F\u3089\u3044\u3057\u304B\
    \u304B\u304B\u3089\u305A\u6E08\u3080\u3002\n// \u30FB\u57FA\u672C\u7684\u306B\
    get\u3068update\u3092\u4F7F\u3063\u3066\u3001\u666E\u901A\u306E\u914D\u5217\u3068\
    \u540C\u3058\u3088\u3046\u306B\u64CD\u4F5C\u3059\u308B\u3002\n// \u30FBmutable_get\u3067\
    \u3082\u5024\u304C\u53D6\u308C\u308B\u304C\u3001\u53C2\u7167\u3082\u5168\u90E8\
    \u3053\u308C\u3084\u308B\u3068node\u5897\u3048\u3059\u304E\u3066MLE\u3057\u304C\
    \u3061\u3063\u307D\u3044\u3002\n// \u30FB\u4F55\u5206\u6728\u306B\u3059\u308B\u304B\
    \u3060\u304C\u3001hotman\u3055\u3093\u306B\u3088\u308B\u306820\u5206\u6728\u304F\
    \u3089\u3044\u304C\u3044\u3044\u3089\u3057\u3044\u3002\n// \u3000\u304C\u3057\u304B\
    \u305740\u4E07\u30AF\u30A8\u30EA\u306E\u554F\u984C\u306B\u6C38\u7D9AUF\u30672,4,8,16\u3092\
    \u8A66\u3057\u306B\u4F7F\u3063\u305F\u3068\u3053\u308D\u3001\n// \u3000\u901F\u5EA6\
    \u306F(4,8,16\u3067\u5927\u5DEE\u306A\u3044\u3082\u306E\u306E)8\u5206\u6728\u304C\
    \u4E00\u756A\u901F\u304F\u3066\u3001\u30E1\u30E2\u30EA\u306F(4,8\u3067\u5927\u5DEE\
    \u306A\u3044\u3051\u3069)4\u5206\u6728\u304C\u4E00\u756A\u8EFD\u304B\u3063\u305F\
    \u3002\n// \u30002\u5206\u6728\u306B\u306A\u308B\u3068\u6025\u306B\u8272\u3005\
    \u60AA\u304F\u306A\u3063\u305F\u3002\u7D50\u5C40\u3001\u3046\u3057\u3055\u3093\
    \u304C\u521D\u671F\u8A2D\u5B9A\u306B\u3057\u3066\u305FLOG=3\u304C\u4E00\u756A\u59A5\
    \u5F53\u3063\u307D\u3044\uFF1F\n// \u30FB\u7279\u5B9A\u306E\u6642\u70B9\u3067\u306E\
    \u72B6\u614B\u306E\u8A18\u9332/\u5FA9\u5143\u306B\u306F\u30DD\u30A4\u30F3\u30BF\
    \u3092\u7528\u3044\u308B\u3002\n// \u3000\u306A\u308B\u3079\u304F\u76F4\u611F\u7684\
    \u306B\u64CD\u4F5C\u3067\u304D\u308B\u3088\u3046\u306B\u30E1\u30BD\u30C3\u30C9\
    \u3092\u751F\u3084\u3057\u3066\u304A\u3044\u305F\u3002\n\ntemplate<typename T,\
    \ int LOG>\nstruct PersistentArray {\npublic:\n    struct Node {\n        T data;\n\
    \        // 2^LOG\u5206\u6728\u3067\u69CB\u7BC9\u3059\u308B\n        Node *child[1\
    \ << LOG] = {};\n\n        Node() {}\n\n        Node(const T &data) : data(data)\
    \ {}\n    };\n\nprivate:\n    Node *build(Node *t, const T &data, int k) {\n \
    \       if (!t) t = new Node();\n        if (k == 0) {\n            t->data =\
    \ data;\n            return t;\n        }\n        auto p = build(t->child[k &\
    \ ((1 << LOG) - 1)], data, k >> LOG);\n        t->child[k & ((1 << LOG) - 1)]\
    \ = p;\n        return t;\n    }\n\n    T get(Node *t, int k) {\n        if (k\
    \ == 0) return t->data;\n        return get(t->child[k & ((1 << LOG) - 1)], k\
    \ >> LOG);\n    }\n\n    pair<Node *, T *> mutable_get(Node *t, int k) {\n   \
    \     t = t ? new Node(*t) : new Node();\n        if (k == 0) return {t, &t->data};\n\
    \        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n   \
    \     t->child[k & ((1 << LOG) - 1)] = p.first;\n        return {t, p.second};\n\
    \    }\n\n    T *mutable_get(const int &k) {\n        auto ret = mutable_get(root,\
    \ k);\n        root = ret.first;\n        return ret.second;\n    }\n\npublic:\n\
    \    PersistentArray() : root(nullptr) {}\n\n    Node *root;\n\n    void build(const\
    \ vector<T> &v) {\n        root = nullptr;\n        for (int i = 0; i < v.size();\
    \ i++) {\n            root = build(root, v[i], i);\n        }\n    }\n\n    T\
    \ get(const int &k) {\n        return get(root, k);\n    }\n\n    T operator[](int\
    \ i) {\n        return get(i);\n    }\n\n    void update(const int &k, const T\
    \ &v) {\n        *mutable_get(k) = v;\n    }\n\n    // \u73FE\u5728\u306E\u914D\
    \u5217\u306E\u72B6\u614B\u3092\u8A18\u9332\u3059\u308B\n    Node *save() {\n \
    \       return root;\n    }\n\n    // \u30DD\u30A4\u30F3\u30BFp\u6642\u70B9\u306E\
    \u914D\u5217\u306E\u72B6\u614B\u3092\u5FA9\u5143\u3059\u308B\n    void load(Node\
    \ *p) {\n        root = p;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u6C38\u7D9A\u914D\u5217\n//\
    \ \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/others/persistent-array.cpp\n\
    // \u3000\u3000\u3000https://qiita.com/hotman78/items/9c643feae1de087e6fc5#%E3%81%9D%E3%82%82%E3%81%9D%E3%82%82%E9%85%8D%E5%88%97%E3%81%A8%E3%81%AF\n\
    // \u7279\u5FB4\n// \u30FB\u5143\u306E\u8981\u7D20\u6570\u304CN\u3042\u308B\u914D\
    \u5217\u3067\u3082\u30B3\u30D4\u30FC\u306Blog(N)\u304F\u3089\u3044\u3057\u304B\
    \u304B\u304B\u3089\u305A\u6E08\u3080\u3002\n// \u30FB\u57FA\u672C\u7684\u306B\
    get\u3068update\u3092\u4F7F\u3063\u3066\u3001\u666E\u901A\u306E\u914D\u5217\u3068\
    \u540C\u3058\u3088\u3046\u306B\u64CD\u4F5C\u3059\u308B\u3002\n// \u30FBmutable_get\u3067\
    \u3082\u5024\u304C\u53D6\u308C\u308B\u304C\u3001\u53C2\u7167\u3082\u5168\u90E8\
    \u3053\u308C\u3084\u308B\u3068node\u5897\u3048\u3059\u304E\u3066MLE\u3057\u304C\
    \u3061\u3063\u307D\u3044\u3002\n// \u30FB\u4F55\u5206\u6728\u306B\u3059\u308B\u304B\
    \u3060\u304C\u3001hotman\u3055\u3093\u306B\u3088\u308B\u306820\u5206\u6728\u304F\
    \u3089\u3044\u304C\u3044\u3044\u3089\u3057\u3044\u3002\n// \u3000\u304C\u3057\u304B\
    \u305740\u4E07\u30AF\u30A8\u30EA\u306E\u554F\u984C\u306B\u6C38\u7D9AUF\u30672,4,8,16\u3092\
    \u8A66\u3057\u306B\u4F7F\u3063\u305F\u3068\u3053\u308D\u3001\n// \u3000\u901F\u5EA6\
    \u306F(4,8,16\u3067\u5927\u5DEE\u306A\u3044\u3082\u306E\u306E)8\u5206\u6728\u304C\
    \u4E00\u756A\u901F\u304F\u3066\u3001\u30E1\u30E2\u30EA\u306F(4,8\u3067\u5927\u5DEE\
    \u306A\u3044\u3051\u3069)4\u5206\u6728\u304C\u4E00\u756A\u8EFD\u304B\u3063\u305F\
    \u3002\n// \u30002\u5206\u6728\u306B\u306A\u308B\u3068\u6025\u306B\u8272\u3005\
    \u60AA\u304F\u306A\u3063\u305F\u3002\u7D50\u5C40\u3001\u3046\u3057\u3055\u3093\
    \u304C\u521D\u671F\u8A2D\u5B9A\u306B\u3057\u3066\u305FLOG=3\u304C\u4E00\u756A\u59A5\
    \u5F53\u3063\u307D\u3044\uFF1F\n// \u30FB\u7279\u5B9A\u306E\u6642\u70B9\u3067\u306E\
    \u72B6\u614B\u306E\u8A18\u9332/\u5FA9\u5143\u306B\u306F\u30DD\u30A4\u30F3\u30BF\
    \u3092\u7528\u3044\u308B\u3002\n// \u3000\u306A\u308B\u3079\u304F\u76F4\u611F\u7684\
    \u306B\u64CD\u4F5C\u3067\u304D\u308B\u3088\u3046\u306B\u30E1\u30BD\u30C3\u30C9\
    \u3092\u751F\u3084\u3057\u3066\u304A\u3044\u305F\u3002\n\ntemplate<typename T,\
    \ int LOG>\nstruct PersistentArray {\npublic:\n    struct Node {\n        T data;\n\
    \        // 2^LOG\u5206\u6728\u3067\u69CB\u7BC9\u3059\u308B\n        Node *child[1\
    \ << LOG] = {};\n\n        Node() {}\n\n        Node(const T &data) : data(data)\
    \ {}\n    };\n\nprivate:\n    Node *build(Node *t, const T &data, int k) {\n \
    \       if (!t) t = new Node();\n        if (k == 0) {\n            t->data =\
    \ data;\n            return t;\n        }\n        auto p = build(t->child[k &\
    \ ((1 << LOG) - 1)], data, k >> LOG);\n        t->child[k & ((1 << LOG) - 1)]\
    \ = p;\n        return t;\n    }\n\n    T get(Node *t, int k) {\n        if (k\
    \ == 0) return t->data;\n        return get(t->child[k & ((1 << LOG) - 1)], k\
    \ >> LOG);\n    }\n\n    pair<Node *, T *> mutable_get(Node *t, int k) {\n   \
    \     t = t ? new Node(*t) : new Node();\n        if (k == 0) return {t, &t->data};\n\
    \        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n   \
    \     t->child[k & ((1 << LOG) - 1)] = p.first;\n        return {t, p.second};\n\
    \    }\n\n    T *mutable_get(const int &k) {\n        auto ret = mutable_get(root,\
    \ k);\n        root = ret.first;\n        return ret.second;\n    }\n\npublic:\n\
    \    PersistentArray() : root(nullptr) {}\n\n    Node *root;\n\n    void build(const\
    \ vector<T> &v) {\n        root = nullptr;\n        for (int i = 0; i < v.size();\
    \ i++) {\n            root = build(root, v[i], i);\n        }\n    }\n\n    T\
    \ get(const int &k) {\n        return get(root, k);\n    }\n\n    T operator[](int\
    \ i) {\n        return get(i);\n    }\n\n    void update(const int &k, const T\
    \ &v) {\n        *mutable_get(k) = v;\n    }\n\n    // \u73FE\u5728\u306E\u914D\
    \u5217\u306E\u72B6\u614B\u3092\u8A18\u9332\u3059\u308B\n    Node *save() {\n \
    \       return root;\n    }\n\n    // \u30DD\u30A4\u30F3\u30BFp\u6642\u70B9\u306E\
    \u914D\u5217\u306E\u72B6\u614B\u3092\u5FA9\u5143\u3059\u308B\n    void load(Node\
    \ *p) {\n        root = p;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/PersistentArray.hpp
  requiredBy:
  - src/graph/PersistentUnionFind.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/PersistentArray.hpp
layout: document
redirect_from:
- /library/src/datastructure/PersistentArray.hpp
- /library/src/datastructure/PersistentArray.hpp.html
title: src/datastructure/PersistentArray.hpp
---
