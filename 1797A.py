import sys

input = sys.stdin.readline

inf = 10**18 + 1

t = int(input())
for _ in range(t):
    n, m, x1, y1, x2, y2 = map(int, input().split())
    k = 4
    h = 4
    if x1 == 1 or x1 == n:
        k -= 1
    if y1 == m or y1 == 1:
        k -= 1
    if x2 == n or x2 == 1:
        h -= 1
    if y2 == m or y2 == 1:
        h -= 1
    print(min(h, k))
