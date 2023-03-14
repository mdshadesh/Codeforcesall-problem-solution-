n, m = map(int, input().split())
w = list(map(int, input().split()))
r, q = sum(w), n // m
t = [[] for _ in range(m)]
for i in range(n):
    t[w[i] % m].append(i)
j = -m
for i, l in enumerate(t):
    if len(l) > q:
        if j <= i - m:
            j = i - m + 1
        while len(l) > q:
            while len(t[j]) >= q:
                j += 1
            w[l.pop()] += j + m - i
            t[j].append(0)
print(sum(w) - r)
print(' '.join(map(str, w)))