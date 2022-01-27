/*
参考：https://www.terry-u16.net/entry/ahc006-for-beginners
　　　https://qiita.com/thun-c/items/058743a25c37c87b8aa4
・なんか良い方針が生えず、最初から解説見ちゃった…。
・貪欲、二分探索、ビームサーチ
・近い方から取る。それだけ。現在位置からの距離を毎回N箇所全部と取っても、
　Nが1000で回数が50回くらいなので全然問題ない。
・距離が遠すぎる場所を予め候補から外しておく。
・レストランと配達先をまとめて処理する。
・候補を絞る距離の閾値を二分探索でギリギリに設定する。
・初めてのビームサーチ。なんかうまくできてるのかは微妙。
　終了周りの条件がいけてない感じはする。。
・始めむしろ貪欲よりダメで、ビーム幅10とかだったのを時間使って1000まで増やしたら
　いくらかマシになって129万点くらいに。
*/

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define CONSTANTS
#include "base.hpp"

constexpr long long INF = 1e18;
// constexpr long long INF = LONG_LONG_MAX;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr long double EPS = 1e-10;
constexpr long double PI = M_PI;

#include "macros.hpp"

#include "common/input.hpp"
#include "common/print.hpp"
#include "common/randrange.hpp"
#include "common/Timer.hpp"
#include "string/zfill.hpp"

#include "common/sum.hpp"
#include "common/listnd.hpp"
#include "common/bisearch.hpp"
#include "common/chmin.hpp"
#include "geometry/Point.hpp"

ld calc(ll t) {
    return round(1e8/(1000+t));
}

void solve(int testcase=-1) {
    #ifdef __LOCAL
        // 入力ファイル読み込み
        string filename = "tools/in/"+zfill(tostr(testcase), 4)+".txt";
        freopen(filename.c_str(), "r", stdin);
        // 出力ファイル準備
        filename = "tools/out/"+zfill(tostr(testcase), 4)+".txt";
        ofstream ofs(filename.c_str());
        if (!ofs) {
            print(-1);
            return;
        }
    #endif

    const int N = 1000;
    const int K = 50;
    Point<ll> s = {400, 400};
    auto XY = list2d(2, N, Point<ll>());
    rep(i, N) {
        cin >> XY[0][i].x >> XY[0][i].y >> XY[1][i].x >> XY[1][i].y;
    }

    // K箇所回れる閾値を二分探索
    ll DIST_MAX = bisearch_min(0, 600, [&](ll m) {
        ll res = N;
        rep(i, N) {
            if (s.manhattan(XY[0][i])+s.manhattan(XY[1][i]) > m) {
                res--;
            }
        }
        return res >= K;
    });
    // 閾値より大きい距離の注文を予め省いておく
    vector<int> removed(N);
    rep(i, N) {
        if (s.manhattan(XY[0][i])+s.manhattan(XY[1][i]) > DIST_MAX) {
            removed[i] = true;
        }
    }
    #ifdef __LOCAL
        debug(N-sum(removed));
    #endif

    const int BEAM_WIDTH = 1000;
    // state[d, v[p, i]] = 距離d, 通ったルートv[レストランor配達先p=0/1, 注文番号i]
    using state = pair<ll, vector<pair<bool, int>>>;
    priority_queue<state, vector<state>, greater<state>> cur_beam;
    cur_beam.push({0, {}});
    ll mn = INF;
    vector<ll> route;
    vector<ll> xy;
    while (1) {
        priority_queue<state, vector<state>, greater<state>> nxt_beam;
        rep(_, BEAM_WIDTH) {
            if (cur_beam.empty()) break;
            auto [d, v] = cur_beam.top(); cur_beam.pop();
            auto cur = v.empty() ? s : XY[v.back().first][v.back().second];
            // 現在の使用状態を作る
            set<pair<bool, int>> used;
            ll abcnt = 0, cdcnt = 0;
            for (auto& [p, i] : v) {
                used.insert({p, i});
                if (p) cdcnt++;
                else abcnt++;
            }
            // 既に終了状態
            if (cdcnt == K) continue;
            rep(i, N) {
                if (removed[i]) continue;
                if (not used.count({0, i}) and abcnt < K) {
                    ll nxd = cur.manhattan(XY[0][i]);
                    v.eb(0, i);
                    nxt_beam.push({d+nxd, v});
                    v.pop_back();
                }
                if (used.count({0, i}) and not used.count({1, i})) {
                    ll nxd = cur.manhattan(XY[1][i]);
                    v.eb(1, i);
                    nxt_beam.push({d+nxd, v});
                    v.pop_back();
                }
            }
        }
        if (nxt_beam.empty()) break;
        cur_beam = nxt_beam;
        // 今一番いい状態を確認
        ll cdcnt = 0;
        auto [d, v] = cur_beam.top();
        for (auto& [p, i] : v) {
            if (p) cdcnt++;
        }
        // K箇所回りきったら答えに使えるかチェック
        if (cdcnt == K) {
            auto cur = XY[v.back().first][v.back().second];
            d += cur.manhattan(s);
            if (chmin(mn, d)) {
                vector<ll> tmp_route;
                vector<ll> tmp_xy = {s.x, s.y};
                for (auto& [p, i] : v) {
                    if (!p) tmp_route.eb(i+1);
                    cur = XY[p][i];
                    tmp_xy.eb(cur.x);
                    tmp_xy.eb(cur.y);
                }
                // 答えを更新
                tmp_xy.eb(s.x);
                tmp_xy.eb(s.y);
                route = tmp_route;
                xy = tmp_xy;
            }
        }
    }

    #ifdef __LOCAL
        debug(mn);
        debug(calc(mn));
    #endif
    cout << route.size() << ' ';
    print(route);
    cout << xy.size()/2 << ' ';
    print(xy);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    #ifdef __LOCAL
        // 実施テスト番号
        vector<ll> T = {
            0,
        };
        for (ll t : T) {
            solve(t);
        }
    #else
        solve();
    #endif

    return 0;
}
