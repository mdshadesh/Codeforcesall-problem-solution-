#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    long long n,k,b,s;
    cin>>n>>k>>b>>s;
    if(k*b>s) {
        cout<<-1;
        return;
    }
    if(n==0) {
        cout<<-1;
        return;
    }
    vector<long long> res(n,0);
    long long x = k*b + k-1;
    if(x>s) {
        res[0] = s;
    }
    else{
        res[0] = x;
        if(k==1){
            if(x!=s) cout<<-1;
            else{
                for(auto x:res){
        cout<<x<<" ";
    }
            }
            return;
        }
        long long y = (s-x)/(k-1);
        long long z = (s-x)%(k-1);
        
        if((z==0 && y>=n) || (z>0 && (y+1)>=n)){
            cout<< -1;
            return;
        } 
        for(int i=1;i<=y;i++){
            res[i] = k-1;
        }
        if(z>0) res[y+1] = z;
    }
    for(auto x:res){
        cout<<x<<" ";
    }
}
int main()
{   
   
   long long t;
   cin>>t;
   while(t--){
      solve();
      cout<<"\n";
   }
   
}