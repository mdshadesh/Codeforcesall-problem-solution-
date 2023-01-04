for _ in range(int(input())):
    n = int(input())
    m = 1000000007 
    ans = (n*(n+1)*(4*n-1))//6
    print(int(2022*ans)%m)

    