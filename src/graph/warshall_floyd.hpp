#pragma once
#include "../common/chmin.hpp"
#include "../macros.hpp"

template<typename T>
vv<T> warshall_floyd(vv<T> G) {
    ll N = G.size();
    rep(i, N) G[i][i] = 0;
    rep(k, N) {
        rep(i, N) {
            if (G[i][k] >= INF) continue;
            rep(j, N) {
                if (G[k][j] >= INF) continue;
                chmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    rep(i, N) {
        if (G[i][i] < 0) {
            return {};
        }
    }
    return G;
}

// 無向辺ならこれでも大丈夫そう。
// template<typename T>
// vv<T> warshall_floyd(vv<T>> G) {
//     ll N = G.size();
//     rep(i, N) G[i][i] = 0;
//     rep(k, N) {
//         rep(i, N) {
//             rep(j, i + 1, N) {
//                 chmin(G[i][j], G[i][k] + G[k][j]);
//                 chmin(G[j][i], G[j][k] + G[k][i]);
//             }
//         }
//     }
//     rep(i, N) {
//         if (G[i][i] < 0) {
//             return {};
//         }
//     }
//     return G;
// }
