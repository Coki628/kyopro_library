#pragma once

// 期待値DP(確率DP)の自己ループ補正
// 通常の遷移が全部終わった所でこの関数に値を渡す。
// val: 自己ループ以外の遷移を計算済のexp or prob
// cost: 自己ループ1回分のコスト(確率DPの時は0)
// self_loop_count: 自己ループになる遷移の回数
// total_count: その時点で取れる遷移の総数
template<typename T>
void self_loop_adjustment(T &val, T cost, T self_loop_count, T total_count) {
    // 自己ループのコスト * そうなる確率
    val += cost * self_loop_count / total_count;
    // 「遷移の総数 / 自己ループにならずに遷移する数」を掛ける
    val *= total_count / (total_count - self_loop_count);
}
