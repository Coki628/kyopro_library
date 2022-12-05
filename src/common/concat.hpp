#include "../base.hpp"

template<typename T>
vector<T> concat(const vector<T>& A, const vector<T>& B) {
    vector<T> res = A;
    res.insert(res.end(), B.begin(), B.end());
    return res;
}
