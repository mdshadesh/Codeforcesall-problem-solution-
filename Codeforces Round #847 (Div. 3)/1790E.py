def solve():
    x = int(input())
    if x % 2 == 1:
        print(-1)
        return
    rest = x // 2
    if x & rest == 0:
        print(x + rest, rest)
    else:
        print(-1)
 
t = int(input())
for _ in range(t):
    solve()
