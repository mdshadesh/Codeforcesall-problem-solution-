n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(n):
    if l[i]<=k:
        c=c+1
b=(n-c)*2 
print(c+b)


