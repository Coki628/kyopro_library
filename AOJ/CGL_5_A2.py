# -*- coding: utf-8 -*-

"""
参考：http://aoba.cc.saga-u.ac.jp/lecture/Algorithms/text/ClosestPair.pdf
　　　https://akkikiki.hatenadiary.org/entry/20130626/1372270211
・最近点対の長さ
・分割統治法、再帰探索する。
・マージの時に調べるペアを絞ってやる。これでAC。
"""

import sys
from operator import itemgetter
from math import hypot
from bisect import bisect_left, bisect_right

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

N=INT()
A=[]
for i in range(N):
    x,y=map(float, input().split())
    A.append((i, x, y))

# xでソート済とyでソート済を準備しておく
Ax=sorted(A, key=itemgetter(1))
Ay=sorted(A, key=itemgetter(2))

def find_min(li):
    n=len(li)
    mn=INF
    for i in range(n):
        for j in range(i+1, n):
            _,x1,y1=li[i]
            _,x2,y2=li[j]
            mn=min(mn, hypot(x1-x2, y1-y2))
    return mn

# x方向のマージ用
def find_min2(mn, li1, li2):
    # 二分探索用にy部分だけのリストを作っておく
    li2b=[y for i, x, y in li2]
    mn=INF
    for i1, x1, y1 in li1:
        s=bisect_left(li2b, y1-mn)
        t=bisect_right(li2b, y1+mn)
        # yが近い組だけやる
        for i in range(s, t):
            i2,x2,y2=li2[i]
            # 同じ点はスキップする
            if i1==i2: continue
            mn=min(mn, hypot(x1-x2, y1-y2))
    return mn

# y方向のマージ用
def find_min3(mn, li1, li2):
    li2b=[x for i, x, y in li2]
    mn=INF
    for i1, x1, y1 in li1:
        s=bisect_left(li2b, x1-mn)
        t=bisect_right(li2b, x1+mn)
        for i in range(s, t):
            i2,x2,y2=li2[i]
            if i1==i2: continue
            mn=min(mn, hypot(x1-x2, y1-y2))
    return mn

def rec(lix, liy, d):
    # 3つ以下になったら直接調べて返却
    if len(lix)<=3:
        return find_min(lix)
    # x方向に半分にする
    if d%2==0:
        lix2=lix[:len(lix)//2]
        lix3=lix[len(lix)//2:]
        xset={x[0] for x in lix2}
        liy2=[]
        liy3=[]
        # xに合わせてyも振り分ける
        for i, x, y in liy:
            if i in xset:
                liy2.append((i, x, y))
            else:
                liy3.append((i, x, y))
        # 前半分と後ろ半分の小さい方
        mn=min(rec(lix2, liy2, d^1), rec(lix3, liy3, d^1))
        # 境界線近くはまとめて直接調べる
        midx=(lix2[-1][1]+lix3[0][1])/2
        borders1=[]
        borders2=[]
        for i in range(len(lix)):
            if midx-mn<=lix[i][1]<=midx+mn:
                borders1.append(lix[i])
            if midx-mn<=liy[i][1]<=midx+mn:
                borders2.append(liy[i]) 
        mn=min(mn, find_min2(mn, borders1, borders2))
        return mn
    # y方向に半分にする(内容はほぼ同じ)
    else:
        liy2=liy[:len(liy)//2]
        liy3=liy[len(liy)//2:]
        yset={y[0] for y in liy2}
        lix2=[]
        lix3=[]
        for i, x, y in lix:
            if i in yset:
                lix2.append((i, x, y))
            else:
                lix3.append((i, x, y))
        mn=min(rec(lix2, liy2, d^1), rec(lix3, liy3, d^1))
        midy=(liy2[-1][2]+liy3[0][2])/2
        borders1=[]
        borders2=[]
        for i in range(len(liy)):
            if midy-mn<=liy[i][2]<=midy+mn:
                borders1.append(liy[i])
            if midy-mn<=lix[i][2]<=midy+mn:
                borders2.append(lix[i])
        mn=min(mn, find_min3(mn, borders1, borders2))
        return mn

print('{:.10f}'.format(rec(Ax, Ay, 0)))
