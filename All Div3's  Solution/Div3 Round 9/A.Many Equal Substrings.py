n, k = map(int, input().split())
s = input().strip()

L = n - 1
while s[:L] != s[n - L:]:
    L -= 1

t = s
for i in range(1, k):
    t += s[L:]

print(t)
