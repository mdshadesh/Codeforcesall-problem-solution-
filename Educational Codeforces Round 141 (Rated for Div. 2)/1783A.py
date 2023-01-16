def solve():
    n = int(input())
    a = list(map(int, input().split()))
 
    if a[0] == a[n - 1]:
        print("NO")
    else:
        print("YES")
        a[1:] = reversed(a[1:])
        print(" ".join(str(x) for x in a))
 
t = int(input())
for _ in range(t):
    solve()
    