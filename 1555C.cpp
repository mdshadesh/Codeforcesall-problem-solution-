#include<bits/stdc++.h>


#define ll long long
#define lli long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define test int t ; cin >> t ; while(t--)
#define rep(i,a,b) for (int i = a; i < b; i++)

const ll mod = 1e9 + 7;


using namespace std ;

void solve() {
    int n ;
    cin >> n ;
    vector<vector<int>> a(2, vector<int>(n)) ;
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> a[i][j] ;
        }
    }
    int sum1 = 0 ;
    int ans = 2e9 + 10 ;
    int sum2 = 0 ;
    for (int i = 0 ; i < n ; i++) {
        sum1 += a[0][i] ;
    }
    for (int i = 0 ; i < n ; i++) {
        sum1 -= a[0][i] ;
        ans = min(ans, max(sum1, sum2)) ;
        sum2 += a[1][i] ;
    }
    cout << ans << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif


    int t;
    cin >> t ;
    while (t--) {
        solve() ;
    };

    return 0 ;
}
