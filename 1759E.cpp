#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200008],b[3];
int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,m,x,y,z,sum=0;
		cin>>n>>m;
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]); 
		sort(a+1,a+n+1);
		b[0]=b[1]=b[2]=m;
		for(ll j=0;j<3;j++){
			x=2;y=0;z=0;
			for(ll i=1;i<=n;i++){
				if(b[j]>a[i]) b[j]+=a[i]/2,z++;
				else{
					if(y==j) b[j]=b[j]*3;
					y++;
					if(b[j]>a[i]) b[j]+=a[i]/2,z++;
					else if(x&&b[j]*2>a[i]){
						x--;b[j]=b[j]*2+a[i]/2;z++;
					}
					else if(x==2&&b[j]*4>a[i]){
						x=0;b[j]=b[j]*4+a[i]/2;z++;
					}
					else break;
				}
			}
			sum=max(sum,z);
		}
		cout<<sum<<endl;
	}
	return 0;
}
 	  	    		 		  	  	 		 		 		 	