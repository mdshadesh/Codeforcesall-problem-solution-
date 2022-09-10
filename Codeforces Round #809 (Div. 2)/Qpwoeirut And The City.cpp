#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define ff               first
#define sc               scanf
#define pf               printf
#define ss               second
#define in               insert
#define pp               pop_back
#define pb               push_back
#define mp               make_pair
#define all              v.begin(), v.end()
#define not_psble        {cout <<   -1  << endl; return; }
#define YES              {cout << "YES" << endl; return; }
#define NOO              {cout << "NOO"  << endl; return; }  
#define rall             v.rbegin(), v.rend()
#define endl             '\n'
#define printans         cout << ans << endl;
#define arrin            {for(int i = 0; i < n; ++i) cin >> v[i];}
#define int long long
 
int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}
 
void solve() {
 
	int ans = 0;
	int n; cin >> n;
	vector <int> v(n);
	arrin
	if(n==3) {
		int res = max(v[0],v[2]) - v[1] + 1;
		cout << max(res, 0) << endl;
		return;
	}
	for(int i = 1; i < n - 1; i += 2) {
		if(v[i] > v[i-1] and v[i] > v[i+1]) continue;
		if(v[i] <= v[i-1] or v[i] <= v[i+1]) {
			ans += max(v[i-1],v[i+1]) - v[i] + 1;
		}
	}
 
	if(n % 2 == 0) {
	int pref[n];
	memset(pref, 0, sizeof pref);
 
	for(int i = n - 2; i >= 1; i-=2) {
		pref[i] = max(max(v[i-1],v[i+1]) - v[i] + 1, 0);
	}
 
	for(int i = n - 2; i >= 0; --i) pref[i] = pref[i] + pref[i+1];
 
	int res = 0;
	
	for(int i = 1; i < n - 1; i += 2) {
		if(v[i] > v[i-1] and v[i] > v[i+1]) continue;
		if(i + 2 < n) {
			int cur = res + pref[i+1];
			ans = min(ans, cur);
			res += max(v[i-1],v[i+1]) - v[i] + 1;
		}
	}}
	
	cout << ans << endl;
}
 
signed main() {
	
	// 7X Font Size Sublime Text
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); int t = 1;
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif 
	cin >> t; 
	
	for(int i = 1; i <= t; ++i){
		//cout << "Case " << i << ":\n";
		solve();
	}
	
	return 0;
}