#pragma GCC optimize(2)
#include<bits/stdc++.h>
using i64 = long long;
i64 f[55];

void solve() {
    int n;
    i64 x,y;
    std::cin>>n;
    std::cin>>x>>y;
    bool ok = true;
    for(int i=n;i>=1;i--){
    	i64 kk = f[i+1] - f[i];
    	y = std::min(y,f[i+1]-y+1);
    	if(y>kk){
    		ok = false;
    		break;
		}
		std::swap(x,y);
	}
    std::cout<<(ok?"YES":"NO")<<'\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	f[0] = f[1] = 1;
	for(int i=2;i<=50;i++){
		f[i] = f[i-1] + f[i-2];
	}
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
