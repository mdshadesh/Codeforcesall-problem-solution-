#include <bits/stdc++.h>
 
using namespace std;
const int c=1000005;
long long n, m, ans, db[c];
int main()
{
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=n; i>=1; i--) {
            long long s=n/i;
            db[i]=s*(s-1)/2;
            for (int j=2*i; j<=n; j+=i) {
                db[i]-=db[j];
            }
        }
        ans=m;
 
        for (int i=n; i>=2; i--) {
            long long lep=min(m, db[i])/(i-1);
            ans+=lep, m-=lep*(i-1);
        }
        if (m) {
            ans=-1;
        }
        cout << ans << "\n";
    }
    return 0;
}