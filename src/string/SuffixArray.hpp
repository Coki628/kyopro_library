#pragma once
#include "../acl/string.hpp"
#include "../datastructure/SegmentTree.hpp"
#include "../datastructure/SparseTable.hpp"
#include "../macros.hpp"

struct SuffixArray {
    int N;
    string S;
    bool use_seg;
    vector<int> sa, rsa, lcp;
    static int f(int a, int b) {
        return min(a, b);
    }
    // クラス内関数へのdecltype
    // see: https://stackoverflow.com/questions/52520276/is-decltype-of-a-non-static-member-function-ill-formed
    SegmentTree<int, decltype(&f)> seg = get_segment_tree(&f, MOD);

    SuffixArray(string S, bool use_seg = true)
        : S(S),
          N(S.size()),
          use_seg(use_seg) {
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
