/**
 * ・自力AC
 * ・計算量でかめの3次元DP、配列節約テク
 * ・素直なDPを考えると、100*100*1万=1億、C++なら間に合う。
 * ・最後の平均チェックするパートで誤差が心配になったけど、値小さめだしまあいいかな、
 * 　WAが出たらEPS入れてもっかい投げよ、くらいの気持ちで投げたら無事AC0.19秒。速い。
 * ・解説見たら想定解法違った。。平均引いて0にするテク使うやつだった。。
 * 　それだと今何個選んでて、の添字がいらなくなる。
 * 　今回は強引に通せたけど、Ratedだったら制約強くされて無理だっただろうな。。
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
constexpr ll INF = LONG_LONG_MAX;
constexpr ll MOD = 1000000007;

template<typename T> vector<vector<T>> list2d(int N, int M, T init) { vector<vector<T>> res(N, vector<T>(M, init)); return res; }
template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init) { vector<vector<vector<T>>> res(N, vector<vector<T>>(M, vector<T>(L, init))); return res; }

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

template<typename T> inline bool chmax(T &x, T y) { return (y > x) ? x = y, true : false; }
template<typename T> inline bool chmin(T &x, T y) { return (y < x) ? x = y, true : false; }

ll sum(vector<ll> A) { ll res = 0; for (ll a: A) res += a; return res; }
ll max(vector<ll> A) { ll res = -INF; for (ll a: A) chmax(res, a); return res; }
ll min(vector<ll> A) { ll res = INF; for (ll a: A) chmin(res, a); return res; }

ll toint(string s) { ll res = 0; for (char c : s) { res *= 10; res += (c - '0'); } return res; }
int toint(char num) { return num - '0'; }
char tochar(int num) { return '0' + num; }

inline ll pow(int x, ll n) { ll res = 1; rep(_, 0, n) res *= x; return res; }
inline ll pow(ll x, ll n, int mod) { ll res = 1; while (n > 0) { if (n & 1) { res = (res * x) % mod; } x = (x * x) % mod; n >>= 1; } return res; }

inline ll floor(ll a, ll b) { if (a < 0) { return (a-b+1) / b; } else { return a / b; } }
inline ll ceil(ll a, ll b) { if (a >= 0) { return (a+b-1) / b; } else { return a / b; } }
pll divmod(ll a, ll b) { ll d = a / b; ll m = a % b; return {d, m}; }

int popcount(ll S) { return __builtin_popcountll(S); }
ll gcd(ll a, ll b) { return __gcd(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    ll MX = N*100;

    auto dp = list3d(2, N+1, MX+1, 0);
    dp[0][0][0] = 1;
    rep(i, 0, N) {
        rep(j, 0, i+1) {
            rep(k, 0, MX+1) {
                if (!dp[i%2][j][k]) continue;
                dp[(i+1)%2][j][k] += dp[i%2][j][k];
                dp[(i+1)%2][j][k] %= MOD;
                dp[(i+1)%2][j+1][k+A[i]] += dp[i%2][j][k];
                dp[(i+1)%2][j+1][k+A[i]] %= MOD;
            }
        }
        dp[i%2] = list2d(N+1, MX+1, 0);
    }

    ll ans = 0;
    rep(j, 1, N+1) {
        rep(k, 0, MX+1) {
            if (k/(ld)j >= K) {
                ans += dp[N%2][j][k];
                ans %= MOD;
            }
        }
    }
    print(ans);
    return 0;
}
