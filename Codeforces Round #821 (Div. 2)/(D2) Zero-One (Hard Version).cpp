#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() 
{
    cin.tie(0); ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--) {
        ll n, x, y;
        cin >> n >> x >> y;
 
        string S, T;
        cin >> S >> T;
 
        vector<int> s(n), t(n);
        for(int i = 0; i < n; i++) {
            s[i] = S[i] - '0';
            t[i] = T[i] - '0';
        }
 
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) v.push_back(i);
        }
 
        if((int)v.size() & 1) {
            cout << -1 << '\n';
            continue;
        }
 
        ll sz = v.size();
        if(x >= y) {
            if(sz > 2) {
                cout << y * sz / 2 << '\n';
            } else if(sz == 0) {
                cout << 0 << '\n';
            } else {
                if(v[0] == v[1] - 1) {
                    cout << min(y * 2, x) << '\n';
                } else {
                    cout << y << '\n';
                }
            }
        } else {
            vector<ll> dp(sz + 5); 
            dp[0] = dp[1] = 0;
            for(int i = 2; i <= sz; i++) {
                if(i & 1) {
                    dp[i] = min({dp[i - 1], dp[i - 2] + (v[i - 1] - v[i - 2]) * x, dp[i - 2] + y});
                } else{
                    dp[i] = min({dp[i - 2] + (v[i - 1] - v[i - 2]) * x, dp[i - 1] + y, dp[i - 2] + y});
                }
            }
            cout << dp[sz] << '\n';
        }
 
    }
}