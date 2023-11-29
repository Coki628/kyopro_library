#include "../macros.hpp"

// 整数で正確にsqrtを返す 
// ※logが結構重い。速度重視なら実数の標準sqrt使う方がいい。
ll isqrt(ll n, bool ceil=false) {
    ll ok = 0;
    ll ng = 3037000500;
    while (ng - ok > 1) {
        ll m = ok + (ng - ok) / 2;
        if (m * m <= n) {
            ok = m;
        } else {
            ng = m;
        }
    }
    if (ceil and ok*ok != n) ok++;
    return ok;
}
