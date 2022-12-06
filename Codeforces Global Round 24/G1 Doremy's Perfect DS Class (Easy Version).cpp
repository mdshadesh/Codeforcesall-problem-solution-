#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int qry(int l,int r,int k){
	cout<<"?"<<" "<<l<<" "<<r<<" "<<k<<endl;
	int t;cin>>t;
	return t;
}
void solve(){
	int n;cin>>n;
	int pn;
	if(n%2==0){
		int l=1,r=n;
		while(r>l+1){
			int mid=(l+r)>>1;
			if(qry(l,mid,n)==2) r=mid;
			else l=mid+1;
		}
		if(l==1) pn=qry(r,n,n)==2?r:l;
		else pn=qry(1,l,n)==2?l:r;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		int a=qry(1,mid,2),b=qry(mid+1,n,2);
		a-=mid-a;b-=n-mid-b;
		if(pn){
			if(pn<=mid) a--;
			else b--;
		}
		if(a>b) r=mid;
		else l=mid+1;
	}
	cout<<"!"<<" "<<l<<endl;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}