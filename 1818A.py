def solve():
    n, k = map(int, input().split())
    s = []
    for i in range(n):
        s.append(input())
    print(s.count(s[0]))

t = int(input())
for i in range(t):
    solve()
