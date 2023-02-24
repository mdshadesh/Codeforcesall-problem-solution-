from sys import stdin, stdout
input = stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    p = q = n - 1
    c = 0
    while p >= 0:
        if a[p] == b[q]: q -= 1
        else: c += 1
        p -= 1
    print(c)