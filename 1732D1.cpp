#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    map<ll,ll> mp;
    map<ll,ll> lst;
    mp[0]=1;
    while(t--){
        char a; ll x; cin>>a>>x;
        if(a=='+'){
            mp[x]=1;
        }
        else{
            ll k = x;
            ll cur = lst[k];
            while(mp[cur]==1) cur+=k;
            lst[k]=cur;
            cout<<cur<<endl;
        }
    }
return 0;
}