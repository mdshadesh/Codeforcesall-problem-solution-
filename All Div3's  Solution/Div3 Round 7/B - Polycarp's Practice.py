n,k=map(int,input().split())
a=list(map(int,input().split()))
b=sorted(a,reverse=True)
b=b[:k]
c=k
print(sum(b))
j=0
for i in range(n):
    if(a[i] in b and c!=1):
        print(i+1-j,end=' ')
        j=i+1
        b.remove(a[i])
        c-=1
    if(c==1):
        print(n-j)
        break