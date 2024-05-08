#pragma once
#include "../common/bisect.hpp"
#include "../macros.hpp"

// 座標圧縮(二分探索ベース)
template<typename T>
struct Compress {
    int N;
    vector<T> dat;
    bool built = false;

    Compress() {}

    Compress(const vector<T> &A) : dat(A) {
        build();
    }

    void build() {
        sort(dat.begin(), dat.end());
        dat.erase(unique(dat.begin(), dat.end()), dat.end());
        N = dat.size();
        built = true;
    }

    void add(T x) {
        assert(not built);
        dat.eb(x);
    }

    // 可変長引数、cp.add(l, r); とかできる
    template<typename... Ts>
    void add(const T val, Ts... ts) {
        dat.eb(val);
        if constexpr (sizeof...(Ts) > 0) {
            add(ts...);
        }
    }

    void add(const vector<T> &A) {
        for (auto a : A) {
            add(a);
        }
    }

    int zip(T x) {
        assert(built);
        return bisect_left(dat, x);
    }

    T unzip(int x) {
        assert(built);
        return dat[x];
    }

    int operator[](T x) {
        return zip(x);
    }

    int size() {
        assert(built);
        return dat.size();
    }

    // 座圧後の位置[i,i+1)の座圧前の大きさを返す
    T size(int i) {
        assert(built and 0 <= i and i < N);
        if (i == N - 1) {
            return 1;
        } else {
            return unzip(i + 1) - unzip(i);
        }
    }

    vector<ll> zip(const vector<T> &A) {
        int M = A.size();
        vector<ll> res(M);
        rep(i, M) res[i] = zip(A[i]);
        return res;
    }
};

// 座標圧縮(mapベース)(旧)
// template<typename T>
// pair<map<T, int>, vector<T>> compress(vector<T> unzipped) {
//     map<T, int> zipped;
//     sort(unzipped.begin(), unzipped.end());
//     unzipped.erase(unique(unzipped.begin(), unzipped.end()), unzipped.end());
//     rep(i, unzipped.size()) {
//         zipped[unzipped[i]] = i;
//     }
//     return {zipped, unzipped};
// }
