#include<bits/stdc++.h>
#define x first
#define y second
#define PB push_back
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define rep(x,l,u) for(ll x=l;x<u;x++)
#define rrep(x,l,u) for(ll x=l;x>=u;x--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
typedef pair<char,char> PCC;
typedef long long ll;
const int N=2*1e5+10;
const int M=1e6+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
ll h[N],n,a,b,k;
void solve(){
    
    cin>>n>>a>>b>>k;
    rep(i,0,n){
    
        cin>>h[i];
        h[i]%=(a+b);
        if(h[i]==0) h[i]=a+b;
        h[i]=h[i]/a+(h[i]%a!=0)-1;
    }
    sort(h,h+n);
    int ans=0;
    rep(i,0,n){
    
        if(h[i]<=k){
    
            ans++;
            k-=h[i];
        }
    }
    cout<<ans<<endl;
}
int main(){
    
    IOS;
    //int t;cin>>t;
    //while(t--){
    
        solve();
    //}
    return 0;
}