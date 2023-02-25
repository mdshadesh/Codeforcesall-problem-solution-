import sys

for _ in range(int(sys.stdin.readline().strip())):
    m = int(sys.stdin.readline().strip())
    count1 = 0
    for temp in map(int, sys.stdin.readline().strip().split()):
        if temp == 1:
            count1 += 1
    print(m - count1 + (count1+1)//2)
