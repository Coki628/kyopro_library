---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/combinatorics/ModTools.hpp
    title: src/combinatorics/ModTools.hpp
  - icon: ':warning:'
    path: src/combinatorics/combinations.hpp
    title: src/combinatorics/combinations.hpp
  - icon: ':warning:'
    path: src/combinatorics/factorial.hpp
    title: src/combinatorics/factorial.hpp
  - icon: ':warning:'
    path: src/combinatorics/nC2.hpp
    title: src/combinatorics/nC2.hpp
  - icon: ':warning:'
    path: src/combinatorics/permutations.hpp
    title: src/combinatorics/permutations.hpp
  - icon: ':warning:'
    path: src/common/Compress.hpp
    title: src/common/Compress.hpp
  - icon: ':warning:'
    path: src/common/Counter.hpp
    title: src/common/Counter.hpp
  - icon: ':warning:'
    path: src/common/RLE.hpp
    title: src/common/RLE.hpp
  - icon: ':warning:'
    path: src/common/bisearch.hpp
    title: src/common/bisearch.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
  - icon: ':warning:'
    path: src/common/bit_length.hpp
    title: src/common/bit_length.hpp
  - icon: ':warning:'
    path: src/common/ceil.hpp
    title: src/common/ceil.hpp
  - icon: ':warning:'
    path: src/common/chmax.hpp
    title: src/common/chmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  - icon: ':warning:'
    path: src/common/divmod.hpp
    title: src/common/divmod.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/input.hpp
    title: src/common/input.hpp
  - icon: ':warning:'
    path: src/common/join.hpp
    title: src/common/join.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':warning:'
    path: src/common/max.hpp
    title: src/common/max.hpp
  - icon: ':warning:'
    path: src/common/min.hpp
    title: src/common/min.hpp
  - icon: ':warning:'
    path: src/common/modulo.hpp
    title: src/common/modulo.hpp
  - icon: ':warning:'
    path: src/common/mul_overflow.hpp
    title: src/common/mul_overflow.hpp
  - icon: ':warning:'
    path: src/common/popcount.hpp
    title: src/common/popcount.hpp
  - icon: ':warning:'
    path: src/common/pow.hpp
    title: src/common/pow.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':warning:'
    path: src/common/reversed.hpp
    title: src/common/reversed.hpp
  - icon: ':warning:'
    path: src/common/sorted.hpp
    title: src/common/sorted.hpp
  - icon: ':warning:'
    path: src/common/split.hpp
    title: src/common/split.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/sum.hpp
    title: src/common/sum.hpp
  - icon: ':warning:'
    path: src/common/to_string.hpp
    title: src/common/to_string.hpp
  - icon: ':warning:'
    path: src/common/tochar.hpp
    title: src/common/tochar.hpp
  - icon: ':warning:'
    path: src/common/toint.hpp
    title: src/common/toint.hpp
  - icon: ':warning:'
    path: src/common/yesno.hpp
    title: src/common/yesno.hpp
  - icon: ':warning:'
    path: src/common/zip.hpp
    title: src/common/zip.hpp
  - icon: ':warning:'
    path: src/graph/UnionFind.hpp
    title: src/graph/UnionFind.hpp
  - icon: ':warning:'
    path: src/grid/constants/dir4.hpp
    title: src/grid/constants/dir4.hpp
  - icon: ':warning:'
    path: src/grid/constants/directions.hpp
    title: src/grid/constants/directions.hpp
  - icon: ':warning:'
    path: src/grid/gridtoid.hpp
    title: src/grid/gridtoid.hpp
  - icon: ':warning:'
    path: src/grid/idtogrid.hpp
    title: src/grid/idtogrid.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/mystl/defaultdict.hpp
    title: src/mystl/defaultdict.hpp
  - icon: ':warning:'
    path: src/numbers/divisors.hpp
    title: src/numbers/divisors.hpp
  - icon: ':warning:'
    path: src/numbers/factorize.hpp
    title: src/numbers/factorize.hpp
  - icon: ':warning:'
    path: src/numbers/gcd.hpp
    title: src/numbers/gcd.hpp
  - icon: ':warning:'
    path: src/numbers/isqrt.hpp
    title: src/numbers/isqrt.hpp
  - icon: ':warning:'
    path: src/numbers/lcm.hpp
    title: src/numbers/lcm.hpp
  - icon: ':warning:'
    path: src/segment/Accumulate.hpp
    title: src/segment/Accumulate.hpp
  - icon: ':warning:'
    path: src/segment/BIT.hpp
    title: src/segment/BIT.hpp
  - icon: ':warning:'
    path: src/segment/SegmentTree.hpp
    title: src/segment/SegmentTree.hpp
  - icon: ':warning:'
    path: src/string/bin.hpp
    title: src/string/bin.hpp
  - icon: ':warning:'
    path: src/string/constants/ascii_lowercase.hpp
    title: src/string/constants/ascii_lowercase.hpp
  - icon: ':warning:'
    path: src/string/constants/ascii_uppercase.hpp
    title: src/string/constants/ascii_uppercase.hpp
  - icon: ':warning:'
    path: src/string/constants/digits.hpp
    title: src/string/constants/digits.hpp
  - icon: ':warning:'
    path: src/string/zfill.hpp
    title: src/string/zfill.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/template.hpp\"\n\n// from common\n#line 3 \"src/common/listnd.hpp\"\n\ntemplate<typename\
    \ T>\nvector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int\
    \ N, int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 2 \"src/common/input.hpp\"\n\ntemplate<typename T=ll> vector<T> LIST(ll\
    \ N) {\n    vector<T> A(N);\n    rep(i, N) {\n        cin >> A[i];\n    }\n  \
    \  return A;\n}\n\n// pair\u5165\u529B\u4E00\u62EC\u53D7\u3051\u53D6\u308A\ntemplate<typename\
    \ T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n}\n\n// vector\u5165\u529B\u4E00\u62EC\
    \u53D7\u3051\u53D6\u308A\ntemplate<typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n    for (T &in: v) is >> in;\n    return is;\n}\n#line 3 \"\
    src/common/print.hpp\"\n\nvoid print() {\n    cout << '\\n';\n}\n\ntemplate<typename\
    \ T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\ntemplate<typename T1,\
    \ typename T2>\nvoid print(const pair<T1, T2> &p) {\n    cout << p.first << '\
    \ ' << p.second << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3>\n\
    void print(const tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << ' ' << get<1>(tp)\
    \ << ' ' << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename\
    \ T3, typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) { \n    cout <<\
    \ get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) <<\
    \ '\\n';\n}\n\ntemplate<typename T1, typename T2>\nvoid print(const vector<pair<T1,\
    \ T2>> &V) {\n    for (auto& p : V) print(p);\n}\n\ntemplate<typename T>\nvoid\
    \ print(const vector<T> &V) {\n    rep(i, V.size()) {\n        cout << V[i];\n\
    \        if (i != V.size()-1) cout << ' ';\n    }\n    cout << '\\n';\n}\n\ntemplate<typename\
    \ T, size_t SZ>\nvoid print(const array<T, SZ> &arr) {\n    rep(i, arr.size())\
    \ {\n        cout << arr[i];\n        if (i != arr.size()-1) cout << ' ';\n  \
    \  }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\nvoid print(const\
    \ vector<array<T, SZ>> &V) {\n    for (auto& arr : V) print(arr);\n}\n\ntemplate<typename\
    \ T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n    print(V);\n\
    }\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n    vector<T> V(ALL(se));\n\
    \    print(V);\n}\n\n#define debug(x) (cout << #x << \": \", print(x));\n#line\
    \ 2 \"src/common/yesno.hpp\"\n\nvoid Yes() { print(\"Yes\"); }\n\nvoid No() {\
    \ print(\"No\"); }\n\nvoid YES() { print(\"YES\"); }\n\nvoid NO() { print(\"NO\"\
    ); }\n#line 3 \"src/common/toint.hpp\"\n\nll toint(string s) {\n    assert(s.size()\
    \ < 20);\n    ll res = 0;\n    for (char &c : s) {\n        res *= 10;\n     \
    \   res += c - '0';\n    }\n    return res;\n}\n\nint toint(char num) {\n    return\
    \ num - '0';\n}\n#line 1 \"src/common/tochar.hpp\"\nchar tochar(int num) {\n \
    \   return '0' + num;\n}\n#line 1 \"src/common/ceil.hpp\"\ntemplate<typename T>\n\
    T ceil(T a, T b) {\n    if (a >= 0) return (a+b-1) / b;\n    else return a / b;\n\
    }\n#line 1 \"src/common/modulo.hpp\"\ntemplate<typename T>\nT modulo(T a, T b)\
    \ {\n    return ((a % b) + b) % b;\n}\n#line 3 \"src/common/divmod.hpp\"\n\ntemplate<typename\
    \ T>\npair<T, T> divmod(T a, T b) {\n    T d = a / b;\n    T m = a % b;\n    return\
    \ {d, m};\n}\n#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool chmin(T\
    \ &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n#line 2 \"src/common/chmax.hpp\"\
    \n\ntemplate<typename T>\nbool chmax(T &x, T y) {\n    return (y > x) ? x = y,\
    \ true : false;\n}\n#line 2 \"src/common/sum.hpp\"\n\ntemplate<typename T>\nT\
    \ sum(const vector<T> &A) {\n    return accumulate(ALL(A), (T)0);\n}\n\ntemplate<typename\
    \ key, typename val>\nval sum(const map<key, val> &mp) {\n    val res = 0;\n \
    \   for (auto& [k, v] : mp) res += v;\n    return res;\n}\n#line 3 \"src/common/min.hpp\"\
    \n\ntemplate<typename T> T min(const vector<T> &A) {\n    return *min_element(ALL(A));\n\
    }\n\ntemplate<typename key, typename val> val min(const map<key, val> &mp) {\n\
    \    val res = numeric_limits<val>::max();\n    for (auto& [k, v] : mp) chmin(res,\
    \ v);\n    return res;\n}\n#line 3 \"src/common/max.hpp\"\n\ntemplate<typename\
    \ T> T max(const vector<T> &A) {\n    return *max_element(ALL(A));\n}\n\ntemplate<typename\
    \ key, typename val> val max(const map<key, val> &mp) {\n    val res = numeric_limits<val>::min();\n\
    \    for (auto& [k, v] : mp) chmax(res, v);\n    return res;\n}\n#line 2 \"src/common/pow.hpp\"\
    \n\nll pow(ll x, ll n) {\n    ll res = 1;\n    rep(_, n) res *= x;\n    return\
    \ res;\n}\n\nll pow(int x, ll n) { return pow((ll)x, n); }\n\nll pow(ll x, int\
    \ n) { return pow(x, (ll)n); }\n\nll pow(int x, int n) { return pow((ll)x, (ll)n);\
    \ }\n\nll pow(ll x, ll n, int mod) {\n    x %= mod;\n    ll res = 1;\n    while\
    \ (n > 0) {\n        if (n & 1) {\n            res = (res * x) % mod;\n      \
    \  }\n        x = (x * x) % mod;\n        n >>= 1;\n    }\n    return res;\n}\n\
    #line 2 \"src/common/popcount.hpp\"\n\nint popcount(ll S) { return __builtin_popcountll(S);\
    \ }\n#line 2 \"src/common/bit_length.hpp\"\n\nint bit_length(ll x) { return x\
    \ != 0 ? floor(log2((ld)x))+1 : 0; }\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename\
    \ T>\nint bisect_left(const vector<T> &A, T val, int lo=0) {\n    return lower_bound(A.begin()+lo,\
    \ A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo=0) {\n    return upper_bound(A.begin()+lo, A.end(),\
    \ val) - A.begin();\n}\n#line 2 \"src/common/Counter.hpp\"\n\ntemplate<typename\
    \ T>\nmap<T, ll> Counter(const vector<T> &A) {\n    map<T, ll> res;\n    for (T\
    \ a : A) {\n        res[a]++;\n    }\n    return res;\n}\n\ntemplate<typename\
    \ T>\nvector<ll> Counter(const vector<T> &A, int mx) {\n\n    vector<ll> res(mx+1);\n\
    \    for (T a : A) {\n        res[a]++;\n    }\n    return res;\n}\n\nmap<char,\
    \ ll> Counter(const string &S) {\n    map<char, ll> res;\n    for (char c : S)\
    \ {\n        res[c]++;\n    }\n    return res;\n}\n#line 2 \"src/common/bisearch.hpp\"\
    \n\n// (mn,mx]\u306E\u7BC4\u56F2\u3067\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u5024\u3092\u898B\u3064\u3051\u308B\u4E8C\u5206\u63A2\u7D22\ntemplate<typename\
    \ F>\nll bisearch_min(ll mn, ll mx, const F &func) {\n    ll ok = mx;\n    ll\
    \ ng = mn;\n    while (ng+1 < ok) {\n        ll mid = (ok+ng) / 2;\n        if\
    \ (func(mid)) {\n            // \u4E0B\u3092\u63A2\u3057\u306B\u884C\u304F\n \
    \           ok = mid;\n        } else {\n            // \u4E0A\u3092\u63A2\u3057\
    \u306B\u884C\u304F\n            ng = mid;\n        }\n    }\n    return ok;\n\
    }\n\n// [mn,mx)\u306E\u7BC4\u56F2\u3067\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\
    \u5927\u5024\u3092\u898B\u3064\u3051\u308B\u4E8C\u5206\u63A2\u7D22\ntemplate<typename\
    \ F>\nll bisearch_max(ll mn, ll mx, const F &func) {\n    ll ok = mn;\n    ll\
    \ ng = mx;\n    while (ok+1 < ng) {\n        ll mid = (ok+ng) / 2;\n        if\
    \ (func(mid)) {\n            // \u4E0A\u3092\u63A2\u3057\u306B\u884C\u304F\n \
    \           ok = mid;\n        } else {\n            // \u4E0B\u3092\u63A2\u3057\
    \u306B\u884C\u304F\n            ng = mid;\n        }\n    }\n    return ok;\n\
    }\n#line 2 \"src/common/zip.hpp\"\n\ntemplate<typename T1, typename T2>\npair<vector<T1>,\
    \ vector<T2>> zip(const vector<pair<T1, T2>> &A) {\n    int N = A.size();\n  \
    \  pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)};\n    rep(i,\
    \ N) {\n        res.first[i] = A[i].first;\n        res.second[i] = A[i].second;\n\
    \    }\n    return res;\n}\n\ntemplate<typename T1, typename T2, typename T3>\n\
    tuple<vector<T1>, vector<T2>, vector<T3>> zip(const vector<tuple<T1, T2, T3>>\
    \ &A) {\n    int N = A.size();\n    tuple<vector<T1>, vector<T2>, vector<T3>>\
    \ res = {vector<T1>(N), vector<T2>(N), vector<T3>(N)};\n    rep(i, N) {\n    \
    \    get<0>(res)[i] = get<0>(A[i]);\n        get<1>(res)[i] = get<1>(A[i]);\n\
    \        get<2>(res)[i] = get<2>(A[i]);\n    }\n    return res;\n}\n#line 2 \"\
    src/common/Compress.hpp\"\n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\
    \u30D9\u30FC\u30B9)\ntemplate<typename T>\nstruct Compress {\n\n    int N;\n \
    \   vector<T> dat;\n\n    Compress(vector<T> A) {\n        sort(A.begin(), A.end());\n\
    \        A.erase(unique(A.begin(), A.end()), A.end());\n        N = A.size();\n\
    \        dat = A;\n    }\n\n    int zip(T x) {\n        return bisect_left(dat,\
    \ x);\n    }\n\n    T unzip(int x) {\n        return dat[x];\n    }\n\n    int\
    \ operator[](T x) {\n        return zip(x);\n    }\n\n    int size() {\n     \
    \   return dat.size();\n    }\n\n    vector<ll> zip(const vector<T> &A) {\n  \
    \      int M = A.size();\n        vector<ll> res(M);\n        rep(i, M) res[i]\
    \ = zip(A[i]);\n        return res;\n    }\n};\n\n// \u5EA7\u6A19\u5727\u7E2E\
    (map\u30D9\u30FC\u30B9)(\u65E7)\n// template<typename T>\n// pair<map<T, int>,\
    \ vector<T>> compress(vector<T> unzipped) {\n//     map<T, int> zipped;\n//  \
    \   sort(unzipped.begin(), unzipped.end());\n//     unzipped.erase(unique(unzipped.begin(),\
    \ unzipped.end()), unzipped.end());\n//     rep(i, unzipped.size()) {\n//    \
    \     zipped[unzipped[i]] = i;\n//     }\n//     return {zipped, unzipped};\n\
    // }\n#line 2 \"src/common/RLE.hpp\"\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\
    \u5727\u7E2E\ntemplate<typename T>\nvector<pair<T, int>> RLE(const vector<T> &A)\
    \ {\n    if (A.empty()) return {};\n    int N = A.size();\n    vector<pair<T,\
    \ int>> res;\n    T cur = A[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n      \
    \  if (A[i] == A[i-1]) {\n            cnt++;\n        } else {\n            res.pb({cur,\
    \ cnt});\n            cnt = 1;\n            cur = A[i];\n        }\n    }\n  \
    \  res.pb({cur, cnt});\n    return res;\n}\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\
    \u30B9\u5727\u7E2E(\u6587\u5B57\u5217)\nvector<pair<char, int>> RLE(const string\
    \ &S) {\n    if (S.empty()) return {};\n    int N = S.size();\n    vector<pair<char,\
    \ int>> res;\n    char cur = S[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n   \
    \     if (S[i] == S[i-1]) {\n            cnt++;\n        } else {\n          \
    \  res.pb({cur, cnt});\n            cnt = 1;\n            cur = S[i];\n      \
    \  }\n    }\n    res.pb({cur, cnt});\n    return res;\n}\n#line 1 \"src/common/mul_overflow.hpp\"\
    \n// \u53C2\u8003\uFF1Ahttps://rsk0315.hatenablog.com/entry/2021/02/23/163040\n\
    // \u4E57\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u691C\u77E5\n\
    template<typename T>\nbool mul_overflow(T x, T y) {\n    T z;\n    return __builtin_mul_overflow(x,\
    \ y, &z);\n}\n#line 3 \"src/common/split.hpp\"\n\nvector<ll> split(const string\
    \ &S, char separator) {\n    int N = S.size();\n    vector<ll> res;\n    string\
    \ cur;\n    rep(i, N) {\n        if (S[i] == separator) {\n            res.eb(toint(cur));\n\
    \            cur = \"\";\n        } else {\n            cur += S[i];\n       \
    \ }\n    }\n    if (cur.size()) res.eb(toint(cur));\n    return res;\n}\n\n//\
    \ \u6587\u5B57\u5217\u306E\u307E\u307E\u7248(\u5F15\u6570\u4E00\u7DD2\u306A\u306E\
    \u3067\u5171\u5B58\u3067\u304D\u306A\u3044)\n// vector<string> split(const string\
    \ &S, char separator) {\n//     int N = S.size();\n//     vector<string> res;\n\
    //     string cur;\n//     rep(i, N) {\n//         if (S[i] == separator) {\n\
    //             res.eb(cur);\n//             cur = \"\";\n//         } else {\n\
    //             cur += S[i];\n//         }\n//     }\n//     if (cur.size()) res.eb(cur);\n\
    //     return res;\n// }\n#line 3 \"src/common/to_string.hpp\"\n\nstring to_string(const\
    \ string &S) { return S; }\nstring to_string(char c) { return {c}; }\n#line 3\
    \ \"src/common/join.hpp\"\n\ntemplate<typename T>\nstring join(const vector<T>\
    \ &A, char separator=0) {\n    int N = A.size();\n    string res;\n    rep(i,\
    \ N) {\n        res += tostr(A[i]);\n        if (separator != 0 and i != N-1)\
    \ res += separator;\n    }\n    return res;\n}\n#line 2 \"src/common/sorted.hpp\"\
    \n\ntemplate<typename T>\nvector<T> sorted(vector<T> A, bool reverse=false) {\n\
    \    sort(ALL(A));\n    if (reverse) std::reverse(ALL(A));\n    return A;\n}\n\
    \nstring sorted(string S, bool reverse=false) {\n    sort(ALL(S));\n    if (reverse)\
    \ std::reverse(ALL(S));\n    return S;\n}\n#line 2 \"src/common/reversed.hpp\"\
    \n\ntemplate<typename T>\nvector<T> reversed(vector<T> A) {\n    reverse(ALL(A));\n\
    \    return A;\n}\n\nstring reversed(string S) {\n    reverse(ALL(S));\n    return\
    \ S;\n}\n#line 33 \"src/template.hpp\"\n\n// from combinatorics\n#line 3 \"src/combinatorics/ModTools.hpp\"\
    \n\n// Mod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\ntemplate<typename\
    \ Mint>\nstruct ModTools {\n\n    int MAX;\n    vector<Mint> _fact, _factinv,\
    \ inv;\n\n    // nCr\u306A\u3089n\u3001nHr\u306A\u3089n+r\u307E\u3067\u4F5C\u308B\
    \n    ModTools(int mx) : MAX(++mx) {\n        _fact.resize(MAX);\n        _factinv.resize(MAX);\n\
    \        inv.resize(MAX);\n        _fact[0] = _fact[1] = 1;\n        rep(i, 2,\
    \ MAX) {\n            _fact[i] = _fact[i-1]*(Mint)i;\n        }\n        _factinv[MAX-1]\
    \ = (Mint)1/_fact[MAX-1];\n        rep(i, MAX-2, -1, -1) {\n            _factinv[i]\
    \ = _factinv[i+1]*(Mint)(i+1);\n        }\n        rep(i, MAX-1, 0, -1) {\n  \
    \          inv[i] = _factinv[i]*_fact[i-1];\n        }\n    }\n\n    // \u6E96\
    \u5099O(N)\u3001\u64CD\u4F5CO(1)\u3067log\u304C\u4E57\u3089\u306A\u3044mod\u9664\
    \u7B97\n    Mint div(Mint a, int b) {\n        return a*inv[b];\n    }\n\n   \
    \ Mint fact(int x) {\n        assert(x < MAX);\n        return _fact[x];\n   \
    \ }\n\n    Mint factinv(int x) {\n        assert(x < MAX);\n        return _factinv[x];\n\
    \    }\n\n    Mint nCr(int n, int r) {\n        if (n < r or r < 0) return 0;\n\
    \        r = min(r, n-r);\n        Mint num = _fact[n];\n        Mint den = _factinv[r]\
    \ * _factinv[n-r];\n        return num * den;\n    }\n\n    Mint nHr(int n, int\
    \ r) {\n        assert(r+n-1 < MAX);\n        return nCr(r+n-1, r);\n    }\n\n\
    \    Mint nPr(int n, int r) {\n        if (n < r or r < 0) return 0;\n       \
    \ return _fact[n] * _factinv[n-r];\n    }\n\n    // \u4E8C\u91CD\u968E\u4E57\n\
    \    // \u53C2\u8003\uFF1Ahttps://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97\n\
    \    Mint double_factorial(int n) {\n        if (n%2 == 0) {\n            int\
    \ k = n/2;\n            return Mint(2).pow(k)*fact(k);\n        } else {\n   \
    \         int k = (n+1)/2;\n            return fact(2*k)/Mint(2).pow(k)/fact(k);\n\
    \        }\n    }\n};\n#line 2 \"src/combinatorics/permutations.hpp\"\n\n// \u9806\
    \u5217\u5168\u5217\u6319\ntemplate<typename T>\nvector<vector<T>> permutations(const\
    \ vector<T> &A, int N=-1) {\n    if (N == -1) N = A.size();\n    int M = A.size();\n\
    \    assert(N <= M);\n    vector<vector<T>> comb;\n    rep(bit, 1<<M) {\n    \
    \    if (popcount(bit) != N) continue;\n        vector<T> res;\n        rep(i,\
    \ M) {\n            if (bit>>i & 1) {\n                res.pb(A[i]);\n       \
    \     }\n        }\n        comb.pb(res);\n    }\n\n    vector<vector<T>> res;\n\
    \    for (auto &perm : comb) {\n        sort(ALL(perm));\n        do {\n     \
    \       res.pb(perm);\n        } while (next_permutation(ALL(perm)));\n    }\n\
    \    return res;\n}\n#line 2 \"src/combinatorics/combinations.hpp\"\n\n// \u7D44\
    \u307F\u5408\u308F\u305B\u5168\u5217\u6319\ntemplate<typename T>\nvector<vector<T>>\
    \ combinations(const vector<T> &A, int N) {\n    int M = A.size();\n    vector<vector<T>>\
    \ res;\n    auto rec = [&](auto&& f, vector<T> &cur, ll x, ll n) -> void {\n \
    \       if (n == N) {\n            res.pb(cur);\n            return;\n       \
    \ }\n        rep(i, x, M) {\n            cur.pb(A[i]);\n            f(f, cur,\
    \ i+1, n+1);\n            cur.pop_back();\n        }\n    };\n    vector<T> cur;\n\
    \    rec(rec, cur, 0, 0);\n    return res;\n}\n#line 2 \"src/combinatorics/nC2.hpp\"\
    \n\nll nC2(ll n) {\n    if (n < 2) return 0;\n    return n*(n-1)/2;\n}\n#line\
    \ 1 \"src/combinatorics/factorial.hpp\"\n// \u968E\u4E57\uFF1AO(N)\ntemplate<typename\
    \ T>\nT factorial(int x) {\n    T res = 1;\n    for (int i=1; i<=x; i++) res *=\
    \ i;\n    return res;\n}\n#line 40 \"src/template.hpp\"\n\n// from graph\n#line\
    \ 2 \"src/graph/UnionFind.hpp\"\n\nstruct UnionFind {\n\n    int n, groupcnt;\n\
    \    vector<int> par, rank, sz;\n    vector<bool> tree;\n\n    UnionFind(int n)\
    \ : n(n) {\n        par.assign(n, 0);\n        rank.assign(n, 0);\n        sz.assign(n,\
    \ 1);\n        tree.assign(n, true);\n        rep(i, n) par[i] = i;\n        groupcnt\
    \ = n;\n    }\n\n    UnionFind() {}\n\n    void resize(int _n) {\n        n =\
    \ _n;\n        par.assign(n, 0);\n        rank.assign(n, 0);\n        sz.assign(n,\
    \ 1);\n        tree.assign(n, true);\n        rep(i, n) par[i] = i;\n        groupcnt\
    \ = n;\n    }\n\n    // \u6839\u306E\u691C\u7D22(\u30B0\u30EB\u30FC\u30D7\u756A\
    \u53F7)\n    int find(int x) {\n        if (par[x] == x) {\n            return\
    \ x;\n        } else {\n            par[x] = find(par[x]);\n            return\
    \ par[x];\n        }\n    }\n\n    // \u4F75\u5408(\u30DE\u30FC\u30B8\u5F8C\u306E\
    \u96C6\u5408\u306E\u6839\u3092\u8FD4\u3059)\n    int merge(int a, int b) {\n \
    \       int x = find(a);\n        int y = find(b);\n\n        if (x == y) {\n\
    \            tree[x] = false;\n            return x;\n        }\n        if (!tree[x]\
    \ or !tree[y]) {\n            tree[x] = tree[y] = false;\n        }\n\n      \
    \  groupcnt--;\n        if (rank[x] < rank[y]) {\n            par[x] = y;\n  \
    \          sz[y] += sz[x];\n            return y;\n        } else {\n        \
    \    par[y] = x;\n            sz[x] += sz[y];\n            if (rank[x] == rank[y])\
    \ {\n                rank[x]++;\n            }\n            return x;\n      \
    \  }\n    }\n\n    // \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\
    \u5B9A\n    bool same(int a, int b) {\n        return find(a) == find(b);\n  \
    \  }\n\n    // \u3042\u308B\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u30CE\u30FC\u30C9\u6570\n    ll size(int x) {\n        return sz[find(x)];\n\
    \    }\n\n    // \u96C6\u5408\u306E\u6570\n    int size() {\n        return groupcnt;\n\
    \    }\n\n    // \u6728\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\n    bool is_tree(int\
    \ x) {\n        return tree[find(x)];\n    }\n\n    // \u5168\u3066\u306E\u6839\
    \u3092\u53D6\u5F97\n    set<int> get_roots() {\n        set<int> res;\n      \
    \  rep(i, n) {\n            res.insert(find(i));\n        }\n        return res;\n\
    \    }\n};\n#line 43 \"src/template.hpp\"\n\n// from grid\n#line 3 \"src/grid/constants/dir4.hpp\"\
    \n\n// 4\u65B9\u5411\nconst vector<pii> dir4 = {{-1, 0}, {1, 0}, {0, -1}, {0,\
    \ 1}};\n#line 3 \"src/grid/constants/directions.hpp\"\n\n// \u5F8C\u65B9\u4E92\
    \u63DB\u7528\n#define directions dir4\n#line 2 \"src/grid/gridtoid.hpp\"\n\n//\
    \ \u30B0\u30EA\u30C3\u30C9\u21D2\u5217\u5909\u63DB\nll gridtoid(ll i, ll j, ll\
    \ W) { return i*W+j; }\n#line 3 \"src/grid/idtogrid.hpp\"\n\n// \u5217\u21D2\u30B0\
    \u30EA\u30C3\u30C9\u5909\u63DB\npll idtogrid(ll id, ll W) { return divmod(id,\
    \ W); }\n#line 48 \"src/template.hpp\"\n\n// from mystl\n#line 2 \"src/mystl/defaultdict.hpp\"\
    \n\n// \u6A19\u6E96map\u3092\u7D99\u627F\u3057\u305Fdefaultdict\ntemplate<typename\
    \ _Key, typename _Tp>\nstruct defaultdict : map<_Key, _Tp> {\n    const _Tp init;\n\
    \n    defaultdict() : init(_Tp()) {};\n\n    defaultdict(_Tp init) : init(init)\
    \ {}\n\n    _Tp& operator[](const _Key& k) {\n        if (this->count(k)) {\n\
    \            return map<_Key, _Tp>::operator[](k);\n        } else {\n       \
    \     return map<_Key, _Tp>::operator[](k) = init;\n        }\n    }\n\n    _Tp&\
    \ operator[](_Key&& k) {\n        if (this->count(k)) {\n            return map<_Key,\
    \ _Tp>::operator[](k);\n        } else {\n            return map<_Key, _Tp>::operator[](k)\
    \ = init;\n        }\n    }\n};\n#line 51 \"src/template.hpp\"\n\n// from numbers\n\
    #line 3 \"src/numbers/gcd.hpp\"\n\nll gcd(ll a, ll b) { return __gcd(a, b); }\n\
    \ntemplate<typename T>\nT gcd(const vector<T> &A) {\n    T res = 0;\n    for (auto\
    \ a : A) res = gcd(res, a);\n    return res;\n}\n#line 3 \"src/numbers/lcm.hpp\"\
    \n\n// \u9664\u7B97\u3092\u524D\u306B\u51FA\u3057\u3066\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3092\u9632\u3050\nll lcm(ll x, ll y) { return x/gcd(x, y)*y;\
    \ }\n\ntemplate<typename T>\nT lcm(const vector<T> &A) {\n    T res = 1;\n   \
    \ for (auto a : A) res = lcm(res, a);\n    return res;\n}\n#line 2 \"src/numbers/factorize.hpp\"\
    \n\n// \u7D20\u56E0\u6570\u5206\u89E3(vector\u30D9\u30FC\u30B9)\ntemplate<typename\
    \ T>\nvector<pair<T, int>> factorize(T n) {\n    vector<pair<T, int>> ret;\n \
    \   for (T i=2; i*i<=n; i++) {\n        int cnt = 0;\n        while (n % i ==\
    \ 0) {\n            n /= i;\n            cnt++;\n        }\n        if (cnt) ret.emplace_back(i,\
    \ cnt);\n    }\n    if (n > 1) ret.emplace_back(n, 1);\n    return ret;\n}\n#line\
    \ 2 \"src/numbers/divisors.hpp\"\n\n// \u7D04\u6570\u5217\u6319\ntemplate<typename\
    \ T>\nvector<T> divisors(T n) {\n    vector<T> res;\n    for (T i=1; i*i<=n; i++)\
    \ {\n        if (n%i == 0) {\n            res.eb(i);\n            if (n/i != i)\
    \ res.eb(n/i);\n        }\n    }\n    // sort(ALL(res));\n    return res;\n}\n\
    #line 2 \"src/numbers/isqrt.hpp\"\n\n// \u6574\u6570\u3067\u6B63\u78BA\u306Bsqrt\u3092\
    \u8FD4\u3059\nll isqrt(ll n, bool ceil=false) {\n    ll ok = 0;\n    ll ng = 3037000500;\n\
    \    while (ng - ok > 1) {\n        ll m = ok + (ng - ok) / 2;\n        if (m\
    \ * m <= n) {\n            ok = m;\n        } else {\n            ng = m;\n  \
    \      }\n    }\n    if (ceil and ok*ok != n) ok++;\n    return ok;\n}\n#line\
    \ 58 \"src/template.hpp\"\n\n// from segment\n#line 2 \"src/segment/Accumulate.hpp\"\
    \n\n// \u7D2F\u7A4D\u548C\ntemplate<typename T>\nstruct Accumulate {\n    vector<T>\
    \ dat;\n    int N;\n\n    Accumulate(int N) : N(N) {\n        dat.resize(N);\n\
    \    }\n\n    Accumulate(const vector<T> &A) : N(A.size()), dat(A) {\n       \
    \ build();\n    }\n\n    void set(int i, T a) {\n        dat[i] = a;\n    }\n\n\
    \    void add(int i, T a) {\n        dat[i] += a;\n    }\n\n    void build() {\n\
    \        rep(i, N-1) {\n            dat[i+1] += dat[i];\n        }\n        dat.insert(dat.begin(),\
    \ 0);\n    }\n\n    T query(int l, int r) {\n        assert(0 <= l and l <= N\
    \ and 0 <= r and r <= N);\n        return dat[r]-dat[l];\n    }\n\n    T get(int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    T operator[](int i) {\n  \
    \      return query(i, i+1);\n    }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\
    \u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\
    \u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r, ll x) {\n        if (l\
    \ > r) return -1;\n        ll l_sm = query(0, l);\n        int ok = r + 1;\n \
    \       int ng = l - 1;\n        while (ng+1 < ok) {\n            int mid = (ok+ng)\
    \ / 2;\n            if (query(0, mid+1) - l_sm >= x) {\n                ok = mid;\n\
    \            } else {\n                ng = mid;\n            }\n        }\n \
    \       if (ok != r+1) {\n            return ok;\n        } else {\n         \
    \   return -1;\n        }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\u304B\
    \u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\
    \u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r, ll x) {\n        if (l\
    \ > r) return -1;\n        ll r_sm = query(0, r+1);\n        int ok = l - 1;\n\
    \        int ng = r + 1;\n        while (ok+1 < ng) {\n            int mid = (ok+ng)\
    \ / 2;\n            if (r_sm - query(0, mid) >= x) {\n                ok = mid;\n\
    \            } else {\n                ng = mid;\n            }\n        }\n \
    \       if (ok != l-1) {\n            return ok;\n        } else {\n         \
    \   return -1;\n        }\n    }\n};\n#line 2 \"src/segment/BIT.hpp\"\n\n// Binary\
    \ Indexed Tree\ntemplate<typename T>\nstruct BIT {\n\n    int sz;\n    vector<T>\
    \ tree;\n\n    BIT(int n) {\n        // 0-indexed\n        n++;\n        sz =\
    \ 1;\n        while (sz < n) {\n            sz *= 2;\n        }\n        tree.resize(sz);\n\
    \    }\n\n    // [0, i]\u3092\u5408\u8A08\u3059\u308B\n    T sum(int i) {\n  \
    \      T s = 0;\n        i++;\n        while (i > 0) {\n            s += tree[i-1];\n\
    \            i -= i & -i;\n        }\n        return s;\n    }\n\n    void add(int\
    \ i, T x) {\n        i++;\n        while (i <= sz) {\n            tree[i-1] +=\
    \ x;\n            i += i & -i;\n        }\n    }\n\n    // \u533A\u9593\u548C\u306E\
    \u53D6\u5F97 [l, r)\n    T query(int l, int r) {\n        return sum(r-1) - sum(l-1);\n\
    \    }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\n    void\
    \ update(int i, T x) {\n        add(i, x - get(i));\n    }\n\n    T operator[](int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    void print(int n) {\n    \
    \    rep(i, n) {\n            cout << query(i, i+1);\n            if (i == n-1)\
    \ cout << endl;\n            else cout << ' ';\n        }\n    }\n\n    // \u533A\
    \u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\
    \u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l,\
    \ int r, ll x) {\n        if (l > r) return -1;\n        ll l_sm = sum(l-1);\n\
    \        int ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n\
    \            int mid = (ok+ng) / 2;\n            if (sum(mid) - l_sm >= x) {\n\
    \                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        if (ok != r+1) {\n            return ok;\n\
    \        } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = sum(r);\n        int\
    \ ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n        \
    \    int mid = (ok+ng) / 2;\n            if (r_sm - sum(mid-1) >= x) {\n     \
    \           ok = mid;\n            } else {\n                ng = mid;\n     \
    \       }\n        }\n        if (ok != l-1) {\n            return ok;\n     \
    \   } else {\n            return -1;\n        }\n    }\n};\n#line 2 \"src/segment/SegmentTree.hpp\"\
    \n\ntemplate<typename Monoid, typename F>\nstruct SegmentTree {\n\n    int sz;\n\
    \    vector<Monoid> seg;\n\n    const F f;\n    const Monoid M1;\n\n    SegmentTree(int\
    \ n, const F f, const Monoid &M1) : f(f), M1(M1) {\n        sz = 1;\n        while(sz\
    \ < n) sz <<= 1;\n        seg.assign(2 * sz, M1);\n    }\n\n    SegmentTree(const\
    \ F f, const Monoid &M1) : f(f), M1(M1) {}\n\n    void resize(int n) {\n     \
    \   sz = 1;\n        while(sz < n) sz <<= 1;\n        seg.resize(2 * sz, M1);\n\
    \    }\n\n    void clear() {\n        seg.clear();\n    }\n\n    void set(int\
    \ k, const Monoid &x) {\n        seg[k+sz] = x;\n    }\n\n    void build() {\n\
    \        for(int k = sz - 1; k > 0; k--) {\n            seg[k] = f(seg[2*k], seg[2*k+1]);\n\
    \        }\n    }\n\n    void build(const vector<Monoid> &A) {\n        int n\
    \ = A.size();\n        resize(n);\n        rep(i, n) set(i, A[i]);\n        build();\n\
    \    }\n\n    void update(int k, const Monoid &x) {\n        k += sz;\n      \
    \  seg[k] = x;\n        while(k >>= 1) {\n            seg[k] = f(seg[2*k], seg[2*k+1]);\n\
    \        }\n    }\n\n    Monoid query(int a, int b) {\n        Monoid L = M1,\
    \ R = M1;\n        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n        \
    \    if(a & 1) L = f(L, seg[a++]);\n            if(b & 1) R = f(seg[--b], R);\n\
    \        }\n        return f(L, R);\n    }\n\n    Monoid operator[](const int\
    \ &k) const {\n        return seg[k+sz];\n    }\n\n    Monoid all() {\n      \
    \  return seg[1];\n    }\n\n    void print(int n) {\n        for (int i=0; i<n;\
    \ i++) {\n            cout << query(i, i+1);\n            if (i == n-1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    template<typename\
    \ C>\n    int find_subtree(int a, const C &check, Monoid &M, bool type) {\n  \
    \      while(a < sz) {\n            Monoid nxt = type ? f(seg[2 * a + type], M)\
    \ : f(M, seg[2 * a + type]);\n            if(check(nxt)) a = 2 * a + type;\n \
    \           else M = nxt, a = 2 * a + 1 - type;\n        }\n        return a -\
    \ sz;\n    }\n\n    // \u7BC4\u56F2[a,N)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\
    \u3051\u308C\u3070-1)\n    template<typename C>\n    int find_first(int a, const\
    \ C &check) {\n        Monoid L = M1;\n        if(a <= 0) {\n            if(check(f(L,\
    \ seg[1]))) return find_subtree(1, check, L, false);\n            return -1;\n\
    \        }\n        int b = sz;\n        for(a += sz, b += sz; a < b; a >>= 1,\
    \ b >>= 1) {\n            if(a & 1) {\n                Monoid nxt = f(L, seg[a]);\n\
    \                if(check(nxt)) return find_subtree(a, check, L, false);\n   \
    \             L = nxt;\n                ++a;\n            }\n        }\n     \
    \   return -1;\n    }\n\n    // \u7BC4\u56F2[0,b)\u3067check\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\
    \u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_last(int\
    \ b, const C &check) {\n        Monoid R = M1;\n        if(b >= sz) {\n      \
    \      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);\n     \
    \       return -1;\n        }\n        int a = sz;\n        for(b += sz; a < b;\
    \ a >>= 1, b >>= 1) {\n            if(b & 1) {\n                Monoid nxt = f(seg[--b],\
    \ R);\n                if(check(nxt)) return find_subtree(b, check, R, true);\n\
    \                R = nxt;\n            }\n        }\n        return -1;\n    }\n\
    };\n\ntemplate<typename Monoid, typename F>\nSegmentTree<Monoid, F> get_segment_tree(int\
    \ N, const F& f, const Monoid& M1) {\n    return {N, f, M1};\n}\n\ntemplate<typename\
    \ Monoid, typename F>\nSegmentTree<Monoid, F> get_segment_tree(const F& f, const\
    \ Monoid& M1) {\n    return {f, M1};\n}\n#line 63 \"src/template.hpp\"\n\n// from\
    \ string\n#line 2 \"src/string/constants/digits.hpp\"\n\nconst string digits =\
    \ \"0123456789\";\n#line 3 \"src/string/constants/ascii_lowercase.hpp\"\n\nconst\
    \ string ascii_lowercase = \"abcdefghijklmnopqrstuvwxyz\";\n#line 3 \"src/string/constants/ascii_uppercase.hpp\"\
    \n\nconst string ascii_uppercase = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n#line 3 \"\
    src/string/zfill.hpp\"\n\nstring zfill(string str, int len) {\n    string zeros;\n\
    \    int n = str.size();\n    rep(i, len-n) zeros += '0';\n    return zeros+str;\n\
    }\n#line 2 \"src/string/bin.hpp\"\n\nstring bin(ll x) {\n    string res;\n   \
    \ while (x) {\n        if (x & 1) {\n            res += '1';\n        } else {\n\
    \            res += '0';\n        }\n        x >>= 1;\n    }\n    reverse(ALL(res));\n\
    \    if (res == \"\") res += '0';\n    return res;\n}\n#line 70 \"src/template.hpp\"\
    \n"
  code: '#include "base.hpp"

    #include "macros.hpp"


    // from common

    #include "common/listnd.hpp"

    #include "common/input.hpp"

    #include "common/print.hpp"

    #include "common/yesno.hpp"

    #include "common/toint.hpp"

    #include "common/tochar.hpp"

    #include "common/ceil.hpp"

    #include "common/modulo.hpp"

    #include "common/divmod.hpp"

    #include "common/chmin.hpp"

    #include "common/chmax.hpp"

    #include "common/sum.hpp"

    #include "common/min.hpp"

    #include "common/max.hpp"

    #include "common/pow.hpp"

    #include "common/popcount.hpp"

    #include "common/bit_length.hpp"

    #include "common/bisect.hpp"

    #include "common/Counter.hpp"

    #include "common/bisearch.hpp"

    #include "common/zip.hpp"

    #include "common/Compress.hpp"

    #include "common/RLE.hpp"

    #include "common/mul_overflow.hpp"

    #include "common/split.hpp"

    #include "common/join.hpp"

    #include "common/sorted.hpp"

    #include "common/reversed.hpp"


    // from combinatorics

    #include "combinatorics/ModTools.hpp"

    #include "combinatorics/permutations.hpp"

    #include "combinatorics/combinations.hpp"

    #include "combinatorics/nC2.hpp"

    #include "combinatorics/factorial.hpp"


    // from graph

    #include "graph/UnionFind.hpp"


    // from grid

    #include "grid/constants/directions.hpp"

    #include "grid/gridtoid.hpp"

    #include "grid/idtogrid.hpp"


    // from mystl

    #include "mystl/defaultdict.hpp"


    // from numbers

    #include "numbers/gcd.hpp"

    #include "numbers/lcm.hpp"

    #include "numbers/factorize.hpp"

    #include "numbers/divisors.hpp"

    #include "numbers/isqrt.hpp"


    // from segment

    #include "segment/Accumulate.hpp"

    #include "segment/BIT.hpp"

    #include "segment/SegmentTree.hpp"


    // from string

    #include "string/constants/digits.hpp"

    #include "string/constants/ascii_lowercase.hpp"

    #include "string/constants/ascii_uppercase.hpp"

    #include "string/zfill.hpp"

    #include "string/bin.hpp"

    '
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/listnd.hpp
  - src/common/input.hpp
  - src/common/print.hpp
  - src/common/yesno.hpp
  - src/common/toint.hpp
  - src/common/tochar.hpp
  - src/common/ceil.hpp
  - src/common/modulo.hpp
  - src/common/divmod.hpp
  - src/common/chmin.hpp
  - src/common/chmax.hpp
  - src/common/sum.hpp
  - src/common/min.hpp
  - src/common/max.hpp
  - src/common/pow.hpp
  - src/common/popcount.hpp
  - src/common/bit_length.hpp
  - src/common/bisect.hpp
  - src/common/Counter.hpp
  - src/common/bisearch.hpp
  - src/common/zip.hpp
  - src/common/Compress.hpp
  - src/common/RLE.hpp
  - src/common/mul_overflow.hpp
  - src/common/split.hpp
  - src/common/join.hpp
  - src/common/to_string.hpp
  - src/common/sorted.hpp
  - src/common/reversed.hpp
  - src/combinatorics/ModTools.hpp
  - src/combinatorics/permutations.hpp
  - src/combinatorics/combinations.hpp
  - src/combinatorics/nC2.hpp
  - src/combinatorics/factorial.hpp
  - src/graph/UnionFind.hpp
  - src/grid/constants/directions.hpp
  - src/grid/constants/dir4.hpp
  - src/grid/gridtoid.hpp
  - src/grid/idtogrid.hpp
  - src/mystl/defaultdict.hpp
  - src/numbers/gcd.hpp
  - src/numbers/lcm.hpp
  - src/numbers/factorize.hpp
  - src/numbers/divisors.hpp
  - src/numbers/isqrt.hpp
  - src/segment/Accumulate.hpp
  - src/segment/BIT.hpp
  - src/segment/SegmentTree.hpp
  - src/string/constants/digits.hpp
  - src/string/constants/ascii_lowercase.hpp
  - src/string/constants/ascii_uppercase.hpp
  - src/string/zfill.hpp
  - src/string/bin.hpp
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: src/template.hpp
---
