#pragma once

// 階乗：O(N)
template<typename T>
T factorial(int x) {
    T res = 1;
    for (int i = 1; i <= x; i++) res *= i;
    return res;
}
