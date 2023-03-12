from math import sqrt
def solve():
    n,pack,time,wait=map(int,input().split());a=list(map(int,input().split()));ans=1;currPack=0;x=a[0]+time+wait
    for index,i in enumerate(a):
        if i<=x:
            currPack+=1
            if currPack==pack and index!=n-1:
                currPack=0;ans+=1
                x=a[index+1]+time+wait
        else:
            ans+=1;
            x=i+time+wait;currPack=1
    print(ans)
for _ in range(int(input())):solve()
