input()
a = list(map(int,input().split()))
b = list(map(int,input().split()))
i=1
dif=0
for bi in b:
	while(bi>dif+a[0]):
		dif+=a.pop(0)
		i+=1
	print(i,bi-dif)