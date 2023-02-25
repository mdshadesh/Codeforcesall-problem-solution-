t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # create an array p where p[i] stores the index of i in the array a
    p = [0] * (n + 1)
    for i in range(n):
        p[a[i]] = i

    # calculate the k array
    k = [0] * (n + 1)
    k[n] = 1
    for i in range(n - 1, 0, -1):
        if p[i] < p[i + 1]:
            k[i] = k[i + 1] + 1
        else:
            k[i] = 1

    # calculate the result
    res = n
    for i in range(1, n + 1):
        res = min(res, max(i - 1, n - (i + k[i] - 1)))

    print(res)
