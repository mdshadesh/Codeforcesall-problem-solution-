p = input()
s1 = set()
for i in range(len(p)):
    if ord(p[i]) >= 97 and ord(p[i]) <= 122:
        s1.add(p[i])
print(len(s1))
