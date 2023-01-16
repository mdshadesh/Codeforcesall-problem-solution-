#include<bits/stdc++.h>
using namespace std;
 void solve(){
 int n,p,l,m,c=0,i,sum=0;
 cin>>n;
 cin>>m;
 int a[n+10];
 for(i=0;i<n;i++){
    cin>>a[i];
 }
 sort(a,a+n,greater<int>());
 for(i=0;i<n;i++){
        m-=a[i];
        c++;
    if(m<=0){
        break;
    }

 }
 cout<<c<<endl;
 }
int main()
{
     solve();
}
