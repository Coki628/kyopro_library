# -*- coding: utf-8 -*-

"""
参考：https://codeforces.com/blog/entry/71080
・最小全域木
・大元の発電所となる頂点を作る。
・先に全部の辺張ってから構築。これもTLE。
・同じのC++で作ってAC0.3秒。
・2000^2/2=200万の辺ならlogとか乗ってもいける気がするんだけどな。
　→提出デバッグした。ボトルネックはソートのlogだ。
"""

import sys
from operator import itemgetter

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
# sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

class UnionFind:

    def __init__(self, n):
        self.n = n
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)
        self.size = [1] * (n+1)

    def find(self, x):
        t = []
        while self.par[x] != x:
            t.append(x)
            x = self.par[x]
        for i in t:
            self.par[i] = x
        return self.par[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.size[y] += self.size[x]
        else:
            self.par[y] = x
            self.size[x] += self.size[y]
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

    def get_size(self, x=None):
        if x is not None:
            return self.size[self.find(x)]
        else:
            res = set()
            for i in range(self.n+1):
                res.add(self.find(i))
            return len(res) - 1

N = INT()
cities = []
edges = []
for i in range(N):
    x, y = MAP()
    cities.append((x, y))
C = LIST()
K = LIST()
for i in range(N):
    c = C[i]
    k = K[i]
    x, y = cities[i]
    cities[i] = (x, y, c, k)
    # 各頂点から大元の発電所への辺
    edges.append((c, i, N))

# 各頂点同士の辺
for i in range(N):
    x1, y1, c1, k1 = cities[i]
    for j in range(i+1, N):
        x2, y2, c2, k2 = cities[j]
        cost = (abs(x1-x2) + abs(y1-y2)) * (k1+k2)
        # 明らかに不要な辺は繋がない
        if C[i] > cost or C[j] > cost:
            edges.append((cost, i, j))

edges.sort(key=itemgetter(0))
uf = UnionFind(N+1)
total = 0
stations = []
edges2 = []
for c, a, b in edges:
    if not uf.is_same(a, b):
        uf.union(a, b)
        total += c
        if b == N:
            stations.append(a+1)
        else:
            edges2.append((a+1, b+1))
    if uf.get_size(N) == N+1:
        break

print(total)
print(len(stations))
print(*sorted(stations))
print(len(edges2))
for a, b in edges2:
    print(a, b)
