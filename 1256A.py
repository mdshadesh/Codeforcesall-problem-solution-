def solve():
    a, b, n, s = map(int, input().split())
    if s % n <= b and a * n + b >= s:
        print("YES")
    else:
        print("NO")

t = int(input())
for i in range(t):
    solve()
