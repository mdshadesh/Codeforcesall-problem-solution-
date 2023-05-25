n = int(input())
i = 0
for i in range(0,n):
    m = int(input())
    p = input()
    L = list(p)
    manage = []
    for j in range(0,m-1):
        s = L[j] + L[j+1]
        manage.append(s)
    final = set(manage)
    print(len(final))
