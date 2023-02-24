def max(a,b):
    if(a>b):
        return a
    else:
        return b
def min(a,b):
    if(a<b):
        return a
    else:
        return b
t=int(input())

s=input()
l=[0]*t
for j in range(t):
    l[j]=s[j]
    #l=[]
c=0
d=0
for j in range(t):
    if(l[j]=='+'):
        c=c+1
    else:
        d=d+1
#print(c,d,end=" ")
#print()
n=int(input())
for j in range(n):
    l1=list(map(int,input().split()))
    a=l1[0]
    b=l1[1]
    
    #print(a,b,end=" ")
    
    #print()
    f=max(a,b)
    g=min(a,b)
    min1=g*c-f*d
    max1=f*c-g*d
    if(min1>0):
        print("NO")
    elif(min1==0 or max1==0):
        print("YES")
    elif(min1<0):
        if(max1==0):
            print("YES")
        elif(max1<0):
            print("No")
        else:
            e=f-g
            #print(e)
            
            #print(g)
            #print(abs(min1)%e)
            if(e!=0 and (max1-0)%e==0):
                print("YES")
            elif(e!=0 and (abs(min1-0))%e==0):
                
                print("YES")
            else:
                print("NO")
    



    