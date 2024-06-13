#pragma once
#include "../base.hpp"

// 桁DPのsmaller flag取得
bool get_smaller_flag(bool current_flag, int current_value, int limit_value) {
    assert(not (current_flag == 0 and current_value > limit_value));
    bool next_flag = current_flag | (current_value < limit_value);
    return next_flag;
}

// 下限が決まってる時用(未verify)
bool get_greater_flag(bool current_flag, int current_value, int limit_value) {
    assert(not (current_flag == 0 and current_value < limit_value));
    bool next_flag = current_flag | (current_value > limit_value);
    return next_flag;
}
