#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define pb push_back
void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    char x = max(s[0], s[len - 1]);
    char y = min(s[0], s[len - 1]);
    vector<pair<char, int>> v;
    for (int i = 1; i < len - 1; i++)
    {
        if (s[i] <= x && s[i] >= y)
        {
            v.pb({s[i], i + 1});
        }
    }
    cout << (abs((s[0] - 'a') - (s[len - 1] - 'a'))) << " " << v.size() + 2 << endl;
    cout << 1 << " ";
    if (s[0] < s[len - 1])
    {
        sort(all(v));
        for (auto V : v)
        {
            cout << V.second << " ";
        }
    }
    else
    {
        sort(all(v));
        reverse(all(v));
        for (auto V : v)
        {
            cout << V.second << " ";
        }
    }
 
    cout << len << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}