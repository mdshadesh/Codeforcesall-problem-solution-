import sys
import math
import collections
import heapq
input=sys.stdin.readline
n,m=(int(i) for i in input().split())
l1=[0]*n
def bfs(d,d1,v):
    q=[v]
    l1[v]=1
    c1=1
    c2=1
    while(c2>0):
        s=q.pop(0)
        c2-=1
        if(d1[s]!=2):
            c1=0
        for i in d[s]:
            if(l1[i]==0):
                q.append(i)
                c2+=1
                l1[i]=1
    return c1
d=collections.defaultdict(list)
d1={}
for i in range(n):
    d1[i]=0
for i in range(m):
    u,v=(int(i) for i in input().split())
    d[u-1].append(v-1)
    d[v-1].append(u-1)
    d1[u-1]+=1
    d1[v-1]+=1
c=0
for i in range(n):
    if(l1[i]==0):
        k=bfs(d,d1,i)
        c+=k
print(c)