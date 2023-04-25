#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void dbg_out() { cerr << endl; }

template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

signed main(){
	fastio;
	int tt; cin>>tt;
	while(tt--){
		int n; cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		sort(a.begin(), a.end());
		cout<<max(a[0]*a[1], a[n-1]*a[n-2])<<endl;
	}
	return 0;
}

