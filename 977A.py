a=input().split()
b=int(a[0])
c=int(a[1])
co=1
while co<=c:
    if str(b)[-1]=="0":
        b=b//10
        co+=1
    else:
        b=b-1
        co+=1
print(b)
    
