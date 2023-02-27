#include "../macros.hpp"
#include "../datastructure/SegmentTree.hpp"
#include "../acl/string.hpp"

auto f = [](int a, int b) { return min(a, b); };

struct SuffixArray {
    int N;
    string S;
    bool use_seg;
    vector<int> sa, rsa, lcp;
    SegmentTree<int, decltype(f)> seg = get_segment_tree(f, MOD);

    SuffixArray(string S, bool use_seg=true) : S(S), N(S.size()), use_seg(use_seg) {
        sa = atcoder::suffix_array(S);
        rsa.assign(N, 0);
        rep(i, N) {
            rsa[sa[i]] = i;
        }
        lcp = atcoder::lcp_array(S, sa);
        if (use_seg) {
            seg.build(lcp);
        }
    }

    // S[i]とS[j]のLCPを取得
    int get_lcp(int i, int j) {
        assert(use_seg);
        int l = rsa[i], r = rsa[j];
        if (l > r) swap(l, r);
        return seg.query(l, r);
    }
};
