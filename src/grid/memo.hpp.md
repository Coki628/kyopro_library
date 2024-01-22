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
    \u53CD\u8EE2\u3055\u305B\u305F\u3044\u6642\u306Ed\u306E\u66F4\u65B0\n// 0<->2,\
    \ 1<->3\n// revd = (d + 2) % 4;\n// 0<->1, 2<->3\n// revd = d & 1 ? d - 1 : d\
    \ + 1;\n\n// \u30C0\u30A4\u30E4\u578B\u306B\u8D70\u67FB(\u30DE\u30F3\u30CF\u30C3\
    \u30BF\u30F3\u8DDD\u96E2\u306E\u7B49\u3057\u3044\u6240\u3092\u901A\u308B\u3084\
    \u3064)\n// TODO(\u3044\u3064\u304B\u306EAHC\u3067\u4F7F\u3063\u305F\u304B\u3089\
    \u6301\u3063\u3066\u304F\u308B)\n\n// \u6E26\u5DFB\u304D\u72B6\u306B\u8D70\u67FB\
    \n// \u2192, \u2193, \u2190, \u2191\n// vector<pll> ds = {{0, 1}, {1, 0}, {0,\
    \ -1}, {-1, 0}};\n// ll ch = 0, cw = 0, d = 0;\n// // do something to (ch,cw)\
    \ here\n// while (cur < H * W) {\n//     auto [dh, dw] = ds[d];\n//     ll nh\
    \ = ch + dh, nw = cw + dw;\n//     if (nh < 0 or nw < 0 or nh >= H or nw >= W\
    \ or (grid[nh][nw] is done)) {\n//         d = (d + 1) % 4;\n//     } else {\n\
    //         // do something to (nh,nw) here\n//         ch = nh, cw = nw;\n// \
    \    }\n// }\n\n// \u3088\u304F\u51FA\u308B\u306E\u3068\u3001\u5730\u5473\u306B\
    \u3053\u308C{}\u305F\u304F\u3055\u3093\u3067\u901F\u304F\u66F8\u304F\u306E\u9762\
    \u5012\u306A\u306E\u3067\n// RLUD -> (dx, dy)\n// map<char, pii> mp = {{'R', {1,\
    \ 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};\n// UDLR -> (dh, dw)\n\
    // map<char, pii> mp = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0,\
    \ 1}}};\n\n// grid\u306E\u5168\u4F53\u3067\u306F\u306A\u304F[sh,sh+szh),[sw,sw+szw)\u306E\
    \u9577\u65B9\u5F62\u9818\u57DF\u3060\u3051180\u5EA6\u56DE\u8EE2\u3059\u308B\n\
    // auto rot180 = [](const vvi &grid, ll sh, ll sw, ll szh, ll szw) {\n//     auto\
    \ res = grid;\n//     rep(i, szh * szw / 2) {\n//         auto [h, w] = idtogrid(i,\
    \ szw);\n//         swap(res[sh + h][sw + w], res[sh + szh - h - 1][sw + szw -\
    \ w - 1]);\n//     }\n//     return res;\n// };\n"
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
    \u6642\u306Ed\u306E\u66F4\u65B0\n// 0<->2, 1<->3\n// revd = (d + 2) % 4;\n// 0<->1,\
    \ 2<->3\n// revd = d & 1 ? d - 1 : d + 1;\n\n// \u30C0\u30A4\u30E4\u578B\u306B\
    \u8D70\u67FB(\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u7B49\u3057\
    \u3044\u6240\u3092\u901A\u308B\u3084\u3064)\n// TODO(\u3044\u3064\u304B\u306E\
    AHC\u3067\u4F7F\u3063\u305F\u304B\u3089\u6301\u3063\u3066\u304F\u308B)\n\n// \u6E26\
    \u5DFB\u304D\u72B6\u306B\u8D70\u67FB\n// \u2192, \u2193, \u2190, \u2191\n// vector<pll>\
    \ ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};\n// ll ch = 0, cw = 0, d = 0;\n// //\
    \ do something to (ch,cw) here\n// while (cur < H * W) {\n//     auto [dh, dw]\
    \ = ds[d];\n//     ll nh = ch + dh, nw = cw + dw;\n//     if (nh < 0 or nw < 0\
    \ or nh >= H or nw >= W or (grid[nh][nw] is done)) {\n//         d = (d + 1) %\
    \ 4;\n//     } else {\n//         // do something to (nh,nw) here\n//        \
    \ ch = nh, cw = nw;\n//     }\n// }\n\n// \u3088\u304F\u51FA\u308B\u306E\u3068\
    \u3001\u5730\u5473\u306B\u3053\u308C{}\u305F\u304F\u3055\u3093\u3067\u901F\u304F\
    \u66F8\u304F\u306E\u9762\u5012\u306A\u306E\u3067\n// RLUD -> (dx, dy)\n// map<char,\
    \ pii> mp = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};\n\
    // UDLR -> (dh, dw)\n// map<char, pii> mp = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L',\
    \ {0, -1}}, {'R', {0, 1}}};\n\n// grid\u306E\u5168\u4F53\u3067\u306F\u306A\u304F\
    [sh,sh+szh),[sw,sw+szw)\u306E\u9577\u65B9\u5F62\u9818\u57DF\u3060\u3051180\u5EA6\
    \u56DE\u8EE2\u3059\u308B\n// auto rot180 = [](const vvi &grid, ll sh, ll sw, ll\
    \ szh, ll szw) {\n//     auto res = grid;\n//     rep(i, szh * szw / 2) {\n//\
    \         auto [h, w] = idtogrid(i, szw);\n//         swap(res[sh + h][sw + w],\
    \ res[sh + szh - h - 1][sw + szw - w - 1]);\n//     }\n//     return res;\n//\
    \ };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/grid/memo.hpp
  requiredBy: []
  timestamp: '2024-01-22 18:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/memo.hpp
layout: document
redirect_from:
- /library/src/grid/memo.hpp
- /library/src/grid/memo.hpp.html
title: src/grid/memo.hpp
---
