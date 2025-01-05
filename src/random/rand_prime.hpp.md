---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/RLE.hpp
    title: src/common/RLE.hpp
  - icon: ':warning:'
    path: src/common/sorted.hpp
    title: src/common/sorted.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/numbers/FastPrimeFactorization.hpp
    title: src/numbers/FastPrimeFactorization.hpp
  - icon: ':warning:'
    path: src/random/mt.hpp
    title: src/random/mt.hpp
  - icon: ':warning:'
    path: src/random/randrange.hpp
    title: src/random/randrange.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: numbers/FastPrimeFactorization.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"numbers/FastPrimeFactorization.hpp\"\
    \n#include \"randrange.hpp\"\n\n// \u7BC4\u56F2[l,r)\u304B\u3089\u30E9\u30F3\u30C0\
    \u30E0\u306B\u9078\u3070\u308C\u305F\u7D20\u6570\u3092\u8FD4\u3059\nll rand_prime(ll\
    \ l, ll r) {\n    ll p = 1;\n    while (not FastPrimeFactorization::is_prime(p))\
    \ {\n        p = randrange(l, r);\n    }\n    return p;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/numbers/FastPrimeFactorization.hpp
  - src/common/RLE.hpp
  - src/common/sorted.hpp
  - src/random/randrange.hpp
  - src/random/mt.hpp
  isVerificationFile: false
  path: src/random/rand_prime.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/rand_prime.hpp
layout: document
redirect_from:
- /library/src/random/rand_prime.hpp
- /library/src/random/rand_prime.hpp.html
title: src/random/rand_prime.hpp
---
