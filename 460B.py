def digitsum(x):
    ans = 0
    for c in str(x):
        ans += int(c)
    return ans

a, b, c = map(int, input().split())

sols = []

for i in range(1, 81):
    x = b * pow(i, a) + c
    if x > 0 and digitsum(x) == i and x < pow(10, 9):
        sols.append(x)

print(len(sols))
print(*sols)
