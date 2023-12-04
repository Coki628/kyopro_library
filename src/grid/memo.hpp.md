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
  bundledCode: "#line 1 \"src/grid/memo.hpp\"\n// \u30B0\u30EA\u30C3\u30C9\u659C\u3081\
    \u306E\u30EB\u30FC\u30D7(\u3044\u3064\u3082\u3071\u3063\u3068\u51FA\u306A\u3044\
    \u3067\u3082\u305F\u3064\u304F\u306E\u3067\u3002\u3002)\n// \u5DE6\u4E0A \u2192\
    \ \u53F3\u4E0B\n// rep(base, -W, W) {\n//     rep(i, H) {\n//         if (0 <=\
    \ base + i and base + i < W) {\n//             // do something below\n//     \
    \        // grid[i][base + i];\n//         }\n//     }\n// }\n// \u53F3\u4E0A\
    \ \u2192 \u5DE6\u4E0B (\u672Averify)\n// rep(base, -W, W) {\n//     rep(i, H)\
    \ {\n//         if (0 <= base + W - i - 1 and base + W - i - 1 < W) {\n//    \
    \         // do something below\n//             // grid[i][base + W - i - 1];\n\
    //         }\n//     }\n// }\n\n// \u53F3\u2192\u5DE6\u3001\u4E0B\u2192\u4E0A\u307F\
    \u305F\u3044\u306B\u3001\u72B6\u614B\u5909\u308F\u308B\u6642\u306B\u65B9\u5411\
    \u53CD\u8EE2\u3055\u305B\u305F\u3044\u6642\u306Ed\u306E\u66F4\u65B0\n// (nxd +\
    \ 2) % 4;\n"
  code: "// \u30B0\u30EA\u30C3\u30C9\u659C\u3081\u306E\u30EB\u30FC\u30D7(\u3044\u3064\
    \u3082\u3071\u3063\u3068\u51FA\u306A\u3044\u3067\u3082\u305F\u3064\u304F\u306E\
    \u3067\u3002\u3002)\n// \u5DE6\u4E0A \u2192 \u53F3\u4E0B\n// rep(base, -W, W)\
    \ {\n//     rep(i, H) {\n//         if (0 <= base + i and base + i < W) {\n//\
    \             // do something below\n//             // grid[i][base + i];\n//\
    \         }\n//     }\n// }\n// \u53F3\u4E0A \u2192 \u5DE6\u4E0B (\u672Averify)\n\
    // rep(base, -W, W) {\n//     rep(i, H) {\n//         if (0 <= base + W - i -\
    \ 1 and base + W - i - 1 < W) {\n//             // do something below\n//    \
    \         // grid[i][base + W - i - 1];\n//         }\n//     }\n// }\n\n// \u53F3\
    \u2192\u5DE6\u3001\u4E0B\u2192\u4E0A\u307F\u305F\u3044\u306B\u3001\u72B6\u614B\
    \u5909\u308F\u308B\u6642\u306B\u65B9\u5411\u53CD\u8EE2\u3055\u305B\u305F\u3044\
    \u6642\u306Ed\u306E\u66F4\u65B0\n// (nxd + 2) % 4;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/grid/memo.hpp
  requiredBy: []
  timestamp: '2023-11-30 01:12:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/memo.hpp
layout: document
redirect_from:
- /library/src/grid/memo.hpp
- /library/src/grid/memo.hpp.html
title: src/grid/memo.hpp
---
