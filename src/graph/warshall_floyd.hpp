#pragma once
#include "../macros.hpp"
#include "../common/chmin.hpp"

template<typename T>
vector<vector<T>> warshall_floyd(vector<vector<T>> G) {
    ll N = G.size();
    rep(i, N) G[i][i] = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
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
// vector<vector<T>> warshall_floyd(vector<vector<T>> G) {
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
