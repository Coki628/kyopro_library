#include "../base.hpp"
#include "../common/print.hpp"

template<typename _Key>
struct my_multiset : multiset<_Key> {
    using multiset<_Key>::multiset;
    _Key front() {
        assert(this->size());
        return *this->begin();
    }
    _Key pop_front() {
        _Key res = this->front();
        // 空の時にこの操作をやると提出ビルドだとREじゃなくてTLEになる…。
        this->erase(this->begin());
        return res;
    }
    _Key back() {
        assert(this->size());
        return *this->rbegin();
    }
    _Key pop_back() {
        _Key res = this->back();
        this->erase(prev(this->end()));
        return res;
    }
    // countがO(個数)との話があるため念のため作っておく
    bool exist(_Key x) {
        return this->find(x) != this->end();
    }
};

template<typename T>
void print(const my_multiset<T> &se) {
    vector<T> V(se.begin(), se.end());
    print(V);
}
