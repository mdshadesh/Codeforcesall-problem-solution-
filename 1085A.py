s = input()
if len(s) % 2 == 0:
    i = len(s) // 2 - 1
    j = i + 1
    while i >= 0:
        print(s[i]+s[j], end="")
        i -= 1
        j += 1
else:
    print(s[len(s)//2], end="")
    i = len(s) // 2 - 1
    j = i + 2
    while i >= 0:
        print(s[j]+s[i], end="")
        i -= 1
        j += 1

