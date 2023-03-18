import sys
input = sys.stdin.readline
from itertools import accumulate

n = int(input())
w = [*accumulate(map(int, input().split()))]
x = set(w)&set(w[-1] - i for i in w if 2*i >= w[-1])
print(max(x, default=0))