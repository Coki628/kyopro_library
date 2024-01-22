#pragma once
#include "../base.hpp"

string tolower(string s) {
    for (auto& c : s) {
        c = tolower(c);
    }
    return s;
}
