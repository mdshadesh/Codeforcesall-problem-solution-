#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

void solve()
{
    int n;
    cin>>n;
    vector<ll>d1(n),d2(n);
    rep(i,n)cin>>d1[i];
    rep(i,n)cin>>d2[i];
    rep(i,n)rep(f,2)
    {
        ll l; //p2-p1
        if(f)l=d1[0]+d2[i];
        else l=abs(d1[0]-d2[i]);
        priority_queue<pair<ll,int>>pq;
        multiset<pair<ll,int>>se;
        rep(j,n)
        {
            pq.push(make_pair(d1[j],0));
            pq.push(make_pair(d2[j],1));
        }
        bool flag=true;
        vector<ll>h;
        while(pq.size())
        {
            auto[d,t]=pq.top();
            pq.pop();
            if(t==0)h.push_back(d);
            else h.push_back(l-d);
            if(h.size()>n)break;
            se.insert(make_pair(abs(d-l),1-t));
            while(pq.size()&&se.count(pq.top()))
            {
                se.erase(se.find(pq.top()));
                pq.pop();
            }
        }
        if(h.size()==n)
        {
            cout<<"YES"<<"\n";
            ll p1=0,p2=l;
            sort(h.begin(),h.end());
            if(h[0]<0)
            {
                p1-=h[0];
                p2-=h[0];
                rrep(i,n)h[i]-=h[0];
            }
            rep(i,n)cout<<h[i]<<" ";
            cout<<"\n";
            cout<<p1<<" "<<p2<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
}