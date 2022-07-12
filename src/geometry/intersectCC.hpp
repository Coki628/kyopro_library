#include "../base.hpp"
#include "../common/pow.hpp"
#include "Circle.hpp"

// 参考：https://manabitimes.jp/math/745
// 円c1と円c2の交差判定(2乗のまま整数で判定できるようにしてある)
template<typename T>
int intersectCC(Circle<T> c1, Circle<T> c2) {
    T d2 = pow(c1.c.x-c2.c.x, 2) + pow(c1.c.y-c2.c.y, 2);
    // 一方が他方を内包
    if (d2 < pow(abs(c1.r-c2.r), 2)) {
        return 1;
    }
    // 内接する
    if (d2 == pow(abs(c1.r-c2.r), 2)) {
        return 2;
    }
    // 2点で交わる
    if (pow(abs(c1.r-c2.r), 2) < d2 and d2 < pow(c1.r+c2.r, 2)) {
        return 3;
    }
    // 外接する
    if (d2 == pow(c1.r+c2.r, 2)) {
        return 4;
    }
    // 2円が離れてる
    if (d2 > pow(c1.r+c2.r, 2)) {
        return 5;
    }
    assert(0);
}
