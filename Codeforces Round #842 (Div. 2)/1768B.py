import sys
import math
import cmath
import time
from bisect import bisect_left
start_time = time.time()
 
 
def per():
    n,k=map(int,inps())
    l=[int(j) for j in inps() ]
    c=1
    for i in l:
        if(i==c):
            c=c+1
    print(math.ceil((n-c+1)/k))
 
def main():
 
    testcases = 1
    testcases = inp()
    for each_testcase in range(testcases):
        per()
 
def inp():
    return(int(input()))
def inps():
    return(input().split())
 
ans = __debug__ 
if ans:
    input = sys.stdin.readline
 
main()