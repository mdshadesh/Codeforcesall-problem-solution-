n,k = map(int,input().split())
a = list(map(int,input().split()))
result = 0
for i in range(n):
    s = sum(a[i : i + k])
    l = k
    result = max(result, s / l)
    for j in range(i + k, min(n, i + 2 * k)):
        s += a[j]
        l += 1
        result = max(result, s / l)
print(result)