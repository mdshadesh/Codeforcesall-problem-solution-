def solve():
    n = int(input())
    a = list(map(int,input().split()))
    l=0
    r=n-1
    while l <= r:
        if l < r:
            print(a[l],end=" ")
            l += 1
            print(a[r],end=" ")
            r -= 1
        else:
            print(a[l],end=" ")
            l += 1
    print()
 
def main():
    t = int(input())
    for i in range(t):
        solve()
 
main()


