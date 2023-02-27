---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/acl/string.hpp
    title: src/acl/string.hpp
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/SegmentTree.hpp
    title: src/datastructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/string:\
    \ line -1: no such header\n"
  code: "#include \"../macros.hpp\"\n#include \"../datastructure/SegmentTree.hpp\"\
    \n#include \"../acl/string.hpp\"\n\nauto f = [](int a, int b) { return min(a,\
    \ b); };\n\nstruct SuffixArray {\n    int N;\n    string S;\n    bool use_seg;\n\
    \    vector<int> sa, rsa, lcp;\n    SegmentTree<int, decltype(f)> seg = get_segment_tree(f,\
    \ MOD);\n\n    SuffixArray(string S, bool use_seg=true) : S(S), N(S.size()), use_seg(use_seg)\
    \ {\n        sa = atcoder::suffix_array(S);\n        rsa.assign(N, 0);\n     \
    \   rep(i, N) {\n            rsa[sa[i]] = i;\n        }\n        lcp = atcoder::lcp_array(S,\
    \ sa);\n        if (use_seg) {\n            seg.build(lcp);\n        }\n    }\n\
    \n    // S[i]\u3068S[j]\u306ELCP\u3092\u53D6\u5F97\n    int get_lcp(int i, int\
    \ j) {\n        assert(use_seg);\n        int l = rsa[i], r = rsa[j];\n      \
    \  if (l > r) swap(l, r);\n        return seg.query(l, r);\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/datastructure/SegmentTree.hpp
  - src/acl/string.hpp
  isVerificationFile: false
  path: src/string/SuffixArray.hpp
  requiredBy: []
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/SuffixArray.hpp
layout: document
redirect_from:
- /library/src/string/SuffixArray.hpp
- /library/src/string/SuffixArray.hpp.html
title: src/string/SuffixArray.hpp
---
