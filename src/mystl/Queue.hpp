#include "../base.hpp"

template<typename _Tp>
struct Queue : queue<_Tp> {
    using queue<_Tp>::queue;
    _Tp pop() {
        _Tp res = this->front();
        queue<_Tp>::pop();
        return res;
    }
};
