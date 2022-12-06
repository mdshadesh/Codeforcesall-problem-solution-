#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto reads()->vector<ll>{
    int t;
    cin>>t;
    vector<ll>v;
    while(t--){
        ll mp;
        cin>>mp;
        v.push_back(mp);
    }
    return v;
}

auto gcd(vector<ll>&v){
    ll res = v.front();
    for(auto it: v){
        res = __gcd(res, it);
    }
    return res;

}


void solve(){
    auto v = reads();
    cout << v.back()/gcd(v) << endl;

}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
