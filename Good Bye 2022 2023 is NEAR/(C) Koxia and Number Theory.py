for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if len(set(a)) != n:
        print("NO")
    else:
        flag = False
        for i in range(2, n // 2 + 1):
            ost = [0] * i
            for j in a:
                ost[j % i] += 1
            ans = 0
            for j in ost:
                if j > 1:
                    ans += 1
            if ans == i:
                flag = True
                break
        if flag:print("NO")
        else:print("YES")