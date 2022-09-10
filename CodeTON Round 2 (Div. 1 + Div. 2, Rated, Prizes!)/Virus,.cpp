#include<cstdio>
#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include <cctype>
#include <vector>
#include<queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long
const int N=5e5+5,maxN=1e5+10;
int a[N],b[N];
int n;
bool cmp(int a,int b)
{
    return a>b;
}
//int  marr[150][150];
inline void solve()
{
    int m;
 
    cin>>n>>m; 
 
    for (int i = 1; i <=m ; ++i) {
        cin>>a[i];
    }
    if (n==m)
    {
        cout<<n<<endl;
        return;
    }
    if (m==1)
    {
        cout<<2<<endl;
        return;
    }
    int cnt=0;
    sort(a+1,a+1+m);
    for (int i = 1; i <=m ; ++i) {
        if (i>1 && a[i]!=a[i-1]+1)
        {
            b[++cnt]=a[i]-a[i-1]-1;
        }
 
    }
    if (a[m]!=n || a[1]!=1)
    {
        b[++cnt]=a[1]-a[m]-1+n;
    }
    sort(b+1,b+1+cnt);
    if (b[cnt]<=2)
    {
        cout<<n-1<<endl;
        return;
    }
    int ans=0;
    if (b[cnt]>2)
    {
        ans+=b[cnt]-1;
    }
    int count=0;
    for (int i = cnt-1; i >=1 ; --i) {
        count++;
        if (b[i]==4*count+1) ans++;
        else if(b[i]>4*count+1)
        {
            ans+=b[i]-4*count-1;
        }
    }
    cout<<n-ans<<endl;
 
 
}
signed main(void) {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}