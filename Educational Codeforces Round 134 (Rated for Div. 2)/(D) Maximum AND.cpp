#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
using ll = long long;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)
#define repback(i, n) for (ll i = n-1; i >= 0; i--)
 
 
int main(){
    int t; cin >> t;
 
    while(t--){
        int n; cin >> n;
        vector<ll> A(n), B(n);
        rep(i,n) cin >> A[i];
        rep(i,n) cin >> B[i];
 
        ll ans = 0;
        repback(i,31){
            ans += 1 << i;
            map<ll, int> cnt;
            rep(j,n){
                cnt[A[j] & ans]++;
                cnt[~B[j] & ans]--;
            }
            bool able = true;
            for(auto it : cnt) able = able & (it.second == 0);
            if(!able) ans -= 1 << i;
        }        
 
        cout << ans << endl;
        
    }
}