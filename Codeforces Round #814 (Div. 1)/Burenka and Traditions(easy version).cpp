#include <bits/stdc++.h>
#define int long long
#define ull unsinged long long
#define pb push_back
#define sz(v) (int)v.size()
#define mp make_pair
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define L(p) 2*p
#define R(p) 2*p+1
#define For(a, b, c) for (int a = b; a <= c; a ++)
#define Rev(a, b, c) for (int a = b; a >= c; a --)
 
using namespace std;
const double EPS = 1e-6;
const int N = 2e5 + 5, mod = 13331, INF = 0x3f3f3f3f;
int n, m, t;
int a[N];
int solve() {
	cin >> n;
	memset(a, 0, sizeof(a));
	map <int, int> b;
	b[0] = 0;
	For (i, 1, n) cin >> a[i];
	For (i, 1, n) {
		a[i] ^= a[i - 1];
		
	}
	int res = n;
	For (i, 1, n) {
		if (b.count(a[i])) {
			res --;
			b.clear();
		}
		b[a[i]] = i;
	}
	return res;
}
 
signed main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}

 