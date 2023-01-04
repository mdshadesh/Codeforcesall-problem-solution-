#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t)
    {
        ll n;
        cin >> n;
        vector<int> a(n), m(2 * n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        ll cnt = 0;
        int curr = 0;
        m[curr]++;
        for (int j = 0; j < n; j++)
        {
            curr ^= a[j];
            for (ll i = 0; i * i < 2 * n; i++)
            {
                if ((curr ^ (i * i)) < 2 * n)
                {
                    cnt += m[curr ^ (i * i)];
                }
            }
            m[curr]++;
        }
        ll ans = ((n * (n + 1)) / 2) - cnt;
        cout << ans << endl;
        t--;
    }
}