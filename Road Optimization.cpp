#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Solution
{
    void run()
    {
        int n, l, k;
        cin >> n >> l >> k;
        int d[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        d[n] = l;
        a[n] = 0;
 
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = i != 0 ? Integer_MAX_VALUE : 0;
            }
        }
 
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int need_k = i - j - 1;
                if (need_k > k)
                    break;
 
                for (int already = 0; already <= k - need_k; already++)
                {
                    dp[i][already + need_k] = min(dp[i][already + need_k], dp[j][already] + a[j] * (d[i] - d[j]));
                }
            }
        }
 
        int ans = Integer_MAX_VALUE;
        for (int i = 0; i <= k; i++)
        {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    Solution solution = Solution();
 
    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
 
    // }
    solution.run();
    return 0;
}