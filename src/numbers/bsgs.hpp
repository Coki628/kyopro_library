#include "../macros.hpp"
#include "common/HashMap.hpp"
#include "common/pow.hpp"
#include "inv_mod.hpp"

// 参考：https://tjkendev.github.io/procon-library/python/math/baby-step-giant-step.html
// BSGS(Baby-step Giant-step)
// ・x^k ≡ y (mod m) となるような最小の k を求める。
// ・xとmodが互いに素であることが条件。
// 　(素数ではなくてもいいように、逆元はフェルマーじゃなくて拡張ユークリッドの方にしてある。)

ll bsgs(ll x, ll y, ll m, ll z=1) {
    assert((gcd(x, m) == 1));

    z %= m;
    HashMap<ll, ll> C;
    C[z] = 0;
    ll sq = sqrt(m) + 1;

    // Baby-step
    rep(i, sq) {
        z = z * x % m;
        if (not C.count(z)) {
            C[z] = i + 1;
        }
    }
    if (C.count(y)) {
        return C[y];
    }

    // Giant-step
    ll r = inv_mod(pow(x, sq, m), m); // r = x^(-sq);
    rep(i, 1, sq+1) {
        y = y * r % m;
        if (C.count(y)) {
            return C[y] + i*sq;
        }
    }
    return -1;
}
