for _ in range(int(input())):
    n = int(input())
    if n % 2 == 0:
        print("Yes")
        for i in range(n//2):
            print(-1, 1, end = ' ')
        print()
    else:
        if n <= 3: print("No")
        else:
            print("Yes")
            for i in range(n//2):
                print(1-(n//2), n//2, end = " ")
            print(1-(n//2))