#pragma once
#include "../common/divmod.hpp"
#include "../macros.hpp"

// 列⇒グリッド変換
pll idtogrid(ll id, ll W) {
    return divmod(id, W);
}
