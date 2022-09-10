#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n >> s;
        string temp = "Timur";
        sort(temp.begin(), temp.end());
        sort(s.begin(), s.end());
        if (temp == s)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}