#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
#define setBits(x) builtin_popcount(x)
const ll N=1e9+1;
const ll  M=1e5+1;



int main() {
   
    int n,k;
    cin>>n>>k;
    
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    ll ans[k];
    for(int i=0;i<k;i++){
        ans[i]=arr[n-1-i];
    }
    cout<<ans[k-1]<<endl;
    
    return 0 ;
    
}