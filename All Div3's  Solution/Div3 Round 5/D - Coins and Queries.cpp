#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
int main(){

    iostream::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;//
    t=1;

    while(t--){
   int n,m;cin>>n>>m;
   vector<ll>v(n);map<ll,ll>freq;
   for(int i=0;i<n;i++){
    cin>>v[i];
    freq[v[i]]++;
   }
   while(m--){
    int x;cin>>x;
    ll ans=0;
    for(int i=31;i>=0;i--){
            ll temp=0;
        ll g=powl(2,i);
    temp=min(freq[g],x/g);
    ans+=temp;
        x-=temp*g;
    }
    if(!x)
    cout<<ans<<"\n";
    else cout<<-1<<"\n";
   }
    }
return 0;
}
