# include <iostream>
# include <cmath>
# include <cstring>
# include <algorithm>

# define ll long long
# define int long long

using namespace std;

const int MAXN=5e3 + 10, MOD = 998244353;
int n, a[MAXN][MAXN], dp1[MAXN], dp2[MAXN];

signed main() {
	cin >> n;
	a[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
	    a[i][0]=1; 
	    for(int j = 1; j <= i; ++j) {
	        a[i][j]=(a[i - 1][j - 1] + a[i - 1][j]) % MOD;
	    }
	}
	dp1[1] = dp2[1] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= i - 1; ++j) {
		    dp1[i] += a[i - 1][j - 1] * dp1[j] % MOD * dp2[i - j] % MOD;
		    dp1[i] %= MOD;
		}
		dp2[i] = dp1[i] * 2 % MOD;	
	}
	cout << ((dp2[n] - 2) % MOD + MOD) % MOD;
	return 0;
}