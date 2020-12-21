# -*- coding: utf-8 -*-

"""
参考：http://kmjp.hatenablog.jp/entry/2015/01/04/0930
・蟻本演習3-5-10
・最小費用流、重み付き二部マッチング、割当問題
・制約を見ると、どのモンスターもアイテムの総計より大きいダメージ量を持ってると書いてある。
　ゲーム的には不自然な感じだけど、このおかげで鍵とアイテムのペアを決めた時に、
　減らせるダメージ量が計算しやすくなってる。(0を下回るなら0に、の心配をしなくていい)
・ペアを1つも使わなくてもいいので、始点から終点にノーコストで直行できる辺を、
　鍵の数だけ流せるように張っておく。
・後は普通に二部マッチング作って鍵の数だけフロー流す。鍵取得コストよりダメージ軽減量が大きいと、
　コストは利得になる(負数になる)ので、負数対応可のベルマンフォード最小費用流を使う。
・pypyでもTLE。最大300*300=9万の辺に対してのフローになるから、
　フローの計算量F*E*V=300*9万*300=81億、そりゃ無理か。。
・今回、マッチングから余った流量は全てコスト0で終点に流せるので、
　コスト0以上の辺は最初から張らないようにしてみた。
　かなり良くなってTLEケース減ったけど、まあやっぱり最悪っぽいケースだとたくさん辺張るだろうからTLEするよね。。
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

class MinCostFlow:
    """ 最小費用流(ベルマンフォード版、負コストに対応可) """

    INF = 10 ** 18

    def __init__(self, N):
        self.N = N
        self.G = [[] for i in range(N)]

    def add_edge(self, fr, to, cap, cost):
        G = self.G
        G[fr].append([to, cap, cost, len(G[to])])
        G[to].append([fr, 0, -cost, len(G[fr])-1])

    def flow(self, s, t, f):

        N = self.N; G = self.G
        INF = MinCostFlow.INF

        res = 0
        prv_v = [0] * N
        prv_e = [0] * N

        while f:
            dist = [INF] * N
            dist[s] = 0
            update = True

            while update:
                update = False
                for v in range(N):
                    if dist[v] == INF:
                        continue
                    for i, (to, cap, cost, _) in enumerate(G[v]):
                        if cap > 0 and dist[to] > dist[v] + cost:
                            dist[to] = dist[v] + cost
                            prv_v[to] = v; prv_e[to] = i
                            update = True
            if dist[t] == INF:
                return INF

            d = f; v = t
            while v != s:
                d = min(d, G[prv_v[v]][prv_e[v]][1])
                v = prv_v[v]
            f -= d
            res += d * dist[t]
            v = t
            while v != s:
                e = G[prv_v[v]][prv_e[v]]
                e[1] -= d
                G[v][e[3]][1] += d
                v = prv_v[v]
        return res

N = INT()
AB = []
for i in range(N):
    a, b = MAP()
    AB.append((a, b))

# 鍵とアイテムで配列を分ける
A, B = [], []
# そこより後ろにいるモンスターの数
moncnt = 0
# 全モンスターから受けるダメージ量合計
total = 0
for a, b in AB[::-1]:
    if a == 0:
        A.append((b, moncnt))
    elif a == 1:
        B.append((b, moncnt))
    else:
        moncnt += 1
        total += b
N1 = len(A)
N2 = len(B)

mcf = MinCostFlow(N1+N2+2)
s = N1 + N2
t = N1 + N2 + 1
# 鍵を使わない選択のために、始点と終点を直接繋ぐ
mcf.add_edge(s, t, N1, 0)
for i in range(N1):
    a, cnt1 = A[i]
    mcf.add_edge(s, i, 1, 0)
    for j in range(N2):
        b, cnt2 = B[j]
        cnt = min(cnt1, cnt2)
        cost = a - b*cnt
        # コスト0以上になる辺は張らない(終点直行の辺を通ればいいので)
        if cost < 0:
            # コストは、鍵の取得コスト - このペアを使って減らせる総ダメージ量(単体の軽減量 * 後ろにいるモンスターの数)
            mcf.add_edge(i, N1+j, 1, a - b*cnt)
for i in range(N2):
    mcf.add_edge(N1+i, t, 1, 0)

# 鍵の数だけフローを流す
res = mcf.flow(s, t, N1)
ans = total + res
print(ans)