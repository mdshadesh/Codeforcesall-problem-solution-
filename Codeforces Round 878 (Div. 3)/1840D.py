def slove():
    n=list(map(int,input().split(' ')))
    a=list(map(int,input().split(' ')))
    a.sort()
    lo,hi=-1,(max(a)-min(a)+1)//2+1
    def check(x):
        cnt=1
        r=a[0]+x
        for y in a:
            if y-x>r:
                cnt+=1
                r=y+x
                if cnt>3: return False
        return cnt<=3
    while lo+1<hi:
        med=(lo+hi)>>1
        if check(med):
            hi=med
        else:
            lo=med
    print(hi)
    return 
    

t=int(input())
M=1<<30
for _ in range(t):
    slove()
        