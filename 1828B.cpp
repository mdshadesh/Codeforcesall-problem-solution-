#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll d[n];
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            d[i]=abs(a[i]-i);
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            ans=__gcd(ans,d[i]);
        }
        cout<<ans<<endl;

    }
    return 0;
}
