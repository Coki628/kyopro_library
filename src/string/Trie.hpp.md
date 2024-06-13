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
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/string/Trie.hpp\"\n\n// Trie \u6728\n// \u30FB\
    \u6587\u5B57\u306E\u7A2E\u985E(char_size)\u3001int\u578B\u30670\u306B\u5BFE\u5FDC\
    \u3059\u308B\u6587\u5B57(base)\n// \u30FBinsert(word): \u5358\u8A9E word \u3092\
    \ Trie \u6728\u306B\u633F\u5165\u3059\u308B\n// \u30FBsearch(word): \u5358\u8A9E\
    \ word \u304C Trie \u6728\u306B\u3042\u308B\u304B\u5224\u5B9A\u3059\u308B\n//\
    \ \u30FBstart_with(prefix):  prefix \u304C\u4E00\u81F4\u3059\u308B\u5358\u8A9E\
    \u304C Trie \u6728\u306B\u3042\u308B\u304B\u5224\u5B9A\u3059\u308B\n// \u30FB\
    count(): \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\u3092\u8FD4\u3059\n\
    // \u30FBsize(): Trie \u6728\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\n// \u30FB\
    \u8A08\u7B97\u91CF\uFF1Ainsert, search \u3068\u3082\u306B O(M)\uFF08M\u306F\u5358\
    \u8A9E\u306E\u9577\u3055\uFF09\ntemplate<int char_size, int base>\nstruct Trie\
    \ {\n    struct Node {           // \u9802\u70B9\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n        vector<int> next;   // \u5B50\u306E\u9802\u70B9\u756A\u53F7\u3092\
    \u683C\u7D0D\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int>\
    \ accept; // \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\u306B\u306A\u308B\u5358\
    \u8A9E\u306E word_id \u3092\u4FDD\u5B58\n        int c;              // base \u304B\
    \u3089\u306E\u9593\u9694\u3092int\u578B\u3067\u8868\u73FE\u3057\u305F\u3082\u306E\
    \n        int common;         // \u3044\u304F\u3064\u306E\u5358\u8A9E\u304C\u3053\
    \u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\u304B\n        Node(int\
    \ c_) : c(c_), common(0) {\n            next.assign(char_size, -1);\n        }\n\
    \    };\n\n    vector<Node> nodes; // trie \u6728\u672C\u4F53\n    int root;\n\
    \    Trie() : root(0) {\n        nodes.push_back(Node(root));\n    }\n\n    //\
    \ \u5358\u8A9E\u306E\u633F\u5165\n    void insert(const string &word, int word_id)\
    \ {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size(); i++)\
    \ {\n            int c = (int)(word[i] - base);\n            int &next_id = nodes[node_id].next[c];\n\
    \            if (next_id == -1) { // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070\u8FFD\u52A0\n                next_id = (int)nodes.size();\n\
    \                nodes.push_back(Node(c));\n            }\n            ++nodes[node_id].common;\n\
    \            node_id = next_id;\n        }\n        ++nodes[node_id].common;\n\
    \        nodes[node_id].accept.push_back(word_id);\n    }\n    void insert(const\
    \ string &word) {\n        insert(word, nodes[0].common);\n    }\n\n    // \u5358\
    \u8A9E\u3068prefix\u306E\u691C\u7D22\n    bool search(const string &word, bool\
    \ prefix = false) {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size();\
    \ i++) {\n            int c = (int)(word[i] - base);\n            int &next_id\
    \ = nodes[node_id].next[c];\n            if (next_id == -1) { // \u6B21\u306E\u9802\
    \u70B9\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u7D42\u4E86\n         \
    \       return false;\n            }\n            node_id = next_id;\n       \
    \ }\n        return (prefix) ? true : nodes[node_id].accept.size() > 0;\n    }\n\
    \n    // prefix \u3092\u6301\u3064\u5358\u8A9E\u304C\u5B58\u5728\u3059\u308B\u304B\
    \u306E\u691C\u7D22\n    bool start_with(const string &prefix) {\n        return\
    \ search(prefix, true);\n    }\n\n    // \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\
    \u6570\n    int count() const {\n        return (nodes[0].common);\n    }\n  \
    \  // Trie\u6728\u306E\u30CE\u30FC\u30C9\u6570\n    int size() const {\n     \
    \   return ((int)nodes.size());\n    }\n\n    // \u4F4D\u7F6Ev\u3067\u6587\u5B57\
    c\u3092\u4F7F\u3063\u305F\u6642\u306E\u6B21\u306E\u9802\u70B9\u3092\u8FD4\u3059\
    \n    int next(int v, int c) {\n        return nodes[v].next[c - base];\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// Trie \u6728\n// \u30FB\u6587\
    \u5B57\u306E\u7A2E\u985E(char_size)\u3001int\u578B\u30670\u306B\u5BFE\u5FDC\u3059\
    \u308B\u6587\u5B57(base)\n// \u30FBinsert(word): \u5358\u8A9E word \u3092 Trie\
    \ \u6728\u306B\u633F\u5165\u3059\u308B\n// \u30FBsearch(word): \u5358\u8A9E word\
    \ \u304C Trie \u6728\u306B\u3042\u308B\u304B\u5224\u5B9A\u3059\u308B\n// \u30FB\
    start_with(prefix):  prefix \u304C\u4E00\u81F4\u3059\u308B\u5358\u8A9E\u304C Trie\
    \ \u6728\u306B\u3042\u308B\u304B\u5224\u5B9A\u3059\u308B\n// \u30FBcount(): \u633F\
    \u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\u3092\u8FD4\u3059\n// \u30FBsize():\
    \ Trie \u6728\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\n// \u30FB\u8A08\u7B97\
    \u91CF\uFF1Ainsert, search \u3068\u3082\u306B O(M)\uFF08M\u306F\u5358\u8A9E\u306E\
    \u9577\u3055\uFF09\ntemplate<int char_size, int base>\nstruct Trie {\n    struct\
    \ Node {           // \u9802\u70B9\u3092\u8868\u3059\u69CB\u9020\u4F53\n     \
    \   vector<int> next;   // \u5B50\u306E\u9802\u70B9\u756A\u53F7\u3092\u683C\u7D0D\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int> accept;\
    \ // \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\u306B\u306A\u308B\u5358\u8A9E\u306E\
    \ word_id \u3092\u4FDD\u5B58\n        int c;              // base \u304B\u3089\
    \u306E\u9593\u9694\u3092int\u578B\u3067\u8868\u73FE\u3057\u305F\u3082\u306E\n\
    \        int common;         // \u3044\u304F\u3064\u306E\u5358\u8A9E\u304C\u3053\
    \u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\u304B\n        Node(int\
    \ c_) : c(c_), common(0) {\n            next.assign(char_size, -1);\n        }\n\
    \    };\n\n    vector<Node> nodes; // trie \u6728\u672C\u4F53\n    int root;\n\
    \    Trie() : root(0) {\n        nodes.push_back(Node(root));\n    }\n\n    //\
    \ \u5358\u8A9E\u306E\u633F\u5165\n    void insert(const string &word, int word_id)\
    \ {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size(); i++)\
    \ {\n            int c = (int)(word[i] - base);\n            int &next_id = nodes[node_id].next[c];\n\
    \            if (next_id == -1) { // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070\u8FFD\u52A0\n                next_id = (int)nodes.size();\n\
    \                nodes.push_back(Node(c));\n            }\n            ++nodes[node_id].common;\n\
    \            node_id = next_id;\n        }\n        ++nodes[node_id].common;\n\
    \        nodes[node_id].accept.push_back(word_id);\n    }\n    void insert(const\
    \ string &word) {\n        insert(word, nodes[0].common);\n    }\n\n    // \u5358\
    \u8A9E\u3068prefix\u306E\u691C\u7D22\n    bool search(const string &word, bool\
    \ prefix = false) {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size();\
    \ i++) {\n            int c = (int)(word[i] - base);\n            int &next_id\
    \ = nodes[node_id].next[c];\n            if (next_id == -1) { // \u6B21\u306E\u9802\
    \u70B9\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u7D42\u4E86\n         \
    \       return false;\n            }\n            node_id = next_id;\n       \
    \ }\n        return (prefix) ? true : nodes[node_id].accept.size() > 0;\n    }\n\
    \n    // prefix \u3092\u6301\u3064\u5358\u8A9E\u304C\u5B58\u5728\u3059\u308B\u304B\
    \u306E\u691C\u7D22\n    bool start_with(const string &prefix) {\n        return\
    \ search(prefix, true);\n    }\n\n    // \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\
    \u6570\n    int count() const {\n        return (nodes[0].common);\n    }\n  \
    \  // Trie\u6728\u306E\u30CE\u30FC\u30C9\u6570\n    int size() const {\n     \
    \   return ((int)nodes.size());\n    }\n\n    // \u4F4D\u7F6Ev\u3067\u6587\u5B57\
    c\u3092\u4F7F\u3063\u305F\u6642\u306E\u6B21\u306E\u9802\u70B9\u3092\u8FD4\u3059\
    \n    int next(int v, int c) {\n        return nodes[v].next[c - base];\n    }\n\
    };\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/Trie.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/Trie.hpp
layout: document
redirect_from:
- /library/src/string/Trie.hpp
- /library/src/string/Trie.hpp.html
title: src/string/Trie.hpp
---
