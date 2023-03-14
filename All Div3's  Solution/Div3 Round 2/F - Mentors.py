f = lambda: map(int, input().split())
n, m = f()
r = list(f())
s = [0] * n
p = sorted((a, i) for i, a in enumerate(r))
for k in range(n):
    a, i = p[k]
    b, j = p[k - 1]
    s[i] = s[j] if a == b else k
for i in range(m):
    a, b = f()
    a -= 1
    b -= 1
    s[a] -= r[a] > r[b]
    s[b] -= r[b] > r[a]
print(*s)