t = int(input())
while t > 0:
    n = int(input())
    a = list(map(int, input().split()))
    k = 0
    l = 0
    for j in range(n):
        if a[j] == 0:
            k += 1
        else:
            l = max(k, l)
            k = 0
    l = max(l, k)
    print(l)
    t -= 1
