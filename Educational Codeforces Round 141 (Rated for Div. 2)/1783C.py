t = int(input())
for p in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = a[:]
    a.sort()
    c = 0
    sum = 0
    flag = True
    for i in range(n):
        if sum + a[i] <= m:
            sum += a[i]
            c += 1
        else:
            flag  = False
            break
    if flag:
        print(1)
    else:
        if c != 0:
            count = b[c]
            for j in range(0, c - 1):
                count += a[j]
            if count > m:
                print(n - c + 1)
            else:
                print(n - c)
        else:
            print(n + 1)
 
 
 
 
 