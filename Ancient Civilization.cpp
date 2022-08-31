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
        int n, l;
        cin >> n >> l;
        int count[l]{0};
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int j = 0; j < l; j++)
            {
                if ((x & (1 << j)) != 0)
                {
                    count[j]++;
                }
            }
        }
 
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            if (count[i] > (n - count[i]))
            {
                ans += 1 << i;
            }
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