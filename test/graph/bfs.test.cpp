#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C"

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define CONSTANTS
// #define CAST_MINT_TO_LL
#include "../../src/base.hpp"

constexpr long long INF = 1e18;
// constexpr long long INF = LONG_LONG_MAX;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr long double EPS = 1e-10;
constexpr long double PI = M_PI;

#include "../../src/macros.hpp"
#include "../../src/common/print.hpp"

#include "../../src/graph/bfs.hpp"

void solve() {
    ll N;
    cin >> N;
    vvi nodes(N);
    rep(_, N) {
        ll u;
        cin >> u;
        u--;
        ll k;
        cin >> k;
        rep(_, 0, k) {
            ll v;
            cin >> v;
            v--;
            nodes[u].pb(v);
        }
    }

    auto res = bfs(nodes, {0});
    vector<pll> ans(N);
    rep(i, N) {
        if (res[i] >= INF) {
            res[i] = -1;
        }
        ans[i].first = i + 1;
        ans[i].second = res[i];
    }
    for (auto &p : ans) print(p);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    // single test case
    solve();

    // multi test cases
    // int T;
    // cin >> T;
    // while (T--) solve();

    return 0;
}
