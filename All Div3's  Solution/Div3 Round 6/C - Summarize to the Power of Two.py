from collections import Counter
a = int(input())
b = list(map(int, input().split()))
c = Counter(b)
q = 0
for i in c:
    for j in range(31):
        w = 2**j
        if (w - i) > 0 and (w - i) in c and (c[i] >= 2 or (w-i) != i):
            break
    else:
        q += c[i]
print(q)
