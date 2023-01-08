t = int(input())
 
for i in range(t):
    
    n = int(input())
    a = list(map(int,input().split(sep = " ")))
    minn = 1023
    maxx = 0
    
    for j in range(n):
        x = minn&a[j]
        minn = x
        y = maxx|a[j]
        maxx = y
        
    print(maxx - minn)
