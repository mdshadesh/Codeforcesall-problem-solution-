#include <bits/stdc++.h>
#define forn(i,l,k) for(ll i=l;i<=k;++i) 
#define di double 
#define ll long long
#define se second
#define fr first
#define N 100010
#define M 1000
#define MAX_N 1000000007
#define mod 1000000007
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
using namespace std;
ll n,k;
ll nr[N],nl[N];
ll qpow(ll x,ll y){
	ll res=1;
	while (y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res%mod;
}
void solve(){
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	k=min(n,k);nl[0]=nr[0]=1;
	forn(i,1,n){
		nr[i]=nr[i-1]*(n-i+1)%mod;
		nl[i]=nl[i-1]*i%mod;
	}ll ans=1;
	forn(i,1,k){ans=(ans+nr[i]*qpow(nl[i],mod-2))%mod;
	}cout<<ans;
	return 0;
}