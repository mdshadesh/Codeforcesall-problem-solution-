#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1e18
#define pb push_back
#define intmax INT_MAX
#define intmin INT_MIN
#define f first
#define ss second
using namespace std;
#define endl '\n'  
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
cin>>n;
ll a[n-1];
for(ll i=0;i<n-1;i++)
cin>>a[i];
ll b[n]={0};
ll maxi=1;
b[0]=1;
set<ll> s;
for(ll i=1;i<=n;i++)s.insert(i);
for(ll i=0;i<n-1;i++)
{
    b[i+1]=b[i]+a[i];
    maxi=max(maxi,b[i+1]);
}   
for(ll i=0;i<n;i++)
{
    b[i]+=(n-maxi);
    s.erase(b[i]);
}
if(s.size()==0)
{
    for(ll i=0;i<n;i++)
    cout<<b[i]<<" ";
}
else cout<<-1<<endl;
return 0;
}