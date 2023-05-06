#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;


void solve(){
    int n;
    cin>>n;
    map<string,int> m;
    vi a(n);
    vector<string> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
        m[b[i]] = INT_MAX;
    }
    
    for(int i=0;i<n;i++){
      
        m[b[i]] = min(m[b[i]],a[i]);
    }
    
    int t = m["11"];
    int x = m["10"];
    int y = m["01"];
 
    if(t==0){
        if(x==0 || y==0){
            cout<<-1<<endl;
            
        }
        else cout<<x+y<<endl;
    }
    else{
        if(x==0 || y==0){
            cout<<t<<endl;
        }
        else{
            int ans = min(t,x+y);
            cout<<ans<<endl;
        }
    }
    
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1,x=1;
	std::cin >> T;
	while(T--){
	  //  cout<<"Test Case #"<<x<<":"<<endl;x++;
	    solve();
	}
	return 0;
}
