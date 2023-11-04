---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/HashMap.hpp
    title: src/common/HashMap.hpp
  - icon: ':warning:'
    path: src/common/HashMapImpl.hpp
    title: src/common/HashMapImpl.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: common/HashMap.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../base.hpp\"\n#include \"common/HashMap.hpp\"\n\n// \u758E\u306A\
    2\u6B21\u5143BIT\ntemplate<typename T>\nclass SparseBIT2D {\n    int H;\n    int\
    \ W;\n    HashMap<int, HashMap<int, T>> data2d;\npublic:\n    SparseBIT2D(int\
    \ H, int W) : H(H), W(W) {\n    }\n\n    // [0,h],[0,w]\n    T sum(int h, int\
    \ w) {\n        T res = 0;\n        h++, w++;\n        for (int i = h; i > 0;\
    \ i -= i & -i) {\n            if (not data2d.count(i-1)) continue;\n         \
    \   for (int j = w; j > 0; j -= j & -j) {\n                if (not data2d[i-1].count(j-1))\
    \ continue;\n                res += data2d[i-1][j-1];\n            }\n       \
    \ }\n        return res;\n    }\n\n    // [h1,h2),[w1,w2)\u306E\u533A\u9593\u548C\
    \n    T query(int h1, int w1, int h2, int w2) {\n        return sum(h2-1, w2-1)\
    \ - sum(h1-1, w2-1) - sum(h2-1, w1-1) + sum(h1-1, w1-1);\n    }\n\n    T get(int\
    \ h, int w) {\n        return query(h, w, h+1, w+1);\n    }\n\n    void add(int\
    \ h, int w, T x) {\n        h++, w++;\n        for (int i = h; i <= H; i += i\
    \ & -i) {\n            for (int j = w; j <= W; j += j & -j) {\n              \
    \  data2d[i-1][j-1] += x;\n            }\n        }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/common/HashMap.hpp
  - src/common/HashMapImpl.hpp
  isVerificationFile: false
  path: src/datastructure/SparseBIT2D.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SparseBIT2D.hpp
layout: document
redirect_from:
- /library/src/datastructure/SparseBIT2D.hpp
- /library/src/datastructure/SparseBIT2D.hpp.html
title: src/datastructure/SparseBIT2D.hpp
---
