"""
・自力AC！
・優先度付きキュー
・解説見たら、制約が実はAが同値なしだったのでもっと簡単にやれた。。
"""

import sys
from heapq import heappush, heappop

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for k in range(c)] for j in range(b)] for i in range(a)]
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
A = LIST(N)

A.sort(reverse=1)
que = [-A[0]]

for a in A[1:]:
    cur = -heappop(que)
    if a+1 < cur:
        cur = a
        heappush(que, -cur)
    else:
        heappush(que, -cur)
        heappush(que, -a)
ans = len(que)
print(ans)
