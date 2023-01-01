for _ in range(int(input())):
    n,m=list(map(int,input().split(" ")))
    l1=list(map(int,input().split(" ")))
    l2=list(map(int,input().split(" ")))
    
    
    for i in range(m):
        l1[l1.index(min(l1))]=l2[i]
    
    
    print(sum(l1))

    