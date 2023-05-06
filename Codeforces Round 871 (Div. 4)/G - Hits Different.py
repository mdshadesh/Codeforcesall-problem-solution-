import sys
import os, math
import math as mth
from collections import Counter, deque, defaultdict
from heapq import nsmallest, nlargest, heapify, heappop, heappush
from io import BytesIO, IOBase
import bisect


# sys.setrecursionlimit(10**6)
BUFSIZE = 4096
MOD = 10 ** 9 + 7
MODD = 998244353
inf = float('inf')
def isprime(n):
    if n==1:
        return(False)
    if n==2:
        return(True)
    if n%2==0:
        return(False)
    i=3
    while i*i<=n:
        if n%i:
            return(False)
        i+=2
    return(True)


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")
i = lambda: input()
ii = lambda: int(input())
MI = lambda: map(str, input().split())
mi = lambda: map(int, input().split())
li = lambda: list(input().split())
lmi = lambda: list(map(int, input().split()))
zli = lambda: [0] + list(map(int, input().split()))


def conv(test_list):
    res = int("".join(str(x) for x in test_list), 2)
    return (res)


def comb(n, r):
    ans = math.factorial(n) // ((math.factorial(r) * math.factorial(n - r)))
    return (ans)





#i see who you are
def solve():
    n=ii()
    def sum(a,b):
        a-=1
        ans=(b*(b+1)*(2*b+1))//6-(a*(a+1)*(2*a+1))//6
        return(ans)
    lst=[(i*(i+1))//2 for i in range(1,2024)]
    r=1
    for i in range(2023):
        if n<=lst[i]:
            r=i+1
            break

    ans=n*n
    prev=n
    aft=n
    uer=(r*(r-1))//2
    uel=((r-1)*(r-2))//2 +1
    x=r
    for i in range(1,x):

        newl=max(uel,prev-r)
        newr=min(uer,aft-r+1)


        ans+=sum(newl,newr)
        r-=1
        uer = (r * (r - 1)) // 2
        uel = ((r - 1) * (r - 2)) // 2  +1
        prev=newl
        aft=newr
    print(ans)

l = ii()

for i in range(l):
    solve()
# solve()