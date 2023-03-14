n=int(input())
s=input()
d=[]
for i in range(n):
     i+=1
     if (n/i)%1==0:
          d.append(i)
for t in d:
     r=list(s[:t])
     r.reverse()
     s=''.join(r)+s[t:]
print(s)
