"""
・なんとか自力AC
・累積和、Zero Sum Ranges系
・基本はZero Sum Rangesなんだけど、ダブりがあった時点で累積和をリセットしたい。
　他の人の見たり公式見たりしたところ、実は先に累積和取らないで、
　動的に進めていけばもっと分かりやすくリセットができたんだけど、解いてる時はそうはできず。。
・結局、1つ手前(i-1)が最初の0みたいな立ち位置になって残るので、i-2までをなかったことにする、でACできた。
"""

import sys
from itertools import accumulate

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c for j in range(b)] for i in range(a)]
def list3d(a, b, c, d): return [[[d for k in range(c)] for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e for l in range(d)] for k in range(c)] for j in range(b)] for i in range(a)]
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

N = INT()
A = LIST()

acc = [0] + list(accumulate(A))
D = {}
ok = -1
ans = 0
for i in range(N+1):
    if acc[i] in D and D[acc[i]] > ok:
        ok = i - 2
        ans += 1
    D[acc[i]] = i
print(ans)
