#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        if (a[0] == a[n - 1]) cout << n / 2 << endl;
        else{
            ll ans = 0;
            for (int i = 1; i < n; i++){
                if (a[i] != a[i - 1]) ans = max(ans, 1LL * i * (n - i));
            }
            cout << ans << endl;
        }
    }
	return 0;
}
