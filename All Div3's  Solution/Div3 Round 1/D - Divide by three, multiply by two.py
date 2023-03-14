a = int(input())
b = list(map(int,input().split()))

awal = 0

for i in b:
    if len(str(i)) > 18:
        if i*3 not in b and i//2 not in b:
            awal = i
    else:
        if i*3 not in b and i/2 not in b:
            awal = i

ans = str(awal)
cek = awal

for a in range(a-1):
    if int(cek*2) in b:
        b.pop(b.index(int(cek*2)))
        ans += " " + str(int(cek*2))
        cek = int(cek*2)
    elif int(cek//3) in b:
        b.pop(b.index(int(cek//3)))
        ans += " " + str(int(cek//3))
        cek = int(cek//3)

print(ans)