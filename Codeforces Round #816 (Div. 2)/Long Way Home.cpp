#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const long long inf = 1e18;
const long long inf1 = 1e15;
 struct CHT{
    struct line{
        long long k,b;
        line(){}
        line(long long k,long long b):k(k), b(b){}
        double intersect(line l) {
            double db=l.b-b;
            double dk=k-l.k;
            return db/dk;
        }
        long long operator ()(long long x){
            return k*x+b;
        }
    };
    vector<double> x;
    vector<line> ll;
    void init(line l){
        x.push_back(-inf);
        ll.push_back(l);
    }
    void addLine(line l){
        while(ll.size()>=2&&l.intersect(ll[ll.size()-2])<=x.back()){
            x.pop_back();
            ll.pop_back();
        }
        if(!ll.empty())
            x.push_back(l.intersect(ll.back()));
        ll.push_back(l);
    }
    long long query(long long qx){
        long long id=upper_bound(x.begin(),x.end(),qx)-x.begin();
        --id;
        return ll[id](qx);
    }
};
void dijkstra(vector<vector<pair<long long,long long>>> &g,vector<long long> &dist){
    const long long n=g.size();
    vector<bool> used(n,false);
    priority_queue<pair<long long,long long>> q;
    for(long long i=0;i<n;++i)
        q.push({-dist[i],i});
    while(!q.empty()){
        long long v=q.top().second;
        q.pop();
        if(used[v])
            continue;
        used[v]=true;
        for(auto [u,w]:g[v]){
            if(dist[u]>dist[v]+w){
                dist[u]=dist[v]+w;
                q.push({-dist[u],u});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<long long,long long>>> g(n);
    for(long long i=0;i<m;++i){
        long long u,v,w;
        cin>>u>>v>>w;
        --u;
        --v;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<long long> dist(n,inf1);
    dist[0]=0;
    dijkstra(g,dist);
    for(long long i=0;i<k;++i){
        CHT cht;
        cht.init(CHT::line(0,0));
        for(long long i=1;i<n;++i)
            cht.addLine(CHT::line(-i*2,dist[i]+i*i));
        for(long long i=0;i<n;++i)
            dist[i]=cht.query(i)+i*i;
        dijkstra(g,dist);
    }
    for(long long i:dist)
        cout<<i<<' ';
}
