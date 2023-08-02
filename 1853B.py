def solve():
    n, k = [int(x) for x in input().split()]

    ans = 0
    for fist in range(1, n+1):
        second = n
        valid = True
        for rounds in range(k-2):
            fist, second = second-fist, fist
            valid &= min(fist, second) >= 0
            valid &= second >= fist
            if not valid:
                break
        if valid:
            ans += 1
    print(ans)


t = int(input())
for _ in range(t):
    solve()
