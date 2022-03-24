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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#include \"base.hpp\"\n#include \"../common/chmin.hpp\"\n\n// XOR\u57FA\u5E95\
    \ntemplate<typename T>\nvector<T> get_xor_basis(const vector<T> &A) {\n    vector<T>\
    \ basis;\n    for (auto a : A) {\n        for (auto b : basis) {\n           \
    \ chmin(a, a^b);\n        }\n        if (a > 0) basis.eb(a);\n    }\n    return\
    \ basis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numbers/xor_basis.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/xor_basis.hpp
layout: document
redirect_from:
- /library/src/numbers/xor_basis.hpp
- /library/src/numbers/xor_basis.hpp.html
title: src/numbers/xor_basis.hpp
---
