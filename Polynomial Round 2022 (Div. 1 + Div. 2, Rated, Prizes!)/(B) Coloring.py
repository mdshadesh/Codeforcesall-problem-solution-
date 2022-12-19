t = int(input())
for _ in range(t):
    n, m , k = map(int, input().split(" "))
    vals = list(map(int, input().split(" ")))
    res = "YES"
    for v in vals:
        if not n % k and v > n / k:
            res ="NO"
            break
        if n % k and v > n // k + 1:
            res ="NO"
            break
        if n % k and v == n // k + 1:
            res = "YES"
            if vals.count(v) > n % k:
                res = "NO"
    print(res)
