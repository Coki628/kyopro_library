#include "../macros.hpp"
#include "LazySegmentTree.hpp"

// 参考：https://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp
// 遅延評価セグメント木(等差数列用)
template<typename F, typename G, typename H, typename Monoid, typename OperatorMonoid>
struct LazySegmentTreeArithmetric : LazySegmentTree<F, G, H, Monoid, OperatorMonoid> {
    using LazySegmentTreeType = LazySegmentTree<F, G, H, Monoid, OperatorMonoid>;
    using LazySegmentTreeType::LazySegmentTree;

    void update(int l, int r, const OperatorMonoid& func) {
        LazySegmentTreeType::update(
            l, r, { func.a, func.b - func.a * LazySegmentTreeType::get(l).left }
        );
    }

    void update(int i, const OperatorMonoid& func) {
        LazySegmentTreeType::update(
            i, { func.a, func.b - func.a * LazySegmentTreeType::get(i).left }
        );
    }
};

template<typename F, typename G, typename H, typename T, typename E>
LazySegmentTreeArithmetric<F, G, H, T, E> get_lazy_segment_tree_arithmetric(
    const F& f,
    const G& g,
    const H& h,
    const T& ti,
    const E& ei
) {
    return {f, g, h, ti, ei};
}

template<typename F, typename G, typename H, typename T, typename E>
LazySegmentTreeArithmetric<F, G, H, T, E> get_lazy_segment_tree_arithmetric(
    int N,
    const F& f,
    const G& g,
    const H& h,
    const T& ti,
    const E& ei
) {
    return {N, f, g, h, ti, ei};
}
