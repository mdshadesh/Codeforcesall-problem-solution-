n = int(input())
w = list(map(int, input().split()))

res = 0
i = 0
while i < n:
    j = i + 1
    while j < n and w[j] <= w[j - 1] * 2:
        j += 1
    res = max(res, j - i)
    i = j

print(res)
