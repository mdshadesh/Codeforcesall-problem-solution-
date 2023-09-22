for _ in range(int(input())):
    counter = 0
    n,k = map(int,input().split())
    s = input()
    i=0
    while i<n:
        if s[i] == 'B':
            counter += 1
            i+=k
        else:
            i+=1
    print(counter)
