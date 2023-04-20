from collections import Counter

n, k = map(int, input().split())
r = []
for l, m in Counter(map(int, input().split())).items():
    r += [(m // i, l) for i in range(1, m + 1)]
print(*(x for _, x in sorted(r)[-k:]))
