def h():
    n = int(input())
    s = input().strip()
    t = input().strip()
    c1 = [0] * 26
    c2 = [0] * 26
    for i in range(n):
        c1[ord(s[i]) - ord('a')] += 1
    for i in range(n):
        c2[ord(t[i]) - ord('a')] += 1
    if c1 != c2:
        print("-1")
        return
    ans = []
    for i in range(n-1, -1, -1):
        if s[i] == t[i]:
            continue
        j = i
        while s[j] != t[i]:
            j -= 1
        for k in range(j, i):
            ans.append(k)
            s = s[:k] + s[k+1] + s[k] + s[k+2:]
    print(len(ans))
    print(" ".join(str(x+1) for x in ans))

# t = int(input())
# for _ in range(t):
h()
