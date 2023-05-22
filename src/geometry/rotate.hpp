#include "../macros.hpp"
#include "Point.hpp"
#include "radians.hpp"

// 回転行列：座標cを軸に座標pから半時計回りにdeg度回転させた座標を返す
template<typename T>
Point<T> rotate(Point<T> c, Point<T> p, ld deg) {
    T x = (p.x-c.x)*cos(radians(deg)) - (p.y-c.y)*sin(radians(deg)) + c.x;
    T y = (p.x-c.x)*sin(radians(deg)) + (p.y-c.y)*cos(radians(deg)) + c.y;
    return {x, y};
}
