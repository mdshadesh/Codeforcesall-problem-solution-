s1 = input()
s2 = ''
co = 0
for i in s1:
    if i in s2:
        continue
    else:
        s2 += i
        co += 1
if co % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
