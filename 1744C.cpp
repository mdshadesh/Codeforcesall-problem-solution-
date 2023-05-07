#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s += s;
        int l = 0, mx = 0;
        while (l < 2 * n)
        {
            int r = l;
            if (s[r] == c)
            {
                while (s[r] != 'g' && r < 2 * n)
                    r++;
            }
            mx = max(mx, r - l);
            l = r + 1;
        }
        cout << mx << "\n";
    }
}
