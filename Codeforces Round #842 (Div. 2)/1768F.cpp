#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
typedef long long ll;
ll a[N],f[N];
int main(){
	int n;scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	f[1]=0;
	for(int i=1;i<=n;i++){
		int dis=n/a[i]+1;
		for(int j=i-1;j>=max(1,i-dis);j--){
			f[i]=min(f[i],f[j]+a[i]*(i-j)*(i-j));
			if(a[j]<=a[i]) break;
		}
		for(int j=i+1;j<=min(n,i+dis);j++){
			f[j]=min(f[j],f[i]+a[i]*(i-j)*(i-j));
			if(a[j]<=a[i]) break;
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",f[i]);
	return 0;
}