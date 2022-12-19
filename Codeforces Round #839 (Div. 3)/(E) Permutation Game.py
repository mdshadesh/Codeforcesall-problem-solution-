import math
t=int(input())
while t>0:
    n=int(input())
    L=list(map(int,input().split()))
    l=1
    r=n
    l_count=0
    r_count=0
    all_count=0
    for i in L:
        l_count+=i!=l
        r_count+=i!=r
        all_count+=(i!=l and i!=r)
        l+=1
        r-=1
    l_count-=all_count
    r_count-=all_count
    if l_count+all_count<=r_count:
        print("First")
    elif r_count+all_count<l_count:
        print("Second")
    else:
        print("Tie")
    t-=1
