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
        int n;
        cin >> n;
 
        int last_pos[150001];
        for (int i = 0; i <= 150000; i++)
        {
            last_pos[i] = -1;
        }
 
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (last_pos[x] != -1)
            {
                int left = last_pos[x];
                int right = n - i - 1;
                ans = max(left + right + 1, ans);
            }
 
            last_pos[x] = i;
        }
 
        cout << ans << endl;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    Solution solution = Solution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution.run();
    }
    return 0;
}