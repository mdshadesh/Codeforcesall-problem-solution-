k = int(input())
a = "314159265358979323846264338327950288419716939937510582097"
for i in range(k):
    n = int(a[i])
    pr = 1
    for j in range(n):
        x = int(input())
        pr *= x
    print(pr)
