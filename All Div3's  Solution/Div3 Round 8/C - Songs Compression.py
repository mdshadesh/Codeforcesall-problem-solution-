n, m = map(int, input().split())
a = []
b = []
dif = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)
    dif.append(x - y)
sum_a = sum(a)
if sum_a <= m:
    print(0)
else:
    dif.sort(reverse=True)
    cnt = 0
    for i in range(n):
        if sum_a <= m:
            break
        cnt += 1
        sum_a -= dif[i]
    if sum_a > m:
        print(-1)
    else:
        print(cnt)
