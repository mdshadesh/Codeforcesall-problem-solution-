l1 = l2 = -1
r1 = r2 = 1 << 30

for i in range(int(input())):
    l, r = map(int, input().split())

    if l > l1:
        il, l1, l2 = i, l, l1
    elif l > l2:
        l2 = l

    if r < r1:
        ir, r1, r2 = i, r, r1
    elif r < r2:
        r2 = r

print(max(0, (r2 - l2, max(r1 - l2, r2 - l1))[il != ir]))
