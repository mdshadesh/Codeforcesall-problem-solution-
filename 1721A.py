def solve():
    a, b, c, d = input().strip()
    ans = 3

    if a == b or a == c or a == d:
        ans -= 1

    if b == c or b == d:
        ans -= 1

    if c == d:
        ans -= 1

    print(ans)

t = int(input().strip())
for _ in range(t):
    solve()
