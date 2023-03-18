n=int(input())
a,b=input(),input()
k=n//2
c=a[k]!=b[k]and n%2
for u,v,x,y in zip(a[:k],a[::-1],b,b[::-1]):c+=(len({x,y}-{u,v}),u!=v)[x==y]
print(c)