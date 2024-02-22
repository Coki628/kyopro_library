---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/twosat.hpp
    title: src/acl/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/subarray.hpp
    title: src/common/subarray.hpp
  - icon: ':warning:'
    path: src/graph/TwoSAT.hpp
    title: src/graph/TwoSAT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1903/submission/235149307
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/twosat:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../common/subarray.hpp\"\
    \n#include \"TwoSAT.hpp\"\n\n// \u533A\u9593\u8FBA2-SAT\n// see: https://codeforces.com/contest/1903/submission/235149307\n\
    // \u30FB\u304A\u3066\u3089\u3055\u3093\u306E\u5B9F\u88C5\u304CACL\u3092\u3046\
    \u307E\u304F\u30E9\u30C3\u30D7\u3057\u3066\u308B\u611F\u3058\u3067\u3059\u3054\
    \u304F\u53C2\u8003\u306B\u306A\u3063\u305F\u3002\n// \u30FB\u4F7F\u7528\u5074\u3068\
    \u3057\u3066\u306F\u306A\u308B\u3079\u304F\u9802\u70B9\u756A\u53F7\u306E\u5909\
    \u5316\u3068\u304B\u3092\u610F\u8B58\u3057\u306A\u3044\u3067\u6E08\u3080\u3088\
    \u3046\u306B\u3001\n// \u3000\u547C\u3073\u51FA\u3057\u6642\u306B\u306F\u5168\u3066\
    \u5143\u9802\u70B9\u306E\u756A\u53F7\u3067\u64CD\u4F5C\u3092\u547C\u3079\u308B\
    \u3088\u3046\u306B\u3057\u305F\u3002\nstruct RangeEdgedTwoSAT : public TwoSAT\
    \ {\n    using base_type = TwoSAT;\n    using base_type::base_type;\n\n    int\
    \ n;\n    RangeEdgedTwoSAT(int n) : n(n), base_type(2 * n) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int cl = i * 2, cr = i * 2 + 1;\n        \
    \    base_type::add_clause(i, true, cl, false);\n            base_type::add_clause(i,\
    \ true, cr, false);\n        }\n    }\n\n    void add_clause(int i, bool f, int\
    \ j, bool g) override {\n        base_type::add_clause(i + n, f, j + n, g);\n\
    \    }\n\n    // u = f, [l,r) = g \u306E\u533A\u9593\u8FBA\u3092\u5F35\u308B\n\
    \    void add_clause(int u, bool f, int l, int r, bool g) {\n        u += n;\n\
    \        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l &\
    \ 1) base_type::add_clause(u, f, l++, g);\n            if (r & 1) base_type::add_clause(u,\
    \ f, --r, g);\n        }\n    }\n\n    vector<bool> answer() {\n        auto res\
    \ = base_type::answer();\n        return subarray(res, n, 2 * n);\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/common/subarray.hpp
  - src/graph/TwoSAT.hpp
  - src/acl/twosat.hpp
  isVerificationFile: false
  path: src/graph/RangeEdgedTwoSAT.hpp
  requiredBy: []
  timestamp: '2024-01-04 14:20:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgedTwoSAT.hpp
layout: document
redirect_from:
- /library/src/graph/RangeEdgedTwoSAT.hpp
- /library/src/graph/RangeEdgedTwoSAT.hpp.html
title: src/graph/RangeEdgedTwoSAT.hpp
---
