#pragma once
#include "Point.hpp"
#include "Segment.hpp"
#include "cross.hpp"

// 線分seg1と線分seg2の交点
// 参考：https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f
template<typename T>
Point<T> get_cross_point(Segment<T> seg1, Segment<T> seg2) {
    T deno = cross(seg1.p2 - seg1.p1, seg2.p2 - seg2.p1);
    if (abs(deno) < EPS) {
        // 線分が平行
        throw -1;
    }
    T s = cross(seg2.p1 - seg1.p1, seg2.p2 - seg2.p1) / deno;
    T t = cross(seg1.p2 - seg1.p1, seg1.p1 - seg2.p1) / deno;
    if (s < -EPS or 1.0 < s - EPS or t < -EPS or 1.0 < t - EPS) {
        // 線分が交差していない
        throw -1;
    }
    return {
        seg1.p1.x + s * (seg1.p2 - seg1.p1).x,
        seg1.p1.y + s * (seg1.p2 - seg1.p1).y
    };
}
