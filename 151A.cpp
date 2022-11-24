#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n, k, l, c, d, p, np, nl, min = 0;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int t1 = (k * l) / nl;
    int t2 = c * d;
    int t3 = p / np;
    if (t1 >= t2)
    {
        min = t2;
        if (t3 < min)
        {
            min = t3;
        }
    }
    else
    {
        min = t1;

        if (t3 < min)
        {
            min = t3;
        }
    }
    cout << min / n;
}