#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 1e5 + 5, MAXK = 320, INF = 1e9 + 7;
 
int p[MAXN];
 
#define print(...) [](const auto&...x){ char c='='; cout<<#__VA_ARGS__<<" "; ((cout<<exchange(c,',')<<" "<<x),...); cout << "\n"; }(__VA_ARGS__);
 
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fill(p, p + MAXN, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int q = INF;
    for (int i = 0; i < n; i++)
    {
        int j = 1;
        while (j <= min(a[i], k))
        {
            p[a[i]/j] = max(p[a[i]/j], q);
            q = a[i]/j;
            j = a[i]/(a[i]/j) + 1;
        }
        
        p[0] = max(p[0], q);
    }
    
    int ans = INF, cur = 0;
    
    for (int i = 0; i < a[0] + 1; i++)
    {
        cur = max(cur, p[i]);
        ans = min(ans, cur - i);
    }
    
    
    
    cout << ans - 1<< "\n";
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
cin >> t;
 while (t--)
{
    solve();
}
 
 return 0;
}