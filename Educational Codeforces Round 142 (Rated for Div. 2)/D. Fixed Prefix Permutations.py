import sys
from collections import defaultdict

input = sys.stdin.readline
debug = print if 'LOCAL' in sys.argv else lambda *_: None

for _ in range(int(input())):
    n, m = map(int, input().split())
    mp = defaultdict(list)
    mx = {}
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        s = ''
        for j, val in enumerate(map(int, input().split())):
            a[i][j] = val - 1
            s += str(a[i][j])
            mp[s].append(i)
        debug(a[i])
    for i in range(n):
        p = [0] * m
        for j in range(m):
            p[a[i][j]] = j
        s = ''
        for b in range(1, m+1):
            s += str(p[b-1])
            mx[s] = max(mx.get(s, 0), b)
    ans = [0] * n
    for s, v in mp.items():
        val = mx.get(s, 0)
        for x in v:
            ans[x] = max(ans[x], val)
    print(*ans)
