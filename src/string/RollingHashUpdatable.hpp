#pragma once
#include "../base.hpp"
#include "../common/pow.hpp"
#include "../datastructure/AbstractBIT.hpp"
#include "RollingHash.hpp"

// 更新ありロリハ
// ・vectorで持っていたテーブルをBITで持つことで1点更新を可能にしている。
// ・累積の値を調整するために基数冪での除算が必要になり、前計算の逆元を用意した。
struct RollingHashUpdatable : public RollingHash {
    using RollingHash::RollingHash;
    using HashTable = AbstractBIT<ull, decltype(&add), decltype(&sub)>;

    vector<ull> pinv = {1};

    inline void expand(size_t sz) {
        RollingHash::expand(sz);
        // query時に使うpower逆元の前計算
        if (pinv.size() < sz + 1) {
            int pre_sz = (int)pinv.size();
            pinv.resize(sz + 1);
            // powはそのままやるとオーバーフローする
            pinv[sz] = pow((uint128_t)power[sz], mod - 2, mod);
            for (int i = sz - 1; i >= pre_sz; i--) {
                pinv[i] = mul(pinv[i + 1], base);
            }
        }
    }

    // 文字列sのハッシュテーブルを返す：O(nlogn)
    HashTable build(const string &s) {
        int sz = s.size();
        expand(sz);
        HashTable table(sz, &add, &sub);
        for (int i = 0; i < sz; i++) {
            table.add(i, mul(power[sz - i - 1], s[i]));
        }
        return table;
    }

    template<typename T>
    HashTable build(const vector<T> &s) {
        int sz = s.size();
        expand(sz);
        HashTable table(sz, &add, &sub);
        for (int i = 0; i < sz; i++) {
            table.add(i, mul(power[sz - i - 1], s[i]));
        }
        return table;
    }

    // tableの区間[l,r)のハッシュ値を返す：O(logn)
    ull query(HashTable &table, int l, int r) {
        expand(r - l);
        int sz = table.size();
        expand(abs(sz - r - l));
        return mul(table.query(l, r), pinv[sz - r]);
    }

    // 構築済ハッシュテーブルtableのi文字目をcに変える：O(logn)
    template<typename T>
    void update(HashTable &table, int i, T c) {
        int sz = table.size();
        table.update(i, mul(power[sz - i - 1], c));
    }

    // ハッシュテーブルaの区間[l1,r1)と、ハッシュテーブルbの区間[l2,r2)の文字列の最長共通接頭辞の長さを返す：O(log2つ)
    int lcp(
        HashTable &a, int l1, int r1,
        HashTable &b, int l2, int r2
    ) {
        int len = min(r1 - l1, r2 - l2);
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }

    // テーブルaの区間[l,r)の回文判定(aを反転させたテーブルrevも渡す)
    bool is_palindrome(
        HashTable &a, HashTable &rev, int l, int r
    ) {
        int n = a.size();
        assert(r <= n);
        int len = r - l;
        int sl = len % 2 == 0 ? l + len / 2 : l + len / 2 + 1;
        int sr = r;
        int tl = n - (l + len / 2);
        int tr = n - l;
        return query(a, sl, sr) == query(rev, tl, tr);
    }
};
