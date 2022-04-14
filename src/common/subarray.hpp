#include "../base.hpp"

template<typename T>
vector<T> subarray(const vector<T>& A, int l, int r) {
    return vector<T>(A.begin()+l, A.begin()+r);
}
