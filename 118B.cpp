#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j < n; j++)
            cout << "  ";
        for (int num = 0; num < i; num++)
            cout << num << " ";
        for (int num = i; num >= 0; num--) {
            cout << num;
            if (num != 0)
                cout << " ";
        }
        cout << '\n';
 
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++)
            cout << "  ";
        for (int num = 0; num < i; num++)
            cout << num << " ";
        for (int num = i; num >= 0; num--) {
            cout << num;
            if (num != 0)
                cout << " ";
        }
        cout << '\n';
 
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
}