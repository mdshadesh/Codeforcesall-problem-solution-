import sys
input = sys.stdin.readline

T = int(input().strip())

for _ in range(T):
    n = int(input().strip())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    max1, max2 = 0, 0
    for i in range(n-1):
        if a[i] >= b[i]:
            max1 = max(max1, a[i])
            max2 = max(max2, b[i])
        else:
            max1 = max(max1, b[i])
            max2 = max(max2, a[i])

    if max1 <= max(a[n-1], b[n-1]) and max2 <= min(a[n-1], b[n-1]):
        print("YES")
    else:
        print("NO")
