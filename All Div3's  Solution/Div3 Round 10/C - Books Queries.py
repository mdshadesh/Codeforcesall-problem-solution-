from sys import stdin, stdout
print = stdout.write
input = stdin.readline
s = [0]*200000
d = {}
r = 1
l = -1
a = []
t = int(input())
s[0] = input().split()[1]
d[s[0]] = 0
for x in range(t-1):
    q, n = input().split()
    if q == 'L':
        s[l] = n
        d[n] = l
        l -= 1
    if q == 'R':
        s[r] = n
        d[n] = r
        r += 1
    if q == '?':
        a += [str(d[n] - l - 1) if d[n] - l < r - d[n] else str(r - d[n] - 1)]
print('\n'.join(a))