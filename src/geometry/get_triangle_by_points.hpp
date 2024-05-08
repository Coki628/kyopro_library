#pragma once
#include "Point.hpp"

// 3頂点が作る三角形の面積
ld get_triangle_by_points(const Point<ld> &s, const Point<ld> &t, const Point<ld> &u) {
    auto [x1, y1] = s;
    auto [x2, y2] = t;
    auto [x3, y3] = u;
    // 面積*2
    ld S2 = abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
    return S2 / 2;
}
