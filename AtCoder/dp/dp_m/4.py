# -*- coding: utf-8 -*-

"""
参考：https://kyopro-friends.hatenablog.com/entry/2019/01/12/231035
　　　https://www.hamayanhamayan.com/entry/2019/01/10/235150
　　　http://anctgcc.hatenablog.com/entry/2014/12/03/194140
　　　https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree
・数え上げDP
・累積和の代わりにBIT(Binary Indexed Tree)を使ってみる。
"""

import sys, re
from collections import deque, defaultdict, Counter
from math import sqrt, hypot, factorial, pi, sin, cos, radians
if sys.version_info.minor >= 5: from math import gcd
else: from fractions import gcd 
from heapq import heappop, heappush, heapify, heappushpop
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from functools import reduce, partial
from fractions import Fraction
from string import ascii_lowercase, ascii_uppercase, digits

def input(): return sys.stdin.readline().strip()
def ceil(a, b=1): return int(-(-a // b))
def round(x): return int((x*2+1) // 2)
def fermat(x, y, MOD): return x * pow(y, MOD-2, MOD) % MOD
def lcm(x, y): return (x * y) // gcd(x, y)
def lcm_list(nums): return reduce(lcm, nums, 1)
def gcd_list(nums): return reduce(gcd, nums, nums[0])
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * n
 
    def sum(self, i):
        s = 0
        i += 1
        while i > 0:
            s += self.tree[i-1]
            i -= i & -i
        return s
    
    def get(self, l, r):
        res = 0
        if r: res += self.sum(r-1)
        if l: res -= self.sum(l-1)
        return res
 
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i-1] += x
            i += i & -i

N, K = MAP()
aN = LIST()

# dp[i][k] := i人目の子供まで配り終えて、残りがk個である組み合わせ
# dpの2次元目をBITで構築する
dp = [BIT(K+1) for i in range(N+1)]
dp[0].add(K, 1)

for i in range(N):
    for j in range(K+1):
        sm = dp[i].get(j, min(K, j+aN[i])+1)
        dp[i+1].add(j, sm)

print(dp[N].get(0, 1) % MOD)
