#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int t, n;
char a[N], b[N];
int cnt[30][30];

int main () 
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) 
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) 
        {
            int c1 = a[i] - 'a' + 1, c2 = b[n - i + 1] - 'a' + 1;
            if (c1 > c2) swap(c1, c2);
            cnt[c1][c2] ++;
        }
        int cnt1 = 0, flag = 1;
        for (int i = 1; i <= 26; i++) 
        {
            if (cnt[i][i] % 2) cnt1++;
            for (int j = i + 1; j <= 26; j++) 
            {
                if (cnt[i][j] % 2) flag = 0;
            }
        }
        if (flag == 0 || cnt1 > 1) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}