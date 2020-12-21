"""
・次の出現位置を前計算して、前から貪欲に置く。
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
INF = 10 ** 19
MOD = 10 ** 9 + 7

for _ in range(INT()):
    N, K = MAP()
    A = input()

    cur = INF
    nxt = [0] * N
    for i in range(N-1, -1, -1):
        if A[i] == '1':
            cur = i
        nxt[i] = cur

    ans = 0
    i = 0
    while i < N:
        if A[i] == '0':
            if nxt[i]-i > K:
                ans += 1
                i += K + 1
            else:
                i += 1
        else:
            i += K + 1
    print(ans)