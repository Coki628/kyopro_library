#include "../base.hpp"
#include "../common/print.hpp"

template<typename _Key>
struct Set : set<_Key> {
    using set<_Key>::set;
    _Key front() {
        assert(this->size());
        return *this->begin();
    }
    _Key pop_front() {
        _Key res = this->front();
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
};

template<typename T>
void print(const Set<T> &se) {
    vector<T> V(se.begin(), se.end());
    print(V);
}
