---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':x:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':question:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':x:'
    path: src/segment/Accumulate.hpp
    title: src/segment/Accumulate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/typical90/tasks/typical90_j
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_j
  bundledCode: "#line 1 \"test/segment/Accumulate.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_j\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 10 \"test/segment/Accumulate.test.cpp\"\n\nconstexpr\
    \ long long INF = 1e18;\n// constexpr long long INF = LONG_LONG_MAX;\nconstexpr\
    \ int MOD = 1000000007;\n// constexpr int MOD = 998244353;\nconstexpr long double\
    \ EPS = 1e-10;\nconstexpr long double PI = M_PI;\n\n#line 3 \"src/macros.hpp\"\
    \n\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using pll = pair<ll, ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\n\
    using pil = pair<int, ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\n\
    using vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing\
    \ vvpil = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define\
    \ rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i,\
    \ a) for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i =\
    \ a, _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b;\
    \ (c > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/listnd.hpp\"\n\ntemplate<typename T> vector<vector<T>> list2d(int N,\
    \ int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M, init));\n}\n\n\
    template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init)\
    \ {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T> vector<vector<vector<vector<T>>>> list4d(int\
    \ N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 3 \"src/common/print.hpp\"\n\nvoid print() {\n    cout << '\\n';\n}\n\n\
    template<typename T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\ntemplate<typename\
    \ T1, typename T2>\nvoid print(const pair<T1, T2> &p) {\n    cout << p.first <<\
    \ ' ' << p.second << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename\
    \ T3>\nvoid print(const tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << '\
    \ ' << get<1>(tp) << ' ' << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename\
    \ T2, typename T3, typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) {\
    \ \n    cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' <<\
    \ get<3>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2>\nvoid print(const\
    \ vector<pair<T1, T2>> &V) {\n    for (auto& p : V) print(p);\n}\n\ntemplate<typename\
    \ T>\nvoid print(const vector<T> &V) {\n    rep(i, V.size()) {\n        cout <<\
    \ V[i];\n        if (i != V.size()-1) cout << ' ';\n    }\n    cout << '\\n';\n\
    }\n\ntemplate<typename T, size_t SZ>\nvoid print(const array<T, SZ> &arr) {\n\
    \    rep(i, arr.size()) {\n        cout << arr[i];\n        if (i != arr.size()-1)\
    \ cout << ' ';\n    }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\n\
    void print(const vector<array<T, SZ>> &V) {\n    for (auto& arr : V) print(arr);\n\
    }\n\ntemplate<typename T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n\
    \    print(V);\n}\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n  \
    \  vector<T> V(ALL(se));\n    print(V);\n}\n\n#define debug(x) (cout << #x <<\
    \ \": \", print(x));\n#line 21 \"test/segment/Accumulate.test.cpp\"\n\n#line 2\
    \ \"src/segment/Accumulate.hpp\"\n\n// \u7D2F\u7A4D\u548C\ntemplate<typename T>\n\
    struct Accumulate {\n    vector<T> acc;\n    int N;\n\n    Accumulate(int N) :\
    \ N(N) {\n        acc.resize(N);\n    }\n\n    Accumulate(const vector<T> &A)\
    \ : N(A.size()), acc(A) {\n        build();\n    }\n\n    void set(int i, T a)\
    \ {\n        acc[i] = a;\n    }\n\n    void add(int i, T a) {\n        acc[i]\
    \ += a;\n    }\n\n    void build() {\n        rep(i, N-1) {\n            acc[i+1]\
    \ += acc[i];\n        }\n        acc.insert(acc.begin(), 0);\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(0 <= l and l <= N and 0 <= r and r <= N);\n    \
    \    return acc[r]-acc[l];\n    }\n\n    T get(int i) {\n        return query(i,\
    \ i+1);\n    }\n\n    T operator[](int i) {\n        return query(i, i+1);\n \
    \   }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\
    \u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int\
    \ l, int r, ll x) {\n        if (l > r) return -1;\n        ll l_sm = query(0,\
    \ l);\n        int ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 <\
    \ ok) {\n            int mid = (ok+ng) / 2;\n            if (query(0, mid+1) -\
    \ l_sm >= x) {\n                ok = mid;\n            } else {\n            \
    \    ng = mid;\n            }\n        }\n        if (ok != r+1) {\n         \
    \   return ok;\n        } else {\n            return -1;\n        }\n    }\n\n\
    \    // \u533A\u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\
    \u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int\
    \ l, int r, ll x) {\n        if (l > r) return -1;\n        ll r_sm = query(0,\
    \ r+1);\n        int ok = l - 1;\n        int ng = r + 1;\n        while (ok+1\
    \ < ng) {\n            int mid = (ok+ng) / 2;\n            if (r_sm - query(0,\
    \ mid) >= x) {\n                ok = mid;\n            } else {\n            \
    \    ng = mid;\n            }\n        }\n        if (ok != l-1) {\n         \
    \   return ok;\n        } else {\n            return -1;\n        }\n    }\n};\n\
    #line 23 \"test/segment/Accumulate.test.cpp\"\n\nvoid solve() {\n    ll N;\n \
    \   cin >> N;\n    auto A = list2d(2, N, 0LL);\n    rep(i, N) {\n        ll c,\
    \ p;\n        cin >> c >> p;\n        c--;\n        A[c][i] = p;\n    }\n\n  \
    \  Accumulate<ll> acc1(A[0]), acc2(A[1]);\n\n    ll Q;\n    cin >> Q;\n    rep(_,\
    \ Q) {\n        ll l, r;\n        cin >> l >> r;\n        l--;\n\n        vector<ll>\
    \ res(2);\n        res[0] = acc1.query(l, r);\n        res[1] = acc2.query(l,\
    \ r);\n        print(res);\n    }\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\
    \n    // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--)\
    \ solve();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_j\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #include \"../../src/base.hpp\"\n\nconstexpr long long INF = 1e18;\n// constexpr\
    \ long long INF = LONG_LONG_MAX;\nconstexpr int MOD = 1000000007;\n// constexpr\
    \ int MOD = 998244353;\nconstexpr long double EPS = 1e-10;\nconstexpr long double\
    \ PI = M_PI;\n\n#include \"../../src/macros.hpp\"\n#include \"../../src/common/listnd.hpp\"\
    \n#include \"../../src/common/print.hpp\"\n\n#include \"../../src/segment/Accumulate.hpp\"\
    \n\nvoid solve() {\n    ll N;\n    cin >> N;\n    auto A = list2d(2, N, 0LL);\n\
    \    rep(i, N) {\n        ll c, p;\n        cin >> c >> p;\n        c--;\n   \
    \     A[c][i] = p;\n    }\n\n    Accumulate<ll> acc1(A[0]), acc2(A[1]);\n\n  \
    \  ll Q;\n    cin >> Q;\n    rep(_, Q) {\n        ll l, r;\n        cin >> l >>\
    \ r;\n        l--;\n\n        vector<ll> res(2);\n        res[0] = acc1.query(l,\
    \ r);\n        res[1] = acc2.query(l, r);\n        print(res);\n    }\n}\n\nint\
    \ main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n\n    // single test case\n    solve();\n\n    // multi\
    \ test cases\n    // int T;\n    // cin >> T;\n    // while (T--) solve();\n\n\
    \    return 0;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/listnd.hpp
  - src/common/print.hpp
  - src/segment/Accumulate.hpp
  isVerificationFile: true
  path: test/segment/Accumulate.test.cpp
  requiredBy: []
  timestamp: '2022-03-24 14:48:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment/Accumulate.test.cpp
layout: document
redirect_from:
- /verify/test/segment/Accumulate.test.cpp
- /verify/test/segment/Accumulate.test.cpp.html
title: test/segment/Accumulate.test.cpp
---
