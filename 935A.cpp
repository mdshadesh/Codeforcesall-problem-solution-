#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define ll long long
 
int main()
{
    ll n; cin>>n;
    ll ans = 1;
    for(int i=2; i<n; i++)
    {
        if(n%i==0) ans++;
    }
    cout<<ans;
    return 0;
}