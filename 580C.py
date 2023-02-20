import sys
input = sys.stdin.readline

from collections import defaultdict, deque

n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
A = defaultdict(list)

i = 0
while i != n - 1:
    x, y = list(map(int, input().split()))
    A[x].append(y)
    A[y].append(x)
    i += 1

q = deque()
visited = set()
q.append((1, a[0]))
ret = 0
while q:
    next, cnt = q.popleft()
    visited.add(next)
    
    if len(A[next]) == 1 and next != 1 and cnt <= m:
        ret += 1
    
    for v in A[next]:
        if v in visited:
            continue

        if cnt <= m:
            q.append((v, cnt + a[v - 1] if a[v-1] == 1 else 0))

print(ret)
    
