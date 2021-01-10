"""
・実験用。これは答え見たあとで試しに書いたもの。
　これを20項くらい取ってOEISに投げると普通に答えの式が出る。。
・なんとなく精進中は自力で頑張りたくてやらなかったんだけど、
　OEISだろうと何だろうと通せないよりはずっといいので、ちゃんとやればよかったな。。
"""

import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10**9)
INF = 10**19
MOD = 10**9 + 7
EPS = 10**-10

N = INT()

dp = [0] * (N+1)
dp[1] = 1
for i in range(2, N+1):
    dp[i] = dp[i-1] + dp[i-2]
ans = [0] * (N+1)
for i in range(1, N+1):
    ans[i] = ans[i-1] + dp[i]**2
print(', '.join(map(str, (ans))))