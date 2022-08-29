#include "../macros.hpp"
#include "HashMap.hpp"

template<typename T>
HashMap<T, ll> Counter(const vector<T> &A) {
    HashMap<T, ll> res;
    for (T a : A) {
        res[a]++;
    }
    return res;
}

template<typename T>
vector<ll> Counter(const vector<T> &A, int mx) {
    vector<ll> res(mx+1);
    for (T a : A) {
        res[a]++;
    }
    return res;
}

HashMap<char, ll> Counter(const string &S) {
    HashMap<char, ll> res;
    for (char c : S) {
        res[c]++;
    }
    return res;
}

template<typename T>
vector<pair<ll, T>> most_common(const HashMap<T, ll>& C) {
    vector<pair<ll, T>> res;
    for (auto [k, v] : C) {
        res.eb(v, k);
    }
    sort(res.rbegin(), res.rend());
    return res;
}
