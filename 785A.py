n=int(input())
sum=0
for i in range(n):
    x=input()
    
    if x=="Tetrahedron":
        sum+=4
    elif x=="Cube":
        sum+=6
    elif x=="Octahedron":
        sum+=8
    elif x=="Dodecahedron":
        sum+=12
    elif x=="Icosahedron":
        sum+=20
 
print(sum)
