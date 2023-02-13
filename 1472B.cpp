#include <bits/stdc++.h> 
 
#define pb push_back
#define ll long long 
  
using namespace std;

void solve(){
	int n;
	cin>>n;
	
	int one=0,two=0;
	
	int x;
	while(n--){
		cin>>x;
		
		if(x==1) one++;
		if(x==2) two++;
	}
	
	if(two%2==0){
		if(one%2==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	if(two%2==1){
		if(one<2) cout<<"NO\n";
		else{
			one-=2;
			cout<<(one%2==0 ? "YES\n":"NO\n");
		}
	}
	
}

int main(){
	int t;
	cin>>t;
	
	while(t--) solve();
	
	return 0;
} 
