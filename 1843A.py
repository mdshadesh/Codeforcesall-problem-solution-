n = int(input())
for i in range(n):
    a = int(input())
    g = list(map(int,input().split()))
    f = sorted(g)
    t = len(f) - 1
    y = 0
    s = 0
    while y < t:
        s += (f[t] - f[y])
        y += 1
        t -= 1
        
    print(s)
