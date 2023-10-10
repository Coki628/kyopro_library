#include "../base.hpp"

template<typename _Tp, typename _Sequence=vector<_Tp>, typename _Compare=less<typename _Sequence::value_type>>
struct PriorityQueue : priority_queue<_Tp, _Sequence, _Compare> {
    using priority_queue<_Tp, _Sequence, _Compare>::priority_queue;
    _Tp pop() {
        _Tp res = this->top();
        priority_queue<_Tp, _Sequence, _Compare>::pop();
        return res;
    }
};
