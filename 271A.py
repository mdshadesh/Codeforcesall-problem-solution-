s = input()
s = int(s)
s += 1
s = str(s)
while not (s[0] != s[1] and s[0] != s[2] and s[0]!= s[3]and s[1] != s[2] and s[1] != s[3] and s[2] != s[3]) :
   s = int(s)
   s += 1
   s = str(s)
else:
    print(s)