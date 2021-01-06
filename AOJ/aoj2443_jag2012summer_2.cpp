/**
 * 参考：https://jag-icpc.org/?plugin=attach&refer=2012%2FPractice%2F%E5%A4%8F%E5%90%88%E5%AE%BF%2F%E8%AC%9B%E8%A9%95&openfile=3B-D.pdf
 * 　　　http://algoogle.hadrori.jp/aoj/2443/
 * ・蟻本演習4-5-1
 * ・バックトラック、両側探索
 * ・開始状態と終了状態の両方から半分ずつ探索をかけて、後から両方を突き合わせる。
 * ・計算量は片方で1200万くらいあるみたいで、mapのlog乗ってるからか無理だった。。(制約5秒でも)
 * ・キーにしてたvector<ll>をstringにしたらちょこっと速くなった気がして、
 * 　stringならとmapをunordered_mapに変えたら通った！AC1.68秒。
 * ・C++のunordered_mapはいけてないってよく言われるけどたまに試すとちゃんと速くなるんだよなー。。
 */

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vvl = vector<vector<ll>>;
using vvi = vector<vector<int>>;
using vvpll = vector<vector<pll>>;
#define rep(i, a, b) for (ll i=(a); i<(b); i++)
#define rrep(i, a, b) for (ll i=(a); i>(b); i--)
#define pb push_back
#define tostr to_string
#define ALL(A) A.begin(), A.end()
// constexpr ll INF = LONG_LONG_MAX;
constexpr ll INF = 1e18;
constexpr ll MOD = 1000000007;

const string digits = "0123456789";
const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";
const string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string ascii_letters = ascii_lowercase + ascii_uppercase;

template<typename T> vector<vector<T>> list2d(int N, int M, T init) { return vector<vector<T>>(N, vector<T>(M, init)); }
template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init) { return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L, init))); }
template<typename T> vector<vector<vector<vector<T>>>> list4d(int N, int M, int L, int O, T init) { return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init)))); }

void print(ld out) { cout << fixed << setprecision(15) << out << '\n'; }
void print(double out) { cout << fixed << setprecision(15) << out << '\n'; }
template<typename T> void print(T out) { cout << out << '\n'; }
template<typename T1, typename T2> void print(pair<T1, T2> out) { cout << out.first << ' ' << out.second << '\n'; }
template<typename T> void print(vector<T> A) { rep(i, 0, A.size()) { cout << A[i]; cout << (i == A.size()-1 ? '\n' : ' '); } }
template<typename T> void print(set<T> S) { vector<T> A(S.begin(), S.end()); print(A); }

void Yes() { print("Yes"); }
void No() { print("No"); }
void YES() { print("YES"); }
void NO() { print("NO"); }

ll floor(ll a, ll b) { if (a < 0) { return (a-b+1) / b; } else { return a / b; } }
ll ceil(ll a, ll b) { if (a >= 0) { return (a+b-1) / b; } else { return a / b; } }
pll divmod(ll a, ll b) { ll d = a / b; ll m = a % b; return {d, m}; }
template<typename T> bool chmax(T &x, T y) { return (y > x) ? x = y, true : false; }
template<typename T> bool chmin(T &x, T y) { return (y < x) ? x = y, true : false; }

template<typename T> T sum(vector<T> A) { T res = 0; for (T a: A) res += a; return res; }
template<typename T> T max(vector<T> A) { return *max_element(ALL(A)); }
template<typename T> T min(vector<T> A) { return *min_element(ALL(A)); }

ll toint(string s) { ll res = 0; for (char c : s) { res *= 10; res += (c - '0'); } return res; }
int toint(char num) { return num - '0'; }
char tochar(int num) { return '0' + num; }
int ord(char c) { return (int)c; }
char chr(int a) { return (char)a; }

ll pow(int x, ll n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
ll pow(ll x, ll n, int mod) { ll res = 1; while (n > 0) { if (n & 1) { res = (res * x) % mod; } x = (x * x) % mod; n >>= 1; } return res; }

int popcount(ll S) { return __builtin_popcountll(S); }
ll gcd(ll a, ll b) { return __gcd(a, b); }

template<typename T> int bisect_left(vector<T> &A, T val) { return lower_bound(ALL(A), val) - A.begin(); }
template<typename T> int bisect_right(vector<T> &A, T val) { return upper_bound(ALL(A), val) - A.begin(); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    string A1(N, '0'), A2(N, '0');
    rep(i, 0, N) {
        ll a;
        cin >> a;
        A1[i] = tochar(a-1);
        A2[i] = tochar(i);
    }

    unordered_map<string, ll> mp1, mp2;
    auto rec = [&](auto&& f, string &A, unordered_map<string, ll> &mp, ll depth) -> void {
        if (depth > 4) return;
        rep(i, 0, N) {
            rep(j, i+1, N+1) {
                reverse(A.begin()+i, A.begin()+j);
                if (mp.count(A)) chmin(mp[A], depth);
                else mp[A] = depth;
                f(f, A, mp, depth+1);
                reverse(A.begin()+i, A.begin()+j);
            }
        }
    };
    mp1[A1] = 0;
    mp2[A2] = 0;
    rec(rec, A1, mp1, 1);
    rec(rec, A2, mp2, 1);

    ll ans = N-1;
    for (auto& [A, cnt] : mp1) {
        if (mp2.count(A)) {
            chmin(ans, cnt+mp2[A]);
        }
    }
    print(ans);
    return 0;
}
