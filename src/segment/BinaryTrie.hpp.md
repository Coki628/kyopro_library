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
    - https://ei1333.github.io/library/structure/trie/binary-trie.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/segment/BinaryTrie.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/structure/trie/binary-trie.hpp\n// Binary\
    \ Trie\n// \u7279\u5FB4\n// \u30FB\u4E2D\u592E\u5024\u306E\u53D6\u5F97\u304C\u5EA7\
    \u5727\u306A\u3057\u3067\u3055\u304F\u3063\u3068\u3044\u3051\u308B\u3002(abc218_g\u3092\
    \u53C2\u7167)\n// \u30FBkth_element\u306F0-indexed\n// \u30FBindex\u3092accept\u306B\
    \u683C\u7D0D\u3057\u3066\u304A\u3051\u308B\u3051\u3069\u3001erase\u3067\u6D88\u3059\
    \u8A33\u3058\u3083\u306A\u3044\u307D\u3044\u306E\u3067\u3001\n// \u3000\u524A\u9664\
    \u304C\u3042\u308B\u6642\u306F\u3053\u3053\u5F53\u3066\u306B\u305B\u305A\u5225\
    \u914D\u5217\u6301\u3063\u305F\u65B9\u304C\u3044\u3044\u307D\u3044\u3002\n// \u30FB\
    count_less\u4F7F\u3048\u3070\u300Ck\u756A\u76EE\u306E\u5024\u300D\u3058\u3083\u306A\
    \u304F\u3066\u300C\u5024x\u306F\u4F55\u756A\u76EE\u304B\u300D\u3082\u53D6\u308C\
    \u308B\u3002(past202203_m\u3092\u53C2\u7167)\n\ntemplate< typename T, int MAX_LOG,\
    \ typename D = int >\nstruct BinaryTrie {\npublic:\n    struct Node {\n      \
    \  Node *nxt[2];\n        D exist;\n        vector< int > accept;\n\n        Node()\
    \ : nxt{nullptr, nullptr}, exist(0) {}\n    };\n\n    Node *root;\n\n    explicit\
    \ BinaryTrie() : root(new Node()) {}\n\n    explicit BinaryTrie(Node *root) :\
    \ root(root) {}\n\n    void add(const T &bit, int idx = -1, D delta = 1, T xor_val\
    \ = 0) {\n        root = add(root, bit, idx, MAX_LOG, delta, xor_val);\n    }\n\
    \n    void erase(const T &bit, T xor_val = 0) {\n        add(bit, -1, -1, xor_val);\n\
    \    }\n\n    Node *find(const T &bit, T xor_val = 0) {\n        return find(root,\
    \ bit, MAX_LOG, xor_val);\n    }\n\n    D count(const T &bit, T xor_val = 0) {\n\
    \        auto node = find(bit, xor_val);\n        return node ? node->exist :\
    \ 0;\n    }\n\n    pair< T, Node * > min_element(T xor_val = 0) {\n        assert(root->exist\
    \ > 0);\n        return kth_element(0, xor_val);\n    }\n\n    pair< T, Node *\
    \ > max_element(T xor_val = 0) {\n        assert(root->exist > 0);\n        return\
    \ kth_element(root->exist - 1, xor_val);\n    }\n\n    pair< T, Node * > kth_element(D\
    \ k, T xor_val = 0) { // 0-indexed\n        assert(0 <= k && k < root->exist);\n\
    \        return kth_element(root, k, MAX_LOG, xor_val);\n    }\n\n    D count_less(const\
    \ T &bit, T xor_val = 0) { // < bit\n        return count_less(root, bit, MAX_LOG,\
    \ xor_val);\n    }\n\nprivate:\n\n    virtual Node *clone(Node *t) { return t;\
    \ }\n\n    Node *add(Node *t, T bit, int idx, int depth, D x, T xor_val, bool\
    \ need = true) {\n        if(need) t = clone(t);\n        if(depth == -1) {\n\
    \            t->exist += x;\n            if(idx >= 0) t->accept.emplace_back(idx);\n\
    \        } else {\n            bool f = (xor_val >> depth) & 1;\n            auto\
    \ &to = t->nxt[f ^ ((bit >> depth) & 1)];\n            if(!to) to = new Node(),\
    \ need = false;\n            to = add(to, bit, idx, depth - 1, x, xor_val, need);\n\
    \            t->exist += x;\n        }\n        return t;\n    }\n\n    Node *find(Node\
    \ *t, T bit, int depth, T xor_val) {\n        if(depth == -1) {\n            return\
    \ t;\n        } else {\n            bool f = (xor_val >> depth) & 1;\n       \
    \     auto &to = t->nxt[f ^ ((bit >> depth) & 1)];\n            return to ? find(to,\
    \ bit, depth - 1, xor_val) : nullptr;\n        }\n    }\n\n    pair< T, Node *\
    \ > kth_element(Node *t, D k, int bit_index, T xor_val) { // 0-indexed\n     \
    \   if(bit_index == -1) {\n            return {0, t};\n        } else {\n    \
    \        bool f = (xor_val >> bit_index) & 1;\n            if((t->nxt[f] ? t->nxt[f]->exist\
    \ : 0) <= k) {\n                auto ret = kth_element(t->nxt[f ^ 1], k - (t->nxt[f]\
    \ ? t->nxt[f]->exist : 0), bit_index - 1, xor_val);\n                ret.first\
    \ |= T(1) << bit_index;\n                return ret;\n            } else {\n \
    \               return kth_element(t->nxt[f], k, bit_index - 1, xor_val);\n  \
    \          }\n        }\n    }\n\n    D count_less(Node *t, const T &bit, int\
    \ bit_index, T xor_val) {\n        if(bit_index == -1) return 0;\n        D ret\
    \ = 0;\n        bool f = (xor_val >> bit_index) & 1;\n        if((bit >> bit_index\
    \ & 1) and t->nxt[f]) ret += t->nxt[f]->exist;\n        if(t->nxt[f ^ (bit >>\
    \ bit_index & 1)]) ret += count_less(t->nxt[f ^ (bit >> bit_index & 1)], bit,\
    \ bit_index - 1, xor_val);\n        return ret;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/trie/binary-trie.hpp\n\
    // Binary Trie\n// \u7279\u5FB4\n// \u30FB\u4E2D\u592E\u5024\u306E\u53D6\u5F97\
    \u304C\u5EA7\u5727\u306A\u3057\u3067\u3055\u304F\u3063\u3068\u3044\u3051\u308B\
    \u3002(abc218_g\u3092\u53C2\u7167)\n// \u30FBkth_element\u306F0-indexed\n// \u30FB\
    index\u3092accept\u306B\u683C\u7D0D\u3057\u3066\u304A\u3051\u308B\u3051\u3069\u3001\
    erase\u3067\u6D88\u3059\u8A33\u3058\u3083\u306A\u3044\u307D\u3044\u306E\u3067\u3001\
    \n// \u3000\u524A\u9664\u304C\u3042\u308B\u6642\u306F\u3053\u3053\u5F53\u3066\u306B\
    \u305B\u305A\u5225\u914D\u5217\u6301\u3063\u305F\u65B9\u304C\u3044\u3044\u307D\
    \u3044\u3002\n// \u30FBcount_less\u4F7F\u3048\u3070\u300Ck\u756A\u76EE\u306E\u5024\
    \u300D\u3058\u3083\u306A\u304F\u3066\u300C\u5024x\u306F\u4F55\u756A\u76EE\u304B\
    \u300D\u3082\u53D6\u308C\u308B\u3002(past202203_m\u3092\u53C2\u7167)\n\ntemplate<\
    \ typename T, int MAX_LOG, typename D = int >\nstruct BinaryTrie {\npublic:\n\
    \    struct Node {\n        Node *nxt[2];\n        D exist;\n        vector< int\
    \ > accept;\n\n        Node() : nxt{nullptr, nullptr}, exist(0) {}\n    };\n\n\
    \    Node *root;\n\n    explicit BinaryTrie() : root(new Node()) {}\n\n    explicit\
    \ BinaryTrie(Node *root) : root(root) {}\n\n    void add(const T &bit, int idx\
    \ = -1, D delta = 1, T xor_val = 0) {\n        root = add(root, bit, idx, MAX_LOG,\
    \ delta, xor_val);\n    }\n\n    void erase(const T &bit, T xor_val = 0) {\n \
    \       add(bit, -1, -1, xor_val);\n    }\n\n    Node *find(const T &bit, T xor_val\
    \ = 0) {\n        return find(root, bit, MAX_LOG, xor_val);\n    }\n\n    D count(const\
    \ T &bit, T xor_val = 0) {\n        auto node = find(bit, xor_val);\n        return\
    \ node ? node->exist : 0;\n    }\n\n    pair< T, Node * > min_element(T xor_val\
    \ = 0) {\n        assert(root->exist > 0);\n        return kth_element(0, xor_val);\n\
    \    }\n\n    pair< T, Node * > max_element(T xor_val = 0) {\n        assert(root->exist\
    \ > 0);\n        return kth_element(root->exist - 1, xor_val);\n    }\n\n    pair<\
    \ T, Node * > kth_element(D k, T xor_val = 0) { // 0-indexed\n        assert(0\
    \ <= k && k < root->exist);\n        return kth_element(root, k, MAX_LOG, xor_val);\n\
    \    }\n\n    D count_less(const T &bit, T xor_val = 0) { // < bit\n        return\
    \ count_less(root, bit, MAX_LOG, xor_val);\n    }\n\nprivate:\n\n    virtual Node\
    \ *clone(Node *t) { return t; }\n\n    Node *add(Node *t, T bit, int idx, int\
    \ depth, D x, T xor_val, bool need = true) {\n        if(need) t = clone(t);\n\
    \        if(depth == -1) {\n            t->exist += x;\n            if(idx >=\
    \ 0) t->accept.emplace_back(idx);\n        } else {\n            bool f = (xor_val\
    \ >> depth) & 1;\n            auto &to = t->nxt[f ^ ((bit >> depth) & 1)];\n \
    \           if(!to) to = new Node(), need = false;\n            to = add(to, bit,\
    \ idx, depth - 1, x, xor_val, need);\n            t->exist += x;\n        }\n\
    \        return t;\n    }\n\n    Node *find(Node *t, T bit, int depth, T xor_val)\
    \ {\n        if(depth == -1) {\n            return t;\n        } else {\n    \
    \        bool f = (xor_val >> depth) & 1;\n            auto &to = t->nxt[f ^ ((bit\
    \ >> depth) & 1)];\n            return to ? find(to, bit, depth - 1, xor_val)\
    \ : nullptr;\n        }\n    }\n\n    pair< T, Node * > kth_element(Node *t, D\
    \ k, int bit_index, T xor_val) { // 0-indexed\n        if(bit_index == -1) {\n\
    \            return {0, t};\n        } else {\n            bool f = (xor_val >>\
    \ bit_index) & 1;\n            if((t->nxt[f] ? t->nxt[f]->exist : 0) <= k) {\n\
    \                auto ret = kth_element(t->nxt[f ^ 1], k - (t->nxt[f] ? t->nxt[f]->exist\
    \ : 0), bit_index - 1, xor_val);\n                ret.first |= T(1) << bit_index;\n\
    \                return ret;\n            } else {\n                return kth_element(t->nxt[f],\
    \ k, bit_index - 1, xor_val);\n            }\n        }\n    }\n\n    D count_less(Node\
    \ *t, const T &bit, int bit_index, T xor_val) {\n        if(bit_index == -1) return\
    \ 0;\n        D ret = 0;\n        bool f = (xor_val >> bit_index) & 1;\n     \
    \   if((bit >> bit_index & 1) and t->nxt[f]) ret += t->nxt[f]->exist;\n      \
    \  if(t->nxt[f ^ (bit >> bit_index & 1)]) ret += count_less(t->nxt[f ^ (bit >>\
    \ bit_index & 1)], bit, bit_index - 1, xor_val);\n        return ret;\n    }\n\
    };\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/segment/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2022-10-07 19:12:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/segment/BinaryTrie.hpp
layout: document
redirect_from:
- /library/src/segment/BinaryTrie.hpp
- /library/src/segment/BinaryTrie.hpp.html
title: src/segment/BinaryTrie.hpp
---
