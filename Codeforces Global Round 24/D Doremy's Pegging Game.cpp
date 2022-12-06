#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b,long long p){
	long long ans=1;
	while(b>0)
	{
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
long long tt[5001],intt[5001];
int main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,p,i,j,ans=0,cur;
	cin>>n>>p;
	tt[0]=1;
	for(i=1;i<=n;i++)tt[i]=tt[i-1]*i%p;
	for(i=0;i<=n;i++)intt[i]=qpow(tt[i],p-2,p);
	for(i=n/2-1;i<=n-3;i++)
	{
		cur=0;
		for(j=0;j<=n-i-3;j++)
		{
			cur+=tt[i+j]*tt[n-i-3]%p*intt[n-i-3-j]%p*intt[j]%p;
			cur%=p;
		}
		if(n%2==0)
		{
			ans+=(n-i-1)*cur%p;
			ans%=p;
		}
		else
		{
			ans+=(n-i-2)*cur%p;
			ans%=p;
		}
	}
	if(n%2==0)
	{
		ans+=tt[n-2];
		ans%=p;
	}
	cout<<ans*n%p<<'\n';
	return 0;
}