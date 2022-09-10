#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+2,0);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    long long rez=0;
    for(int i=1;i<=n;++i)
        rez+=(a[i]!=a[i+1])*(n-(i+1)+1)*i;
    while(m--){
        int i,x;
        cin>>i>>x;
        rez-=(a[i]!=a[i-1])*(n-i+1)*(i-1);
        rez-=(a[i+1]!=a[i])*(n-(i+1)+1)*i;
        a[i]=x;
        rez+=(a[i]!=a[i-1])*(n-i+1)*(i-1);
        rez+=(a[i+1]!=a[i])*(n-(i+1)+1)*i;
        cout<<rez+n*(n+1)/2<<'\n';
    }
}