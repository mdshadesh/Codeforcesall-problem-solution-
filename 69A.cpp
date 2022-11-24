#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,v[100],r=0;
    cin>>n;
    if(n==1){
        cin>>a>>b>>v[0];
        if(a!=0 || b!=0){
            cout<<"NO";
            return 0;
        }
        else{
            cout<<"YES";
            return 0;
        }
    }
    else for(int i=0;i<n;i++){
        cin>>a>>b>>v[i];
        r+=v[i];
    }
    if(r==0){
        cout<<"YES";
    }
    else cout<<"NO";
}