---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/union-find/persistent-union-find.cpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../common/PersistentArray.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../base.hpp\"\n#include \"../common/PersistentArray.hpp\"\n\n\
    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/union-find/persistent-union-find.cpp\n\
    // \u6C38\u7D9AUF\nstruct PersistentUnionFind {\n    PersistentArray< int, 3 >\
    \ data;\n\n    PersistentUnionFind() {}\n\n    PersistentUnionFind(int sz) {\n\
    \        data.build(vector< int >(sz, -1));\n    }\n\n    int find(int k) {\n\
    \        int p = data.get(k);\n        return p >= 0 ? find(p) : k;\n    }\n\n\
    \    int size(int k) {\n        return (-data.get(find(k)));\n    }\n\n    bool\
    \ merge(int x, int y) {\n        x = find(x);\n        y = find(y);\n        if\
    \ (x == y) return false;\n        auto u = data.get(x);\n        auto v = data.get(y);\n\
    \n        if (u < v) {\n            data.update(x, u+v);\n            data.update(y,\
    \ x);\n        } else {\n            data.update(y, u+v);\n            data.update(x,\
    \ y);\n        }\n        return true;\n    }\n\n    bool same(int x, int y) {\n\
    \        return find(x) == find(y);\n    }\n\n    decltype(data)::Node* get_root_node()\
    \ {\n        return data.root;\n    }\n\n    void set_root_node(decltype(data)::Node*\
    \ np) {\n        data.root = np;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/PersistentUnionFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/PersistentUnionFind.hpp
layout: document
redirect_from:
- /library/src/graph/PersistentUnionFind.hpp
- /library/src/graph/PersistentUnionFind.hpp.html
title: src/graph/PersistentUnionFind.hpp
---
