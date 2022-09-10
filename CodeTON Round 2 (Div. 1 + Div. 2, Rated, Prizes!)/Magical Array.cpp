#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int M=1e5+5;
 
vector<int>v[M];
int sum[M];
 
signed main() {
    IOS;
    int t;cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int mx=-1e18,mn=1e18;
        for(int i=1;i<=n;i++) {
            sum[i]=0;
            v[i].clear();
            for(int j=1;j<=m;j++) {
                int x;cin>>x;
                v[i].push_back(x);
                sum[i]+=v[i][j-1]*j;
            }
            mx=max(mx,sum[i]);
            mn=min(mn,sum[i]);
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
            if(sum[i]==mx)
                cout<<i<<' '<<mx-mn<<endl;
    }
    return 0;
}