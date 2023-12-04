#pragma once
#include "../macros.hpp"

// インタラクティブ用
// (これらをそのままと言うより、取ってきて中身ちょっといじって使う。)

ll ask(ll i) {
    ll res;
    cout << "? " << i + 1 << endl;
    cin >> res;
    res--;
    return res;
}

void answer(ll i) {
    cout << "! " << i + 1 << endl;
}

void answer(const vector<ll> &A) {
    int N = A.size();
    rep(i, N) {
        cout << A[i];
        if (i == N - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}
