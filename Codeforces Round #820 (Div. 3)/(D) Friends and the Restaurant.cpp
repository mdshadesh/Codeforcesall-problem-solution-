#include<bits/stdc++.h>
using namespace  std;
using ll=long long;
const int maxn=200020;
ll x[maxn],y[maxn],v[maxn];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0,cntpo=0,pos;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>y[i];
        }
        for(int i=1;i<=n;i++)
        {
            v[i]=y[i]-x[i];
        }
        sort(v+1,v+1+n);
        for(int i=n;i>=1;i--)
        {
            if(v[i]>=0){
                pos=i;
                cntpo++;
            }
        }
        int l=pos-1,r=pos;
        while(l>=1 && r<=n)
        {
            while(r<=n && v[l]+v[r]<0)
            {
                r++;
            }
            if(r>n) {break;}
            cntpo--;
            l--;
            r++;
            ans++;
        }
        ans+=cntpo/2;
        cout<<ans<<endl;
    }
 
    return 0;
}