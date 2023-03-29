nt, mc = map(int, input().split())
seg = [0] * mc
for i in range(nt):
    p, k = map(int, input().split())
    for j in range(p-1, k):
        seg[j] += 1
count = 0
uncovered = []
for i in range(mc):
    if seg[i] == 0:
        count += 1
        uncovered.append(i+1)
print(count)
print(*uncovered)
