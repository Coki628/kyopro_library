#pragma once
#include "../macros.hpp"
#include "mt.hpp"

// [l,r]の範囲で乱数生成
ll randint(ll l, ll r) {
    uniform_int_distribution<ll> rand(l, r);
    return rand(mt);
}
