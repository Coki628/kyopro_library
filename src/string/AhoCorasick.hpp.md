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
    - https://ei1333.github.io/library/string/aho-corasick.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/string/AhoCorasick.hpp\"\n\n// Aho-Corasick\n\
    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/string/aho-corasick.hpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u521D\u671F\u5316\u306F\u3001AhoCorasick<\u6587\
    \u5B57\u7A2E\u985E\u6570, \u6700\u521D\u306E\u6587\u5B57>\n// \u30FBadd\u3067\u30D1\
    \u30BF\u30FC\u30F3\u6587\u5B57\u5217\u3092\u5168\u90E8\u8A70\u3081\u3066\u304B\
    \u3089build\u3057\u3066\u3001\u305D\u306E\u5F8Cmove\u3084match\u3092\u4F7F\u3046\
    \u3002\n// \u30FBmatch(str, now): \u73FE\u72B6\u614B\u304Cnow\u3067\u3001\u6587\
    \u5B57\u5217str\u304C\u73FE\u308C\u305F\u6642\u306B\u3001\u65B0\u305F\u306B\u5404\
    \u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\u305F\
    \u56DE\u6570\u3092\u8FD4\u3059\u3002\n// \u30FBmove(c, now): \u73FE\u72B6\u614B\
    \u304Cnow\u3067, \u6587\u5B57c\u304C\u73FE\u308C\u305F\u3068\u304D\u306B\u3001\
    \u65B0\u305F\u306B\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\
    \u30C1\u3057\u305F\u500B\u6570\u3068\u3001\u6B21\u72B6\u614B\u3092\u8FD4\u3059\
    \u3002\ntemplate<int char_size>\nstruct TrieNode {\n    int nxt[char_size];\n\n\
    \    int exist;\n    vector<int> accept;\n\n    TrieNode() : exist(0) {\n    \
    \    memset(nxt, -1, sizeof(nxt));\n    }\n};\n\ntemplate<int char_size, int margin>\n\
    struct Trie {\n    using Node = TrieNode<char_size>;\n\n    vector<Node> nodes;\n\
    \    int root;\n\n    Trie() : root(0) {\n        nodes.push_back(Node());\n \
    \   }\n\n    void update_direct(int node, int id) {\n        nodes[node].accept.push_back(id);\n\
    \    }\n\n    void update_child(int node, int child, int id) {\n        ++nodes[node].exist;\n\
    \    }\n\n    void add(const string &str, int str_index, int node_index, int id)\
    \ {\n        if (str_index == str.size()) {\n            update_direct(node_index,\
    \ id);\n        } else {\n            const int c = str[str_index] - margin;\n\
    \            if (nodes[node_index].nxt[c] == -1) {\n                nodes[node_index].nxt[c]\
    \ = (int)nodes.size();\n                nodes.push_back(Node());\n           \
    \ }\n            add(str, str_index + 1, nodes[node_index].nxt[c], id);\n    \
    \        update_child(node_index, nodes[node_index].nxt[c], id);\n        }\n\
    \    }\n\n    void add(const string &str, int id) {\n        add(str, 0, 0, id);\n\
    \    }\n\n    void add(const string &str) {\n        add(str, nodes[0].exist);\n\
    \    }\n\n    void query(\n        const string &str, const function<void(int)>\
    \ &f, int str_index,\n        int node_index\n    ) {\n        for (auto &idx\
    \ : nodes[node_index].accept) f(idx);\n        if (str_index == str.size()) {\n\
    \            return;\n        } else {\n            const int c = str[str_index]\
    \ - margin;\n            if (nodes[node_index].nxt[c] == -1) return;\n       \
    \     query(str, f, str_index + 1, nodes[node_index].nxt[c]);\n        }\n   \
    \ }\n\n    void query(const string &str, const function<void(int)> &f) {\n   \
    \     query(str, f, 0, 0);\n    }\n\n    int count() const {\n        return (nodes[0].exist);\n\
    \    }\n\n    int size() const {\n        return ((int)nodes.size());\n    }\n\
    };\n\ntemplate<int char_size, int margin>\nstruct AhoCorasick : Trie<char_size\
    \ + 1, margin> {\n    using Trie<char_size + 1, margin>::Trie;\n\n    const int\
    \ FAIL = char_size;\n    vector<int> correct;\n\n    void build(bool heavy = true)\
    \ {\n        correct.resize(this->size());\n        for (int i = 0; i < this->size();\
    \ i++) {\n            correct[i] = (int)this->nodes[i].accept.size();\n      \
    \  }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++) {\n\
    \            if (~this->nodes[0].nxt[i]) {\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n                que.emplace(this->nodes[0].nxt[i]);\n            } else\
    \ {\n                this->nodes[0].nxt[i] = 0;\n            }\n        }\n  \
    \      while (!que.empty()) {\n            auto &now = this->nodes[que.front()];\n\
    \            int fail = now.nxt[FAIL];\n            correct[que.front()] += correct[fail];\n\
    \            que.pop();\n            for (int i = 0; i < char_size; i++) {\n \
    \               if (~now.nxt[i]) {\n                    this->nodes[now.nxt[i]].nxt[FAIL]\
    \ =\n                        this->nodes[fail].nxt[i];\n                    if\
    \ (heavy) {\n                        auto &u = this->nodes[now.nxt[i]].accept;\n\
    \                        auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        vector<int> accept;\n                        set_union(\n\
    \                            begin(u), end(u), begin(v), end(v),\n           \
    \                 back_inserter(accept)\n                        );\n        \
    \                u = accept;\n                    }\n                    que.emplace(now.nxt[i]);\n\
    \                } else {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n\
    \                }\n            }\n        }\n    }\n\n    map<int, int> match(const\
    \ string &str, int now = 0) {\n        map<int, int> result;\n        for (auto\
    \ &c : str) {\n            now = this->nodes[now].nxt[c - margin];\n         \
    \   for (auto &v : this->nodes[now].accept) result[v] += 1;\n        }\n     \
    \   return result;\n    }\n\n    // Trie\u6728\u4E0A\u306E\u4F4D\u7F6Enow\u306B\
    \u3044\u3066\u3001\u6B21\u306B\u6587\u5B57c\u3092\u4F7F\u3063\u305F\u6642\u306B\
    \u3001\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\
    \u305F\u500B\u6570\u3068\u6B21\u306E\u4F4D\u7F6Ec\u3092\u8FD4\u3059\n    pair<int64_t,\
    \ int> move(const char &c, int now = 0) {\n        now = this->nodes[now].nxt[c\
    \ - margin];\n        return {correct[now], now};\n    }\n\n    pair<int64_t,\
    \ int> move(const string &str, int now = 0) {\n        int64_t sum = 0;\n    \
    \    for (auto &c : str) {\n            auto nxt = move(c, now);\n           \
    \ sum += nxt.first;\n            now = nxt.second;\n        }\n        return\
    \ {sum, now};\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// Aho-Corasick\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/string/aho-corasick.hpp\n// \u4F7F\u3044\
    \u65B9\n// \u30FB\u521D\u671F\u5316\u306F\u3001AhoCorasick<\u6587\u5B57\u7A2E\u985E\
    \u6570, \u6700\u521D\u306E\u6587\u5B57>\n// \u30FBadd\u3067\u30D1\u30BF\u30FC\u30F3\
    \u6587\u5B57\u5217\u3092\u5168\u90E8\u8A70\u3081\u3066\u304B\u3089build\u3057\u3066\
    \u3001\u305D\u306E\u5F8Cmove\u3084match\u3092\u4F7F\u3046\u3002\n// \u30FBmatch(str,\
    \ now): \u73FE\u72B6\u614B\u304Cnow\u3067\u3001\u6587\u5B57\u5217str\u304C\u73FE\
    \u308C\u305F\u6642\u306B\u3001\u65B0\u305F\u306B\u5404\u30D1\u30BF\u30FC\u30F3\
    \u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\u305F\u56DE\u6570\u3092\u8FD4\
    \u3059\u3002\n// \u30FBmove(c, now): \u73FE\u72B6\u614B\u304Cnow\u3067, \u6587\
    \u5B57c\u304C\u73FE\u308C\u305F\u3068\u304D\u306B\u3001\u65B0\u305F\u306B\u30D1\
    \u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\u305F\u500B\
    \u6570\u3068\u3001\u6B21\u72B6\u614B\u3092\u8FD4\u3059\u3002\ntemplate<int char_size>\n\
    struct TrieNode {\n    int nxt[char_size];\n\n    int exist;\n    vector<int>\
    \ accept;\n\n    TrieNode() : exist(0) {\n        memset(nxt, -1, sizeof(nxt));\n\
    \    }\n};\n\ntemplate<int char_size, int margin>\nstruct Trie {\n    using Node\
    \ = TrieNode<char_size>;\n\n    vector<Node> nodes;\n    int root;\n\n    Trie()\
    \ : root(0) {\n        nodes.push_back(Node());\n    }\n\n    void update_direct(int\
    \ node, int id) {\n        nodes[node].accept.push_back(id);\n    }\n\n    void\
    \ update_child(int node, int child, int id) {\n        ++nodes[node].exist;\n\
    \    }\n\n    void add(const string &str, int str_index, int node_index, int id)\
    \ {\n        if (str_index == str.size()) {\n            update_direct(node_index,\
    \ id);\n        } else {\n            const int c = str[str_index] - margin;\n\
    \            if (nodes[node_index].nxt[c] == -1) {\n                nodes[node_index].nxt[c]\
    \ = (int)nodes.size();\n                nodes.push_back(Node());\n           \
    \ }\n            add(str, str_index + 1, nodes[node_index].nxt[c], id);\n    \
    \        update_child(node_index, nodes[node_index].nxt[c], id);\n        }\n\
    \    }\n\n    void add(const string &str, int id) {\n        add(str, 0, 0, id);\n\
    \    }\n\n    void add(const string &str) {\n        add(str, nodes[0].exist);\n\
    \    }\n\n    void query(\n        const string &str, const function<void(int)>\
    \ &f, int str_index,\n        int node_index\n    ) {\n        for (auto &idx\
    \ : nodes[node_index].accept) f(idx);\n        if (str_index == str.size()) {\n\
    \            return;\n        } else {\n            const int c = str[str_index]\
    \ - margin;\n            if (nodes[node_index].nxt[c] == -1) return;\n       \
    \     query(str, f, str_index + 1, nodes[node_index].nxt[c]);\n        }\n   \
    \ }\n\n    void query(const string &str, const function<void(int)> &f) {\n   \
    \     query(str, f, 0, 0);\n    }\n\n    int count() const {\n        return (nodes[0].exist);\n\
    \    }\n\n    int size() const {\n        return ((int)nodes.size());\n    }\n\
    };\n\ntemplate<int char_size, int margin>\nstruct AhoCorasick : Trie<char_size\
    \ + 1, margin> {\n    using Trie<char_size + 1, margin>::Trie;\n\n    const int\
    \ FAIL = char_size;\n    vector<int> correct;\n\n    void build(bool heavy = true)\
    \ {\n        correct.resize(this->size());\n        for (int i = 0; i < this->size();\
    \ i++) {\n            correct[i] = (int)this->nodes[i].accept.size();\n      \
    \  }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++) {\n\
    \            if (~this->nodes[0].nxt[i]) {\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n                que.emplace(this->nodes[0].nxt[i]);\n            } else\
    \ {\n                this->nodes[0].nxt[i] = 0;\n            }\n        }\n  \
    \      while (!que.empty()) {\n            auto &now = this->nodes[que.front()];\n\
    \            int fail = now.nxt[FAIL];\n            correct[que.front()] += correct[fail];\n\
    \            que.pop();\n            for (int i = 0; i < char_size; i++) {\n \
    \               if (~now.nxt[i]) {\n                    this->nodes[now.nxt[i]].nxt[FAIL]\
    \ =\n                        this->nodes[fail].nxt[i];\n                    if\
    \ (heavy) {\n                        auto &u = this->nodes[now.nxt[i]].accept;\n\
    \                        auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        vector<int> accept;\n                        set_union(\n\
    \                            begin(u), end(u), begin(v), end(v),\n           \
    \                 back_inserter(accept)\n                        );\n        \
    \                u = accept;\n                    }\n                    que.emplace(now.nxt[i]);\n\
    \                } else {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n\
    \                }\n            }\n        }\n    }\n\n    map<int, int> match(const\
    \ string &str, int now = 0) {\n        map<int, int> result;\n        for (auto\
    \ &c : str) {\n            now = this->nodes[now].nxt[c - margin];\n         \
    \   for (auto &v : this->nodes[now].accept) result[v] += 1;\n        }\n     \
    \   return result;\n    }\n\n    // Trie\u6728\u4E0A\u306E\u4F4D\u7F6Enow\u306B\
    \u3044\u3066\u3001\u6B21\u306B\u6587\u5B57c\u3092\u4F7F\u3063\u305F\u6642\u306B\
    \u3001\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\
    \u305F\u500B\u6570\u3068\u6B21\u306E\u4F4D\u7F6Ec\u3092\u8FD4\u3059\n    pair<int64_t,\
    \ int> move(const char &c, int now = 0) {\n        now = this->nodes[now].nxt[c\
    \ - margin];\n        return {correct[now], now};\n    }\n\n    pair<int64_t,\
    \ int> move(const string &str, int now = 0) {\n        int64_t sum = 0;\n    \
    \    for (auto &c : str) {\n            auto nxt = move(c, now);\n           \
    \ sum += nxt.first;\n            now = nxt.second;\n        }\n        return\
    \ {sum, now};\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/src/string/AhoCorasick.hpp
- /library/src/string/AhoCorasick.hpp.html
title: src/string/AhoCorasick.hpp
---
