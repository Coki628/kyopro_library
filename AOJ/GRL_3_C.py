# -*- coding: utf-8 -*-

"""
参考：https://mathtrain.jp/kyorenketsu
　　　http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1761971#1
・強連結成分分解
・これも線形時間で出せる。
"""

import sys

sys.setrecursionlimit(10 ** 9)
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
INF=float('inf')

N,M=MAP()
nodes1=[[] for i in range(N)]
nodes2=[[] for i in range(N)]
for i in range(M):
    u,v=MAP()
    nodes1[u].append(v)
    nodes2[v].append(u)

T=[]
visited=[False]*N
def rec1(cur):
    visited[cur]=True
    for nxt in nodes1[cur]:
        if not visited[nxt]:
            rec1(nxt)
    # 行き止まったところから順にTに入れていく
    T.append(cur)

# グラフが連結とは限らないので全頂点やる
for u in range(N):
    if not visited[u]:
        rec1(u)

visited=[False]*N
group=[0]*N
grpnum=1
def rec2(cur):
    global grpnum
    group[cur]=grpnum
    visited[cur]=True
    for nxt in nodes2[cur]:
        if not visited[nxt]:
            rec2(nxt)

# 逆順で進めるところまで行く
for u in reversed(T):
    if not visited[u]:
        rec2(u)
        grpnum+=1

Q=INT()
for _ in range(Q):
    u,v=MAP()
    if group[u]==group[v]:
        print(1)
    else:
        print(0)
