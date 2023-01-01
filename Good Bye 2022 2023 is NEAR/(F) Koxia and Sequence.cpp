#include<bits/stdc++.h>
using namespace std;
long long n,x,y,ans;
int main(){
	scanf("%lld%lld%lld",&n,&x,&y);
	if(n&1ll){
		for(long long i=0ll;i<=y;i++){
			if((y|i)==y){
				for(long long j=0ll;j<20ll;j++){
					if(i&(1ll<<j)){
						long long u=(n*i)-(1ll<<j);
						long long v=x-(1ll<<j);
						if(u>=0ll&&v>=0ll){
							if((u|v)==u)ans=(ans^(1ll<<j));
						}
					} 
				}
			}
		}
	}
	printf("%lld\n",ans);
}