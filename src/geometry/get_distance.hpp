#pragma once
#include "Point.hpp"
#include "Line.hpp"
#include "Segment.hpp"
#include "dot.hpp"
#include "cross.hpp"
#include "intersect.hpp"

template<typename T>
T get_distance_PP(Point<T> p1, Point<T> p2) {

    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// 直線lineと点pの距離
template<typename T>
T get_distance_LP(Line<T> line, Point<T> p) {

    return std::abs(
        cross(line.p2 - line.p1, p - line.p1) / abs(line.p2 - line.p1)
    );
}

// 線分segと点pの距離
template<typename T>
T get_distance_SP(Segment<T> seg, Point<T> p) {

    if (dot(seg.p2 - seg.p1, p - seg.p1) < 0) {
        return abs(p - seg.p1);
    }
    if (dot(seg.p1 - seg.p2, p - seg.p2) < 0) {
        return abs(p - seg.p2);
    }
    return get_distance_LP(seg, p);
}

// 線分seg1と線分seg2の距離
template<typename T>
T get_distance_SS(Segment<T> seg1, Segment<T> seg2) {

    if (intersect(seg1, seg2)) {
        return 0;
    }
    return min({
        get_distance_SP(seg1, seg2.p1),
        get_distance_SP(seg1, seg2.p2),
        get_distance_SP(seg2, seg1.p1),
        get_distance_SP(seg2, seg1.p2),
    });
}
