#include"bits/stdc++.h"
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int main(){
    FAST_IO;
    int n,cnt=0,cnt1=0;cin>>n;
    int arr[2*n];
    for(int i=0;i<2*n;i++) cin>>arr[i];
    for(int i=0;i<2*n;i++){
        if(arr[i%n]==1){
            cnt++;
            cnt1=max(cnt1,cnt);
        }
        else cnt=0;
    }
    cout<<cnt1<<endl;
    return 0;
}