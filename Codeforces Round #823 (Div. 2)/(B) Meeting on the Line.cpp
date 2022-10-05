#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    int t; cin>>t;
    while (t--)
    {
        ll n; cin>>n;
        ll a[n] ,b[n], c[n], d[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        for(int i=0; i<n; i++)
        {
            c[i]=a[i]-b[i];
            d[i]=a[i]+b[i];
        }
        sort(c, c+n);
        sort(d, d+n);
        double ans, fi=c[0], la = d[n-1], sum;
        sum = fi+la;
        ans = sum/2;
        cout << fixed;  
        cout<<setprecision(1)<<ans<<"\n";
    }
    return 0;
}