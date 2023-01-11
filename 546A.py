k,n,w=map(int,input().split())
total=0
for i in range(1,w+1):
    cost=i*k
    total+=cost
if total-n==0 or total-n<=0:
    print("0")
else:
    print(total-n)  