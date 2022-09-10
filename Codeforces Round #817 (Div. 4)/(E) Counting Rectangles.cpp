#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100010;
int t, n, q;
int f[1015][1015];

void solve() 
{
	memset(f,0,sizeof f);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) 
    {
		int h, w;
		cin >> h >> w;
		f[h][w] += h * w;
	}
	for(int i = 1; i <= 1010; i ++) 
    {
		for(int j = 1; j <= 1010; j ++) 
        {
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
		}
	}
	while(q --) 
    {
		int h1, w1, h2, w2;
		cin >> h1 >> w1 >> h2 >> w2;
		h2--, w2--;
		h1++, w1++;
		cout << f[h2][w2] + f[h1 - 1][w1 - 1] - f[h1 - 1][w2] - f[h2][w1 - 1] << '\n';
	}
}
signed main() 
{
	cin >> t;
	while(t --) solve();
}
