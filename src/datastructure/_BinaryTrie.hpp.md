---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/data-structure/binary-trie.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/datastructure/_BinaryTrie.hpp\"\n\n// \u53C2\
    \u8003\uFF1Ahttps://nyaannyaan.github.io/library/data-structure/binary-trie.hpp\n\
    // Binary Trie\n// \u7279\u5FB4\n// \u30FB\u4E2D\u592E\u5024\u306E\u53D6\u5F97\
    \u304C\u5EA7\u5727\u306A\u3057\u3067\u3055\u304F\u3063\u3068\u3044\u3051\u308B\
    \u3002(abc218_g\u3092\u53C2\u7167)\n// \u30FB\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u5F15\u6570NODES\u3092\u5C11\u306A\u3081\u306B\u53D6\u308C\u3070\u3001\u30E1\u30E2\
    \u30EA\u524A\u6E1B\u30FB\u901F\u5EA6\u6539\u5584\u3059\u308B\u3051\u3069\u3001\
    \u601D\u3063\u305F\u3088\u308A\u6E1B\u3089\u305B\u306A\u3044\u3002\n// \u3000\u5B9F\
    \u88C5\u3092\u898B\u308B\u9650\u308A\u3001\u591A\u5206\u300Cadd,del\u3092\u4F7F\
    \u3046\u6700\u5927\u56DE\u6570*(MAX_LOG+2)\u300D\u3067\u8DB3\u308A\u308B\u307D\
    \u3044\u3051\u3069\u3001\u78BA\u8A3C\u306F\u306A\u3044\u3002\n// \u3000\u8A66\u3057\
    \u3066\u3046\u307E\u304F\u3044\u3063\u305F\u3060\u3051\u3002\n// \u30FBget_kth\u3092\
    \u3084\u308B\u6642\u3001\u5143\u30050\u304C\u5165\u3063\u3066\u3044\u308B\u3088\
    \u3046\u3067\u30011-index\u3063\u307D\u304F\u53D6\u308B\u3002\n\ntemplate <typename\
    \ T, int MAX_LOG, int NODES = 16777216>\nstruct BinaryTrie {\n    using Container\
    \ = vector<int>;\n    struct Node {\n        Node *nxt[2];\n        int exist;\n\
    \        Container accept;\n        Node() {}\n    };\n\n    Node *pool;\n   \
    \ int pid;\n    T lazy;\n    Node *nil;\n    Node *root;\n    int sz;\n\n    BinaryTrie()\
    \ : pid(0), lazy(T(0)), nil(nullptr), sz(0) {\n        pool = new Node[NODES];\n\
    \        nil = my_new();\n        nil->nxt[0] = nil->nxt[1] = root = nil;\n  \
    \  }\n\n    Node *my_new(int exist_ = 0, int id = -1) {\n        pool[pid].nxt[0]\
    \ = pool[pid].nxt[1] = nil;\n        pool[pid].exist = exist_;\n        if (id\
    \ != -1) pool[pid].accept.push_back(id);\n        return &(pool[pid++]);\n   \
    \ }\n\n    Node *merge(Node *l, Node *r) {\n        pool[pid].nxt[0] = l;\n  \
    \      pool[pid].nxt[1] = r;\n        pool[pid].exist = l->exist + r->exist;\n\
    \        return &(pool[pid++]);\n    }\n\nprivate:\n    Node *add_(const T &x,\
    \ int id, Node *n, int bit_idx) {\n        if (bit_idx == -1) {\n            if\
    \ (n == nil) return my_new(1, id);\n            n->exist++;\n            n->accept.push_back(id);\n\
    \            return n;\n        } else {\n            if (((lazy >> bit_idx) &\
    \ 1) == ((x >> bit_idx) & 1))\n                return merge(add_(x, id, n->nxt[0],\
    \ bit_idx - 1), n->nxt[1]);\n            else\n                return merge(n->nxt[0],\
    \ add_(x, id, n->nxt[1], bit_idx - 1));\n        }\n    }\n\npublic:\n    void\
    \ add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); sz++; }\n\n\
    private:\n    Node *del_(const T &x, int id, Node *n, int bit_idx) {\n       \
    \ if (bit_idx == -1) {\n            n->exist--;\n            return n;\n     \
    \   } else {\n            if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \                return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n\
    \            else\n                return merge(n->nxt[0], del_(x, id, n->nxt[1],\
    \ bit_idx - 1));\n        }\n    }\n\npublic:\n    void del(const T &x, int id\
    \ = -1) { root = del_(x, id, root, MAX_LOG); sz--; }\n\nprivate:\n    pair<int,\
    \ Container &> find_(const T &x, Node *n, int bit_idx) {\n        if (bit_idx\
    \ == -1)\n            return pair<int, Container &>(n->exist, n->accept);\n  \
    \      else {\n            if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \                return find_(x, n->nxt[0], bit_idx - 1);\n            else\n\
    \                return find_(x, n->nxt[1], bit_idx - 1);\n        }\n    }\n\n\
    public:\n    pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG);\
    \ }\n\nprivate:\n    pair<T, Container &> max_element_(Node *n, int bit_idx) {\n\
    \        if (bit_idx == -1) return pair<T, Container &>(0, n->accept);\n     \
    \   if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {\n            auto ret = max_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        } else {\n            return max_element_(n->nxt[(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n        }\n    }\n\npublic:\n    pair<T, Container\
    \ &> max_element() { return max_element_(root, MAX_LOG); }\n\nprivate:\n    pair<T,\
    \ Container &> min_element_(Node *n, int bit_idx) {\n        if (bit_idx == -1)\
    \ return pair<T, Container &>(0, n->accept);\n        if (n->nxt[(lazy >> bit_idx)\
    \ & 1]->exist) {\n            return min_element_(n->nxt[(lazy >> bit_idx) & 1],\
    \ bit_idx - 1);\n        } else {\n            auto ret = min_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        }\n    }\n\npublic:\n    pair<T, Container &>\
    \ min_element() { return min_element_(root, MAX_LOG); }\n\nprivate:\n    pair<T,\
    \ Container &> get_kth_(Node *n, int64_t k, int bit_idx) {\n        if (bit_idx\
    \ == -1) return pair<T, Container &>(0, n->accept);\n        int ex0 = n->nxt[(lazy\
    \ >> bit_idx) & 1]->exist;\n        if (ex0 < k) {\n            auto ret = get_kth_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], k - ex0, bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        } else {\n            return get_kth_(n->nxt[(lazy\
    \ >> bit_idx) & 1], k, bit_idx - 1);\n        }\n    }\n\npublic:\n    pair<T,\
    \ Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }\n\n \
    \   void operate_xor(T x) { lazy ^= x; }\n\n    int size() { return sz; }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/data-structure/binary-trie.hpp\n\
    // Binary Trie\n// \u7279\u5FB4\n// \u30FB\u4E2D\u592E\u5024\u306E\u53D6\u5F97\
    \u304C\u5EA7\u5727\u306A\u3057\u3067\u3055\u304F\u3063\u3068\u3044\u3051\u308B\
    \u3002(abc218_g\u3092\u53C2\u7167)\n// \u30FB\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u5F15\u6570NODES\u3092\u5C11\u306A\u3081\u306B\u53D6\u308C\u3070\u3001\u30E1\u30E2\
    \u30EA\u524A\u6E1B\u30FB\u901F\u5EA6\u6539\u5584\u3059\u308B\u3051\u3069\u3001\
    \u601D\u3063\u305F\u3088\u308A\u6E1B\u3089\u305B\u306A\u3044\u3002\n// \u3000\u5B9F\
    \u88C5\u3092\u898B\u308B\u9650\u308A\u3001\u591A\u5206\u300Cadd,del\u3092\u4F7F\
    \u3046\u6700\u5927\u56DE\u6570*(MAX_LOG+2)\u300D\u3067\u8DB3\u308A\u308B\u307D\
    \u3044\u3051\u3069\u3001\u78BA\u8A3C\u306F\u306A\u3044\u3002\n// \u3000\u8A66\u3057\
    \u3066\u3046\u307E\u304F\u3044\u3063\u305F\u3060\u3051\u3002\n// \u30FBget_kth\u3092\
    \u3084\u308B\u6642\u3001\u5143\u30050\u304C\u5165\u3063\u3066\u3044\u308B\u3088\
    \u3046\u3067\u30011-index\u3063\u307D\u304F\u53D6\u308B\u3002\n\ntemplate <typename\
    \ T, int MAX_LOG, int NODES = 16777216>\nstruct BinaryTrie {\n    using Container\
    \ = vector<int>;\n    struct Node {\n        Node *nxt[2];\n        int exist;\n\
    \        Container accept;\n        Node() {}\n    };\n\n    Node *pool;\n   \
    \ int pid;\n    T lazy;\n    Node *nil;\n    Node *root;\n    int sz;\n\n    BinaryTrie()\
    \ : pid(0), lazy(T(0)), nil(nullptr), sz(0) {\n        pool = new Node[NODES];\n\
    \        nil = my_new();\n        nil->nxt[0] = nil->nxt[1] = root = nil;\n  \
    \  }\n\n    Node *my_new(int exist_ = 0, int id = -1) {\n        pool[pid].nxt[0]\
    \ = pool[pid].nxt[1] = nil;\n        pool[pid].exist = exist_;\n        if (id\
    \ != -1) pool[pid].accept.push_back(id);\n        return &(pool[pid++]);\n   \
    \ }\n\n    Node *merge(Node *l, Node *r) {\n        pool[pid].nxt[0] = l;\n  \
    \      pool[pid].nxt[1] = r;\n        pool[pid].exist = l->exist + r->exist;\n\
    \        return &(pool[pid++]);\n    }\n\nprivate:\n    Node *add_(const T &x,\
    \ int id, Node *n, int bit_idx) {\n        if (bit_idx == -1) {\n            if\
    \ (n == nil) return my_new(1, id);\n            n->exist++;\n            n->accept.push_back(id);\n\
    \            return n;\n        } else {\n            if (((lazy >> bit_idx) &\
    \ 1) == ((x >> bit_idx) & 1))\n                return merge(add_(x, id, n->nxt[0],\
    \ bit_idx - 1), n->nxt[1]);\n            else\n                return merge(n->nxt[0],\
    \ add_(x, id, n->nxt[1], bit_idx - 1));\n        }\n    }\n\npublic:\n    void\
    \ add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); sz++; }\n\n\
    private:\n    Node *del_(const T &x, int id, Node *n, int bit_idx) {\n       \
    \ if (bit_idx == -1) {\n            n->exist--;\n            return n;\n     \
    \   } else {\n            if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \                return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n\
    \            else\n                return merge(n->nxt[0], del_(x, id, n->nxt[1],\
    \ bit_idx - 1));\n        }\n    }\n\npublic:\n    void del(const T &x, int id\
    \ = -1) { root = del_(x, id, root, MAX_LOG); sz--; }\n\nprivate:\n    pair<int,\
    \ Container &> find_(const T &x, Node *n, int bit_idx) {\n        if (bit_idx\
    \ == -1)\n            return pair<int, Container &>(n->exist, n->accept);\n  \
    \      else {\n            if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \                return find_(x, n->nxt[0], bit_idx - 1);\n            else\n\
    \                return find_(x, n->nxt[1], bit_idx - 1);\n        }\n    }\n\n\
    public:\n    pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG);\
    \ }\n\nprivate:\n    pair<T, Container &> max_element_(Node *n, int bit_idx) {\n\
    \        if (bit_idx == -1) return pair<T, Container &>(0, n->accept);\n     \
    \   if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {\n            auto ret = max_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        } else {\n            return max_element_(n->nxt[(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n        }\n    }\n\npublic:\n    pair<T, Container\
    \ &> max_element() { return max_element_(root, MAX_LOG); }\n\nprivate:\n    pair<T,\
    \ Container &> min_element_(Node *n, int bit_idx) {\n        if (bit_idx == -1)\
    \ return pair<T, Container &>(0, n->accept);\n        if (n->nxt[(lazy >> bit_idx)\
    \ & 1]->exist) {\n            return min_element_(n->nxt[(lazy >> bit_idx) & 1],\
    \ bit_idx - 1);\n        } else {\n            auto ret = min_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        }\n    }\n\npublic:\n    pair<T, Container &>\
    \ min_element() { return min_element_(root, MAX_LOG); }\n\nprivate:\n    pair<T,\
    \ Container &> get_kth_(Node *n, int64_t k, int bit_idx) {\n        if (bit_idx\
    \ == -1) return pair<T, Container &>(0, n->accept);\n        int ex0 = n->nxt[(lazy\
    \ >> bit_idx) & 1]->exist;\n        if (ex0 < k) {\n            auto ret = get_kth_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], k - ex0, bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n\
    \            return ret;\n        } else {\n            return get_kth_(n->nxt[(lazy\
    \ >> bit_idx) & 1], k, bit_idx - 1);\n        }\n    }\n\npublic:\n    pair<T,\
    \ Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }\n\n \
    \   void operate_xor(T x) { lazy ^= x; }\n\n    int size() { return sz; }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/_BinaryTrie.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/_BinaryTrie.hpp
layout: document
redirect_from:
- /library/src/datastructure/_BinaryTrie.hpp
- /library/src/datastructure/_BinaryTrie.hpp.html
title: src/datastructure/_BinaryTrie.hpp
---
