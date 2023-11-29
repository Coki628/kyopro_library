#include "../base.hpp"

// 配列の連結
template<typename T, typename... Ts>
vector<T> concat(const vector<T>& A, const vector<T>& B, Ts... args) {
    vector<T> res = A;
    res.insert(res.end(), B.begin(), B.end());
    if constexpr (sizeof...(Ts) == 0) {
        return res;
    } else {
        return concat(res, args...);
    }
}
