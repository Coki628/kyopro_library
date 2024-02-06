#pragma once
#include "../base.hpp"
#include "mt.hpp"

// 範囲[l,r)からランダムで実数の値を返す
// see: https://www.albow.net/entry/random-range/
double rand_double(double l, double r) {
    uniform_real_distribution<double> dist(l, r);
    return dist(mt);
}
