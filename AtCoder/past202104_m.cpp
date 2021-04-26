/*
・終了後自力AC！だいたい方針合ってた。。
・クエリ平方分割、座圧
・平方分割で個数管理する。まともにやると、mapのlog乗るとTLEで、
　先に座圧しておいてクエリ内での個数管理をvectorにしてやったら無事AC1.56秒。(制約4秒)
　20万に√つくからね。それにさらにmapのlogはきつい。
　でも逆に言えばそれがなければ2秒でも間に合うんだよね。。
・バケット管理してるとこと、まとめて管理してるとこで、
　切り替わる時にそれぞれ反映させるのを忘れないよう注意する。
　(コンテスト中は、全体→バケットへの反映をしてなくてWAだった。)
*/

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vvl = vector<vector<ll>>;
using vvi = vector<vector<int>>;
using vvpll = vector<vector<pll>>;
#define name4(i, a, b, c, d, e, ...) e
#define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(i, a) for(ll i = 0, _aa = a; i < _aa; i++)
#define rep2(i, a, b) for(ll i = a, _bb = b; i < _bb; i++)
#define rep3(i, a, b, c) for(ll i = a, _bb = b; (a <= i && i < _bb) or (a >= i && i > _bb); i += c)
#define rrep(i, a, b) for (ll i=(a); i>(b); i--)
#define pb push_back
#define mkp make_pair
#define ALL(A) A.begin(), A.end()
#define elif else if
#define tostr to_string
constexpr ll INF = 1e18;
// constexpr ll INF = LONG_LONG_MAX;
constexpr ll MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr ld EPS = 1e-10;
constexpr ld PI = M_PI;

const string digits = "0123456789";
const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";
const string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string ascii_letters = ascii_lowercase + ascii_uppercase;

template<typename T> vector<vector<T>> list2d(int N, int M, T init) { return vector<vector<T>>(N, vector<T>(M, init)); }
template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init) { return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L, init))); }
template<typename T> vector<vector<vector<vector<T>>>> list4d(int N, int M, int L, int O, T init) { return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init)))); }

template<typename T=ll> vector<T> LIST(ll N) { vector<T> A(N); rep(i, 0, N) cin >> A[i]; return A; }

void print() { cout << '\n'; }
void print(ld out) { cout << fixed << setprecision(15) << out << '\n'; }
void print(double out) { cout << fixed << setprecision(15) << out << '\n'; }
template<typename T> void print(T out) { cout << out << '\n'; }
template<typename T1, typename T2> void print(pair<T1, T2> out) { cout << out.first << ' ' << out.second << '\n'; }
template<typename T> void print(vector<T> A) { rep(i, 0, A.size()) { cout << A[i]; cout << (i == A.size()-1 ? '\n' : ' '); } }
template<typename T> void print(deque<T> A) { rep(i, 0, A.size()) { cout << A[i]; cout << (i == A.size()-1 ? '\n' : ' '); } }
template<typename T> void print(set<T> S) { vector<T> A(S.begin(), S.end()); print(A); }

void Yes() { print("Yes"); }
void No() { print("No"); }
void YES() { print("YES"); }
void NO() { print("NO"); }

ll floor(ll a, ll b) { if (a < 0) { return (a-b+1) / b; } else { return a / b; } }
ll ceil(ll a, ll b) { if (a >= 0) { return (a+b-1) / b; } else { return a / b; } }
template<typename T> pll divmod(ll a, T b) { ll d = a / b; ll m = a % b; return {d, m}; }
template<typename T> bool chmax(T &x, T y) { return (y > x) ? x = y, true : false; }
template<typename T> bool chmin(T &x, T y) { return (y < x) ? x = y, true : false; }

template<typename T> T sum(vector<T> &A) { T res = 0; for (T a: A) res += a; return res; }
template<typename T> T max(vector<T> &A) { return *max_element(ALL(A)); }
template<typename T> T min(vector<T> &A) { return *min_element(ALL(A)); }

ll toint(string s) { ll res = 0; for (char c : s) { res *= 10; res += (c - '0'); } return res; }
int toint(char num) { return num - '0'; }
char tochar(int num) { return '0' + num; }
int ord(char c) { return (int)c; }
char chr(int a) { return (char)a; }

ll pow(int x, int n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
ll pow(int x, ll n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
ll pow(ll x, int n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
ll pow(ll x, ll n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
ll pow(ll x, ll n, int mod) { ll res = 1; while (n > 0) { if (n & 1) { res = (res * x) % mod; } x = (x * x) % mod; n >>= 1; } return res; }

int popcount(ll S) { return __builtin_popcountll(S); }
int bit_length(ll x) { return floor(log2(x))+1; }
string bin(ll x) { string res; while (x) { if (x & 1) res += '1'; else res += '0'; x >>= 1; } reverse(ALL(res)); if(res == "") res += '0'; return res; }

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll x, ll y) { return (x * y) / gcd(x, y); }

ld degrees(ld radians) { return radians * 180.0 / PI; }
ld radians(ld degrees) { return degrees * PI / 180.0; }

template<typename T> int bisect_left(vector<T> &A, T val) { return lower_bound(ALL(A), val) - A.begin(); }
template<typename T> int bisect_right(vector<T> &A, T val) { return upper_bound(ALL(A), val) - A.begin(); }
template<typename F> ll bisearch_min(ll mn, ll mx, const F &func) { ll ok = mx, ng = mn; while (ng+1 < ok) { ll mid = (ok+ng) / 2; if (func(mid)) ok = mid; else ng = mid; } return ok; }
template<typename F> ll bisearch_max(ll mn, ll mx, const F &func) { ll ok = mn, ng = mx; while (ok+1 < ng) { ll mid = (ok+ng) / 2; if (func(mid)) ok = mid; else ng = mid; } return ok; }

template<typename T> unordered_map<T, ll> Counter(vector<T> &A) { unordered_map<T, ll> res; for (T a : A) res[a]++; return res; }
unordered_map<char, ll> Counter(string &S) { unordered_map<char, ll> res; for (char c : S) res[c]++; return res; }
template<typename T1, typename T2> pair<vector<T1>, vector<T2>> zip(vector<pair<T1, T2>> &A) { ll N = A.size(); pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)}; rep(i, N) { res.first[i] = A[i].first; res.second[i] = A[i].second; } return res; }

template<typename T> struct Accumulate {
    vector<T> acc; int N;
    Accumulate(vector<T> &A) { N = A.size(); acc = A; rep(i, N-1) acc[i+1] += acc[i]; acc.insert(acc.begin(), 0); }
    T query(int l, int r) { assert(0 <= l and l <= N and 0 <= r and r <= N); return acc[r]-acc[l]; }
    T get(int i) { return query(i, i+1); }
    T operator[](int i) { return get(i); }
};

template<int mod> struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
    ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
    ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }
    ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    bool operator<(const ModInt &p) const { return x < p.x; }
    ModInt inverse() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
    ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
    friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
    static int get_mod() { return mod; }
    // operator int() const { return x; }
};
using mint = ModInt<MOD>;

template<typename T>
struct Compress {

    int N;
    vector<T> dat;

    Compress(vector<T> A) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        N = A.size();
        dat = A;
    }

    int zip(T x) {
        return bisect_left(dat, x);
    }

    T unzip(int x) {
        return dat[x];
    }

    int operator[](T x) {
        return zip(x);
    }

    int size() {
        return dat.size();
    }

    vector<T> zip(vector<T> &A) {
        int M = A.size();
        vector<T> res(M);
        rep(i, M) res[i] = zip(A[i]);
        return res;
    }
};

void solve() {
    ll N;
    cin >> N;
    auto A = LIST(N);

    auto B = A;
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q), X(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i] >> X[i];
        L[i]--;
        B.pb(X[i]);
    }
    // mapだと重いので座圧してvectorで個数管理する
    Compress<ll> cp(B);
    A = cp.zip(A);
    X = cp.zip(X);
    ll M = cp.size();

    ll D = ceil(sqrt(N));
    vvpll bucket(D);
    rep(i, N) {
        bucket[i/D].pb({A[i], i});
    }
    // バケット内全ての要素が同じかどうか
    vector<bool> all_same(D, 0);
    vector<ll> all_val(D, -1);

    vector<ll> C(M);
    rep(i, N) C[A[i]]++;
    ll ans = 0;
    for (auto v : C) {
        ans += v*(v-1)/2;
    }

    rep(i, Q) {
        ll l = L[i], r = R[i], x = X[i];

        ll ld = l/D;
        ll rd = (r-1)/D;
        // 左端と右端が同じ区間なら重複がないようにする
        if (ld == rd) {
            // 全部同じになっていた区間なら、値をバケットに反映させる
            if (all_same[ld]) {
                for (auto& [a, i] : bucket[ld]) {
                    a = all_val[ld];
                }
            }
            for (auto& [a, i] : bucket[ld]) {
                if (l <= i and i < r) {
                    ll acnt = C[a];
                    ans -= acnt*(acnt-1)/2;
                    acnt--;
                    ans += acnt*(acnt-1)/2;
                    C[a]--;
                    a = x;
                    ll xcnt = C[x];
                    ans -= xcnt*(xcnt-1)/2;
                    xcnt++;
                    ans += xcnt*(xcnt-1)/2;
                    C[x]++; 
                }
            }
            all_same[ld] = 0;
        } else {
            // 左右の端は愚直に見る
            if (all_same[ld]) {
                for (auto& [a, i] : bucket[ld]) {
                    a = all_val[ld];
                }
            }
            for (auto& [a, i] : bucket[ld]) {
                if (l <= i) {
                    ll acnt = C[a];
                    ans -= acnt*(acnt-1)/2;
                    acnt--;
                    ans += acnt*(acnt-1)/2;
                    C[a]--;
                    a = x;
                    ll xcnt = C[x];
                    ans -= xcnt*(xcnt-1)/2;
                    xcnt++;
                    ans += xcnt*(xcnt-1)/2;
                    C[x]++;
                }
            }
            all_same[ld] = 0;
            if (all_same[rd]) {
                for (auto& [a, i] : bucket[rd]) {
                    a = all_val[rd];
                }
            }
            for (auto& [a, i] : bucket[rd]) {
                if (i < r) {
                    ll acnt = C[a];
                    ans -= acnt*(acnt-1)/2;
                    acnt--;
                    ans += acnt*(acnt-1)/2;
                    C[a]--;
                    a = x;
                    ll xcnt = C[x];
                    ans -= xcnt*(xcnt-1)/2;
                    xcnt++;
                    ans += xcnt*(xcnt-1)/2;
                    C[x]++;
                }
            }
            all_same[rd] = 0;
            // 全部を含む区間はまとめて処理
            rep(i, ld+1, rd) {
                // 半端になっていた区間を整える
                if (not all_same[i]) {
                    for (auto& [a, j] : bucket[i]) {
                        ll acnt = C[a];
                        ans -= acnt*(acnt-1)/2;
                        acnt--;
                        ans += acnt*(acnt-1)/2;
                        C[a]--;
                        a = x;
                        ll xcnt = C[x];
                        ans -= xcnt*(xcnt-1)/2;
                        xcnt++;
                        ans += xcnt*(xcnt-1)/2;
                        C[x]++;
                    }
                    all_same[i] = 1;
                    all_val[i] = x;
                } else {
                    ll a = all_val[i];
                    ll acnt = C[a];
                    ll sz = bucket[i].size();
                    ans -= acnt*(acnt-1)/2;
                    acnt -= sz;
                    ans += acnt*(acnt-1)/2;
                    C[a] -= sz;
                    all_same[i] = 1;
                    all_val[i] = x;
                    ll xcnt = C[x];
                    ans -= xcnt*(xcnt-1)/2;
                    xcnt += sz;
                    ans += xcnt*(xcnt-1)/2;
                    C[x] += sz;
                }
            }
        }
        print(ans);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(15);

    // single test case
    solve();

    // multi test cases
    // int T;
    // cin >> T;
    // while (T--) solve();

    return 0;
}
