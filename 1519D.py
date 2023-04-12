def solvet():
    global n
    n = int(input())
    res = 0
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(1, n+1):
        res += a[i-1] * b[i-1]

    tmp = 0
    for i in range(1, n+1):
        tmp1 = 0
        for j, k in zip(range(i, 0, -1), range(i, n+1)):
            tmp1 += (a[j-1] - a[k-1]) * (b[k-1] - b[j-1])
            tmp = max(tmp, tmp1)
            
    for i in range(1, n):
        tmp1 = 0
        for j, k in zip(range(i, 0, -1), range(i+1, n+1)):
            tmp1 += (a[j-1] - a[k-1]) * (b[k-1] - b[j-1])
            tmp = max(tmp, tmp1)

    print(res + tmp)

t = 1
for _ in range(t):
    solvet()
