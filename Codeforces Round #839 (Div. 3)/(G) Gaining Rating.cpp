#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define space <<' '<<
using namespace std;
 
int main(){
    fastio
    int t, n, ind;
    long long x, y, tmp, ans;
    vector<long long> a(2e5);
    for(cin >> t; t>0; t--){
        cin >> n >> x >> y;
        ans = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.begin()+n);
        ind = upper_bound(a.begin(), a.begin()+n, x)-a.begin();
        while(ind<n){
            if(x+ind>=y){
                cout << ans+(y-x) << '\n';
                n = 0;
                break;
            }
            if(x+ind>=a[ind]){
                ind++;
                continue;
            }
            if(ind<(n>>1)+1){
                cout << "-1\n";
                n = 0;
                break;
            }
            tmp = min(a[ind], y)-ind;
            tmp = (tmp-1-x)/((ind<<1)-n)+1;
            ans += n*tmp;
            x += tmp*((ind<<1)-n);
            //cout << ind space x space ans << '\n';
        }
        if(n) cout << ans+y-x << '\n';
    }
    return 0;
}