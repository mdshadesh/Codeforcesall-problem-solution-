#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, pair<int, int>> ppi;
const int M=1e9+7;

int main(){
int n;
cin>>n;
vector<ll>v(n);
ll maxi=LLONG_MIN,mini=LLONG_MAX;
for (int i = 0; i < n; i++)
{
    cin>>v[i];
    maxi=max(maxi,v[i]);
    mini=min(mini,v[i]);
}
map<ll,ll>mp;
for (int i = 0; i < n; i++)
{
    if(v[i]==maxi)
    mp[maxi]++;
    else if(v[i]==mini)
    mp[mini]++;
}
cout<<maxi-mini<<" ";
if(maxi==mini){
    cout<<(mp[maxi]*(mp[maxi]-1))/2<<endl;
}
else cout<<mp[maxi]*mp[mini]<<endl;


return 0;
}