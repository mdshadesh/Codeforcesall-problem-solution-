n, m = map(int,input().split())
a = list(map(int,input().split()))
d = {0: 1}
check, q, ans = 0,0,0
for i in a:
    if i < m:
        q -= 1
    elif i > m:
        q += 1
    else:
        check = 1
    if check:
        ans += d.get(q,0)+d.get(q-1,0)
    else:
        new = d.get(q,0) + 1
        d[q] = new
print(ans)
