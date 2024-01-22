---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/HashMap.hpp
    title: src/common/HashMap.hpp
  - icon: ':warning:'
    path: src/common/HashMapImpl.hpp
    title: src/common/HashMapImpl.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmax.hpp
    title: src/common/chmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':warning:'
    path: src/graph/HeavyLightDecomposition.hpp
    title: src/graph/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/mystl/Vector.hpp
    title: src/mystl/Vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/HashMapImpl.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://nyaannyaan.github.io/library/hashmap/hashmap-base.hpp\nnamespace\
    \ HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate<typename\
    \ Key, typename Data>\nstruct HashMapBase;\n\ntemplate<typename Key, typename\
    \ Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t,\
    \ Data *, Data &> {\n    using base =\n        iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data *, Data &>;\n    using ptr = typename base::pointer;\n\
    \    using ref = typename base::reference;\n\n    u32 i;\n    HashMapBase<Key,\
    \ Data> *p;\n\n    explicit constexpr itrB() : i(0), p(nullptr) {\n    }\n   \
    \ explicit constexpr itrB(u32 _i, HashMapBase<Key, Data> *_p) : i(_i), p(_p) {\n\
    \    }\n    explicit constexpr itrB(u32 _i, const HashMapBase<Key, Data> *_p)\n\
    \        : i(_i),\n          p(const_cast<HashMapBase<Key, Data> *>(_p)) {\n \
    \   }\n    friend void swap(itrB &l, itrB &r) {\n        swap(l.i, r.i), swap(l.p,\
    \ r.p);\n    }\n    friend bool operator==(const itrB &l, const itrB &r) {\n \
    \       return l.i == r.i;\n    }\n    friend bool operator!=(const itrB &l, const\
    \ itrB &r) {\n        return l.i != r.i;\n    }\n    const ref operator*() const\
    \ {\n        return const_cast<const HashMapBase<Key, Data> *>(p)->data[i];\n\
    \    }\n    ref operator*() {\n        return p->data[i];\n    }\n    ptr operator->()\
    \ const {\n        return &(p->data[i]);\n    }\n\n    itrB &operator++() {\n\
    \        assert(i != p->cap && \"itr::operator++()\");\n        do {\n       \
    \     i++;\n            if (i == p->cap) break;\n            if (p->flag[i] ==\
    \ true && p->dflag[i] == false) break;\n        } while (true);\n        return\
    \ (*this);\n    }\n    itrB operator++(int) {\n        itrB it(*this);\n     \
    \   ++(*this);\n        return it;\n    }\n    itrB &operator--() {\n        do\
    \ {\n            i--;\n            if (p->flag[i] == true && p->dflag[i] == false)\
    \ break;\n            assert(i != 0 && \"itr::operator--()\");\n        } while\
    \ (true);\n        return (*this);\n    }\n    itrB operator--(int) {\n      \
    \  itrB it(*this);\n        --(*this);\n        return it;\n    }\n};\n\ntemplate<typename\
    \ Key, typename Data>\nstruct HashMapBase {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n    using iterator = itrB<Key, Data>;\n    using itr = iterator;\n\
    \nprotected:\n    template<typename K>\n    inline u64 randomized(const K &key)\
    \ const {\n        return u64(key) ^ r;\n    }\n\n    template<\n        typename\
    \ K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n        enable_if_t<is_integral<K>::value,\
    \ nullptr_t> = nullptr>\n    inline u32 inner_hash(const K &key) const {\n   \
    \     return (randomized(key) * 11995408973635179863ULL) >> shift;\n    }\n  \
    \  template<\n        typename K, enable_if_t<is_same<K, Key>::value, nullptr_t>\
    \ = nullptr,\n        enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t>\
    \ =\n            nullptr,\n        enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> =\n            nullptr>\n    inline u32 inner_hash(const K &key)\
    \ const {\n        u64 a = randomized(key.first), b = randomized(key.second);\n\
    \        a *= 11995408973635179863ULL;\n        b *= 10150724397891781847ULL;\n\
    \        return (a + b) >> shift;\n    }\n    template<\n        typename K, enable_if_t<is_same<K,\
    \ Key>::value, nullptr_t> = nullptr,\n        enable_if_t<is_integral<typename\
    \ K::value_type>::value, nullptr_t> =\n            nullptr>\n    inline u32 inner_hash(const\
    \ K &key) const {\n        static constexpr u64 mod = (1LL << 61) - 1;\n     \
    \   static constexpr u64 base = 950699498548472943ULL;\n        u64 res = 0;\n\
    \        for (auto &elem : key) {\n            __uint128_t x = __uint128_t(res)\
    \ * base + (randomized(elem) & mod);\n            res = (x & mod) + (x >> 61);\n\
    \        }\n        __uint128_t x = __uint128_t(res) * base;\n        res = (x\
    \ & mod) + (x >> 61);\n        if (res >= mod) res -= mod;\n        return res\
    \ >> (shift - 3);\n    }\n\n    template<\n        typename D = Data,\n      \
    \  enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n    inline u32 hash(const\
    \ D &dat) const {\n        return inner_hash(dat);\n    }\n    template<\n   \
    \     typename D = Data,\n        enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> =\n            nullptr>\n    inline u32 hash(const D &dat) const\
    \ {\n        return inner_hash(dat.first);\n    }\n\n    template<\n        typename\
    \ D = Data,\n        enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n\
    \    inline Key dtok(const D &dat) const {\n        return dat;\n    }\n    template<\n\
    \        typename D = Data,\n        enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> =\n            nullptr>\n    inline Key dtok(const D &dat) const\
    \ {\n        return dat.first;\n    }\n\n    void reallocate(u32 ncap) {\n   \
    \     vector<Data> ndata(ncap);\n        vector<bool> nf(ncap);\n        shift\
    \ = 64 - __lg(ncap);\n        for (u32 i = 0; i < cap; i++) {\n            if\
    \ (flag[i] == true && dflag[i] == false) {\n                u32 h = hash(data[i]);\n\
    \                while (nf[h]) h = (h + 1) & (ncap - 1);\n                ndata[h]\
    \ = move(data[i]);\n                nf[h] = true;\n            }\n        }\n\
    \        data.swap(ndata);\n        flag.swap(nf);\n        cap = ncap;\n    \
    \    dflag.resize(cap);\n        fill(std::begin(dflag), std::end(dflag), false);\n\
    \    }\n\n    inline bool extend_rate(u32 x) const {\n        return x * 2 >=\
    \ cap;\n    }\n\n    inline bool shrink_rate(u32 x) const {\n        return HASHMAP_DEFAULT_SIZE\
    \ < cap && x * 10 <= cap;\n    }\n\n    inline void extend() {\n        reallocate(cap\
    \ << 1);\n    }\n\n    inline void shrink() {\n        reallocate(cap >> 1);\n\
    \    }\n\npublic:\n    u32 cap, s;\n    vector<Data> data;\n    vector<bool> flag,\
    \ dflag;\n    u32 shift;\n    static u64 r;\n    static constexpr uint32_t HASHMAP_DEFAULT_SIZE\
    \ = 4;\n\n    explicit HashMapBase()\n        : cap(HASHMAP_DEFAULT_SIZE),\n \
    \         s(0),\n          data(cap),\n          flag(cap),\n          dflag(cap),\n\
    \          shift(64 - __lg(cap)) {\n    }\n\n    itr begin() const {\n       \
    \ u32 h = 0;\n        while (h != cap) {\n            if (flag[h] == true && dflag[h]\
    \ == false) break;\n            h++;\n        }\n        return itr(h, this);\n\
    \    }\n    itr end() const {\n        return itr(this->cap, this);\n    }\n\n\
    \    friend itr begin(const HashMapBase &h) {\n        return h.begin();\n   \
    \ }\n    friend itr end(const HashMapBase &h) {\n        return h.end();\n   \
    \ }\n\n    itr find(const Key &key) const {\n        u32 h = inner_hash(key);\n\
    \        while (true) {\n            if (flag[h] == false) return this->end();\n\
    \            if (dtok(data[h]) == key) {\n                if (dflag[h] == true)\
    \ return this->end();\n                return itr(h, this);\n            }\n \
    \           h = (h + 1) & (cap - 1);\n        }\n    }\n\n    bool contain(const\
    \ Key &key) const {\n        return find(key) != this->end();\n    }\n\n    itr\
    \ insert(const Data &d) {\n        u32 h = hash(d);\n        while (true) {\n\
    \            if (flag[h] == false) {\n                if (extend_rate(s + 1))\
    \ {\n                    extend();\n                    h = hash(d);\n       \
    \             continue;\n                }\n                data[h] = d;\n   \
    \             flag[h] = true;\n                ++s;\n                return itr(h,\
    \ this);\n            }\n            if (dtok(data[h]) == dtok(d)) {\n       \
    \         if (dflag[h] == true) {\n                    data[h] = d;\n        \
    \            dflag[h] = false;\n                    ++s;\n                }\n\
    \                return itr(h, this);\n            }\n            h = (h + 1)\
    \ & (cap - 1);\n        }\n    }\n\n    // tips for speed up :\n    // if return\
    \ value is unnecessary, make argument_2 false.\n    itr erase(itr it, bool get_next\
    \ = true) {\n        if (it == this->end()) return this->end();\n        s--;\n\
    \        if (shrink_rate(s)) {\n            Data d = data[it.i];\n           \
    \ shrink();\n            it = find(dtok(d));\n        }\n        int ni = (it.i\
    \ + 1) & (cap - 1);\n        if (this->flag[ni]) {\n            this->dflag[it.i]\
    \ = true;\n        } else {\n            this->flag[it.i] = false;\n        }\n\
    \        if (get_next) ++it;\n        return it;\n    }\n\n    itr erase(const\
    \ Key &key) {\n        return erase(find(key));\n    }\n\n    bool empty() const\
    \ {\n        return s == 0;\n    }\n\n    int size() const {\n        return s;\n\
    \    }\n\n    void clear() {\n        fill(std::begin(flag), std::end(flag), false);\n\
    \        fill(std::begin(dflag), std::end(dflag), false);\n        s = 0;\n  \
    \  }\n\n    void reserve(int n) {\n        if (n <= 0) return;\n        n = 1\
    \ << min(23, __lg(n) + 2);\n        if (cap < u32(n)) reallocate(n);\n    }\n\
    };\n\ntemplate<typename Key, typename Data>\nuint64_t HashMapBase<Key, Data>::r\
    \ =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch()\n\
    \    ).count();\n\n} // namespace HashMapImpl\n#line 4 \"src/common/HashMap.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/hashmap/hashmap.hpp\n\
    // \u30FB\u3081\u3061\u3083\u901F\u3044\u3002\n// \u6CE8\u610F\u70B9\n// \u30FB\
    erase\u3057\u3066size\u53D6\u308B\u307F\u305F\u3044\u306A\u64CD\u4F5C\u3057\u3066\
    \u305F\u3089\u306A\u3093\u304B\u30ED\u30FC\u30AB\u30EB\u306F\u5927\u4E08\u592B\
    \u3060\u3051\u3069\n// \u3000\u30B3\u30FC\u30C9\u30C6\u30B9\u30C8\u3067\u6319\u52D5\
    \u304C\u4E00\u5B9A\u3067\u306A\u304F\u306A\u3063\u305F\u306E\u3067\u3001\u305D\
    \u308C\u3084\u308A\u305F\u3044\u6642\u306F\u5225\u5909\u6570\u3067size\u7BA1\u7406\
    \u3057\u305F\u65B9\u304C\u3044\u3044\u304B\u3082\u3002\n// \u30FB\u8272\u3005\u8A66\
    \u3057\u305F\u611F\u3058\u3001\u305D\u3082\u305D\u3082erase\u3084\u308B\u3053\u3068\
    \u304C\u975E\u63A8\u5968\u3068\u8003\u3048\u305F\u65B9\u304C\u826F\u3055\u305D\
    \u3046\u3002\n// \u30FBHashMap<int, mint>\u307F\u305F\u3044\u306E\u3067 += \u3084\
    \u308B\u6642\u306B\u3001\u8DB3\u3055\u308C\u308B\u5074\u306E\u6DFB\u5B57\u30A2\
    \u30AF\u30BB\u30B9\u3067extend\u304C\u8D70\u308B\u3068\u3001\n// \u3000\u8981\u7D20\
    \u306E\u4F4D\u7F6E\u304C\u5909\u308F\u3063\u3066\u3057\u307E\u3046\u305F\u3081\
    \u3001\u5148\u306B\u8A55\u4FA1\u3055\u308C\u3066\u65E2\u306B\u8FD4\u3057\u3066\
    \u3044\u308B\u8DB3\u3059\u5074\u306E\u53C2\u7167\u304C\u58CA\u308C\u308B\u3063\
    \u307D\u3044\u3002\n// \u3000\u306A\u3093\u304Bint\u3060\u3068\u5927\u4E08\u592B\
    \u3063\u307D\u3044\u306E\u3067\u3001mint\u307F\u305F\u3044\u306B\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3060\u3068\u30C0\u30E1\u306A\u3093\u304B\u306A\u591A\u5206\
    \u3002\n// \u30FBDP\u306E2\u6B21\u5143\u76EE\u306B\u4F7F\u3063\u305F\u3089\u3001\
    \u30E1\u30E2\u30EA\u3092\u98DF\u3046\u3068\u7D50\u69CB\u91CD\u304F\u306A\u308B\
    \u3088\u3046\u3060\u3063\u305F\u306E\u3067\u3001\n// \u3000\u914D\u5217\u7BC0\u7D04\
    \u30C6\u30AF\u306F\u4F7F\u3063\u305F\u65B9\u304C\u826F\u3055\u3052\u3002\ntemplate<typename\
    \ Key, typename Val>\nstruct HashMap : HashMapImpl::HashMapBase<Key, pair<Key,\
    \ Val>> {\n    using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n\
    \    using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;\n    using\
    \ Data = pair<Key, Val>;\n\n    Val &operator[](const Key &k) {\n        typename\
    \ base::u32 h = base::inner_hash(k);\n        while (true) {\n            if (base::flag[h]\
    \ == false) {\n                if (base::extend_rate(base::s + 1)) {\n       \
    \             base::extend();\n                    h = base::hash(k);\n      \
    \              continue;\n                }\n                base::data[h].first\
    \ = k;\n                base::data[h].second = Val();\n                base::flag[h]\
    \ = true;\n                ++base::s;\n                return base::data[h].second;\n\
    \            }\n            if (base::data[h].first == k) {\n                if\
    \ (base::dflag[h] == true) base::data[h].second = Val();\n                return\
    \ base::data[h].second;\n            }\n            h = (h + 1) & (base::cap -\
    \ 1);\n        }\n    }\n\n    typename base::itr emplace(const Key &key, const\
    \ Val &val) {\n        return base::insert(Data(key, val));\n    }\n\n    bool\
    \ count(const Key &k) {\n        return this->contain(k);\n    }\n};\n#line 3\
    \ \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing pll = pair<ll, ll>;\nusing pii = pair<int, int>;\n\
    using pli = pair<ll, int>;\nusing pil = pair<int, ll>;\ntemplate<typename T>\n\
    using vv = vector<vector<T>>;\nusing vvl = vv<ll>;\nusing vvi = vv<int>;\nusing\
    \ vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil = vv<pil>;\n#define name4(i,\
    \ a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2,\
    \ rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i < _aa; i++)\n\
    #define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define rep3(i, a,\
    \ b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a >=\
    \ i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mkp make_pair\n#define ALL(A)\
    \ begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)), A.end())\n\
    #define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n    constexpr\
    \ ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr ld EPS =\
    \ 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/chmax.hpp\"\
    \n\ntemplate<typename T>\nbool chmax(T &x, T y) {\n    return (y > x) ? x = y,\
    \ true : false;\n}\n#line 4 \"src/common/print.hpp\"\n\n// \u203B\u5185\u5074\u3067\
    \u547C\u3070\u308C\u305D\u3046\u306A\u3082\u306E\u307B\u3069\u4E0A\u306B\u66F8\
    \u3044\u3066\u304A\u304F\u3002\n\n// pair\ntemplate<typename T1, typename T2>\n\
    ostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n    return os << p.first\
    \ << ' ' << p.second;\n}\n\n// tuple\n// see: https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150\n\
    template<class T, size_t... Is>\nvoid print_tuple(ostream &os, const T &arg, index_sequence<Is...>)\
    \ {\n    static_cast<void>(((os << (Is == 0 ? \"\" : \" \"), os << get<Is>(arg)),\
    \ ...));\n}\ntemplate<class... Ts>\nostream &operator<<(ostream &os, const tuple<Ts...>\
    \ &arg) {\n    print_tuple(os, arg, make_index_sequence<sizeof...(Ts)>());\n \
    \   return os;\n}\n\n// \u65E7\u4ED5\u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\
    \u308B\u7A0B\u5EA6\u52D5\u4F5C\u554F\u984C\u306A\u3044\u78BA\u8A8D\u304C\u53D6\
    \u308C\u305F\u3089\u524A\u9664\n// template<typename T1, typename T2, typename\
    \ T3>\n// ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {\n//\
    \     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n// }\n\
    // template<typename T1, typename T2, typename T3, typename T4>\n// ostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n//     return os << get<0>(tp) << '\
    \ ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n// }\n// template<typename\
    \ T1, typename T2, typename T3>\n// void print(const tuple<T1, T2, T3> &tp) {\n\
    //     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\\n';\n\
    // }\n// template<typename T1, typename T2, typename T3, typename T4>\n// void\
    \ print(const tuple<T1, T2, T3, T4> &tp) {\n//     cout << get<0>(tp) << ' ' <<\
    \ get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n// }\n\n// array\n\
    template<typename T, size_t N>\nostream &operator<<(ostream &os, const array<T,\
    \ N> &arr) {\n    rep(i, N) {\n        os << arr[i];\n        if (i != (int)N\
    \ - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, string sep = \" \") {\n   \
    \ rep(i, N) {\n        cout << arr[i];\n        if (i != (int)N - 1) cout << sep;\n\
    \    }\n    cout << '\\n';\n}\n\n// vector\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &vec) {\n    rep(i, vec.size()) {\n        os << vec[i];\n\
    \        if (i != (int)vec.size() - 1) {\n            os << ' ';\n        }\n\
    \    }\n    return os;\n}\ntemplate<typename T>\nvoid print(const vector<T> &vec,\
    \ string sep = \" \") {\n    rep(i, vec.size()) {\n        cout << vec[i];\n \
    \       if (i != (int)vec.size() - 1) cout << sep;\n    }\n    cout << '\\n';\n\
    }\n\n// deque\ntemplate<typename T>\nvoid print(const deque<T> &que, string sep\
    \ = \" \") {\n    vector<T> vec(ALL(que));\n    print(vec, sep);\n}\n\n// set\n\
    template<typename T>\nvoid print(const set<T> &se, string sep = \" \") {\n   \
    \ vector<T> vec(ALL(se));\n    print(vec, sep);\n}\n\n// set, multiset, deque,\
    \ etc...\n// \u203B\u3068\u3066\u3082\u6C4E\u7528\u6027\u9AD8\u3044\u3093\u3060\
    \u3051\u3069\u3001string\u307E\u3067\u53D6\u308A\u8FBC\u307E\u308C\u3066vector\u306B\
    \u3055\u308C\u3066\u3057\u307E\u3046\u306E\u3067\u4F7F\u308F\u306A\u3044\n// template<template<typename\
    \ T>class Container, typename T>\n// void print(const Container<T>& con, string\
    \ sep=\" \") {\n//     vector<T> V(ALL(con));\n//     print(V, sep);\n// }\n\n\
    // initializer_list (\u300Cprint({1, 2, 3, 4});\u300D\u3068\u304B\u3067\u304D\u308B\
    )\ntemplate<typename T>\nvoid print(const initializer_list<T> &li, string sep\
    \ = \" \") {\n    vector<T> V(ALL(li));\n    print(V, sep);\n}\n\n// \u53EF\u5909\
    \u9577\u5F15\u6570\u3002operator<<\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3055\u3048\
    \u3044\u308C\u3070\u3001\u578B\u304C\u9055\u3046\u540C\u58EB\u3067\u3082\u96D1\
    \u591A\u306B\u4E26\u3079\u3066\u51FA\u529B\u3067\u304D\u308B\n// \u203Bprint(vector,\
    \ \"\\n\")\u3068\u304B\u3082\u3053\u3053\u306B\u6765\u3066\u3057\u307E\u3063\u305F\
    \u306E\u3067\u4E00\u65E6\u4E2D\u6B62\n// template<typename T, typename... Ts>\n\
    // void print(const T val, Ts... ts) {\n//     if constexpr (sizeof...(Ts) ==\
    \ 0) {\n//         cout << val << '\\n';\n//     } else {\n//         cout <<\
    \ val << ' ';\n//         print(ts...);\n//     }\n// }\n\n// \u6539\u884C\u306E\
    \u307F\nvoid print() {\n    cout << '\\n';\n}\n\n// \u305D\u306E\u4ED6 (pair,tuple,string\u7B49\
    \u3082\u3053\u3053\u306B\u6765\u3066operator<<\u306B\u6E21\u3055\u308C\u308B)\n\
    template<typename T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\n//\
    \ debug (\u5909\u6570\u540D\u4ED8\u304D\u3067\u51FA\u529B\u3001stderr\u306A\u306E\
    \u3067\u63D0\u51FA\u3092\u90AA\u9B54\u3057\u306A\u3044)\n// #define debug(x) (cerr\
    \ << #x << \": \" << x << endl);\n// \u53EF\u5909\u9577\u5F15\u6570\u5BFE\u5FDC\
    \u7248\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n#define debug(...)\
    \ multi_debug(#__VA_ARGS__, __VA_ARGS__)\n\n// \u30B0\u30EA\u30C3\u30C9\u3060\u3051\
    \u898B\u3084\u3059\u304F\u306A\u308B\u3088\u3046\u306B\u3061\u3087\u3063\u3068\
    \u500B\u5225\u5BFE\u5FDC\ntemplate<typename T>\nvoid multi_debug(string name,\
    \ const vv<T> &grid) {\n    cerr << name << \":\" << endl;\n    int H = grid.size();\n\
    \    int W = grid[0].size();\n    // \u5217\u6BCE\u306B\u6700\u5927\u5E45\u3092\
    \u53D6\u3063\u3066\u304A\u304F\n    vector<int> mxlen(W);\n    rep(h, H) {\n \
    \       rep(w, W) {\n            chmax(mxlen[w], (int)tostr(grid[h][w]).size());\n\
    \        }\n    }\n    rep(h, H) {\n        rep(w, W) {\n            int pad =\
    \ mxlen[w] - (int)tostr(grid[h][w]).size();\n            cerr << string(pad, '\
    \ ') << grid[h][w];\n            if (w == W - 1) {\n                cerr << endl;\n\
    \            } else {\n                cerr << ' ';\n            }\n        }\n\
    \    }\n}\n\ntemplate<class Tp, class... Ts>\nvoid multi_debug(string names, Tp\
    \ arg, Ts... args) {\n    // args...\u306E\u30D1\u30E9\u30E1\u30FC\u30BF\u304C\
    0\u500B\u306E\u3068\u304D\u3001\u5358\u306Barg\u3060\u3051\u3092\u51FA\u529B\u3057\
    \u3066\u7D42\u4E86\n    if constexpr (sizeof...(Ts) == 0) {\n        while (names.back()\
    \ == ' ') {\n            names.pop_back();\n        }\n        cerr << names <<\
    \ \": \" << arg << endl;\n    } else {\n        // names\u306B\u306F\u5168\u90E8\
    \u306E\u5909\u6570\u306E\u540D\u524D\u304C\u683C\u7D0D\u3055\u308C\u3066\u3044\
    \u308B\u306E\u3067\u30011\u3064\u76EE\u306E\u5909\u6570\u540D\u306E\u7D42\u308F\
    \u308A\u306E','\u306E\u4F4D\u7F6E\u3092\u63A2\u3059\n        int n = names.size(),\
    \ comma_pos = -1, paren_depth = 0,\n            inside_quote = false;\n      \
    \  rep(i, n) {\n            if (not inside_quote and paren_depth == 0 and names[i]\
    \ == ',') {\n                comma_pos = i;\n                break;\n        \
    \    }\n            if (names[i] == '\\\"' or names[i] == '\\'') {\n         \
    \       if (i > 0 and names[i - 1] == '\\\\') continue;\n                inside_quote\
    \ ^= true;\n            }\n            if (not inside_quote and names[i] == '(')\
    \ {\n                paren_depth++;\n            }\n            if (not inside_quote\
    \ and names[i] == ')') {\n                paren_depth--;\n            }\n    \
    \    }\n        assert(comma_pos != -1);\n        string name = names.substr(0,\
    \ comma_pos);\n        while (name.back() == ' ') {\n            name.pop_back();\n\
    \        }\n        cerr << name << \": \" << arg << endl;\n\n        int next_begin_at\
    \ = comma_pos + 1;\n        while (names[next_begin_at] == ' ') {\n          \
    \  next_begin_at++;\n        }\n        names = names.substr(next_begin_at);\n\
    \        // \u3053\u306E\u95A2\u6570\u3092\u518D\u5E30\u7684\u306B\u547C\u3093\
    \u3067\u6B8B\u308A\u306E\u5909\u6570\u3082\u51FA\u529B\u3059\u308B\n        multi_debug(names,\
    \ args...);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>\nvoid\
    \ print(const vector<T> &V, char sep) {\n    print(V, string{sep});\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, char sep) {\n    print(arr,\
    \ string{sep});\n}\n\n// TODO\uFF1A\u305D\u306E\u3046\u3061\u81EA\u52D5\u5B9F\u884C\
    \u3068\u304B\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\u3002\n// test cases\
    \ for print() and cout <<\n// pair<char, int> p = {'a', 1};\n// cout << p << '\\\
    n';\n// print(p);\n// tuple<char, int, ll, string> tp = {'a', 1, 2, \"abc\"};\n\
    // cout << tp << '\\n';\n// print(tp);\n// vector<ll> vec = {1, 2, 3, 4, 5};\n\
    // cout << vec << '\\n';\n// print(vec);\n// print(vec, \"\\n\");\n// array<ll,\
    \ 5> arr = {1, 2, 3, 4, 5};\n// cout << arr << '\\n';\n// print(arr);\n// print(arr,\
    \ \"\\n\");\n// deque<ll> que = {1, 2, 3, 4, 5};\n// print(que);\n// print(que,\
    \ \"\\n\");\n// set<ll> se = {1, 2, 3, 4, 5};\n// print(se);\n// print(se, \"\\\
    n\");\n// print({1, 2, 3, 4, 5});\n// print({1, 2, 3, 4, 5}, \"\\n\");\n// print();\n\
    // ll a = 100;\n// cout << a << '\\n';\n// print(a);\n// print(100);\n// string\
    \ S = \"abc\";\n// cout << S << '\\n';\n// print(S);\n// print(\"abc\");\n// char\
    \ c = 'a';\n// cout << c << '\\n';\n// print(c);\n// print('a');\n// // print(1,\
    \ \"abc\", 22LL);\n// // print(s, c);\n\n// test cases for debug()\n// int a =\
    \ 2;\n// string b = \"agc\";\n// char c = 'z';\n// ll d = 10000;\n// debug(a,\
    \  b, \"aaa\", 'y', c,d, max((ll)a, d));\n#line 4 \"src/mystl/Vector.hpp\"\n\n\
    template<typename _Tp>\nstruct Vector : vector<_Tp> {\n    // \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306E\u7D99\u627F\n    using vector<_Tp>::vector;\n \
    \   _Tp pop() {\n        _Tp res = this->back();\n        this->pop_back();\n\
    \        return res;\n    }\n\n    template<typename F>\n    auto map(F f) {\n\
    \        Vector<decltype(f(_Tp()))> res;\n        for (auto &val : *this) {\n\
    \            res.eb(f(val));\n        }\n        return res;\n    }\n};\n\ntemplate<typename\
    \ T>\nvoid print(const Vector<T> &A) {\n    vector<T> V(A.begin(), A.end());\n\
    \    print(V);\n}\n#line 3 \"src/graph/HeavyLightDecomposition.hpp\"\n\n// HL\u5206\
    \u89E3\n// see: https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp\n\
    // \u30FB\u4E3B\u306A\u4F7F\u7528\u65B9\u6CD5\u306A\u3069\n// \u3000\u30FB\u521D\
    \u671F\u5316\u5F8C\u3001\u5FD8\u308C\u305A\u306Bbuild\u3092\u547C\u3076\u3053\u3068\
    \u3002\u2192build\u306F\u521D\u671F\u5316\u306B\u542B\u3081\u305F\u3002\n// \u3000\
    \u30FB\u30D1\u30B9\u30AF\u30A8\u30EA\u306Fadd,query\u3067\u51E6\u7406\n// \u3000\
    \u30FB1\u70B9\u53D6\u5F97/\u66F4\u65B0\u306Fhld.in[x]\u3067\u53EF\u80FD\u3002\
    add,query\u306F\u547C\u3070\u306A\u304F\u3066\u3044\u3044\u3002\n// \u3000\u30FB\
    \u8FBA\u5C5E\u6027\u306B\u3059\u308B\u3068\u3001\u6DFB\u5B570\u304C\u6B20\u756A\
    \u306B\u306A\u308B\u3002(\u89AA\u306B\u5411\u304B\u3046\u8FBA\u3068\u5BFE\u5FDC\
    \u3059\u308B\u306F\u305A\u306A\u306E\u3067\u305D\u308C\u306F\u305D\u3046\u304B\
    )\n// \u3000\u3000\u306A\u304A\u8FBA\u5C5E\u6027\u306B\u5024\u3092\u5272\u308A\
    \u5F53\u3066\u308B\u6642\u306F\u3001dep\u3067\u6DF1\u3044\u65B9\u306E\u9802\u70B9\
    \u306B\u3063\u3066\u3084\u308B\u3068\u3044\u3044\u3002(ABC133f\u3068\u304B\u53C2\
    \u7167)\n// \u3000\u30FB\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306F[hld.in[x],hld.out[x])\u3067\
    \u51E6\u7406\u3002\n// \u3000\u3000\u306A\u304A\u90E8\u5206\u6728\u30AF\u30A8\u30EA\
    \u3082\u8FBA\u5C5E\u6027\u306E\u6642\u306Fedge=true\u306E\u3088\u3046\u306B\u5DE6\
    \u7AEF\u3092+1\u3059\u308B\u3002\n// \u3000\u3000\u3042\u3068\u300C\u90E8\u5206\
    \u6728\u3058\u3083\u306A\u3044\u90E8\u5206\u300D\u3082\u53D6\u308C\u308B\u3002\
    [0,hld.in[x])\u3068[hld.out[x],N) \u306E2\u533A\u9593\u3067OK\u3002\n// \u3000\
    \u3000\u3053\u308C\u3068\u6DF1\u3055\u3067\u6BD4\u8F03\u3057\u3066\u5834\u5408\
    \u5206\u3051\u3059\u308C\u3070\u3001\u3042\u308B\u30D1\u30B9\u306E\u624B\u524D\
    \u3068\u5411\u3053\u3046\u5074\u304C\u4EFB\u610F\u306B\u53D6\u308C\u308B\u3088\
    \u3046\u306B\u306A\u308B\u3002\n// \u3000\u30FB\u6839\u4ED8\u304D\u6728\u306F\u9802\
    \u70B90\u304C\u6839\u3067\u3042\u308B\u524D\u63D0\u3002\u4ED6\u306E\u9802\u70B9\
    \u3092\u6839\u306B\u3057\u305F\u3044\u5834\u5408\u3001\n// \u3000\u3000HLD\u69CB\
    \u7BC9\u524D\u306B\u6839\u3068\u9802\u70B90\u306E\u95A2\u4FC2\u3092\u5168\u3066\
    \u30B9\u30EF\u30C3\u30D7\u3057\u3066\u304A\u304F\u3002\n// \u3000\u3000\u2192\u4EFB\
    \u610F\u306E\u9802\u70B9\u3092\u6839\u306B\u3067\u304D\u308B\u3088\u3046\u6539\
    \u4FEE\u3057\u3066\u307F\u305F\u3002\u524D\u3084\u308D\u3046\u3068\u3057\u3066\
    \u5931\u6557\u3057\u305F\u3093\u3060\u3051\u3069\u3001\n// \u3000\u3000head\u306E\
    \u521D\u671F\u5024\u3092root\u306B\u3057\u305F\u3089\u3046\u307E\u304F\u3044\u3063\
    \u305F\u3002\n// \u3000\u30FB\u30D1\u30B9\u30AF\u30A8\u30EA[u,v]\u306B\u3066\u3001\
    u->lca\u3068lca->v\u3067HLD\u4E0A\u306E\u5217\u306E\u5411\u304D\u304C\u9006\u306B\
    \u306A\u308B\u306E\u3067\u3001\n// \u3000\u3000\u4E57\u305B\u305F\u30BB\u30B0\u6728\
    \u306E\u6F14\u7B97\u306B\u30DE\u30FC\u30B8\u65B9\u5411\u304C\u3042\u308B\u5834\
    \u5408\u306A\u3069\u306F\u6CE8\u610F\u3057\u3066\u51E6\u7406\u3059\u308B\u3002\
    \n// \u3000\u30FB\u5DE6\u53F3\u306E\u533A\u5225\u304C\u3042\u308B\u30E2\u30CE\u30A4\
    \u30C9\u3092\u4E57\u305B\u305F\u3044\u6642\u306F\u30AF\u30A8\u30EA\u3067\u95A2\
    \u6570S\u3092\u4F7F\u3046\u3068\u3046\u307E\u304F\u3044\u3063\u305F\u3002(cf1843F2\u53C2\
    \u7167)\n\n// HL\u5206\u89E3\nstruct HeavyLightDecomposition {\npublic:\n    vvi\
    \ g;\n    vector<int> sz, in, out, head, rev, par, dep;\n\n    // \u9802\u70B9\
    v\u304B\u3089k\u56DE\u9061\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int\
    \ la(int v, int k) {\n        while (1) {\n            int u = head[v];\n    \
    \        if (in[v] - k >= in[u]) return rev[in[v] - k];\n            k -= in[v]\
    \ - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u,\
    \ int v) const {\n        for (;; v = par[head[v]]) {\n            if (in[u] >\
    \ in[v]) swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n\
    \    }\n\n    // \u9802\u70B9u\u304B\u3089v\u306B\u5411\u304B\u3063\u30661\u3064\
    \u9032\u3093\u3060\u9802\u70B9\u3092\u8FD4\u3059\n    int next(int u, int v) {\n\
    \        // assert(lca(u, v) == u);\n        int d = dist(u, v);\n        return\
    \ la(v, d - 1);\n    }\n\n    int dist(int u, int v) const {\n        return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template<typename E, typename Q,\
    \ typename F, typename S>\n    E query(\n        int u, int v, const E &ti, const\
    \ Q &q, const F &f, const S &s,\n        bool edge = false\n    ) {\n        E\
    \ l = ti, r = ti;\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n\
    \            l = f(q(in[head[v]], in[v] + 1), l);\n        }\n        return s(f(q(in[u]\
    \ + edge, in[v] + 1), l), r);\n    }\n\n    template<typename E, typename Q, typename\
    \ F>\n    E query(\n        int u, int v, const E &ti, const Q &q, const F &f,\
    \ bool edge = false\n    ) {\n        return query(u, v, ti, q, f, f, edge);\n\
    \    }\n\n    template<typename Q>\n    void update(int u, int v, const Q &q,\
    \ bool edge = false) {\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            if (head[u] == head[v]) break;\n         \
    \   q(in[head[v]], in[v] + 1);\n        }\n        q(in[u] + edge, in[v] + 1);\n\
    \    }\n\n    /* {parent, child} */\n    vector<pair<int, int>> compress(vector<int>\
    \ &remark) {\n        auto cmp = [&](int a, int b) { return in[a] < in[b]; };\n\
    \        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        int K = (int)remark.size();\n        for\
    \ (int k = 1; k < K; k++)\n            remark.emplace_back(lca(remark[k - 1],\
    \ remark[k]));\n        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        vector<pair<int, int>> es;\n        stack<int>\
    \ st;\n        for (auto &k : remark) {\n            while (!st.empty() && out[st.top()]\
    \ <= in[k]) st.pop();\n            if (!st.empty()) es.emplace_back(st.top(),\
    \ k);\n            st.emplace(k);\n        }\n        return es;\n    }\n\n  \
    \  explicit HeavyLightDecomposition(const vvi &g, int root = 0) : g(g) {\n   \
    \     build(root);\n    }\n\n    int operator[](int u) const {\n        assert(0\
    \ <= u && u < (int)g.size());\n        return in[u];\n    }\n\nprivate:\n    void\
    \ build(int root = 0) {\n        sz.assign(g.size(), 0);\n        in.assign(g.size(),\
    \ 0);\n        out.assign(g.size(), 0);\n        head.assign(g.size(), root);\n\
    \        rev.assign(g.size(), 0);\n        par.assign(g.size(), 0);\n        dep.assign(g.size(),\
    \ 0);\n        dfs_sz(root, -1, 0);\n        int t = 0;\n        dfs_hld(root,\
    \ -1, t);\n    }\n\n    void dfs_sz(int idx, int p, int d) {\n        dep[idx]\
    \ = d;\n        par[idx] = p;\n        sz[idx] = 1;\n        if (g[idx].size()\
    \ && g[idx][0] == p) swap(g[idx][0], g[idx].back());\n        for (auto &to :\
    \ g[idx]) {\n            if (to == p) continue;\n            dfs_sz(to, idx, d\
    \ + 1);\n            sz[idx] += sz[to];\n            if (sz[g[idx][0]] < sz[to])\
    \ swap(g[idx][0], to);\n        }\n    }\n\n    void dfs_hld(int idx, int p, int\
    \ &times) {\n        in[idx] = times++;\n        rev[in[idx]] = idx;\n       \
    \ for (auto &to : g[idx]) {\n            if (to == p) continue;\n            head[to]\
    \ = (g[idx][0] == to ? head[idx] : to);\n            dfs_hld(to, idx, times);\n\
    \        }\n        out[idx] = times;\n    }\n};\n#line 6 \"src/graph/AuxiliaryTree.hpp\"\
    \n\n// Auxiliary Tree\n// \u8AAC\u660E\n// \u30FB\u6307\u5B9A\u3057\u305F\u9802\
    \u70B9\u96C6\u5408S\u3068\u3001\u305D\u308C\u3089\u306ELCA\u306E\u307F\u3067\u69CB\
    \u6210\u3055\u308C\u308B\u30B0\u30E9\u30D5\u3092\u8A08\u7B97\u91CF|S|log|S|\u7A0B\
    \u5EA6\u3067\u69CB\u7BC9\u3059\u308B\u3002\n// \u4F7F\u3044\u65B9\n// \u30FB\u5168\
    \u4F53\u306E\u30B0\u30E9\u30D5\u304C\u78BA\u5B9A\u3057\u305F\u6642\u70B9\u3067\
    \u96A3\u63A5\u30EA\u30B9\u30C8nodes\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n\
    // \u30FB\u5404\u30AF\u30A8\u30EA\u6BCE\u306B\u4F7F\u3046\u9802\u70B9\u96C6\u5408\
    \u306E\u914D\u5217A\u3092\u6E21\u3057\u3066build\n// \u30FB\u623B\u308A\u5024\u306F\
    \u5727\u7E2E\u3055\u308C\u305F\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u3002\u91CD\u307F\u4ED8\u304D\u306B\u3057\u3066\u30B3\u30B9\u30C8\u3092\
    \u5143\u30B0\u30E9\u30D5\u4E0A\u3067\u306E\u8DDD\u96E2\u3068\u3057\u3066\u3042\
    \u308B\u3002\n// \u3000\u96A3\u63A5\u30EA\u30B9\u30C8\u306E\u30AD\u30FC\u306F\
    HashMap\u3067\u69CB\u6210\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u9802\u70B9\
    \u756A\u53F7\u306F\u5143\u30B0\u30E9\u30D5\u3068\u540C\u3058\u3082\u306E\u3092\
    \u4F7F\u3048\u308B(\u306E\u3067\u6DFB\u5B57\u304C\u5206\u304B\u308A\u3084\u3059\
    \u3044)\u3002\n// \u3000(\u305D\u306E\u5206\u591A\u5C11\u306F\u901F\u5EA6\u304C\
    \u72A0\u7272\u306B\u306A\u3063\u3066\u3044\u308B\u306F\u305A\u3060\u3051\u3069\
    \u3001\u307E\u3042Nyaan\u3055\u3093\u306EHashMap\u7206\u901F\u3060\u304B\u3089\
    \u5927\u6982\u5927\u4E08\u592B\u3060\u3068\u601D\u3046\u3002)\nstruct AuxiliaryTree\
    \ {\n    int N;\n    HeavyLightDecomposition hld;\n\n    AuxiliaryTree(const vvi\
    \ &nodes) : hld(nodes), N(nodes.size()) {}\n\n    HashMap<int, vector<pil>> build(const\
    \ vector<int> &A) {\n        int K = A.size();\n        vector<pii> tmp;\n   \
    \     rep(i, K) {\n            tmp.eb(hld.in[A[i]], A[i]);\n        }\n      \
    \  sort(ALL(tmp));\n        Vector<int> st = {tmp[0].second};\n        HashMap<int,\
    \ vector<pil>> res;\n        rep(i, 1, K) {\n            ll u = st.pop();\n  \
    \          ll v = tmp[i].second;\n            ll lca = hld.lca(u, v);\n      \
    \      while (st.size() and hld.dep[st.back()] > hld.dep[lca]) {\n           \
    \     res[st.back()].eb(u, hld.dist(u, st.back()));\n                res[u].eb(st.back(),\
    \ hld.dist(u, st.back()));\n                u = st.pop();\n            }\n   \
    \         if (st.empty() or st.back() != lca) {\n                st.eb(lca);\n\
    \            }\n            if (u != lca) {\n                res[lca].eb(u, hld.dist(u,\
    \ lca));\n                res[u].eb(lca, hld.dist(u, lca));\n            }\n \
    \           st.eb(v);\n        }\n        while (st.size() >= 2) {\n         \
    \   ll u = st.pop();\n            res[st.back()].eb(u, hld.dist(u, st.back()));\n\
    \            res[u].eb(st.back(), hld.dist(u, st.back()));\n        }\n      \
    \  return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../common/HashMap.hpp\"\n#include \"../macros.hpp\"\
    \n#include \"../mystl/Vector.hpp\"\n#include \"HeavyLightDecomposition.hpp\"\n\
    \n// Auxiliary Tree\n// \u8AAC\u660E\n// \u30FB\u6307\u5B9A\u3057\u305F\u9802\u70B9\
    \u96C6\u5408S\u3068\u3001\u305D\u308C\u3089\u306ELCA\u306E\u307F\u3067\u69CB\u6210\
    \u3055\u308C\u308B\u30B0\u30E9\u30D5\u3092\u8A08\u7B97\u91CF|S|log|S|\u7A0B\u5EA6\
    \u3067\u69CB\u7BC9\u3059\u308B\u3002\n// \u4F7F\u3044\u65B9\n// \u30FB\u5168\u4F53\
    \u306E\u30B0\u30E9\u30D5\u304C\u78BA\u5B9A\u3057\u305F\u6642\u70B9\u3067\u96A3\
    \u63A5\u30EA\u30B9\u30C8nodes\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n// \u30FB\
    \u5404\u30AF\u30A8\u30EA\u6BCE\u306B\u4F7F\u3046\u9802\u70B9\u96C6\u5408\u306E\
    \u914D\u5217A\u3092\u6E21\u3057\u3066build\n// \u30FB\u623B\u308A\u5024\u306F\u5727\
    \u7E2E\u3055\u308C\u305F\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    \u3002\u91CD\u307F\u4ED8\u304D\u306B\u3057\u3066\u30B3\u30B9\u30C8\u3092\u5143\
    \u30B0\u30E9\u30D5\u4E0A\u3067\u306E\u8DDD\u96E2\u3068\u3057\u3066\u3042\u308B\
    \u3002\n// \u3000\u96A3\u63A5\u30EA\u30B9\u30C8\u306E\u30AD\u30FC\u306FHashMap\u3067\
    \u69CB\u6210\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u9802\u70B9\u756A\u53F7\
    \u306F\u5143\u30B0\u30E9\u30D5\u3068\u540C\u3058\u3082\u306E\u3092\u4F7F\u3048\
    \u308B(\u306E\u3067\u6DFB\u5B57\u304C\u5206\u304B\u308A\u3084\u3059\u3044)\u3002\
    \n// \u3000(\u305D\u306E\u5206\u591A\u5C11\u306F\u901F\u5EA6\u304C\u72A0\u7272\
    \u306B\u306A\u3063\u3066\u3044\u308B\u306F\u305A\u3060\u3051\u3069\u3001\u307E\
    \u3042Nyaan\u3055\u3093\u306EHashMap\u7206\u901F\u3060\u304B\u3089\u5927\u6982\
    \u5927\u4E08\u592B\u3060\u3068\u601D\u3046\u3002)\nstruct AuxiliaryTree {\n  \
    \  int N;\n    HeavyLightDecomposition hld;\n\n    AuxiliaryTree(const vvi &nodes)\
    \ : hld(nodes), N(nodes.size()) {}\n\n    HashMap<int, vector<pil>> build(const\
    \ vector<int> &A) {\n        int K = A.size();\n        vector<pii> tmp;\n   \
    \     rep(i, K) {\n            tmp.eb(hld.in[A[i]], A[i]);\n        }\n      \
    \  sort(ALL(tmp));\n        Vector<int> st = {tmp[0].second};\n        HashMap<int,\
    \ vector<pil>> res;\n        rep(i, 1, K) {\n            ll u = st.pop();\n  \
    \          ll v = tmp[i].second;\n            ll lca = hld.lca(u, v);\n      \
    \      while (st.size() and hld.dep[st.back()] > hld.dep[lca]) {\n           \
    \     res[st.back()].eb(u, hld.dist(u, st.back()));\n                res[u].eb(st.back(),\
    \ hld.dist(u, st.back()));\n                u = st.pop();\n            }\n   \
    \         if (st.empty() or st.back() != lca) {\n                st.eb(lca);\n\
    \            }\n            if (u != lca) {\n                res[lca].eb(u, hld.dist(u,\
    \ lca));\n                res[u].eb(lca, hld.dist(u, lca));\n            }\n \
    \           st.eb(v);\n        }\n        while (st.size() >= 2) {\n         \
    \   ll u = st.pop();\n            res[st.back()].eb(u, hld.dist(u, st.back()));\n\
    \            res[u].eb(st.back(), hld.dist(u, st.back()));\n        }\n      \
    \  return res;\n    }\n};\n"
  dependsOn:
  - src/common/HashMap.hpp
  - src/base.hpp
  - src/common/HashMapImpl.hpp
  - src/macros.hpp
  - src/mystl/Vector.hpp
  - src/common/print.hpp
  - src/common/chmax.hpp
  - src/graph/HeavyLightDecomposition.hpp
  isVerificationFile: false
  path: src/graph/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-01-08 14:31:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/src/graph/AuxiliaryTree.hpp
- /library/src/graph/AuxiliaryTree.hpp.html
title: src/graph/AuxiliaryTree.hpp
---
