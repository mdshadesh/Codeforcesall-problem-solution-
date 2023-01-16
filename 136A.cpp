#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],i,temp;
    for(i=1;i<=n;i++){
     cin >> temp;
     a[temp]=i;
    }
    for(i=1;i<=n;i++){
        cout << a[i] << " ";
        }
        return 0;
}