#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
vector<pii>v;
ll H;
int ck(ll md)
{
    ll d=0;
    for(auto p:v)
    {
        ll x=p.ff;
        ll y=p.ss;
        ll ps=0;
        ps=x*md;
        d+=(ps/y);
        d++;
    }
    if(d==H) return 0;
    else if(d>H) return 2;
    else return 1;
}
int main()
{
    int n,k,i,j,x,y;
    cin>>n>>H;
    int c=0;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        if(!x)c++;
        v.push_back({x,y});
    }
 
    ll lo=1,hi=2e9;
    ll m;
 
    ll L=0;
    while(lo<=hi)
    {
        m=(lo+hi)/2;
        if(ck(m)==0)
        {
            L=m;
            hi=m-1;
        }
        else if(ck(m)==1)
        {
            lo=m+1;
        }
        else
        {
            hi=m-1;
        }
    }
    ll R=-1;
    lo=1,hi=2e9;
    while(lo<=hi)
    {
        m=(lo+hi)/2;
        if(ck(m)==0)
        {
            R=m;
            lo=m+1;
        }
        else if(ck(m)==1)
        {
            lo=m+1;
        }
        else
        {
            hi=m-1;
        }
    }
    if(c==n)cout<<-1<<endl;
    else cout<<R-L+1<<endl;
    return 0;
}