import sys
import math
import cmath 
import time
for t in range(int(sys.stdin.readline())):
    n= int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().strip().split()))
    l= [0]*n
    sorter = True
 
    for i in range(n):
        l[a[i]-1] += 1
        if l[a[i]-1] ==3:
            sorter = False
            print('NO')
            break
    if sorter:
        sum= 0
        for i in range(n):
            sum+=l[i]
            if not sum <= i+1:
                sorter = False
                print('NO')
                break
        if sorter:
            print('YES')
            zeros = []
            for i in range(n):
                if l[i]==0: zeros.append(i)
 
            pq = [0]*n
            count = 0
            for i in range(n):
                if l[i] == 1:
                    pq[i] = i+1
                if l[i] == 2:
                    pq[i]  = zeros[count]+1
                    pq[zeros[count]] = i+1
                    count+=1
            p = [0]*n
            q= [0]*n
 
            for i in range(n):
                if l[a[i]-1] == 1:
                    p[i] = a[i]
                    q[i] = a[i]
                elif l[a[i]-1] ==2:
                    p[i]= a[i]
                    q[i]= pq[a[i]-1]
                    l[a[i]-1] -=2
                else:
                    p[i] = pq[a[i]-1]
                    q[i] =a[i]
 
            print(*p)
            print(*q)