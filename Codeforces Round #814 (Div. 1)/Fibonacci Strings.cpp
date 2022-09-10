#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MXF = 50;
 
ll fib[MXF];
 
void prep() {
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i < MXF; i++)
        fib[i] = fib[i-1] + fib[i-2];
}
 
ll to_base(int x) {
    ll ans = 0;
    for(int i = MXF-1; i >= 0; i--) {
        if(x >= fib[i]) {
            x-= fib[i];
            ans ^= 1ll<<i;
        }
    }
    return ans;
}
 
bool solve() {
    int k;
    cin >> k;
    ll sm = 0;
    ll xr = 0;
    vector<ll> A, B;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ll a = to_base(x);
        ll b = to_base(x-1);
        A.push_back(a);
        B.push_back(b);
        sm += a;
        xr ^= a;
    }
    if(sm == 1)
        return true;
    for(int i = 0; i < k; i++) {
        for(int j = i+1; j < k; j++) {
            ll msk = sm - A[i] + B[i] - A[j] + B[j];
            if(msk == (xr ^ A[i] ^ B[i] ^ A[j] ^ B[j])) {
                if((msk & 1) == 0 && __builtin_popcountll(msk) + 1 == 64 - __builtin_clzll(msk))
                    return true;
            } 
        }
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    prep();
 
    int q;
    cin >> q;
    while(q--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}