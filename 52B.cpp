#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x[1005],y[1005]; 
char mp[1005][1005];
signed main() {
    cin>>n>>m;
    for (long long i=1;i<=n;i++) 
    	for (long long j=1;j<=m;j++) {
        	cin>>mp[i][j]; 
            if (mp[i][j]=='*') {
            	x[i]++; 
                y[j]++; 
            }
        }
    for (long long i=1;i<=n;i++) 
    	for (long long j=1;j<=m;j++)
        	if (mp[i][j]=='*') 
            	ans+=(x[i]-1)*(y[j]-1);
    cout<<ans<<endl;
    return 0;
}
