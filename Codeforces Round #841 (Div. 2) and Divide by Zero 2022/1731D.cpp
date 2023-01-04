#include <bits/stdc++.h>
 
using namespace std;
int w, n, m;
vector<vector<int> > t, pref;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        t.resize(n+1), pref.resize(n+1);
        for (int i=0; i<=n; i++) {
            t[i].resize(m+1), pref[i].resize(m+1);
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> t[i][j];
            }
        }
        int lo=1, hi=n+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            bool jo=0;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(t[i][j]>=mid);
                    if (i>=mid && j>=mid && pref[i][j]+pref[i-mid][j-mid]-pref[i][j-mid]-pref[i-mid][j]==mid*mid) {
                        jo=1;
                    }
                }
            }
            if (jo) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        cout << lo << "\n";
    }
    return 0;
}