#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ll n, w;
	cin >> n >> w;

	ll a[n];
	for(ll i=0;i<n;i++) cin >> a[i];

	ll b[n];
	for(ll i=0;i<w;i++) cin >> b[i];

	if(n < w){
		cout << "0\n";
		return 0;
	}

	if(w == 1){
		cout << n << '\n';
		return 0;
	}

	ll da[n-1];
	for(ll i=1;i<n;i++) da[i-1] = a[i] - a[i-1];

	ll db[w-1];
	for(ll i=1;i<w;i++) db[i-1] = b[i] - b[i-1];

	ll x = n-1 + w-1 + 1;

	ll c[x];
	c[w-1] = INT_MAX;
	
	for(ll i=0;i<w-1;i++) c[i] = db[i];
	for(ll i=w;i<x;i++) c[i] = da[i-w];

	ll kmp[x];
	kmp[0] = 0;

	for(int i=1;i<x;i++){
		int len = kmp[i-1];
		while(len > 0 && c[len] != c[i]) len = kmp[len-1];
		if(c[len] == c[i]) kmp[i] = len+1;
		else kmp[i] = 0;
	}

	int cnt = 0;
	for(int i=w;i<x;i++) if(kmp[i] == w-1) cnt++;

	cout << cnt << '\n';

	return 0;
}
     	           	 		  	  		