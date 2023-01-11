n = int(input())
 
for i in range(n):
    k = int(input())
    lst = list(map(int, input().split()))
    if lst[0] == min(lst): print("Bob")
    else: print("Alice")