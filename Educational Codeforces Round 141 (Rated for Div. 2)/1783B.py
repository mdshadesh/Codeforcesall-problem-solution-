n = int(input())
while n > 0:
    n -= 1
    x = int(input())
    r = x * x
    l = 1
    i = j = ind = 0
    dir = 1
    mat = [0 for k in range(x)]
    while l <= r:
        if ind == 0:
            mat[j] = l
            l += 1
            ind = 1
        else:
            mat[j] = r
            r -= 1
            ind = 0
        j += dir
        if j == x or j == -1:
            for k in range(x):
                print(mat[k], end=" ")
            print()
            dir *= -1
            if dir == 1:
                j = 0
            else:
                j = x-1