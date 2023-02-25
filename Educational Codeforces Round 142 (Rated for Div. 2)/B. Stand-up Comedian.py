import sys
input = sys.stdin.readline
 
def solve():
    a, b, c, d = map(int, input().split())
    
    counter = 0
    mood = 1
    
    if a == 0:
        if b or c or d:
            print(1)
        else:
            print(0)
        return
    
    counter += a
    mood += counter
    
    dif = min(b, c)
    c = max(b, c) - dif
    counter += (dif * 2)
    
    c = min(mood, c)
    counter += c
    mood -= c
    counter += min(mood, d)
    
    print(counter)
    
a = int(input().strip())
for i in range(a):
    solve()
