---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/Compress.hpp
    title: src/common/Compress.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
  - icon: ':warning:'
    path: src/graph/HeavyLightDecomposition.hpp
    title: src/graph/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/tree/auxiliary_tree.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename T>\n\
    int bisect_left(const vector<T> &A, T val, int lo = 0) {\n    return lower_bound(A.begin()\
    \ + lo, A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo = 0) {\n    return upper_bound(A.begin() + lo, A.end(),\
    \ val) - A.begin();\n}\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll,\
    \ ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/common/Compress.hpp\"\
    \n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\u30D9\u30FC\u30B9)\n\
    template<typename T>\nstruct Compress {\n    int N;\n    vector<T> dat;\n    bool\
    \ built = false;\n\n    Compress() {}\n\n    Compress(const vector<T> &A) : dat(A)\
    \ {\n        build();\n    }\n\n    void build() {\n        sort(dat.begin(),\
    \ dat.end());\n        dat.erase(unique(dat.begin(), dat.end()), dat.end());\n\
    \        N = dat.size();\n        built = true;\n    }\n\n    void add(T x) {\n\
    \        assert(not built);\n        dat.emplace_back(x);\n    }\n\n    // \u53EF\
    \u5909\u9577\u5F15\u6570\u3001cp.add(l, r); \u3068\u304B\u3067\u304D\u308B\n \
    \   template<typename... Ts>\n    void add(const T val, Ts... ts) {\n        dat.emplace_back(val);\n\
    \        if constexpr (sizeof...(Ts) > 0) {\n            add(ts...);\n       \
    \ }\n    }\n\n    void add(const vector<T> &A) {\n        for (auto a : A) {\n\
    \            add(a);\n        }\n    }\n\n    int zip(T x) {\n        assert(built);\n\
    \        return bisect_left(dat, x);\n    }\n\n    T unzip(int x) {\n        assert(built);\n\
    \        return dat[x];\n    }\n\n    int operator[](T x) {\n        return zip(x);\n\
    \    }\n\n    int size() {\n        assert(built);\n        return dat.size();\n\
    \    }\n\n    // \u5EA7\u5727\u5F8C\u306E\u4F4D\u7F6E[i,i+1)\u306E\u5EA7\u5727\
    \u524D\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059\n    T size(int i) {\n      \
    \  assert(built and 0 <= i and i < N);\n        if (i == N - 1) {\n          \
    \  return 1;\n        } else {\n            return unzip(i + 1) - unzip(i);\n\
    \        }\n    }\n\n    vector<T> zip(const vector<T> &A) {\n        int M =\
    \ A.size();\n        vector<T> res(M);\n        for (int i = 0; i < M; i++) {\n\
    \            res[i] = zip(A[i]);\n        }\n        return res;\n    }\n};\n\n\
    // \u5EA7\u6A19\u5727\u7E2E(map\u30D9\u30FC\u30B9)(\u65E7)\n// template<typename\
    \ T>\n// pair<map<T, int>, vector<T>> compress(vector<T> unzipped) {\n//     map<T,\
    \ int> zipped;\n//     sort(unzipped.begin(), unzipped.end());\n//     unzipped.erase(unique(unzipped.begin(),\
    \ unzipped.end()), unzipped.end());\n//     for (int i = 0; i < unzipped.size();\
    \ i++) {\n//         zipped[unzipped[i]] = i;\n//     }\n//     return {zipped,\
    \ unzipped};\n// }\n#line 3 \"src/graph/HeavyLightDecomposition.hpp\"\n\n// HL\u5206\
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
    \u7167)\nstruct HeavyLightDecomposition {\npublic:\n    int N;\n    vvi nodes;\n\
    \    vector<int> sz, in, out, head, rev, par, dep;\n\n    // \u9802\u70B9v\u304B\
    \u3089k\u56DE\u9061\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int la(int\
    \ v, int k) {\n        while (1) {\n            int u = head[v];\n           \
    \ if (in[v] - k >= in[u]) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        for (;; v = par[head[v]]) {\n            if (in[u] > in[v])\
    \ swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n    }\n\
    \n    // \u9802\u70B9u\u304B\u3089v\u306B\u5411\u304B\u3063\u3066k\u500B\u9032\
    \u3093\u3060\u9802\u70B9\u3092\u8FD4\u3059(u\u306Fv\u306E\u7956\u5148\u3067\u3042\
    \u308B\u3053\u3068)\n    int next(int u, int v, int k) {\n        // assert(lca(u,\
    \ v) == u);\n        int d = dist(u, v);\n        assert(d >= k);\n        return\
    \ la(v, d - k);\n    }\n\n    int dist(int u, int v) const {\n        return dep[u]\
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
    \  explicit HeavyLightDecomposition(const vvi &nodes, int root = 0) : N(nodes.size()),\
    \ nodes(nodes) {\n        sz.assign(N, 0);\n        in.assign(N, 0);\n       \
    \ out.assign(N, 0);\n        head.assign(N, root);\n        rev.assign(N, 0);\n\
    \        par.assign(N, 0);\n        dep.assign(N, 0);\n        dfs_sz(root, -1,\
    \ 0);\n        int t = 0;\n        dfs_hld(root, -1, t);\n    }\n\n    int operator[](int\
    \ u) const {\n        assert(0 <= u && u < N);\n        return in[u];\n    }\n\
    \nprivate:\n    void dfs_sz(int idx, int p, int d) {\n        dep[idx] = d;\n\
    \        par[idx] = p;\n        sz[idx] = 1;\n        if (nodes[idx].size() &&\
    \ nodes[idx][0] == p) swap(nodes[idx][0], nodes[idx].back());\n        for (auto\
    \ &to : nodes[idx]) {\n            if (to == p) continue;\n            dfs_sz(to,\
    \ idx, d + 1);\n            sz[idx] += sz[to];\n            if (sz[nodes[idx][0]]\
    \ < sz[to]) swap(nodes[idx][0], to);\n        }\n    }\n\n    void dfs_hld(int\
    \ idx, int p, int &times) {\n        in[idx] = times++;\n        rev[in[idx]]\
    \ = idx;\n        for (auto &to : nodes[idx]) {\n            if (to == p) continue;\n\
    \            head[to] = (nodes[idx][0] == to ? head[idx] : to);\n            dfs_hld(to,\
    \ idx, times);\n        }\n        out[idx] = times;\n    }\n};\n#line 5 \"src/graph/AuxiliaryTree.hpp\"\
    \n\n// ## Auxiliary Tree\n// ### \u8AAC\u660E\n// - \u6307\u5B9A\u3057\u305F\u9802\
    \u70B9\u96C6\u5408S\u3068\u3001\u305D\u308C\u3089\u306ELCA\u306E\u307F\u3067\u69CB\
    \u6210\u3055\u308C\u308B\u30B0\u30E9\u30D5\u3092\u8A08\u7B97\u91CF|S|log|S|\u7A0B\
    \u5EA6\u3067\u69CB\u7BC9\u3059\u308B\u3002\n// ### \u4F7F\u3044\u65B9\n// - \u5168\
    \u4F53\u306E\u30B0\u30E9\u30D5\u304C\u78BA\u5B9A\u3057\u305F\u6642\u70B9\u3067\
    \u96A3\u63A5\u30EA\u30B9\u30C8nodes\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n\
    // - \u5404\u30AF\u30A8\u30EA\u6BCE\u306B\u4F7F\u3046\u9802\u70B9\u96C6\u5408\u306E\
    \u914D\u5217A\u3092\u6E21\u3057\u3066build\n// - \u3053\u306E\u30AF\u30E9\u30B9\
    \u672C\u4F53\u3078\u306E\u6DFB\u5B57\u30A2\u30AF\u30BB\u30B9\u3067\u96A3\u63A5\
    \u30EA\u30B9\u30C8\u307F\u305F\u3044\u306B\u4F7F\u3048\u308B\u3002\n// - \u9802\
    \u70B9\u756A\u53F7\u306F\u305D\u306E\u307E\u307E\u306A\u306E\u3067\u3001\u8DDD\
    \u96E2\u304C\u5FC5\u8981\u306A\u3089dist\u3067\u53D6\u308C\u308B\u3088\u3046\u306B\
    \u3057\u305F\u3002\n// - get_vertices\u3067\u76F4\u8FD1\u306Ebuild\u3067\u4F7F\
    \u7528\u3057\u305F\u9802\u70B9\u3092\u5217\u6319\u3067\u304D\u308B\u3088\u3046\
    \u306B\u3057\u305F\u3002  \n//   LCA\u9802\u70B9\u306F\u8907\u6570\u56DE\u4F7F\
    \u308F\u308C\u308B\u306E\u3067\u3001\u3053\u308C\u3092\u72B6\u614B\u623B\u3057\
    \u306B\u4F7F\u3048\u308B\u3002\n// - \u96A3\u63A5\u30EA\u30B9\u30C8\u3067\u306A\
    \u304F\u8FBA\u96C6\u5408\u304C\u4F7F\u3044\u305F\u3044\u6642\u306B\u306Fget_edges\u304C\
    \u4F7F\u3048\u308B\u3002\n// - \u5143\u9802\u70B9\u756A\u53F7\u3067\u306F\u306A\
    \u304F\u3001\u30B5\u30A4\u30BA\u3092\u5C0F\u3055\u304F\u3057\u305F\u30B0\u30E9\
    \u30D5\u3067\u4F55\u304B\u3057\u305F\u3044\u6642\u306Fget_compress\u3092\u4F7F\
    \u3048\u3070\u5EA7\u5727\u60C5\u5831\u304C\u5F97\u3089\u308C\u308B\u3002\n// ###\
    \ \u4F7F\u7528\u4F8B\n// - \u8272\u6BCE\u306B\u6728DP\u3084DFS\u3059\u308B\uFF1A\
    abc340_g,abc359_g,typical90_ai,cf613D,cf1923E\n// - \u7E2E\u7D04\u5F8C\u30B0\u30E9\
    \u30D5\u3092\u4F7F\u3063\u3066bitDP\uFF1Acf1929E\n// - \u7E2E\u7D04\u5F8C\u30B0\
    \u30E9\u30D5\u3067\u6B21\u6570\u30C1\u30A7\u30C3\u30AF\uFF1Acf1702G1\n// - \u8272\
    \u6BCE\u306B\u5168\u65B9\u4F4D\u6728DP\uFF1Aabc359_g\n// ### \u53C2\u8003\n//\
    \ https://suisen-cp.github.io/cp-library-cpp/library/tree/auxiliary_tree.hpp\n\
    struct AuxiliaryTree {\n    int N;\n    HeavyLightDecomposition hld;\n\n    AuxiliaryTree()\
    \ = default;\n    AuxiliaryTree(const vvi &nodes) : N(nodes.size()), hld(nodes),\
    \ _aux(N) {}\n\n    const vector<int> &operator[](int u) const {\n        return\
    \ _aux[u];\n    }\n\n    int dist(int u, int v) {\n        return hld.dist(u,\
    \ v);\n    }\n\n    int build(vector<int> vs) {\n        const int k = vs.size();\n\
    \        for (int v : _upd) _aux[v].clear();\n        _upd.clear();\n\n      \
    \  sort(vs.begin(), vs.end(), [this](int i, int j) {\n            return hld.in[i]\
    \ < hld.in[j];\n        });\n\n        copy(vs.begin(), vs.end(), back_inserter(_upd));\n\
    \n        vector<int> st{vs[0]};\n        for (int i = 0; i < k - 1; ++i) {\n\
    \            const int w = hld.lca(vs[i], vs[i + 1]);\n\n            if (w !=\
    \ vs[i]) {\n                _upd.push_back(w);\n                int last = st.back();\n\
    \                st.pop_back();\n                while (st.size() and hld.dep[w]\
    \ < hld.dep[st.back()]) {\n                    int u = st.back();\n          \
    \          _aux[u].push_back(last);\n                    _aux[last].push_back(u);\n\
    \                    last = st.back();\n                    st.pop_back();\n \
    \               }\n\n                if (st.empty() or st.back() != w) {\n   \
    \                 st.push_back(w);\n                    vs.push_back(w);\n   \
    \                 _aux[w].push_back(last);\n                    _aux[last].push_back(w);\n\
    \                } else {\n                    _aux[w].push_back(last);\n    \
    \                _aux[last].push_back(w);\n                }\n            }\n\n\
    \            st.push_back(vs[i + 1]);\n        }\n        const int siz = st.size();\n\
    \        for (int i = 0; i < siz - 1; ++i) {\n            _aux[st[i]].push_back(st[i\
    \ + 1]);\n            _aux[st[i + 1]].push_back(st[i]);\n        }\n\n       \
    \ // \u91CD\u8907\u524A\u9664\n        sort(_upd.begin(), _upd.end()), _upd.erase(unique(_upd.begin(),\
    \ _upd.end()), _upd.end());\n\n        return st[0];\n    }\n\n    // \u73FE\u5728\
    \u306E\u30B0\u30E9\u30D5\u306E\u5EA7\u5727\u60C5\u5831(\u5143\u9802\u70B9\u756A\
    \u53F7\u21D4\u5EA7\u5727\u5F8C\u306E\u756A\u53F7)\u3092\u8FD4\u3059\n    Compress<int>\
    \ get_compress() {\n        Compress<int> cp(get_vertices());\n        return\
    \ cp;\n    }\n\n    // \u73FE\u5728\u306E\u30B0\u30E9\u30D5\u306E\u8FBA\u96C6\u5408\
    (\u7121\u5411\u8FBA)\u3092\u8FD4\u3059\n    vector<pair<int, int>> get_edges()\
    \ {\n        vector<pair<int, int>> edges;\n        for (auto u : get_vertices())\
    \ {\n            for (auto v : _aux[u]) {\n                if (u > v) continue;\n\
    \                edges.push_back({u, v});\n            }\n        }\n        return\
    \ edges;\n    }\n\n    // \u76F4\u8FD1\u306Ebuild\u3067\u4F7F\u7528\u3057\u305F\
    \u9802\u70B9\u3092\u5217\u6319(\u72B6\u614B\u623B\u3057\u3068\u304B\u306B\u4F7F\
    \u3048\u308B)\n    vector<int> get_vertices() {\n        return _upd;\n    }\n\
    \nprivate:\n    vector<vector<int>> _aux;\n    vector<int> _upd;\n};\n"
  code: "#pragma once\n#include \"../common/Compress.hpp\"\n#include \"../macros.hpp\"\
    \n#include \"HeavyLightDecomposition.hpp\"\n\n// ## Auxiliary Tree\n// ### \u8AAC\
    \u660E\n// - \u6307\u5B9A\u3057\u305F\u9802\u70B9\u96C6\u5408S\u3068\u3001\u305D\
    \u308C\u3089\u306ELCA\u306E\u307F\u3067\u69CB\u6210\u3055\u308C\u308B\u30B0\u30E9\
    \u30D5\u3092\u8A08\u7B97\u91CF|S|log|S|\u7A0B\u5EA6\u3067\u69CB\u7BC9\u3059\u308B\
    \u3002\n// ### \u4F7F\u3044\u65B9\n// - \u5168\u4F53\u306E\u30B0\u30E9\u30D5\u304C\
    \u78BA\u5B9A\u3057\u305F\u6642\u70B9\u3067\u96A3\u63A5\u30EA\u30B9\u30C8nodes\u3092\
    \u6E21\u3057\u3066\u521D\u671F\u5316\n// - \u5404\u30AF\u30A8\u30EA\u6BCE\u306B\
    \u4F7F\u3046\u9802\u70B9\u96C6\u5408\u306E\u914D\u5217A\u3092\u6E21\u3057\u3066\
    build\n// - \u3053\u306E\u30AF\u30E9\u30B9\u672C\u4F53\u3078\u306E\u6DFB\u5B57\
    \u30A2\u30AF\u30BB\u30B9\u3067\u96A3\u63A5\u30EA\u30B9\u30C8\u307F\u305F\u3044\
    \u306B\u4F7F\u3048\u308B\u3002\n// - \u9802\u70B9\u756A\u53F7\u306F\u305D\u306E\
    \u307E\u307E\u306A\u306E\u3067\u3001\u8DDD\u96E2\u304C\u5FC5\u8981\u306A\u3089\
    dist\u3067\u53D6\u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3002\n// - get_vertices\u3067\
    \u76F4\u8FD1\u306Ebuild\u3067\u4F7F\u7528\u3057\u305F\u9802\u70B9\u3092\u5217\u6319\
    \u3067\u304D\u308B\u3088\u3046\u306B\u3057\u305F\u3002  \n//   LCA\u9802\u70B9\
    \u306F\u8907\u6570\u56DE\u4F7F\u308F\u308C\u308B\u306E\u3067\u3001\u3053\u308C\
    \u3092\u72B6\u614B\u623B\u3057\u306B\u4F7F\u3048\u308B\u3002\n// - \u96A3\u63A5\
    \u30EA\u30B9\u30C8\u3067\u306A\u304F\u8FBA\u96C6\u5408\u304C\u4F7F\u3044\u305F\
    \u3044\u6642\u306B\u306Fget_edges\u304C\u4F7F\u3048\u308B\u3002\n// - \u5143\u9802\
    \u70B9\u756A\u53F7\u3067\u306F\u306A\u304F\u3001\u30B5\u30A4\u30BA\u3092\u5C0F\
    \u3055\u304F\u3057\u305F\u30B0\u30E9\u30D5\u3067\u4F55\u304B\u3057\u305F\u3044\
    \u6642\u306Fget_compress\u3092\u4F7F\u3048\u3070\u5EA7\u5727\u60C5\u5831\u304C\
    \u5F97\u3089\u308C\u308B\u3002\n// ### \u4F7F\u7528\u4F8B\n// - \u8272\u6BCE\u306B\
    \u6728DP\u3084DFS\u3059\u308B\uFF1Aabc340_g,abc359_g,typical90_ai,cf613D,cf1923E\n\
    // - \u7E2E\u7D04\u5F8C\u30B0\u30E9\u30D5\u3092\u4F7F\u3063\u3066bitDP\uFF1Acf1929E\n\
    // - \u7E2E\u7D04\u5F8C\u30B0\u30E9\u30D5\u3067\u6B21\u6570\u30C1\u30A7\u30C3\u30AF\
    \uFF1Acf1702G1\n// - \u8272\u6BCE\u306B\u5168\u65B9\u4F4D\u6728DP\uFF1Aabc359_g\n\
    // ### \u53C2\u8003\n// https://suisen-cp.github.io/cp-library-cpp/library/tree/auxiliary_tree.hpp\n\
    struct AuxiliaryTree {\n    int N;\n    HeavyLightDecomposition hld;\n\n    AuxiliaryTree()\
    \ = default;\n    AuxiliaryTree(const vvi &nodes) : N(nodes.size()), hld(nodes),\
    \ _aux(N) {}\n\n    const vector<int> &operator[](int u) const {\n        return\
    \ _aux[u];\n    }\n\n    int dist(int u, int v) {\n        return hld.dist(u,\
    \ v);\n    }\n\n    int build(vector<int> vs) {\n        const int k = vs.size();\n\
    \        for (int v : _upd) _aux[v].clear();\n        _upd.clear();\n\n      \
    \  sort(vs.begin(), vs.end(), [this](int i, int j) {\n            return hld.in[i]\
    \ < hld.in[j];\n        });\n\n        copy(vs.begin(), vs.end(), back_inserter(_upd));\n\
    \n        vector<int> st{vs[0]};\n        for (int i = 0; i < k - 1; ++i) {\n\
    \            const int w = hld.lca(vs[i], vs[i + 1]);\n\n            if (w !=\
    \ vs[i]) {\n                _upd.push_back(w);\n                int last = st.back();\n\
    \                st.pop_back();\n                while (st.size() and hld.dep[w]\
    \ < hld.dep[st.back()]) {\n                    int u = st.back();\n          \
    \          _aux[u].push_back(last);\n                    _aux[last].push_back(u);\n\
    \                    last = st.back();\n                    st.pop_back();\n \
    \               }\n\n                if (st.empty() or st.back() != w) {\n   \
    \                 st.push_back(w);\n                    vs.push_back(w);\n   \
    \                 _aux[w].push_back(last);\n                    _aux[last].push_back(w);\n\
    \                } else {\n                    _aux[w].push_back(last);\n    \
    \                _aux[last].push_back(w);\n                }\n            }\n\n\
    \            st.push_back(vs[i + 1]);\n        }\n        const int siz = st.size();\n\
    \        for (int i = 0; i < siz - 1; ++i) {\n            _aux[st[i]].push_back(st[i\
    \ + 1]);\n            _aux[st[i + 1]].push_back(st[i]);\n        }\n\n       \
    \ // \u91CD\u8907\u524A\u9664\n        sort(_upd.begin(), _upd.end()), _upd.erase(unique(_upd.begin(),\
    \ _upd.end()), _upd.end());\n\n        return st[0];\n    }\n\n    // \u73FE\u5728\
    \u306E\u30B0\u30E9\u30D5\u306E\u5EA7\u5727\u60C5\u5831(\u5143\u9802\u70B9\u756A\
    \u53F7\u21D4\u5EA7\u5727\u5F8C\u306E\u756A\u53F7)\u3092\u8FD4\u3059\n    Compress<int>\
    \ get_compress() {\n        Compress<int> cp(get_vertices());\n        return\
    \ cp;\n    }\n\n    // \u73FE\u5728\u306E\u30B0\u30E9\u30D5\u306E\u8FBA\u96C6\u5408\
    (\u7121\u5411\u8FBA)\u3092\u8FD4\u3059\n    vector<pair<int, int>> get_edges()\
    \ {\n        vector<pair<int, int>> edges;\n        for (auto u : get_vertices())\
    \ {\n            for (auto v : _aux[u]) {\n                if (u > v) continue;\n\
    \                edges.push_back({u, v});\n            }\n        }\n        return\
    \ edges;\n    }\n\n    // \u76F4\u8FD1\u306Ebuild\u3067\u4F7F\u7528\u3057\u305F\
    \u9802\u70B9\u3092\u5217\u6319(\u72B6\u614B\u623B\u3057\u3068\u304B\u306B\u4F7F\
    \u3048\u308B)\n    vector<int> get_vertices() {\n        return _upd;\n    }\n\
    \nprivate:\n    vector<vector<int>> _aux;\n    vector<int> _upd;\n};\n"
  dependsOn:
  - src/common/Compress.hpp
  - src/common/bisect.hpp
  - src/base.hpp
  - src/macros.hpp
  - src/graph/HeavyLightDecomposition.hpp
  isVerificationFile: false
  path: src/graph/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-06-25 17:52:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/src/graph/AuxiliaryTree.hpp
- /library/src/graph/AuxiliaryTree.hpp.html
title: src/graph/AuxiliaryTree.hpp
---
