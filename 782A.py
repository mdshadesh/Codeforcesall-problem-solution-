t = 1
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    a = 0
    c = 0
    m = {}
    for i in range(2*n):
        if m.get(A[i], 0) == 1:
            a -= 1
        elif m.get(A[i], 0) == 0:
            a += 1
            m[A[i]] = 1
        c = max(c, a)

    print(c)
