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
