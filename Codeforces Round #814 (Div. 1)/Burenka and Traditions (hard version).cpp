#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, pre[N], a[N], dp[N];
void solve() 
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) 
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) 
        pre[i] = pre[i - 1] ^ a[i];
    map<int, int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1] + !(a[i] == 0);
        if(mp.count(pre[i]))
            dp[i] = min(dp[i], dp[mp[pre[i]]] + i - mp[pre[i]] - 1);
        mp[pre[i]] = i;
    }
    printf("%d\n", dp[n]);
}
 
int main() 
{
    int tc;
    scanf("%d", &tc);
    for(; tc; tc --) 
       solve();
}