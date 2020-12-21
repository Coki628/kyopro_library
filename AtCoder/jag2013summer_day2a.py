# -*- coding: utf-8 -*-

"""
・いもす法
・縦横独立で考えられる。
・なんかWA取れなくて結局人の見た。H,W上は範囲内に含まないみたいだ。
　これは多分マスH,Wじゃなくて座標H,Wだから、終端は含まなくていいんだと思う。
"""

import sys
from itertools import accumulate

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
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

N, W, H = MAP()
imosx = [0] * (W+1)
imosy = [0] * (H+1)
for i in range(N):
    x, y, w = MAP()
    imosx[max(0, x-w)] += 1
    imosx[min(W, x+w)] -= 1
    imosy[max(0, y-w)] += 1
    imosy[min(H, y+w)] -= 1

# 縦横独立でいもす
imosx = list(accumulate(imosx))
imosy = list(accumulate(imosy))

# 縦か横どちらかが0の区間なしならOK
for i in range(W):
    if imosx[i] == 0:
        break
else:
    Yes()
    exit()
for i in range(H):
    if imosy[i] == 0:
        break
else:
    Yes()
    exit()
No()
