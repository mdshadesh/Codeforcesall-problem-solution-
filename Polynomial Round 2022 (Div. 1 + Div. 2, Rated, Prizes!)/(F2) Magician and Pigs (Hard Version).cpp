#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=1000013,p=998244353,inf=1+1e9;
int op[N][2];
void solve(){
    int n;cin>>n;
    int s=0,m=0;ll r=0,db=1;
    for(int i=1;i<=n;i++){
        cin>>op[i][0];
        if(op[i][0]!=3)cin>>op[i][1];
        if(op[i][0]==2)s+=op[i][1],s=min(s,inf);
        if(op[i][0]==3){
            if(s<inf)op[i][1]=s,s=min(inf,s+s);
            else op[i][0]=0;
        }
    }
    vector<int>c;
    for(int _=n;_;_--){
        int o=op[_][0],v=op[_][1];
        if(o==1){
            int rem=max(0ll,v-m);
            if(rem>0){
                int nw=0;
                for(auto x:c){
                    nw*=2;
                    if(rem>x)rem-=x,nw++;
                }
                (r+=(ll)(nw+1)*db%p)%=p;
            }
        }
        if(o==2)m+=v;
        if(o==3){
            if(!v)(db+=db)%=p;
            else c.push_back(v);
        }
    }
    cout<<r<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);
    int T=1;//cin>>T;
    while(T--)solve();
}