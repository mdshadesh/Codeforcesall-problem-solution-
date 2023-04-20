import sys
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,r = inpl()
a = inpl()
b = [False] * n
res = 0
for i in range(n):
    if b[i]: continue
    for j in range(-r+1,r)[::-1]:
        if i+j >= n or i+j < 0: continue
        if a[i+j]:
            for k in range(i+j-r+1,i+j+r):
                if 0 <= k < n:
                    b[k] = True
            res += 1
            break
if sum(b) == n:
    print(res)
else:
    print(-1)