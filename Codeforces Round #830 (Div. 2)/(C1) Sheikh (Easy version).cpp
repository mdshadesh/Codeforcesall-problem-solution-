#include<bits/stdc++.h>
using namespace std;
int T,n,q,L,R,ansl=1,ansr=1;
long long ans=0;
int s[100005];
long long sum[100005];
int xr[100005];
int las[100005];
long long update(int l,int r){
	long long rans=sum[r]-sum[l-1]-(xr[r]^xr[l-1]);
	if(rans>ans) {
		ans=rans;
		ansr=r;
		ansl=l;
	}
	else if(rans==ans && (ansr-ansl)>(r-l)){
		ans=rans;
		ansr=r;
		ansl=l;	
	}
	return rans;
}


int main(){
	cin>>T;
while(T--){
	cin>>n>>q;
	ans=0;ansl=1;ansr=1;
	int tmp=0;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		las[i]=tmp;
		if(s[i]>0) tmp=i;
	}
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i],xr[i]=xr[i-1]^s[i];
	cin>>L>>R;
	for(int i=L;i<=R;i++){
		int rr=R,dq=R;
		long long lans=update(i,rr);
		while(1){
			dq=las[dq];
			if(dq<i) break;
	
			long long tmpans=update(i,dq);
			if(tmpans<lans) break;
			lans=tmpans;
		}
	}
	cout<<ansl<<" "<<ansr<<"\n";
}
	return 0;
} 