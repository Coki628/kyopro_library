#pragma once
#include "../base.hpp"

string toupper(string s) {
    for (auto& c : s) {
        c = toupper(c);
    }
    return s;
}
