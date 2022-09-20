#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 520;
LL n, m, q, t, x, y;
LL a[N][N];
LL num(LL t, LL x, LL y)
{
    memset(a, 0, sizeof a);
    a[0][0] = max(t - (x + y) + 1LL, 0LL);
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j <= y; ++j)
        {
            a[i + 1][j] += a[i][j] / 2;
            a[i][j + 1] += a[i][j] -a[i][j]/2;
        }
    return a[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        cin >> t >> x >> y;
        if (num(t, x, y) > num(t - 1, x, y))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}