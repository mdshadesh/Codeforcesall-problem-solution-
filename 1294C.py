import math

for _ in range(int(input())):
    n = int(input())
    a, b, c = 1, n, n
    lim = int(math.sqrt(n)) + 1

    # Find a prime factor of n and divide n by it
    for i in range(2, lim):
        if n % i == 0:
            a = i
            break
    n //= a

    # Find two more factors of n
    lim = int(math.sqrt(b)) + 1
    for i in range(2, lim):
        if n % i == 0:
            if i != a:
                b = min(b, i)
            if i != n // i:
                b = min(b, n // i)
    c = n // b

    # Check if a, b, and c are distinct and greater than 1
    if a != b and b != c and a != c and c > 1 and b > 1:
        print("YES")
        print(a, b, c)
    else:
        print("NO")
