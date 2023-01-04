import heapq
T=int(input())
while T>0:
    n,m=map(int,input().split())
    A=list(map(int,input().split()))
    val=0
    heap=[]
    ret=0
    for i in range(m-1,0,-1):
        val+=A[i]
        if A[i]>0:
            heapq.heappush(heap,-A[i])
            while val>0:
                t=heapq.heappop(heap)
                val+=2*t
                ret+=1
    heap=[]
    val=0
    for i in range(m,n):
        val+=A[i]
        if A[i]<0:
            heapq.heappush(heap,A[i])
            while val<0:
                t=heapq.heappop(heap)
                val-=2*t
                ret+=1
    print(ret)
    T-=1