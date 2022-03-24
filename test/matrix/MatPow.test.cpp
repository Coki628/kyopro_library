#define PROBLEM "https://yukicoder.me/problems/no/1299"

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
#include "common/input.hpp"
#include "common/print.hpp"
#include "common/sum.hpp"
#include "combinatorics/ModInt.hpp"

#include "matrix/MatPow.hpp"

void solve() {
    ll N, K;
    cin >> N >> K;
    auto A = LIST(N);

    mint invN = (mint)1/(mint)N;
    vector<vector<mint>> mat = {
        {1, N},
        {invN, 1},
    };
    vector<mint> init = { sum(A), (mint)sum(A)*invN };
    MatPow<mint> mp;
    auto res = mp.solve(mat, init, K);
    print(res[0]);
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
