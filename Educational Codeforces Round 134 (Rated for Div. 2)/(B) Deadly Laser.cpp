#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll ;
   
void solve(){
 
  int n,m,x,y,d;
  cin>>n>>m>>x>>y>>d;
 
  int x1 = x - d;
  int x2 = x + d;
  int y1 = y - d;
  int y2 = y + d;
 
  if(x1<=1 and x2>=n || y1<=1 and y2>=m || x1<=1 and y1<=1 || x2>=n and y2>=m){
    cout<<-1<<endl;
  }else{
    cout<<abs(n+m-2)<<endl;
  }
    
}
int f = 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    if (f == 0) solve();
    else{
        int t;
        cin>>t;
        while(t--){
            solve();
        }
    }
}