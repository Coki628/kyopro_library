#pragma once
#include "../macros.hpp"

// 差分列管理
// ・こどふぉでたまに出るmultisetでこねこねするだるいやつ。
// 仕様説明
// ・現在の要素を表す集合と、それらの(ソート済だとして)隣接との差分列の集合を管理する。
// ・上記に対する、要素追加・要素削除・最大値取得・最小値取得ができる。
// ・中身はmultisetなので、作ってないけど個数とかも取れると思う。
// ・遅くならなかったので抽象化した。これで差分XORとか差分GCDとかでもできる。
template<typename T, typename F>
struct DifferenceManager {
    // se1: 現在の要素を表す集合
    // se2: 現在の差分列の要素を表す集合
    multiset<T> se1, se2;

    const F f;

    DifferenceManager(const vector<T> &A, const F &f) : se1(ALL(A)), f(f) {
        build();
    }

    void build() {
        auto itr = se1.begin();
        while (itr != se1.end() and itr != --se1.end()) {
            se2.insert(f(*next(itr), *itr));
            itr++;
        }
    }

    void insert(T x) {
        auto itr = se1.insert(x);
        if (itr != se1.begin() and itr != --se1.end()) {
            se2.erase(se2.find(f(*next(itr), *prev(itr))));
        }
        if (itr != se1.begin()) {
            se2.insert(f(*itr, *prev(itr)));
        }
        if (itr != --se1.end()) {
            se2.insert(f(*next(itr), *itr));
        }
    }

    void erase(T x) {
        auto itr = se1.find(x);
        assert(itr != se1.end());
        if (itr != se1.begin()) {
            se2.erase(se2.find(f(*itr, *prev(itr))));
        }
        if (itr != --se1.end()) {
            se2.erase(se2.find(f(*next(itr), *itr)));
        }
        if (itr != se1.begin() and itr != --se1.end()) {
            se2.insert(f(*next(itr), *prev(itr)));
        }
        se1.erase(itr);
    }

    int size() {
        return se1.size();
    }

    T max_val() {
        assert(size() >= 1);
        return *--se1.end();
    }

    T min_val() {
        assert(size() >= 1);
        return *se1.begin();
    }

    T max_diff() {
        assert(size() >= 2);
        return *--se2.end();
    }

    T min_diff() {
        assert(size() >= 2);
        return *se2.begin();
    }
};

template<typename T, typename F>
DifferenceManager<T, F> get_difference_manager(const vector<T> &A, const F &f) {
    return {A, f};
}

template<typename T>
auto get_difference_manager(const vector<T> &A) {
    // 基本はこれを渡す
    const auto f = [](T a, T b) { return a - b; };
    return DifferenceManager<T, decltype(f)>(A, f);
}
