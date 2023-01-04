t=int(input())
for i in range(1,t+1):
    n=int(input())
    a=list(map(int,input().split()))
    c=0
    s=0
    for x in a:
        if(x>1):
            c=c+1
    if(c==0):
        c=1
    while(c!=1):
        c=0
        for i in range(0,n+1):
            if(a[i]>1):
                break
        for j in range(i+1,n+1):
            if(a[j]>1):
                break
        a[i]=a[i]*a[j]
        a[j]=1
        for x in a:
            if(x>1):
                c=c+1
    for i in a:
        s=s+i
        amt=2022*s
    print(amt)