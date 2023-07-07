n = int(input())
for _ in range(n):
    values = {}
    noropes = int(input())
    count = 0
    for _ in range(noropes):
        a, b = map(int, input().split())
        values[a] = b
        if a > b:
            count += 1
    print(count)
