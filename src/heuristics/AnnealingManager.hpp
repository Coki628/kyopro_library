#pragma once
#include "../base.hpp"

// 焼きなまし管理
// 参考資料：https://gasin.hatenadiary.jp/entry/2019/09/03/162613
// 　　　　　https://shindannin.hatenadiary.com/entry/20121224/1356364040
// ・温度と悪化量が同じくらいだと1/3くらいの確率で遷移、
// 　悪化量が10倍くらいあるとほぼ0になる。
struct AnnealingManager {
    const int TL;
    // 開始温度：一回の遷移で動きうるスコア幅の最大値程度
    const double T0;
    // 終了温度：一回の遷移で動きうるスコア幅の最小値程度
    const double T1;
    // デフォルトはスコア最大化で最小化時はtrue
    bool is_min;
    // 温度計算のタイプ
    // 1: 線形
    // 2: 2次関数
    int temp_type;

    // T0 = 0, T1 = 0 にすれば山登り
    AnnealingManager(
        int TL, double T0, double T1, bool is_min = false, int temp_type = 1
    )
        : TL(TL),
          T0(T0),
          T1(T1),
          is_min(is_min),
          temp_type(temp_type) {
    }

    // 0~1の一様ランダムな実数を返す
    double rand_double() {
        return 1.0 * rand() / RAND_MAX;
    }

    // 焼きなましに使う温度の計算
    double calc_temp(int elapsed) {
        double t = elapsed / (double)TL;
        if (t > 1) {
            // 時間切れは温度0にしとくか(採用0)
            return 0;
        }
        if (temp_type == 1) {
            // 線形っぽく減る
            return T0 + (T1 - T0) * t;
        } else if (temp_type == 2) {
            // 2次関数っぽく減る
            return pow(T0, (1 - t)) * pow(T1, t);
        }
        assert(0);
    }

    // 焼きなましを踏まえた採用確率の計算
    double calc_prob(double diff, double temp) {
        if (diff >= 0) {
            return 1;
        }
        return exp(diff / temp);
    }

    // 採用するか判定
    bool judge(double cur_score, double nxt_score, int elapsed) {
        double temp = calc_temp(elapsed);
        double diff = nxt_score - cur_score;
        if (is_min) {
            diff = -diff;
        }
        double prob = calc_prob(diff, temp);
        return rand_double() < prob;
    }
};
