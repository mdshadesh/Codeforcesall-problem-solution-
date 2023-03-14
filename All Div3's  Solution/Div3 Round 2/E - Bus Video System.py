n, w = map(int, input().split())
a = list(map(int, input().split()))
minw, maxw = 0, w
k = 0
for e in a:
    w -= e
    k -= e
    maxw = min(w, maxw)
    minw = max(minw, k)
if minw > maxw:
    print(0)
else:
    print(maxw - minw + 1)