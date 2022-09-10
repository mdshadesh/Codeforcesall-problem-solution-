#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
 
int main()
{
    cin.tie(0) -> sync_with_stdio(false);
 
    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
 
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
 
        map<int,vector<ll>> mp;
        map<int,multiset<ll>> mps;
        for (int i = 2, x = n; i <= x; i++)
        {
            if (x % i) continue;
 
            while (x % i == 0) x /= i;
            auto&& v = mp[i];
            v.resize(n / i);
            for (int sp = 0, blk = n / i; sp < blk; sp++)
            {
                ll sum = 0;
 
                for (int j = sp, cnt = 0; cnt < i; j = (j + blk) % n, cnt++)
                {
                    sum += a[j];
                }
 
                sum *= blk;
                v[sp] = sum;
            }
            mps[i] = multiset<ll>(v.begin(), v.end());
        }
 
        auto getans = [&]() -> ll   
        {
            ll ans = 0;
            for (auto&& [k, s] : mps)
            {
                ans = max(ans, *s.rbegin());
            }
            return ans;
        };
 
        cout << getans() << "\n";
 
        while (q--)
        {
            ll p, x;
            cin >> p >> x;
            p--;
 
            for (auto&& [k, v] : mp)
            {
                ll rem = n / k;
                mps[k].erase(mps[k].find(v[p%rem]));
                v[p%rem] -= rem * a[p];
                v[p%rem] += rem * x;
                mps[k].insert(v[p%rem]);
            }
            a[p] = x;
 
            cout << getans() << "\n";
        }
    }
 
    return 0;
}