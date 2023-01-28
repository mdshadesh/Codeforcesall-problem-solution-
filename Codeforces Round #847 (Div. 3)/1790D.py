from heapq import heappop, heappush ,heapify
 
import sys
input = lambda: sys.stdin.readline().strip()
 
 
    
def lst():return [int(i) for i in input().split()]
mm=int(input())
for i in range(mm):
    nn=int(input())
    ll=lst()
    ll=sorted(ll)
    hh=[]
    tot=0
    for i in ll:
        while hh and hh[0]+1<i: heappop(hh);tot+=1
        if hh and  hh[0]==i:heappush(hh,i)
        elif  hh and hh[0]+1==i:heappop(hh);heappush(hh,i)
        elif  hh :
            
            heappop(hh);heappush(hh,i);tot+=1
        else:heappush(hh,i)
    print (str(len(hh)+tot))