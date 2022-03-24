#define PROBLEM "https://atcoder.jp/contests/abc149/tasks/abc149_e"

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
#include "../../src/common/input.hpp"
#include "../../src/common/print.hpp"

#include "../../src/common/bisearch.hpp"
#include "../../src/common/bisect.hpp"
#include "../../src/segment/Accumulate.hpp"

void solve() {
    ll N, M;
    cin >> N >> M;
    auto A = LIST(N);

    sort(ALL(A));
    ll x = bisearch_min(0, INF, [&](ll m) {
        ll cnt = 0;
        rep(i, N) {
            cnt += N - bisect_left(A, m-A[i]);
        }
        return cnt <= M;
    });

    Accumulate<ll> acc(A);
    ll ans = 0, cnt = M;
    rep(i, N-1, -1, -1) {
        ll j = N - bisect_left(A, x-A[i]);
        cnt -= j;
        ans += acc.query(N-j, N) + A[i]*j;
    }
    // 端数
    ans += (x-1) * cnt;
    print(ans);
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
