#include "../macros.hpp"

int bit_length(ll x) {
    int res = 0;
    while (x) {
        res++;
        x /= 2;
    }
    return res;
}
