(n, m) = map(int, input().split())

array = [0] * (n + 1)
lst = []
for x in range(m):
    (s, d, c) = map(int, input().split())
    lst.append((d, s, c, x + 1))

lst.sort()
i = 0
flag = True
for (d, s, c, p) in lst:
    x = s
    while c > 0 and x < d:
        if array[x] == 0:
            array[x] = p
            c -= 1
        x += 1
    if c != 0:
        flag = False
        break
    else:
        array[d] = m + 1

if flag:
    print(*array[1:])
else:
    print(-1)
