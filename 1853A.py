for case in range(int(input())):
    delta = 10 ** 10
    n_input = int(input())
    a = list(map(int, input().split()))
    for i in range(n_input - 1):
        delta = min(delta, a[i+1] - a[i])
    print(max(0, (delta + 2) // 2))
