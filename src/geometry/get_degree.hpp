#include "../macros.hpp"
#include "Point.hpp"
#include "degrees.hpp"

// 座標bを軸にして反時計回りに座標aから座標cに向かう角度を取得
template<typename T>
ld get_degree(Point<T> a, Point<T> b, Point<T> c) {
    // bから見たa,cへ向かうベクトル
    Point<T> v1 = a-b;
    Point<T> v2 = c-b;
    // atan2がx=0から見た角度を返すので、差分を取る
    T res = degrees(atan2(v2.y, v2.x) - atan2(v1.y, v1.x));
    // 誤差対策のEPS、負の数なら時計回り側にあるので逆向きにする
    if (res < -EPS) res += 360;
    return res;
}

// // 座標bを軸にして近い側回りに座標aから座標cに向かう角度を取得
// template<typename T>
// ld get_degree(Point<T> a, Point<T> b, Point<T> c) {
//     // bから見たa,cへ向かうベクトル
//     Point<T> v1 = a-b;
//     Point<T> v2 = c-b;
//     // atan2がx=0から見た角度を返すので、差分を取る
//     T res = degrees(atan2(v2.y, v2.x) - atan2(v1.y, v1.x));
//     // 近い側に回転させる(-180~180に収める)
//     if (res+EPS >= 180) {
//         res -= 360;
//     } elif (res <= -180+EPS) {
//         res += 360;
//     }
//     assert(-180 < res and res < 180);
//     return res;
// }
