t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    h = list(map(int,input().split()))
    p = list(map(int,input().split()))
    z = list(zip(p,h))
    z.sort()
    tongst = k
    M = max(h);
    i =0;
    x = len(z)
    while i <x and k!=0:
        if z[i][1] > tongst:
            k= max(0,k-z[i][0])
            tongst= tongst +k
        else:
            i= i+1
    if tongst<M:
        print("NO")
    else:
        print("YES")