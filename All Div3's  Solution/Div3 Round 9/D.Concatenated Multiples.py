def solve():
    n, k = [int(x) for x in input().split(' ')]
    a = [int(x) for x in input().split(' ')]
    a_pows = []
    a_pow_dict = [{} for u in range(11)]
    for j in range(n):
        x = a[j] % k
        i = 0
        while i < 11:
            if x in a_pow_dict[i]:
                a_pow_dict[i][x] += 1
            else:
                a_pow_dict[i][x] = 1
            i += 1
            x = (x * 10) % k

    c = 0

    for x in a:
        m = len(str(x))
        if (-x) % k in a_pow_dict[m]:
            c += a_pow_dict[m][(-x) % k]
            c -= int(int(str(x) * 2) % k == 0)

    return c


print(solve())
