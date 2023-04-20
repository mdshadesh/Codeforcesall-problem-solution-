n = int(input())
lst = list(map(int, input().split()))
lst2 = []
sum1 = 0

for j in range(n):
    lst2.append((lst[j], j+1))
    sum1 += lst[j]

lst2.sort()

ans = []
max1 = lst2[-1][0]
copy = 0

for i in range(n):
    copy = sum1
    if i == n-1:
        max1 = lst2[-2][0]
    copy -= (max1 + lst2[i][0])

    if max1 == copy:
        ans.append(lst2[i][1])

print(len(ans))
print(*ans)
