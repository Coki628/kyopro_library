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
  - icon: ':warning:'
    path: src/common/pow.hpp
    title: src/common/pow.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/numbers/extgcd.hpp
    title: src/numbers/extgcd.hpp
  - icon: ':warning:'
    path: src/numbers/inv_mod.hpp
    title: src/numbers/inv_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://tjkendev.github.io/procon-library/python/math/baby-step-giant-step.html
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
  code: "#include \"../macros.hpp\"\n#include \"common/HashMap.hpp\"\n#include \"\
    common/pow.hpp\"\n#include \"inv_mod.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://tjkendev.github.io/procon-library/python/math/baby-step-giant-step.html\n\
    // BSGS(Baby-step Giant-step)\n// \u30FBx^k \u2261 y (mod m) \u3068\u306A\u308B\
    \u3088\u3046\u306A\u6700\u5C0F\u306E k \u3092\u6C42\u3081\u308B\u3002\n// \u30FB\
    x\u3068mod\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\u6761\
    \u4EF6\u3002\n// \u3000(\u7D20\u6570\u3067\u306F\u306A\u304F\u3066\u3082\u3044\
    \u3044\u3088\u3046\u306B\u3001\u9006\u5143\u306F\u30D5\u30A7\u30EB\u30DE\u30FC\
    \u3058\u3083\u306A\u304F\u3066\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u65B9\u306B\u3057\u3066\u3042\u308B\u3002)\n\nll bsgs(ll x, ll y, ll m,\
    \ ll z=1) {\n    assert((gcd(x, m) == 1));\n\n    z %= m;\n    HashMap<ll, ll>\
    \ C;\n    C[z] = 0;\n    ll sq = sqrt(m) + 1;\n\n    // Baby-step\n    rep(i,\
    \ sq) {\n        z = z * x % m;\n        if (not C.count(z)) {\n            C[z]\
    \ = i + 1;\n        }\n    }\n    if (C.count(y)) {\n        return C[y];\n  \
    \  }\n\n    // Giant-step\n    ll r = inv_mod(pow(x, sq, m), m); // r = x^(-sq);\n\
    \    rep(i, 1, sq+1) {\n        y = y * r % m;\n        if (C.count(y)) {\n  \
    \          return C[y] + i*sq;\n        }\n    }\n    return -1;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/HashMap.hpp
  - src/common/HashMapImpl.hpp
  - src/common/pow.hpp
  - src/numbers/inv_mod.hpp
  - src/numbers/extgcd.hpp
  isVerificationFile: false
  path: src/numbers/bsgs.hpp
  requiredBy: []
  timestamp: '2023-10-10 14:51:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/bsgs.hpp
layout: document
redirect_from:
- /library/src/numbers/bsgs.hpp
- /library/src/numbers/bsgs.hpp.html
title: src/numbers/bsgs.hpp
---
