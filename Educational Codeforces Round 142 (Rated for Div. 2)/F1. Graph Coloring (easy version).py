import math

MOD = 998244353
MAXN = 5000 + 10

n = int(input())
a = [[0] * MAXN for _ in range(MAXN)]
dp1 = [0] * MAXN
dp2 = [0] * MAXN

a[0][0] = 1
for i in range(1, n+1):
    a[i][0] = 1
    for j in range(1, i+1):
        a[i][j] = (a[i-1][j-1] + a[i-1][j]) % MOD

dp1[1] = dp2[1] = 1
for i in range(2, n+1):
    for j in range(1, i):
        dp1[i] += (a[i-1][j-1] * dp1[j] % MOD * dp2[i-j] % MOD)
        dp1[i] %= MOD
    dp2[i] = dp1[i] * 2 % MOD

print((dp2[n] - 2) % MOD)
