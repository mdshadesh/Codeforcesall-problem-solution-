t = int(input())
 
while t != 0:
    t-=1
    n = int(input())
    s = input()
    if 'L'*n == s or 'R'*n == s:
        print(-1)
    elif "LR" in s:
        print(s.find("LR")+1)
    else:
        print(0)