import sys
input = lambda: sys.stdin.readline().rstrip()
 
def solve():
    n, m1, m2 = map(int, input().split())
 
    primes = set()
    divisors = []
 
    for m in [m1, m2]:
        D = [1, m]
        x = m
        for d in range(2, int(m ** 0.5) + 1):
            if m % d == 0:
                D.append(d)
                D.append(m // d)
            
            if x % d == 0:
                primes.add(d)
                while x % d == 0:
                    x //= d
 
        if x > 1:
            primes.add(x)
        
        divisors.append(D)
 
    mdiv = set()
    
    for d0 in divisors[0]:
        for d1 in divisors[1]:
            mdiv.add(d0 * d1)
 
    divisors = list(mdiv)
    divisors.sort()
    dp = dict()
    cnt  = 0
    total = 0
    
    for d in divisors:
        if d <= n:
            dp[d] = d
        
        else:
            mx = 0
            for p in primes:
                if d % p == 0:
                    mx = max(mx, dp[d // p])
            dp[d] = mx
        
        if dp[d] and d // dp[d] <= n:
            cnt += 1
            total ^= d // dp[d]
 
    print(cnt, total)
 
    return
 
 
for _ in range(int(input())):
    solve()
