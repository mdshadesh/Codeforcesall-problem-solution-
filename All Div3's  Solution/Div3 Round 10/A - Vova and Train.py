t=int(input())
for i in range(t):
	L,v,l,r=map(int,input().split())
	print((l-1)//v+L//v-r//v)
	
	
