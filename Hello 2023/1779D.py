import heapq
T=int(input())
import collections
while T>0:
    n=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    m=int(input())
    X=list(map(int,input().split()))
    counter=collections.Counter(X)
    sign=1
    heap=[]
    for i in range(n):
        if B[i]>A[i]:
            print("NO")
            sign=0
            break
        while heap and heap[0]<B[i]:
            heapq.heappop(heap)
        if B[i]<A[i] and (not heap or heap[0]>B[i]):
            if counter[B[i]]==0:
                print("NO")
                sign = 0
                break
            else:
                counter[B[i]]-=1
                heapq.heappush(heap,B[i])
    if sign:
        print("YES")
    T-=1