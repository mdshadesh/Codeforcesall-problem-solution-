#include <bits/stdc++.h>
#define ll long long
using namespace std;
void s(){
    ll n;
    cin>>n;
    vector <ll> a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    ll x,y,mn=INT_MAX;
    a.push_back(a[0]);
    for(ll i=0; i<a.size(); i++){
        if(mn>abs(a[i]-a[i+1])){
            x=i;
            y=i+1;
            mn=abs(a[i]-a[i+1]);
        }
    }
    if(y==a.size()-1){
        cout<<x+1<<" "<<1;
    }
    else cout<<x+1<<" "<<y+1;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m=1;
    while(m--){
        s();
    }
}
