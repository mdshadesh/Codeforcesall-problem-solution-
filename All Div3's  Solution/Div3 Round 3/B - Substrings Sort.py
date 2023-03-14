n=int(input())
a=sorted((input()for _ in[0]*n),key=len)
print(('NO','\n'.join(['YES']+a))[all(x in y for x,y in zip(a,a[1:]))])