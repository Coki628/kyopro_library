#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"

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
#include "../../src/combinatorics/ModInt.hpp"
#include "../../src/template.hpp"

void solve() {
    ll N, M;
    cin >> N;
    auto A = LIST(N);
    cin >> M;
    auto B = LIST(M);

    UNIQUE(A);
    ll ans = 0;
    for (ll b : B) {
        ll i = bisect_left(A, b);
        ll j = bisect_right(A, b);
        ans += (j-i);
    }
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
