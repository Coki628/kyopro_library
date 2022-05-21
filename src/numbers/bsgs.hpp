#include "../macros.hpp"
#include "../common/pow.hpp"

// x^k ≡ y (mod m) となるような k を求める
ll bsgs(ll x, ll y, ll m) {
    ll z = 1;
    map<ll, ll> C = {{z, 0}};
    ll sq = int(sqrt(m)) + 1;

    // Baby-step
    rep(i, sq) {
        z = z * x % m;
        C[z] = i + 1;
    }
    if (C.count(y)) {
        return C[y];
    }

    // Giant-step
    ll r = pow(z, m-2, m); // r = x^(-sq);
    rep(i, 1, sq+1) {
        y = y * r % m;
        if (C.count(y)) {
            return C[y] + i*sq;
        }
    }
    return -1;
}
