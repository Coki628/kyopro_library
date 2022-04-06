---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  - icon: ':warning:'
    path: src/geometry/Segment.hpp
    title: src/geometry/Segment.hpp
  - icon: ':warning:'
    path: src/geometry/cross.hpp
    title: src/geometry/cross.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/Point.hpp:\
    \ line -1: no such header\n"
  code: "#include \"geometry/Point.hpp\"\n#include \"geometry/Segment.hpp\"\n#include\
    \ \"geometry/cross.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\n\
    // \u7DDA\u5206seg1\u3068\u7DDA\u5206seg2\u306E\u4EA4\u70B9\ntemplate<typename\
    \ T>\nPoint<T> get_cross_point(Segment<T> seg1, Segment<T> seg2) {\n    T deno\
    \ = cross(seg1.p2 - seg1.p1, seg2.p2 - seg2.p1);\n    if (abs(deno) < EPS) {\n\
    \        // \u7DDA\u5206\u304C\u5E73\u884C\n        throw -1;\n    }\n    T s\
    \ = cross(seg2.p1 - seg1.p1, seg2.p2 - seg2.p1) / deno;\n    T t = cross(seg1.p2\
    \ - seg1.p1, seg1.p1 - seg2.p1) / deno;\n    if (s < -EPS or 1.0 < s-EPS or t\
    \ < -EPS or 1.0 < t-EPS) {\n        // \u7DDA\u5206\u304C\u4EA4\u5DEE\u3057\u3066\
    \u3044\u306A\u3044\n        throw -1;\n    }\n    return { seg1.p1.x + s * (seg1.p2\
    \ - seg1.p1).x, seg1.p1.y + s * (seg1.p2 - seg1.p1).y };\n}\n"
  dependsOn:
  - src/geometry/Point.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/geometry/Segment.hpp
  - src/geometry/cross.hpp
  isVerificationFile: false
  path: src/geometry/get_cross_point.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/get_cross_point.hpp
layout: document
redirect_from:
- /library/src/geometry/get_cross_point.hpp
- /library/src/geometry/get_cross_point.hpp.html
title: src/geometry/get_cross_point.hpp
---
