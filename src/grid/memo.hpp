// グリッド斜めのループ(いつもぱっと出ないでもたつくので。。)
// 左上 → 右下
// rep(base, -W, W) {
//     rep(i, H) {
//         if (0 <= base + i and base + i < W) {
//             // do something below
//             // grid[i][base + i];
//         }
//     }
// }
// 右上 → 左下 (未verify)
// rep(base, -W, W) {
//     rep(i, H) {
//         if (0 <= base + W - i - 1 and base + W - i - 1 < W) {
//             // do something below
//             // grid[i][base + W - i - 1];
//         }
//     }
// }

// 右→左、下→上みたいに、状態変わる時に方向反転させたい時のdの更新
// 0<->2, 1<->3
// revd = (d + 2) % 4;
// 0<->1, 2<->3
// revd = d & 1 ? d - 1 : d + 1;

// ダイヤ型に走査(マンハッタン距離の等しい所を通るやつ)
// TODO(いつかのAHCで使ったから持ってくる)

// 渦巻き状に走査
// →, ↓, ←, ↑
// vector<pll> ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// ll ch = 0, cw = 0, d = 0;
// // do something to (ch,cw) here
// while (cur < H * W) {
//     auto [dh, dw] = ds[d];
//     ll nh = ch + dh, nw = cw + dw;
//     if (nh < 0 or nw < 0 or nh >= H or nw >= W or (grid[nh][nw] is done)) {
//         d = (d + 1) % 4;
//     } else {
//         // do something to (nh,nw) here
//         ch = nh, cw = nw;
//     }
// }

// よく出るのと、地味にこれ{}たくさんで速く書くの面倒なので
// RLUD -> (dx, dy)
// map<char, pii> mp = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};
// UDLR -> (dh, dw)
// map<char, pii> mp = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

// gridの全体ではなく[sh,sh+szh),[sw,sw+szw)の長方形領域だけ180度回転する
// auto rot180 = [](const vvi &grid, ll sh, ll sw, ll szh, ll szw) {
//     auto res = grid;
//     rep(i, szh * szw / 2) {
//         auto [h, w] = idtogrid(i, szw);
//         swap(res[sh + h][sw + w], res[sh + szh - h - 1][sw + szw - w - 1]);
//     }
//     return res;
// };
