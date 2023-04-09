n = int(input())

for i in range(n+1):
    for j in range(n-i, 0, -1):
        print("  ", end="")
    for j in range(i+1):
        if i == j == 0:
            print(j, end="")
        else:
            print(j, end=" ")
    for j in range(i-1, -1, -1):
        if j == 0:
            print(j, end="")
        else:
            print(j, end=" ")
    print()

for i in range(n-1, -1, -1):
    for j in range(n-i, 0, -1):
        print("  ", end="")
    for j in range(i+1):
        if i == j == 0:
            print(j, end="")
        else:
            print(j, end=" ")
    for j in range(i-1, -1, -1):
        if j == 0:
            print(j, end="")
        else:
            print(j, end=" ")
    print()
