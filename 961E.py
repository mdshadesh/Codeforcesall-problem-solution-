class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0]*(self.n+1) # 1-indexed

    def init(self, init_val):
        for i, v in enumerate(init_val):
            self.add(i, v)

    def add(self, i, x):
        # i: 0-indexed
        i += 1 # to 1-indexed
        while i <= self.n:
            self.bit[i] += x
            i += (i & -i)

    def sum(self, i, j):
        # return sum of [i, j)
        # i, j: 0-indexed
        return self._sum(j) - self._sum(i)

    def _sum(self, i):
        # return sum of [0, i)
        # i: 0-indexed
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & (-i)
        return res

    def lower_bound(self, x):
        s = 0
        pos = 0
        depth = self.n.bit_length()
        v = 1 << depth
        for i in range(depth, -1, -1):
            k = pos + v
            if k <= self.n and s + self.bit[k] < x:
                    s += self.bit[k]
                    pos += v
            v >>= 1
        return pos

    def __str__(self): # for debug
        arr = [self.sum(i,i+1) for i in range(self.n)]
        return str(arr)

n = int(input())
A = list(map(int, input().split()))
A = [a-1 for a in A]
A = [min(a, n-1) for a in A]
bit = BIT(n+5)
B = [[] for i in range(n)]
for i, a in enumerate(A):
    bit.add(i, 1)
    B[a].append(i)
ans = 0
for i, a in enumerate(A):
    ans += bit.sum(0, a+1)
    for j in B[i]:
        bit.add(j, -1)
for i, a in enumerate(A):
    if a >= i:
        ans -= 1
ans //= 2
print(ans)