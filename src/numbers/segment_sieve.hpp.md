---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: macros.hpp: line\
    \ -1: no such header\n"
  code: "#include \"macros.hpp\"\n\n// \u533A\u9593[l,r)\u5185\u306E\u5404\u7D20\u56E0\
    \u6570\u306E\u500B\u6570(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u533A\
    \u9593\u7BE9) \nmap<ll, ll> segment_sieve(ll l, ll r) {\n\n    int MAX = int(sqrt(r));\n\
    \    vector<bool> is_prime(MAX+1, true);\n    map<ll, ll> C;\n    vector<ll> A(r-l);\n\
    \    iota(ALL(A), l);\n\n    rep(i, 2, MAX+1) {\n        ll cnt = 0;\n       \
    \ if (is_prime[i]) {\n            rep(j, i*2, MAX+1, i) {\n                is_prime[j]\
    \ = false;\n            }\n            // \u7D20\u6570\u304C\u898B\u3064\u304B\
    \u3063\u305F\u3089\u3001\u533A\u9593\u5185\u306B\u3042\u308B\u305D\u306E\u500D\
    \u6570\u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\u3044\
    \u304F\n            rep(j, max(2LL, (l+i-1)/i)*i, r, i) {\n                while\
    \ (A[j-l] % i == 0) {\n                    A[j-l] /= i;\n                    cnt++;\n\
    \                }\n            }\n            C[i] += cnt;\n        }\n    }\n\
    \    // \u81EA\u8EAB\u304C\u7D20\u6570\u3067\u3042\u308C\u3070\u305D\u306E\u5206\
    \u3092\u8DB3\u3059\n    rep(i, r-l) {\n        if (A[i] > 1) {\n            C[A[i]]++;\n\
    \        }\n    }\n    return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numbers/segment_sieve.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/segment_sieve.hpp
layout: document
redirect_from:
- /library/src/numbers/segment_sieve.hpp
- /library/src/numbers/segment_sieve.hpp.html
title: src/numbers/segment_sieve.hpp
---
