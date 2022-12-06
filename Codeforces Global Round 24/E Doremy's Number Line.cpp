#include <iostream>
#include <algorithm>
using namespace std;
const int MX=2e5+5;
int n,s;
struct Goat{
    int x,y,id;
}A[MX];
bool cmp(Goat a,Goat b){
    return a.x<b.x;
}
int mx[MX];
int calc(int id){
    if(id==1) return A[id].x;
    int far=max(calc(id-1),mx[id-2]);
    return max(min(far,A[id].x)+A[id].y,A[id].x);
}
int ans[MX];
void solve(){
    cin>>n>>s;
    for(int i=1,x,y;i<=n;++i){
        cin>>x>>y;
        A[i]=(Goat){x,y,i};
        ans[i]=false;
    }
    sort(A+1,A+1+n,cmp);
    for(int i=1;i<=n;++i)
        mx[i]=max(A[i].x+A[i].y ,mx[i-1]);
    for(int i=1;i<n;++i)
        if(A[i].x+A[i].y>=s)
            ans[A[i].id]=true;
    if(calc(n)>=s) ans[A[n].id]=true;
    cout<<(ans[1]?"YES\n":"NO\n");
}
int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
