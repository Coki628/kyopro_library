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
    - https://nyaannyaan.github.io/library/segment-tree/segment-tree-beats-abstract.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/datastructure/AbstructBeats.hpp\"\n\n// \u53C2\
    \u8003\uFF1Ahttps://nyaannyaan.github.io/library/segment-tree/segment-tree-beats-abstract.hpp\n\
    template<typename Node, typename T, typename F>\nstruct AbstructBeats {\n    int\
    \ n, log;\n    vector<Node> v;\n\n    AbstructBeats(const vector<T>& vc) {\n \
    \       n = 1, log = 0;\n        while (n < (int)vc.size()) n <<= 1, log++;\n\
    \        v.resize(2 * n);\n        for (int i = 0; i < (int)vc.size(); ++i) v[i\
    \ + n] = Node(vc[i]);\n        for (int i = n - 1; i; --i) _update(i);\n    }\n\
    \n    // F\u306FNode\u306Eapply\u306E\u5F15\u6570\u306E\u30C7\u30FC\u30BF\u578B\
    \n    void apply(int l, int r, const F& x) {\n        if (l == r) return;\n  \
    \      l += n, r += n;\n        for (int i = log; i >= 1; i--) {\n           \
    \ if (((l >> i) << i) != l) _push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) _push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 =\
    \ r;\n            while (l < r) {\n                if (l & 1) _apply(l++, x);\n\
    \                if (r & 1) _apply(--r, x);\n                l >>= 1;\n      \
    \          r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i)\
    \ << i) != l) _update(l >> i);\n            if (((r >> i) << i) != r) _update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template<typename Q>\n    void query(int\
    \ l, int r, const Q& q) {\n        if (l == r) return;\n        l += n, r += n;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) _push(l >> i);\n            if (((r >> i) << i) != r) _push((r - 1) >> i);\n\
    \        }\n        while (l < r) {\n            if (l & 1) q(v[l++]);\n     \
    \       if (r & 1) q(v[--r]);\n            l >>= 1;\n            r >>= 1;\n  \
    \      }\n    }\n\nprivate:\n    void _push(int i) { v[i].push(v[2 * i + 0], v[2\
    \ * i + 1]); }\n    void _update(int i) { v[i].update(v[2 * i + 0], v[2 * i +\
    \ 1]); }\n    void _apply(int i, const F& x) {\n        bool res = v[i].apply(x);\n\
    \        if (i < n && res == false) {\n            _push(i);\n            _apply(i\
    \ * 2 + 0, x);\n            _apply(i * 2 + 1, x);\n            _update(i);\n \
    \       }\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/segment-tree/segment-tree-beats-abstract.hpp\n\
    template<typename Node, typename T, typename F>\nstruct AbstructBeats {\n    int\
    \ n, log;\n    vector<Node> v;\n\n    AbstructBeats(const vector<T>& vc) {\n \
    \       n = 1, log = 0;\n        while (n < (int)vc.size()) n <<= 1, log++;\n\
    \        v.resize(2 * n);\n        for (int i = 0; i < (int)vc.size(); ++i) v[i\
    \ + n] = Node(vc[i]);\n        for (int i = n - 1; i; --i) _update(i);\n    }\n\
    \n    // F\u306FNode\u306Eapply\u306E\u5F15\u6570\u306E\u30C7\u30FC\u30BF\u578B\
    \n    void apply(int l, int r, const F& x) {\n        if (l == r) return;\n  \
    \      l += n, r += n;\n        for (int i = log; i >= 1; i--) {\n           \
    \ if (((l >> i) << i) != l) _push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) _push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 =\
    \ r;\n            while (l < r) {\n                if (l & 1) _apply(l++, x);\n\
    \                if (r & 1) _apply(--r, x);\n                l >>= 1;\n      \
    \          r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i)\
    \ << i) != l) _update(l >> i);\n            if (((r >> i) << i) != r) _update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template<typename Q>\n    void query(int\
    \ l, int r, const Q& q) {\n        if (l == r) return;\n        l += n, r += n;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) _push(l >> i);\n            if (((r >> i) << i) != r) _push((r - 1) >> i);\n\
    \        }\n        while (l < r) {\n            if (l & 1) q(v[l++]);\n     \
    \       if (r & 1) q(v[--r]);\n            l >>= 1;\n            r >>= 1;\n  \
    \      }\n    }\n\nprivate:\n    void _push(int i) { v[i].push(v[2 * i + 0], v[2\
    \ * i + 1]); }\n    void _update(int i) { v[i].update(v[2 * i + 0], v[2 * i +\
    \ 1]); }\n    void _apply(int i, const F& x) {\n        bool res = v[i].apply(x);\n\
    \        if (i < n && res == false) {\n            _push(i);\n            _apply(i\
    \ * 2 + 0, x);\n            _apply(i * 2 + 1, x);\n            _update(i);\n \
    \       }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/AbstructBeats.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/AbstructBeats.hpp
layout: document
redirect_from:
- /library/src/datastructure/AbstructBeats.hpp
- /library/src/datastructure/AbstructBeats.hpp.html
title: src/datastructure/AbstructBeats.hpp
---
