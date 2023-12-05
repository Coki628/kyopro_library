#pragma once
#include "../base.hpp"

// ロリハ
// see: https://ei1333.github.io/library/string/rolling-hash.hpp
struct RollingHash {
    static const ull mod = (1ull << 61ull) - 1;
    using uint128_t = __uint128_t;
    vector<ull> power;
    const ull base;

    static inline ull add(ull a, ull b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline ull sub(ull a, ull b) {
        return add(a, mod - b);
    }

    static inline ull mul(ull a, ull b) {
        uint128_t c = (uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    // 2^61-1以下の乱数を返す。これをbaseとするとHackされにくい
    static inline ull generate_base() {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ull> rand(1, RollingHash::mod - 1);
        return rand(mt);
    }

    inline void expand(size_t sz) {
        if (power.size() < sz + 1) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for (int i = pre_sz - 1; i < sz; i++) {
                power[i + 1] = mul(power[i], base);
            }
        }
    }

    // 基数baseのローリングハッシュを構築する
    explicit RollingHash(ull base = generate_base()) : base(base), power{1} {}

    // 文字列sのハッシュテーブルを返す：O(n)
    vector<ull> build(const string &s) const {
        int sz = s.size();
        vector<ull> table(sz + 1);
        for (int i = 0; i < sz; i++) {
            table[i + 1] = add(mul(table[i], base), s[i]);
        }
        return table;
    }

    template<typename T>
    vector<ull> build(const vector<T> &s) const {
        int sz = s.size();
        vector<ull> table(sz + 1);
        for (int i = 0; i < sz; i++) {
            table[i + 1] = add(mul(table[i], base), s[i]);
        }
        return table;
    }

    // tableの区間[l,r)のハッシュ値を返す：O(1)
    ull query(const vector<ull> &table, int l, int r) {
        expand(r - l);
        return sub(table[r], mul(table[l], power[r - l]));
    }

    // ハッシュ値h1と長さh2lenのハッシュ値h2を結合する
    ull combine(ull h1, ull h2, size_t h2len) {
        expand(h2len);
        return add(mul(h1, power[h2len]), h2);
    }

    // ハッシュテーブルaの区間[l1,r1)と、ハッシュテーブルbの区間[l2,r2)の文字列の最長共通接頭辞の長さを返す：O(logn)
    int lcp(
        const vector<ull> &a, int l1, int r1,
        const vector<ull> &b, int l2, int r2
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

    ull get_hash(const string &s, int l, int r) {
        auto table = build(s);
        return query(table, l, r);
    }

    template<typename T>
    ull get_hash(const vector<T> &s, int l, int r) {
        auto table = build(s);
        return query(table, l, r);
    }

    ull get_hash(const string &s) {
        auto table = build(s);
        return query(table, 0, s.size());
    }

    template<typename T>
    ull get_hash(const vector<T> &s) {
        auto table = build(s);
        return query(table, 0, s.size());
    }

    // 長さlenの文字列のhashのx文字目(0-indexed)をaからbに変える
    template<typename T>
    ull update(ull &hash, int len, int x, T a, T b) {
        return hash = add(hash, mul(sub(b, a), power[len - x - 1]));
    }

    // テーブルaの区間[l,r)の回文判定(aを反転させたテーブルrevも渡す)
    bool is_palindrome(
        const vector<ull> &a, const vector<ull> &rev, int l, int r
    ) {
        int n = (int)a.size() - 1;
        assert(r <= n);
        int len = r - l;
        int sl = len % 2 == 0 ? l + len / 2 : l + len / 2 + 1;
        int sr = r;
        int tl = n - (l + len / 2);
        int tr = n - l;
        return query(a, sl, sr) == query(rev, tl, tr);
    }
};
