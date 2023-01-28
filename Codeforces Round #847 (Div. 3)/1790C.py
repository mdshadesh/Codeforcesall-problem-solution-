import sys
import math
import heapq
import bisect
 
 
t=int(input())
for _ in range(t):
    n=int(input())
    arr=[]
    for i in range(n):
        l=[int(x) for x in input().split()]
        arr.append(l)
    a,b,c=arr[0],arr[1],arr[2]
    ans=[]
    for i in range(n-1):
        if a[i]==b[i]:
            ans.append(a[i])
        else:
            for j in range(n-1):
                if c[j]==a[i]:
                    ans.append(a[i])
                    ans.extend(b[i:])
                    break
                elif c[j]==b[i]:
                    ans.append(b[i])
                    ans.extend(a[i:])
                    break
            break
    print(*ans)
 