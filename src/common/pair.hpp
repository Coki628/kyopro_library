#pragma once
#include "../base.hpp"

// pairの四則計算
template<class T, class U> inline pair<T, U>& operator+=(pair<T, U>& a, const pair<T, U>& b) {a.fi += b.fi; a.se += b.se; return a;}
template<class T, class U> inline pair<T, U>& operator-=(pair<T, U>& a, const pair<T, U>& b) {a.fi -= b.fi; a.se -= b.se; return a;}
template<class T, class U> inline pair<T, U>& operator*=(pair<T, U>& a, const pair<T, U>& b) {a.fi *= b.fi; a.se *= b.se; return a;}
template<class T, class U> inline pair<T, U>& operator/=(pair<T, U>& a, const pair<T, U>& b) {a.fi /= b.fi; a.se /= b.se; return a;}

template<class T, class U>
constexpr void operator++(pair<T, U>& a, int) noexcept {
    a.first++;
    a.second++;
}

template<class T, class U>
constexpr void operator--(pair<T, U>& a, int) noexcept {
    a.first--;
    a.second--;
}
