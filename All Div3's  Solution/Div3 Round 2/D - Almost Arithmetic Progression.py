n = int(input())
arr = [int(i) for i in input().split()]

if n<3:
    print(0)
    exit()

ans = []

for i in range(-1,2):
    for j in range(-1,2):
        a = arr[0] + i
        b = arr[1] + j
        changes = abs(i) + abs(j)
        diff = b-a
        curr = b+diff
        for k in range(2,n):
            add = abs(arr[k]-curr)
            curr += diff
            if add<2:
                changes += add
            else:
                changes = n+1
                break
        ans.append(changes)

ans = min(ans)
if ans == n+1: print(-1)
else: print(ans)
