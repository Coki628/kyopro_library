#pragma once
#include "../base.hpp"
#include "bit_vector.hpp"
#include <immintrin.h>

// 重み付きWavelet Matrix
// see: https://drken1215.hatenablog.com/entry/2023/10/20/020039
// ・(x,y)への点に重みvalを付けられる。
template<typename T, typename U>
struct WeightedWaveletMatrix {
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;

    int n, lg;
    vector<T> a;
    vector<U> dat;
    vector<bit_vector> bv;
    vector<vector<U>> sum;

    WeightedWaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n), dat(n) {}

    WeightedWaveletMatrix(const vector<T> &_a, const vector<U> &_dat)
        : n(_a.size()),
          a(_a),
          dat(_dat) {
        build();
    }

    __attribute__((optimize("O3"))) void build() {
        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;
        bv.assign(lg, n);
        sum.assign(lg + 1, vector<U>(n + 1, (U)0));
        vector<int> l(n), r(n), ord(n);
        iota(begin(ord), end(ord), 0);
        for (int h = lg - 1; h >= 0; --h) {
            int left = 0, right = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[ord[i]] >> h) & 1) {
                    bv[h].set(i);
                    r[right++] = ord[i];
                } else {
                    l[left++] = ord[i];
                }
            }
            bv[h].build();
            swap(ord, l);
            for (int i = 0; i < right; i++) {
                ord[left + i] = r[i];
            }
            for (int i = 0; i < n; i++) {
                sum[h][i + 1] = sum[h][i] + dat[ord[i]];
            }
        }
        // 全体の累積和を持っておく
        for (int i = 0; i < n; i++) {
            sum[lg][i + 1] = sum[lg][i] + dat[i];
        }
        return;
    }

    // 位置(x,y)に重さvalの点をセットする
    // (xは重複できないので、idとペアで座圧するなどで対応する)
    void set(u32 x, const T &y, const U &val) {
        assert(x >= 0 && y >= 0);
        a[x] = y;
        dat[x] = val;
    }

    inline pair<u32, u32> succ0(int l, int r, int h) const {
        return make_pair(bv[h].rank0(l), bv[h].rank0(r));
    }

    inline pair<u32, u32> succ1(int l, int r, int h) const {
        u32 l0 = bv[h].rank0(l);
        u32 r0 = bv[h].rank0(r);
        u32 zeros = bv[h].zeros;
        return make_pair(l + zeros - l0, r + zeros - r0);
    }

    // return a[k]
    T access(u32 k) const {
        T ret = 0;
        for (int h = lg - 1; h >= 0; --h) {
            u32 f = bv[h].get(k);
            ret |= f ? T(1) << h : 0;
            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
        }
        return ret;
    }

    // k-th (0-indexed) smallest number in a[l, r)
    T kth_smallest(u32 l, u32 r, u32 k) const {
        T res = 0;
        for (int h = lg - 1; h >= 0; --h) {
            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (k < r0 - l0) l = l0, r = r0;
            else {
                k -= r0 - l0;
                res |= (T)1 << h;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            }
        }
        return res;
    }

    // k-th (0-indexed) largest number in a[l, r)
    T kth_largest(int l, int r, int k) {
        return kth_smallest(l, r, r - l - k - 1);
    }

    // 参考：https://twitter.com/US_kyopro/status/1601792850886242304
    // 　　　https://atcoder.jp/contests/abc281/submissions/37200871
    // sum of [0,k)th smallest elements([l, r))
    T kth_smallest_sum(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k <= r - l);
        T res = 0;
        for (int h = lg - 1; h >= 0; h--) {
            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (k < r0 - l0) {
                l = l0, r = r0;
            } else {
                k -= r0 - l0;
                res += sum[h][r0] - sum[h][l0];
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            }
        }
        if (k) res += sum[0][l + k] - sum[0][l];
        return res;
    }

    // sum of [0,k)th largest elements([l, r))
    T kth_largest_sum(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k <= r - l);
        return kth_smallest_sum(l, r, r - l) -
               kth_smallest_sum(l, r, r - l - k);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
        if (upper >= (T(1) << lg)) return r - l;
        int ret = 0;
        for (int h = lg - 1; h >= 0; --h) {
            bool f = (upper >> h) & 1;
            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (f) {
                ret += r0 - l0;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }

    T range_freq_sum(int l, int r, T upper) {
        if (upper >= (T(1) << lg)) return sum[lg][r] - sum[lg][l];
        T ret = 0;
        for (int h = lg - 1; h >= 0; --h) {
            bool f = (upper >> h) & 1;
            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (f) {
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
                ret += sum[h][r0] - sum[h][l0];
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }

    // l <= x < r and lower <= y < upper な要素の個数
    int range_freq(int l, int r, T lower, T upper) {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // l <= x < r and lower <= y < upper な要素の総和
    T range_freq_sum(int l, int r, T lower, T upper) {
        return range_freq_sum(l, r, upper) - range_freq_sum(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
        int cnt = range_freq(l, r, upper);
        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
        int cnt = range_freq(l, r, lower);
        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
};