#pragma once
#include "../macros.hpp"
#include "Point.hpp"

template<typename T>
struct Circle {
    Point<T> c;
    T r;
    Circle(Point<T> c={0, 0}, T r=0) : c(c), r(r) {}
};
