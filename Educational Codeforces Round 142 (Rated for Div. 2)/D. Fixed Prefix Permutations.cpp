#include<bits/stdc++.h>
using ll = long long;
const int inf = 0x3f3f3f3f;
const ll Base = 131, MOD = 1e9 + 9;
void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    auto b = a;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
            a[i][j]--;
            b[i][a[i][j]] = j;
        }
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        auto k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        auto check = [&](std::vector<int> &a1, std::vector<int> &b1)
        {
            int i = 0;
            while(i < m && a1[i] == b1[i])
                i++;
            return i;
        };
        int ans = 0;
        if(k < n)
            ans = std::max(ans, check(a[i], b[k]));
        if(k > 0)
            ans = std::max(ans, check(a[i], b[k - 1]));
        std::cout << ans << " \n"[i + 1 == n];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    int _t = 1;
    std::cin >> _t;
 
    while(_t--) {
        solve();
    }
    
    return 0;
}