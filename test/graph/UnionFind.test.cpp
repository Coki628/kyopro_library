#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define CONSTANTS
// #define CAST_MINT_TO_LL
#include "base.hpp"

constexpr long long INF = 1e18;
// constexpr long long INF = LONG_LONG_MAX;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr long double EPS = 1e-10;
constexpr long double PI = M_PI;

#include "macros.hpp"
#include "common/print.hpp"

#include "graph/UnionFind.hpp"

void solve() {
    ll N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    rep(_, Q) {
        ll op;
        cin >> op;
        if (op == 0) {
            ll x, y;
            cin >> x >> y;
            uf.merge(x, y);
        } else {
            ll x, y;
            cin >> x >> y;
            int res = uf.same(x, y);
            print(res);
        }
    }
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
