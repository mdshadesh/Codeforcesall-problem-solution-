#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n,x,y; cin>>n>>x>>y;
    if((x+y)>0 && (x==0 || y==0) && ((n-1)%(x+y))==0)
    {
        int s = 1;
        while (s<=n)
        {
            for(int i=0;i<(x+y);i++) 
                cout<<s<<" ";
            s += (x+y) + (s==1);
        }
        cout<<endl;
    }else cout<<-1<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t{1};
    cin>>t;
    while (t--) 
       solve();
    return 0;
}