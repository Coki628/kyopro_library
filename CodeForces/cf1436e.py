"""
参考：https://totori.hatenadiary.com/entry/2020/10/25/030146
・連続部分列の区間mex
・ある数aが区間mexとなるためには、aが含まれない区間内で、[1,a)の値が全て出現している必要がある。
　これをチェックするためには、まずaの前回出現位置〜今回出現位置を1つの区間として見ること、
　そしてセグ木に seg[i] := 値iが出現する直近のindex を持たせて、[1,a)の区間で全ての値(index)が
　前回出現位置よりも大きいかどうかを確認する、とやればうまくいく。
・この方法だとmex = 1の場合はカバーできないのでそこは別途場合分け。
・あと普通に見るだけだと、最後の出現位置を左端とした区間がチェックできてないので、それも後から別途やる。
・あと部分列のmexは最大でN+1まで取りうるので、最終的な答えは最大でN+2までありうる。(1ペナ)
・こういうindexと値を逆にしたやつセグ木に持たせてえいえいやるやつ、訳分かんなくなるね。。
"""

import sys

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
INF = 10**19
MOD = 10**9 + 7
EPS = 10**-10

class SegTree:

    def __init__(self, n, func, intv, A=[]):
        self.n = n
        self.func = func
        self.intv = intv
        n2 = 1
        while n2 < n:
            n2 <<= 1
        self.n2 = n2
        self.tree = [self.intv] * (n2 << 1)
        if A:
            for i in range(n):
                self.tree[n2+i] = A[i]
            for i in range(n2-1, -1, -1):
                self.tree[i] = self.func(self.tree[i*2], self.tree[i*2+1])

    def update(self, i, x):
        i += self.n2
        self.tree[i] = x
        while i > 0:
            i >>= 1
            self.tree[i] = self.func(self.tree[i*2], self.tree[i*2+1])

    def add(self, i, x):
        self.update(i, self.get(i) + x)

    def query(self, a, b):
        l = a + self.n2
        r = b + self.n2
        s = self.intv
        while l < r:
            if r & 1:
                r -= 1
                s = self.func(s, self.tree[r])
            if l & 1:
                s = self.func(s, self.tree[l])
                l += 1
            l >>= 1
            r >>= 1
        return s

    def get(self, i):
        return self.tree[i+self.n2]

    def all(self):
        return self.tree[1]

    def print(self):
        for i in range(self.n):
            print(self.get(i), end=' ')
        print()

N = INT()
A = LIST()

seg = SegTree(N+2, min, INF, [-1]*(N+2))
mex = [0] * (N+2)
# mex = 1 は他と同じにできないので場合分け
if sorted(A, reverse=1)[0] != 1:
    mex[1] = 1
# 前回の出現位置〜今回の出現位置を区間として、その区間内に[1,A[i])が全て含まれるかどうかをチェックする
for i in range(N):
    if A[i] == 1:
        seg.update(A[i], i)
        continue
    prev = seg.get(A[i])
    # 区間(prev,i)に[1,A[i])が全て含まれる → [1,A[i])の最小indexがprevより大きい
    mn = seg.query(1, A[i])
    if mn > prev:
        mex[A[i]] = 1
    seg.update(A[i], i)

# 最後の出現位置を左端として、全ての値について再度チェックする
for a in range(2, N+2):
    prev = seg.get(a)
    mn = seg.query(1, a)
    if mn > prev:
        mex[a] = 1

ans = N + 2
for i in range(1, N+2):
    if not mex[i]:
        ans = i
        break
print(ans)
