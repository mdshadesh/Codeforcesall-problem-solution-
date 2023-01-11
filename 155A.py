n = int(input())
mas = list(map(int, input().split()))
mx, mn = mas[0], mas[0]
res = 0
 
for i in mas:
    if i > mx:
        mx = i
        res += 1
    elif i < mn:
        mn = i
        res += 1
 
print(res)