#pragma once
#include "../macros.hpp"

string to_string(const string &S) {
    return S;
}

string to_string(char c) {
    return {c};
}

template<typename T1, typename T2>
string to_string(pair<T1, T2> p) {
    return to_string(p.first) + " " + to_string(p.second);
}
