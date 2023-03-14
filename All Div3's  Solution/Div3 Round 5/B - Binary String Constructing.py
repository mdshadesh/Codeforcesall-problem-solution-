a, b, x = list(map(int, input().split()))
bs = ''

if x % 2 == 0:
    if a > b:
        for i in range(x//2):
            bs += '01'
        bs += (b-x//2) * '1'
        bs += (a-x//2) * '0'
    else:
        for i in range(x//2):
            bs += '10'
        bs += (a-x//2) * '0'
        bs += (b-x//2) * '1'
elif a > b:
    for i in range(x // 2):
        bs += '01'
    bs += (a - x // 2) * '0'
    bs += (b - x // 2) * '1'
else:
    for i in range(x // 2):
        bs += '10'
    bs += (b - x // 2) * '1'
    bs += (a - x // 2) * '0'

print(bs)