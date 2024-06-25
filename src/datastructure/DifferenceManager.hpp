#pragma once
#include "../macros.hpp"

// 差分列管理
// ・こどふぉでたまに出るmultisetでこねこねするだるいやつ。
// 仕様説明
// ・現在の要素を表す集合と、それらの(ソート済だとして)隣接との差分列の集合を管理する。
// ・上記に対する、要素追加・要素削除・最大値取得・最小値取得ができる。
// ・中身はmultisetなので、作ってないけど個数とかも取れると思う。
// ・遅くならなかったので抽象化した。これで差分XORとか差分GCDとかでもできる。
// ・元の列と差分列で違うデータ形式(T1とT2)を持てるようにした。(使用例：past202309_l)
template<typename T1, typename T2, typename F>
struct DifferenceManager {
    // se1: 現在の要素を表す集合
    // se2: 現在の差分列の要素を表す集合
    multiset<T1> se1;
    multiset<T2> se2;

    const F f;

    DifferenceManager(const vector<T1> &A, const F &f) : se1(ALL(A)), f(f) {
        build();
    }

    void build() {
        auto itr = se1.begin();
        while (itr != se1.end() and itr != --se1.end()) {
            se2.insert(f(*next(itr), *itr));
            itr++;
        }
    }

    bool exist(T1 x) {
        return se1.find(x) != se1.end();
    }

    void insert(T1 x) {
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

    void erase(T1 x) {
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

    T1 max_val() {
        assert(size() >= 1);
        return *--se1.end();
    }

    T1 min_val() {
        assert(size() >= 1);
        return *se1.begin();
    }

    T2 max_diff() {
        assert(size() >= 2);
        return *--se2.end();
    }

    T2 min_diff() {
        assert(size() >= 2);
        return *se2.begin();
    }
};

template<typename T, typename F>
DifferenceManager<T, T, F> get_difference_manager(const vector<T> &A, const F &f) {
    return {A, f};
}

template<typename T>
auto get_difference_manager(const vector<T> &A) {
    // 基本はこれを渡す
    const auto f = [](T a, T b) { return a - b; };
    return DifferenceManager<T, T, decltype(f)>(A, f);
}
