---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/HashMapImpl.hpp
    title: src/common/HashMapImpl.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/hashmap/hashset.hpp
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
    \    ).count();\n\n} // namespace HashMapImpl\n#line 3 \"src/common/HashSet.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/hashmap/hashset.hpp\n\
    template<typename Key>\nstruct HashSet : HashMapImpl::HashMapBase<Key, Key> {\n\
    \    using HashMapImpl::HashMapBase<Key, Key>::HashMapBase;\n\n    bool count(const\
    \ Key &k) {\n        return this->contain(k);\n    }\n};\n"
  code: "#pragma once\n#include \"HashMapImpl.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/hashmap/hashset.hpp\n\
    template<typename Key>\nstruct HashSet : HashMapImpl::HashMapBase<Key, Key> {\n\
    \    using HashMapImpl::HashMapBase<Key, Key>::HashMapBase;\n\n    bool count(const\
    \ Key &k) {\n        return this->contain(k);\n    }\n};\n"
  dependsOn:
  - src/common/HashMapImpl.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/HashSet.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/HashSet.hpp
layout: document
redirect_from:
- /library/src/common/HashSet.hpp
- /library/src/common/HashSet.hpp.html
title: src/common/HashSet.hpp
---
