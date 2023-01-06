t = int(input())
 
for ___ in range(t):
    n = int(input())
    cnt = 0
    ok = False
    vis = [0] * (n + 2)
    p = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        if vis[i] > 0:
            continue
        k = i
        while True:
            vis[k] = i
            if vis[k - 1] == i or vis[k + 1] == i:
                ok = True
            k = p[k]
            if k == i:
                break
            cnt += 1
 
    print(cnt + (-1 if ok else 1))