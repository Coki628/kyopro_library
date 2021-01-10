# -*- coding: utf-8 -*-

"""
・自力AC！
・素数、整数系
・手元で色々試した結果、正しい予測に辿り着けてよかった。
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
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

def factorize(num: int) -> dict:
    from math import sqrt
    from collections import Counter

    d = Counter()
    for i in range(2, int(sqrt(num))+1):
        while num % i == 0:
            num //= i
            d[i] += 1
        if num == 1:
            break
    if num != 1:
        d[num] += 1
    return d

N = INT()

# 素因数が1つならその数、2つ以上あったら1
d = factorize(N)
if len(d) == 1:
    for k in d.keys():
        print(k)
else:
    print(1)