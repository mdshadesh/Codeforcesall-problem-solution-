#include <bits/stdc++.h>

#define ll long long

const ll  MM = 1e9 + 7, N = 3e5 + 10, MAX = 1e18;
using namespace std;

ll dp[N][2],res[N];
vector<ll>v[N];
vector<ll>v1[N][2];

ll DP(int i = 1, int ch = 0,int p=-1) {
	if (dp[i][ch] + 1)return dp[i][ch];
	set<pair<ll, ll>>s;
	ll res = 0;
	for (auto x : v[i]) {
		if (x != p) {
			pair<ll, ll>a = { DP(x,0,i),DP(x,1,i) + 2 };
			res += a.first;
			s.insert({ a.second - a.first,x });
		}
	}
	bool f = 0;
	while (s.size()&&s.begin()->first < 0) {
		f = 1;
		v1[i][ch].emplace_back(s.begin()->second);
		res += s.begin()->first;
		s.erase(s.begin());
	}
	if (!ch && !f) {
		if (s.empty())return dp[i][ch]=MAX;
		res += s.begin()->first;
		v1[i][ch].emplace_back(s.begin()->second);
	}
	return dp[i][ch] = res;
}

void path(int i=1, int ch=0, int p=-1, int ins=1) {
	set<ll>s;
	for (auto x : v1[i][ch]) {
		path(x, 1, i, ins);
		ins = x;
		s.insert(x);
	}
	for (auto x : v[i]) {
		if (s.count(x) || x == p)continue;
		path(x, 0, i, x);
	}
	res[i] = ins;
}

int solve() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << DP() << '\n';
	path();
	for (int i = 1; i <= n; i++)cout << res[i]<<" ";
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	int t = 1;//cin >> t;
	int i = 1;
	while (t--) {
		//cout << "Case #" << i++ << ": ";
		solve();
	}
}
/*

*/
  				  		       		   	 		  		