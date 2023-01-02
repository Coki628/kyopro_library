#include "../base.hpp"

bool isdigit(string S) {
    for (auto c : S) {
        if (not isdigit(c)) {
            return false;
        }
    }
    return true;
}
