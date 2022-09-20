#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1, n;
    bool neighbour;
    long long x, y, d, last_flip;
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        cin >> a >> b;
        d = 0;
        last_flip = -2;
        neighbour = false;
        for (int i = 0;i < n;i ++)
        {
            if (a[i] != b[i])
            {
                d ++;
                if (last_flip == i - 1)
                    neighbour = true;
                last_flip = i;
            }
        }
        if (d % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        if (d == 2)
        {
            if (neighbour)
                cout << min(x, 2ll * y) << '\n';
            else
                cout << y << '\n';
            continue;
        }
        cout << (d * y) / 2ll << '\n';
    }
    return 0;
}