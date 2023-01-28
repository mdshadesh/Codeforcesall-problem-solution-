n=int(input())
for i in range(n):
    s=input()
    c=0
    p="314159265358979323846264338327"
    for i in s:
        if(i==p[c]):
            c+=1
        else:
            break
    print(c)
            
        
