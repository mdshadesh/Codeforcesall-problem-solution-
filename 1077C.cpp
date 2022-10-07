#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=998244353;
const int N=2e5+5;

int a[N];
int cnt[30][30];

bool solve(){
    int n;cin>>n;
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=c-'a';
    }
    for(int j=1;j<=n;j++){
        char c;cin>>c;
        int c1=a[n-j+1], c2=c-'a';
        if(c1>c2) swap(c1,c2);
        cnt[c1][c2]++;
    }
    bool f=0;
    for(int i=0;i<26;i++){
        for(int j=i;j<26;j++){
            if(cnt[i][j]==0) continue;
            if(i==j){
                if(f && (cnt[i][j]&1)) return 0;
                if(cnt[i][j]&1) f=1;
                continue;
            }
            if(cnt[i][j]&1) return 0;
        }
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int _;cin>>_;
    for(int cas=1;cas<=_;cas++){
        cout<< (solve()?"YES":"NO") <<endl;
    }
    
    return 0;
}