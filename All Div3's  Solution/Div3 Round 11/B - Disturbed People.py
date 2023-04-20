n = int(input())
a = list(map(int, input().split()))
k = 0

i = 1
while i < n-1:
    if a[i] == 0 and a[i-1] == a[i+1] and a[i+1] == 1:
        k += 1
        i += 3
    else:
        i += 1

print(k)
