def solve():
    c1, c2, c3 = map(int, input().split())
    a1, a2, a3, a4, a5 = map(int, input().split())
    if a1 <= c1 and a2 <= c2 and a3 <= c3 and a1 + a3 + a4 <= c1 + c3 and a2 + a3 + a5 <= c2 + c3 and a1 + a2 + a3 + a4 + a5 <= c1 + c2 + c3:
        print("YES")
    else:
        print("NO")

t = int(input())
for i in range(t):
    solve()
