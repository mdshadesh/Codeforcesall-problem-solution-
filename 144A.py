n = int(input())
arr = list(map(int, input().split()))

max_val = 0
max_index = 0
min_val = 110
min_index = 0

for i in range(n):
    if arr[i] > max_val:
        max_val = arr[i]
        max_index = i+1
    if arr[i] <= min_val:
        min_val = arr[i]
        min_index = i+1

if max_index > min_index:
    print((max_index-1) + (n-min_index) - 1)
else:
    print((max_index-1) + (n-min_index))
