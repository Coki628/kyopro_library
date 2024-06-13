---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/ArbitraryModConvolution.hpp
    title: src/math/ArbitraryModConvolution.hpp
  - icon: ':warning:'
    path: src/math/FormalPowerSeries.hpp
    title: src/math/FormalPowerSeries.hpp
  - icon: ':warning:'
    path: src/math/fps/pow.hpp
    title: src/math/fps/pow.hpp
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
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
    \ namespace std;\n#line 3 \"src/math/FastFourierTransform.hpp\"\n\nnamespace FastFourierTransform\
    \ {\nusing real = double;\n\nstruct C {\n    real x, y;\n\n    C() : x(0), y(0)\
    \ {}\n\n    C(real x, real y) : x(x), y(y) {\n    }\n\n    inline C operator+(const\
    \ C &c) const {\n        return C(x + c.x, y + c.y);\n    }\n\n    inline C operator-(const\
    \ C &c) const {\n        return C(x - c.x, y - c.y);\n    }\n\n    inline C operator*(const\
    \ C &c) const {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n   \
    \ }\n\n    inline C conj() const {\n        return C(x, -y);\n    }\n};\n\nconst\
    \ real PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int>\
    \ rev = {0, 1};\n\nvoid ensure_base(int nbase) {\n    if (nbase <= base) return;\n\
    \    rev.resize(1 << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0;\
    \ i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n    }\n    while (base < nbase) {\n        real angle = PI *\
    \ 2.0 / (1 << (base + 1));\n        for (int i = 1 << (base - 1); i < (1 << base);\
    \ i++) {\n            rts[i << 1] = rts[i];\n            real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n        }\n        ++base;\n    }\n}\n\nvoid fft(vector<C> &a,\
    \ int n) {\n    assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i]\
    \ >> shift]);\n        }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n     \
    \   for (int i = 0; i < n; i += 2 * k) {\n            for (int j = 0; j < k; j++)\
    \ {\n                C z = a[i + j + k] * rts[j + k];\n                a[i + j\
    \ + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n           \
    \ }\n        }\n    }\n}\n\nvector<int64_t> multiply(const vector<int> &a, const\
    \ vector<int> &b) {\n    int need = (int)a.size() + (int)b.size() - 1;\n    int\
    \ nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector<C> fa(sz);\n    for (int i = 0; i < sz;\
    \ i++) {\n        int x = (i < (int)a.size() ? a[i] : 0);\n        int y = (i\
    \ < (int)b.size() ? b[i] : 0);\n        fa[i] = C(x, y);\n    }\n    fft(fa, sz);\n\
    \    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0; i <=\
    \ (sz >> 1); i++) {\n        int j = (sz - i) & (sz - 1);\n        C z = (fa[j]\
    \ * fa[j] - (fa[i] * fa[i]).conj()) * r;\n        fa[j] = (fa[i] * fa[i] - (fa[j]\
    \ * fa[j]).conj()) * r;\n        fa[i] = z;\n    }\n    for (int i = 0; i < (sz\
    \ >> 1); i++) {\n        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n        C A1\
    \ = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n        fa[i] = A0\
    \ + A1 * s;\n    }\n    fft(fa, sz >> 1);\n    vector<int64_t> ret(need);\n  \
    \  for (int i = 0; i < need; i++) {\n        ret[i] = llround(i & 1 ? fa[i >>\
    \ 1].y : fa[i >> 1].x);\n    }\n    return ret;\n}\n}; // namespace FastFourierTransform\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nnamespace FastFourierTransform\
    \ {\nusing real = double;\n\nstruct C {\n    real x, y;\n\n    C() : x(0), y(0)\
    \ {}\n\n    C(real x, real y) : x(x), y(y) {\n    }\n\n    inline C operator+(const\
    \ C &c) const {\n        return C(x + c.x, y + c.y);\n    }\n\n    inline C operator-(const\
    \ C &c) const {\n        return C(x - c.x, y - c.y);\n    }\n\n    inline C operator*(const\
    \ C &c) const {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n   \
    \ }\n\n    inline C conj() const {\n        return C(x, -y);\n    }\n};\n\nconst\
    \ real PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int>\
    \ rev = {0, 1};\n\nvoid ensure_base(int nbase) {\n    if (nbase <= base) return;\n\
    \    rev.resize(1 << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0;\
    \ i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n    }\n    while (base < nbase) {\n        real angle = PI *\
    \ 2.0 / (1 << (base + 1));\n        for (int i = 1 << (base - 1); i < (1 << base);\
    \ i++) {\n            rts[i << 1] = rts[i];\n            real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n        }\n        ++base;\n    }\n}\n\nvoid fft(vector<C> &a,\
    \ int n) {\n    assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i]\
    \ >> shift]);\n        }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n     \
    \   for (int i = 0; i < n; i += 2 * k) {\n            for (int j = 0; j < k; j++)\
    \ {\n                C z = a[i + j + k] * rts[j + k];\n                a[i + j\
    \ + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n           \
    \ }\n        }\n    }\n}\n\nvector<int64_t> multiply(const vector<int> &a, const\
    \ vector<int> &b) {\n    int need = (int)a.size() + (int)b.size() - 1;\n    int\
    \ nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector<C> fa(sz);\n    for (int i = 0; i < sz;\
    \ i++) {\n        int x = (i < (int)a.size() ? a[i] : 0);\n        int y = (i\
    \ < (int)b.size() ? b[i] : 0);\n        fa[i] = C(x, y);\n    }\n    fft(fa, sz);\n\
    \    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0; i <=\
    \ (sz >> 1); i++) {\n        int j = (sz - i) & (sz - 1);\n        C z = (fa[j]\
    \ * fa[j] - (fa[i] * fa[i]).conj()) * r;\n        fa[j] = (fa[i] * fa[i] - (fa[j]\
    \ * fa[j]).conj()) * r;\n        fa[i] = z;\n    }\n    for (int i = 0; i < (sz\
    \ >> 1); i++) {\n        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n        C A1\
    \ = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];\n        fa[i] = A0\
    \ + A1 * s;\n    }\n    fft(fa, sz >> 1);\n    vector<int64_t> ret(need);\n  \
    \  for (int i = 0; i < need; i++) {\n        ret[i] = llround(i & 1 ? fa[i >>\
    \ 1].y : fa[i >> 1].x);\n    }\n    return ret;\n}\n}; // namespace FastFourierTransform\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/math/FastFourierTransform.hpp
  requiredBy:
  - src/math/fps/pow_term2.hpp
  - src/math/fps/pow.hpp
  - src/math/FormalPowerSeries.hpp
  - src/math/ArbitraryModConvolution.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/FastFourierTransform.hpp
layout: document
redirect_from:
- /library/src/math/FastFourierTransform.hpp
- /library/src/math/FastFourierTransform.hpp.html
title: src/math/FastFourierTransform.hpp
---
