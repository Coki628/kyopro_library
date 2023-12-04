#pragma once
#include "../macros.hpp"

//  2次方程式の解の公式
pair<ld, ld> dim2formula(ld a, ld b, ld c) {
    ld d = sqrt(pow(b, 2) - 4 * a * c);
    // 解なし
    if (isnan(d)) {
        return {nan(""), nan("")};
    }
    return {(-b + d) / (2 * a), (-b - d) / (2 * a)};
}
