#include "../macros.hpp"

// インタラクティブ用
ll ask(ll i) {
    ll res;
    cout << "? " << i+1 << endl;
    cin >> res;
    res--;
    return res;
}

void answer(ll i) {
    cout << "! " << i+1 << endl;
}

void answer(const vector<ll>& A) {
    int N = A.size();
    rep(i, N) {
        cout << A[i];
        if (i == N-1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}
