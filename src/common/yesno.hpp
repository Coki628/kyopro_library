#pragma once
#include "print.hpp"

void Yes() {
    print("Yes");
}

void No() {
    print("No");
}

void YES() {
    print("YES");
}

void NO() {
    print("NO");
}

void YESNO(bool f) {
    print(f ? "YES" : "NO");
}

void YesNo(bool f) {
    print(f ? "Yes" : "No");
}

void yesno(bool f) {
    print(f ? "yes" : "no");
}
