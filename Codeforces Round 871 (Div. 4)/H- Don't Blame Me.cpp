#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define pb push_back
#define PII pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=(int)a,i##i=(int)b;i<=i##i;i++)
#define per(i,a,b) for(int i=(int)a,i##i=(int)b;i>=i##i;i--)
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f,mod=1e9+7;
const int N=2e5+5;
int a[N];
int dp[2][64];
int get(int x){
	int cnt=0;
	while(x) x-=x&-x,cnt++;
	return cnt;
}
int cnt[64];
void init(){
	for(int i=0;i<64;i++){
		cnt[i]=get(i);
	}
}
ll ksm(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1) res=res*a%mod;
		a=a*a%mod; n>>=1;  
	} return res;
}
void solve(){
	int n,k; cin>>n>>k;
	memset(dp,0,sizeof dp);
	rep(i,1,n) cin>>a[i];
	if(k==6){
		cout<<(ksm(2,count(a+1,a+1+n,63))-1+mod)%mod<<endl;
		return;
	}
	dp[0][63]=1;
	int lst=0,cur=1;
	rep(i,1,n){
		rep(j,0,63) dp[cur][j]=dp[lst][j];
		rep(j,0,63) (dp[cur][j&a[i]]+=dp[lst][j])%=mod;
		swap(lst,cur);
	}
	int ans=0;
	rep(i,0,63) if(cnt[i]==k) (ans+=dp[lst][i])%=mod;
	cout<<ans<<endl;
}
int main(){
    IOS; init();
    int T=1; cin>>T;
    while(T--) solve();
}