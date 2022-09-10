#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sortl(v) sort(v.begin(), v.end())
#define loop(i, n) for (ll i = 0; i < n; i++)
const int inf = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        ll x;
        cin >> x;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        int num_min = vec[0];
        int num_max = vec[0];
        ll res = 0;
        for (int i = 1; i < n; i++)
        {
            if (vec[i] > num_max)
                num_max = vec[i];
            if (vec[i] < num_min)
                num_min = vec[i];
            if (num_max - num_min > 2 * x)
            {
                res++;
                num_max = vec[i];
                num_min = vec[i];
            }
        }
        cout << res << endl;
    }
 
    return 0;
}