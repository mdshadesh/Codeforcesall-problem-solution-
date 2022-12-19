#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;
map<ll, ll> m;
#define int long long
 
inline void add(ll &x, ll y) {
	x += y;
	x %= MOD;
}
int bpo(int x)
{
    if(x == 0) return 1;
    int r = bpo(x / 2);
    r *= r;
    r %= MOD;
    if(x % 2 == 1) add(r, r);
    return r;
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll q, x, type, shift = 0, mul = 0;
	int e = 2 * 1e5;
	vector<int> v(e + 1);
	cin >> q;
	while (q--) {
		cin >> type;
		if(type == 3) {
			if(shift == 0) mul++;
			else if(shift <= 2 * 1e5)
			{
				for(int i = shift + 2*1e5; i >= shift + 1; i--)
				{
					add(m[i+shift], m[i]);
				}
				shift *= 2;
			}
 
		} else if(type == 1) {
 
			cin >> x;
			if(shift == 0)
            {
                m[x] *= bpo(mul - v[x]);
                v[x] = mul;
            }
			m[x + shift]++;
			m[x + shift] %= MOD;
		} else if (type == 2) {
			if(shift == 0)
			{
				for(int i = 1; i <= 2 * 1e5; i++)
				{
					m[i] *= bpo(mul - v[i]);
					m[i] %= MOD;
				}
			}
			cin >> x;
			shift += x;
		}
	}
	if(shift == 0)
    {
        for(int i = 1; i <= 2 * 1e5; i++)
        {
            m[i] *= bpo(mul - v[i]);
            m[i] %= MOD;
        }
    }
	ll ans = 0;
	for (auto i : m) {
		if (i.first > shift) {
			add(ans, i.second);
		}
	}
	cout << ans << "\n";
}