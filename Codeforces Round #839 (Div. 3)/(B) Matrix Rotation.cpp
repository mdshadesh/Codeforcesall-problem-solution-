#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
void solve()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
   for(int i=0; i<4 ;i++){
        if(a<b and c<d and a<c and b<d)
           {
            cout<<"YES"<<endl;
            return;
           }
          swap(a,b);
          swap(a,c);
          swap(c,d);
     }
       cout<<"NO"<<endl;
    return;
}
int32_t main()
{
    int32_t _=1;
    cin>>_;
    while(_--)
    {
       solve();
    }
    return 0;
}
