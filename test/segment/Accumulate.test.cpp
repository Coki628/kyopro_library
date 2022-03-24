#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_j"

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
#include "../../src/common/listnd.hpp"
#include "../../src/common/print.hpp"

#include "../../src/segment/Accumulate.hpp"

void solve() {
    ll N;
    cin >> N;
    auto A = list2d(2, N, 0LL);
    rep(i, N) {
        ll c, p;
        cin >> c >> p;
        c--;
        A[c][i] = p;
    }

    Accumulate<ll> acc1(A[0]), acc2(A[1]);

    ll Q;
    cin >> Q;
    rep(_, Q) {
        ll l, r;
        cin >> l >> r;
        l--;

        vector<ll> res(2);
        res[0] = acc1.query(l, r);
        res[1] = acc2.query(l, r);
        print(res);
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
