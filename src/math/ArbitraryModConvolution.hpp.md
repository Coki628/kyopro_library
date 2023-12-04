---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/math/FastFourierTransform.hpp
    title: src/math/FastFourierTransform.hpp
  _extendedRequiredBy:
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
    links:
    - https://ei1333.github.io/library/math/fft/arbitrary-mod-convolution.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/math/FastFourierTransform.hpp\"\n\nnamespace\
    \ FastFourierTransform {\nusing real = double;\n\nstruct C {\n    real x, y;\n\
    \n    C() : x(0), y(0) {}\n\n    C(real x, real y) : x(x), y(y) {\n    }\n\n \
    \   inline C operator+(const C &c) const {\n        return C(x + c.x, y + c.y);\n\
    \    }\n\n    inline C operator-(const C &c) const {\n        return C(x - c.x,\
    \ y - c.y);\n    }\n\n    inline C operator*(const C &c) const {\n        return\
    \ C(x * c.x - y * c.y, x * c.y + y * c.x);\n    }\n\n    inline C conj() const\
    \ {\n        return C(x, -y);\n    }\n};\n\nconst real PI = acosl(-1);\nint base\
    \ = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n    if (nbase <= base) return;\n    rev.resize(1 << nbase);\n    rts.resize(1\
    \ << nbase);\n    for (int i = 0; i < (1 << nbase); i++) {\n        rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n    }\n    while (base < nbase) {\n\
    \        real angle = PI * 2.0 / (1 << (base + 1));\n        for (int i = 1 <<\
    \ (base - 1); i < (1 << base); i++) {\n            rts[i << 1] = rts[i];\n   \
    \         real angle_i = angle * (2 * i + 1 - (1 << base));\n            rts[(i\
    \ << 1) + 1] = C(cos(angle_i), sin(angle_i));\n        }\n        ++base;\n  \
    \  }\n}\n\nvoid fft(vector<C> &a, int n) {\n    assert((n & (n - 1)) == 0);\n\
    \    int zeros = __builtin_ctz(n);\n    ensure_base(zeros);\n    int shift = base\
    \ - zeros;\n    for (int i = 0; i < n; i++) {\n        if (i < (rev[i] >> shift))\
    \ {\n            swap(a[i], a[rev[i] >> shift]);\n        }\n    }\n    for (int\
    \ k = 1; k < n; k <<= 1) {\n        for (int i = 0; i < n; i += 2 * k) {\n   \
    \         for (int j = 0; j < k; j++) {\n                C z = a[i + j + k] *\
    \ rts[j + k];\n                a[i + j + k] = a[i + j] - z;\n                a[i\
    \ + j] = a[i + j] + z;\n            }\n        }\n    }\n}\n\nvector<int64_t>\
    \ multiply(const vector<int> &a, const vector<int> &b) {\n    int need = (int)a.size()\
    \ + (int)b.size() - 1;\n    int nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n\
    \    ensure_base(nbase);\n    int sz = 1 << nbase;\n    vector<C> fa(sz);\n  \
    \  for (int i = 0; i < sz; i++) {\n        int x = (i < (int)a.size() ? a[i] :\
    \ 0);\n        int y = (i < (int)b.size() ? b[i] : 0);\n        fa[i] = C(x, y);\n\
    \    }\n    fft(fa, sz);\n    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n\
    \    for (int i = 0; i <= (sz >> 1); i++) {\n        int j = (sz - i) & (sz -\
    \ 1);\n        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n        fa[j]\
    \ = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n        fa[i] = z;\n    }\n\
    \    for (int i = 0; i < (sz >> 1); i++) {\n        C A0 = (fa[i] + fa[i + (sz\
    \ >> 1)]) * t;\n        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1)\
    \ + i];\n        fa[i] = A0 + A1 * s;\n    }\n    fft(fa, sz >> 1);\n    vector<int64_t>\
    \ ret(need);\n    for (int i = 0; i < need; i++) {\n        ret[i] = llround(i\
    \ & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n    }\n    return ret;\n}\n}; // namespace\
    \ FastFourierTransform\n#line 4 \"src/math/ArbitraryModConvolution.hpp\"\n\n//\
    \ \u4EFB\u610FMOD\u7573\u307F\u8FBC\u307F\n// see: https://ei1333.github.io/library/math/fft/arbitrary-mod-convolution.hpp\n\
    template<typename T>\nstruct ArbitraryModConvolution {\n    using real = FastFourierTransform::real;\n\
    \    using C = FastFourierTransform::C;\n\n    ArbitraryModConvolution() = default;\n\
    \n    static vector<T> multiply(const vector<T> &a, const vector<T> &b, int need\
    \ = -1) {\n        if (need == -1) need = a.size() + b.size() - 1;\n        int\
    \ nbase = 0;\n        while ((1 << nbase) < need) nbase++;\n        FastFourierTransform::ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        vector<C> fa(sz);\n        for (int i =\
    \ 0; i < a.size(); i++) {\n            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x\
    \ >> 15);\n        }\n        fft(fa, sz);\n        vector<C> fb(sz);\n      \
    \  if (a == b) {\n            fb = fa;\n        } else {\n            for (int\
    \ i = 0; i < b.size(); i++) {\n                fb[i] = C(b[i].x & ((1 << 15) -\
    \ 1), b[i].x >> 15);\n            }\n            fft(fb, sz);\n        }\n   \
    \     real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0), r4(0, -ratio),\
    \ r5(0, 1);\n        for (int i = 0; i <= (sz >> 1); i++) {\n            int j\
    \ = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n       \
    \     C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] + fb[j].conj())\
    \ * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n            if (i !=\
    \ j) {\n                C c1 = (fa[j] + fa[i].conj());\n                C c2 =\
    \ (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j] + fb[i].conj())\
    \ * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n               \
    \ fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 * d2 + c2 * d1;\n\
    \            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n            fb[j]\
    \ = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n        fft(fb, sz);\n\
    \        vector<T> ret(need);\n        for (int i = 0; i < need; i++) {\n    \
    \        int64_t aa = llround(fa[i].x);\n            int64_t bb = llround(fb[i].x);\n\
    \            int64_t cc = llround(fa[i].y);\n            aa = T(aa).x, bb = T(bb).x,\
    \ cc = T(cc).x;\n            ret[i] = aa + (bb << 15) + (cc << 30);\n        }\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"FastFourierTransform.hpp\"\
    \n\n// \u4EFB\u610FMOD\u7573\u307F\u8FBC\u307F\n// see: https://ei1333.github.io/library/math/fft/arbitrary-mod-convolution.hpp\n\
    template<typename T>\nstruct ArbitraryModConvolution {\n    using real = FastFourierTransform::real;\n\
    \    using C = FastFourierTransform::C;\n\n    ArbitraryModConvolution() = default;\n\
    \n    static vector<T> multiply(const vector<T> &a, const vector<T> &b, int need\
    \ = -1) {\n        if (need == -1) need = a.size() + b.size() - 1;\n        int\
    \ nbase = 0;\n        while ((1 << nbase) < need) nbase++;\n        FastFourierTransform::ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        vector<C> fa(sz);\n        for (int i =\
    \ 0; i < a.size(); i++) {\n            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x\
    \ >> 15);\n        }\n        fft(fa, sz);\n        vector<C> fb(sz);\n      \
    \  if (a == b) {\n            fb = fa;\n        } else {\n            for (int\
    \ i = 0; i < b.size(); i++) {\n                fb[i] = C(b[i].x & ((1 << 15) -\
    \ 1), b[i].x >> 15);\n            }\n            fft(fb, sz);\n        }\n   \
    \     real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0), r4(0, -ratio),\
    \ r5(0, 1);\n        for (int i = 0; i <= (sz >> 1); i++) {\n            int j\
    \ = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n       \
    \     C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] + fb[j].conj())\
    \ * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n            if (i !=\
    \ j) {\n                C c1 = (fa[j] + fa[i].conj());\n                C c2 =\
    \ (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j] + fb[i].conj())\
    \ * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n               \
    \ fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 * d2 + c2 * d1;\n\
    \            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n            fb[j]\
    \ = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n        fft(fb, sz);\n\
    \        vector<T> ret(need);\n        for (int i = 0; i < need; i++) {\n    \
    \        int64_t aa = llround(fa[i].x);\n            int64_t bb = llround(fb[i].x);\n\
    \            int64_t cc = llround(fa[i].y);\n            aa = T(aa).x, bb = T(bb).x,\
    \ cc = T(cc).x;\n            ret[i] = aa + (bb << 15) + (cc << 30);\n        }\n\
    \        return ret;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/math/FastFourierTransform.hpp
  isVerificationFile: false
  path: src/math/ArbitraryModConvolution.hpp
  requiredBy:
  - src/math/FormalPowerSeries.hpp
  - src/math/fps/pow.hpp
  - src/math/fps/pow_term2.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/ArbitraryModConvolution.hpp
layout: document
redirect_from:
- /library/src/math/ArbitraryModConvolution.hpp
- /library/src/math/ArbitraryModConvolution.hpp.html
title: src/math/ArbitraryModConvolution.hpp
---
