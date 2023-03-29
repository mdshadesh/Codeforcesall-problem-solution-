n, k, s = map(int, input().split())
if k * (n - 1) < s:
    print("NO")
    exit()
if s < k:
    print("NO")
    exit()
print("YES")
q = s // k
r = s % k
curr = 1
for i in range(k):
    step = q
    if r > 0:
        step += 1
        r -= 1
    if i % 2 == 0:
        curr += step
    else:
        curr -= step
    print(curr, end=" ")
print()
