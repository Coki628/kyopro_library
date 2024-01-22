#pragma once
#include "../base.hpp"
#include "../common/print.hpp"

template<typename _Key>
struct Multiset : multiset<_Key> {
    using multiset<_Key>::multiset;
    _Key front() {
        assert(this->size());
        return *this->begin();
    }
    _Key pop_front() {
        _Key res = this->front();
        // 空の時にこの操作をやると提出ビルドだとREじゃなくてTLEになる…。
        multiset<_Key>::erase(this->begin());
        return res;
    }
    _Key back() {
        assert(this->size());
        return *this->rbegin();
    }
    _Key pop_back() {
        _Key res = this->back();
        multiset<_Key>::erase(prev(this->end()));
        return res;
    }
    // countがO(個数)との話があるため念のため作っておく
    bool exist(_Key x) {
        return this->find(x) != this->end();
    }
    // 1個削除
    auto erase(_Key x) {
        auto itr = this->find(x);
        assert(itr != this->end());
        return multiset<_Key>::erase(itr);
    }
};

template<typename T>
void print(const Multiset<T> &se) {
    vector<T> V(se.begin(), se.end());
    print(V);
}
