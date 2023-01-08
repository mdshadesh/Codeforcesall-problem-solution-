mod = 1000000007
 
 
def check(pos, val):
    if pos == kk and val != ss:
        return False
    if pos == tt and val != pp:
        return False
  #  print(dp[1][1])
    return True
 
 
def solve():
    global n, kk, tt, ss, pp
    n, kk, tt, ss, pp = map(int, input().split())
  #  print(n, kk, tt, ss, pp)
    global dp
    dp = [[0 for i in range(n + 2)] for j in range(n + 2)]
    for i in range(2, n, 1):
        if check(i, n):
            dp[i][i] = 1
            # print(i)
    for i in range(n, 0, -1):
        for j in range(i, n+1):
            val = n - (j - i + 1)
            if check(i - 1, val):
                dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % mod
            if check(j + 1, val):
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod
    print(int(dp[1][n]))
 
 
if __name__ == '__main__':
    __t = int(input())
    while(__t > 0):
        __t -= 1
        solve()
