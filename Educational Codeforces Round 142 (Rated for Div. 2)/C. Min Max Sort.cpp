#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int p[n+1];
        int k[n+1];
        for(int i=0;i<n;i++){
            cin>>a[i];
            p[a[i]]=i;
        }
        k[n]=1;
        for(int i=n-1;i>=1;i--){
            if(p[i]<p[i+1]){
                k[i]=k[i+1]+1;
            }else{
                k[i]=1;
            }
        }
        int res=n;
        for(int i=1;i<=n;i++){
            res=min(res,max(i-1, n-(i+k[i]-1)));
        }
        cout<<res<<endl;
    }
}