t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    degree = [0] * (n + 1)
    for _ in range(m):
        x, y = map(int, input().split())
        degree[x] += 1
        degree[y] += 1
    y1 = sum(d == 1 for d in degree)
    x1 = n - 1 - y1
    print(x1, y1 // x1)
