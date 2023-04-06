t = int(input()) 
for i in range(t):
    n, k = map(int, input().split())
    if n % 2 == 0:
        print("YES")
    elif k % 2 == 1:
        print("YES")
    else:
        print("NO")
