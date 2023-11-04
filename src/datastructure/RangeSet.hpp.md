---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://mugen1337.hatenablog.com/entry/2020/10/14/134022
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/datastructure/RangeSet.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://mugen1337.hatenablog.com/entry/2020/10/14/134022\n// \u9589\u533A\
    \u9593\u306E\u7BC4\u56F2\u3092\u7BA1\u7406\ntemplate<typename T>\nstruct RangeSet\
    \ {\n    set<pair<T,T>> st;\n    T TINF;\n\n    RangeSet() {\n        TINF=numeric_limits<T>::max()/2;\n\
    \        st.emplace(TINF,TINF);\n        st.emplace(-TINF,-TINF);\n    }\n   \
    \ // [l,r] covered?\n    bool covered(T l,T r) {\n        assert(l<=r);\n    \
    \    auto ite=prev(st.lower_bound({l+1,l+1}));\n        return ite->first<=l and\
    \ r<=ite->second;\n    }\n    bool covered(T x) {\n        return covered(x,x);\n\
    \    }\n    // [l, r]\u304C\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u306A\
    \u3089\uFF0C\u305D\u306E\u533A\u9593\u3092\u8FD4\u3059. \u3055\u308C\u3066\u3044\
    \u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\u8FD4\u3059\n    pair<T,T> covered_by(T\
    \ l,T r) {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if (ite->first<=l and r<=ite->second) return *ite;\n        return make_pair(-TINF,-TINF);\n\
    \    }\n    pair<T,T> covered_by(T x) {\n        return covered_by(x,x);\n   \
    \ }\n    // insert[l,r], \u5897\u52A0\u91CF\u3092\u8FD4\u3059\n    T insert(T\
    \ l,T r) {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if (ite->first<=l and r<=ite->second) return T(0);\n        T sum_erased=T(0);\n\
    \        if (ite->first<=l and l<=ite->second+1) {\n            l=ite->first;\n\
    \            sum_erased+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n\
    \        } else ite=next(ite);\n        while (r>ite->second) {\n            sum_erased+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }\n        if (ite->first-1<=r and r<=ite->second)\
    \ {\n            sum_erased+=ite->second-ite->first+1;\n            r=ite->second;\n\
    \            st.erase(ite);\n        }\n        st.emplace(l,r);\n        return\
    \ r-l+1-sum_erased;\n    }\n    T insert(T x) {\n        return insert(x,x);\n\
    \    }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T\
    \ l,T r) {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if (ite->first<=l and r<=ite->second) {\n            // \u5B8C\u5168\u306B\
    1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\n  \
    \          if (ite->first<l)  st.emplace(ite->first,l-1);\n            if (r<ite->second)\
    \ st.emplace(r+1,ite->second);\n            st.erase(ite);\n            return\
    \ r-l+1;\n        }\n\n        T ret=T(0);\n        if (ite->first<=l and l<=ite->second)\
    \ {\n            ret+=ite->second-l+1;// \u6D88\u3048\u305F\n            if (ite->first<l)\
    \ st.emplace(ite->first,l-1);\n            ite=st.erase(ite);// \u6B21\u3078\n\
    \        } else ite=next(ite);\n        while (ite->second<=r) {\n           \
    \ ret+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n        }\n\
    \        // \u53F3\u7AEF\u304C\u533A\u9593\u306E\u9593\u306B\u3042\u308B\u304B\
    \n        if (ite->first<=r and r<=ite->second) {\n            ret+=r-ite->first+1;\n\
    \            if (r<ite->second) st.emplace(r+1,ite->second);\n            st.erase(ite);\n\
    \        }\n        return ret;\n    }\n    T erase(T x) {\n        return erase(x,x);\n\
    \    }\n    // number of range\n    int size() {\n        return (int)st.size()-2;\n\
    \    }\n    // mex [x,~)\n    T mex(T x=0) {\n        auto ite=prev(st.lower_bound({x+1,x+1}));\n\
    \        if (ite->first<=x and x<=ite->second) return ite->second+1;\n       \
    \ else return x;\n    }\n    void output() {\n        cout<<\"RangeSet : \";\n\
    \        for(auto &p:st) {\n            if (p.first==-TINF or p.second==TINF)\
    \ continue;\n            cout<<\"[\"<<p.first<<\", \"<<p.second<<\"] \";\n   \
    \     }\n        cout<<\"\\n\";\n    }\n\n    vector<pair<T, T>> get_ranges()\
    \ {\n        vector<pair<T, T>> res;\n        for (auto& [l, r] : st) {\n    \
    \        if (l == -TINF or r == TINF) continue;\n            res.emplace_back(l,\
    \ r);\n        }\n        return res;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://mugen1337.hatenablog.com/entry/2020/10/14/134022\n\
    // \u9589\u533A\u9593\u306E\u7BC4\u56F2\u3092\u7BA1\u7406\ntemplate<typename T>\n\
    struct RangeSet {\n    set<pair<T,T>> st;\n    T TINF;\n\n    RangeSet() {\n \
    \       TINF=numeric_limits<T>::max()/2;\n        st.emplace(TINF,TINF);\n   \
    \     st.emplace(-TINF,-TINF);\n    }\n    // [l,r] covered?\n    bool covered(T\
    \ l,T r) {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        return ite->first<=l and r<=ite->second;\n    }\n    bool covered(T x)\
    \ {\n        return covered(x,x);\n    }\n    // [l, r]\u304C\u30AB\u30D0\u30FC\
    \u3055\u308C\u3066\u3044\u308B\u306A\u3089\uFF0C\u305D\u306E\u533A\u9593\u3092\
    \u8FD4\u3059. \u3055\u308C\u3066\u3044\u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\
    \u8FD4\u3059\n    pair<T,T> covered_by(T l,T r) {\n        assert(l<=r);\n   \
    \     auto ite=prev(st.lower_bound({l+1,l+1}));\n        if (ite->first<=l and\
    \ r<=ite->second) return *ite;\n        return make_pair(-TINF,-TINF);\n    }\n\
    \    pair<T,T> covered_by(T x) {\n        return covered_by(x,x);\n    }\n   \
    \ // insert[l,r], \u5897\u52A0\u91CF\u3092\u8FD4\u3059\n    T insert(T l,T r)\
    \ {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if (ite->first<=l and r<=ite->second) return T(0);\n        T sum_erased=T(0);\n\
    \        if (ite->first<=l and l<=ite->second+1) {\n            l=ite->first;\n\
    \            sum_erased+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n\
    \        } else ite=next(ite);\n        while (r>ite->second) {\n            sum_erased+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }\n        if (ite->first-1<=r and r<=ite->second)\
    \ {\n            sum_erased+=ite->second-ite->first+1;\n            r=ite->second;\n\
    \            st.erase(ite);\n        }\n        st.emplace(l,r);\n        return\
    \ r-l+1-sum_erased;\n    }\n    T insert(T x) {\n        return insert(x,x);\n\
    \    }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T\
    \ l,T r) {\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if (ite->first<=l and r<=ite->second) {\n            // \u5B8C\u5168\u306B\
    1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\n  \
    \          if (ite->first<l)  st.emplace(ite->first,l-1);\n            if (r<ite->second)\
    \ st.emplace(r+1,ite->second);\n            st.erase(ite);\n            return\
    \ r-l+1;\n        }\n\n        T ret=T(0);\n        if (ite->first<=l and l<=ite->second)\
    \ {\n            ret+=ite->second-l+1;// \u6D88\u3048\u305F\n            if (ite->first<l)\
    \ st.emplace(ite->first,l-1);\n            ite=st.erase(ite);// \u6B21\u3078\n\
    \        } else ite=next(ite);\n        while (ite->second<=r) {\n           \
    \ ret+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n        }\n\
    \        // \u53F3\u7AEF\u304C\u533A\u9593\u306E\u9593\u306B\u3042\u308B\u304B\
    \n        if (ite->first<=r and r<=ite->second) {\n            ret+=r-ite->first+1;\n\
    \            if (r<ite->second) st.emplace(r+1,ite->second);\n            st.erase(ite);\n\
    \        }\n        return ret;\n    }\n    T erase(T x) {\n        return erase(x,x);\n\
    \    }\n    // number of range\n    int size() {\n        return (int)st.size()-2;\n\
    \    }\n    // mex [x,~)\n    T mex(T x=0) {\n        auto ite=prev(st.lower_bound({x+1,x+1}));\n\
    \        if (ite->first<=x and x<=ite->second) return ite->second+1;\n       \
    \ else return x;\n    }\n    void output() {\n        cout<<\"RangeSet : \";\n\
    \        for(auto &p:st) {\n            if (p.first==-TINF or p.second==TINF)\
    \ continue;\n            cout<<\"[\"<<p.first<<\", \"<<p.second<<\"] \";\n   \
    \     }\n        cout<<\"\\n\";\n    }\n\n    vector<pair<T, T>> get_ranges()\
    \ {\n        vector<pair<T, T>> res;\n        for (auto& [l, r] : st) {\n    \
    \        if (l == -TINF or r == TINF) continue;\n            res.emplace_back(l,\
    \ r);\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/RangeSet.hpp
layout: document
redirect_from:
- /library/src/datastructure/RangeSet.hpp
- /library/src/datastructure/RangeSet.hpp.html
title: src/datastructure/RangeSet.hpp
---