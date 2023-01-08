#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define lowbit(x) (x)&(-x)
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
 
const int maxn=200100;
 
int a[maxn];
int dp[maxn];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    memset(dp,0x3f,sizeof(dp));
    int m=2;
    for(;m<=n+10;++m){
        a[m]=m*(m-1)/2;
        if(a[m]>n)break;
    }
    dp[0]=0;
    for(int i=2;i<=m;++i){
        for(int j=a[i];j<=n;++j){
            dp[j]=min(dp[j],dp[j-a[i]]+i);
        }
    }
    int ans=dp[n];
    cout<<ans<<' '<<ans*(ans-1)/2-n<<'\n';
    
 
    return 0;
}