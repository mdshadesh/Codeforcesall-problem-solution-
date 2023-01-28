def solve():
    n,s,r = map(int,input().split())
    arr = []
    arr.append(s-r)
    rem = r%(n-1)
    for i in range(n-1):
        if rem > 0:
            arr.append(r//(n-1) + 1)
            rem -= 1
        else:
            arr.append(r//(n-1))
    print(*arr)
 
for _ in range(int(input())):
    solve()