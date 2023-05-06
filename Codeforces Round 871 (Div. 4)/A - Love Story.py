t = int(input())
while t > 0:
    s = input()
    a = "codeforces"
    k = 0
    for i in range(10):
        if s[i] == a[i]:
            k += 1
    print(10 - k)
    t -= 1
