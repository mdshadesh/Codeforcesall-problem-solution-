#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
 
using namespace std;
 
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 1;
 
int a[N], b[N], t, dmi[N], dmx[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1, j = 1; i <= n; i++){
        while(a[i] > b[j] && j <= n) j++;
        dmi[i] = b[j] - a[i];
    }
    int j = 1;
    for(int i = 1; i <= n; i++){
        j = max(j, i);
        while(a[j+1] <= b[j] && j + 1 <= n) j++;
        dmx[i] = b[j] - a[i];
    }
    for(int i = 1; i <= n; i++) cout << dmi[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << dmx[i] << ' ';
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}