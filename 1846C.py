aa = []
for _ in range(int(input())):
    n,m,h = map(int,input().split())
    l = list(map(int,input().split()))
    l.sort()
    o = 1
    c = 0 
    p = 0 
    s = 0
    for i in l :
        if s + i <= h :
            c+=1 
            s+=i
            p+=s
        else :
            break
    for i in range(n-1):
        l = list(map(int,input().split()))
        pp = 0 
        cc = 0
        ss = 0
        for j in sorted(l) :
            if ss + j <= h :
                cc+=1 
                ss+=j
                pp+=ss
            else :
                break
        if cc > c :
            o+=1 
        elif c == cc :
            if pp < p :
                o+=1 
    aa.append(o)
for i in aa :
    print(i)
