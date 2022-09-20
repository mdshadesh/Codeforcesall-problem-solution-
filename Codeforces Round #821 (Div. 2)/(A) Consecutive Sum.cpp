#include <bits/stdc++.h>
#define REDIRECT_INPUT (freopen("./input", "r", stdin))
#define ll long long
#define int128 __int128_t
 
using namespace std;
 
const int maxn = 2e5 + 100;
const int inf = 2e9;
 
int val[maxn];
int mx[maxn];
void solve(int testcase) {
    int n, k; cin >> n >> k;
    for (int i=0; i<k; i++) mx[i] = 0;
    for (int i=0; i<n; i++) {
        cin >> val[i];
        mx[i % k] = max(mx[i % k], val[i]);
    }
    ll sum = 0;
    for (int i=0; i<k; i++) {
        sum += mx[i];
    }
    cout << sum << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}