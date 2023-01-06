#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mod;
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int jc[3000010],invjc[3000010];
int C(int n,int m)
{
	if(n<m || n<0 || m<0) return 0;
	return jc[n]*invjc[n-m]%mod*invjc[m]%mod;
}
signed main()
{
	cin>>n>>mod;
	jc[0]=invjc[0]=1; for(int i=1; i<=3*n; ++i) jc[i]=jc[i-1]*i%mod,invjc[i]=qpow(jc[i],mod-2);
	int cnt1=0,cnt2=0,cnt3=0;
	cnt1=(jc[2*n]+jc[2*n]-jc[n]-1+mod)%mod; 
	cnt2=2*(C(2*n,n)*jc[n]%mod*jc[2*n]%mod);
	int qc=0;
	for(int i=0; i<=n; ++i) qc=(qc+C(n,i)*C(n,i)%mod*C(n+i,i))%mod;
	qc=qc*jc[n]%mod*jc[n]%mod*jc[n]%mod;
	cnt2=(cnt2-qc-1-cnt1+2*mod)%mod;
	cnt3=(jc[3*n]-1-cnt1-cnt2+3*mod)%mod;
	cout<<(cnt1+cnt2*2+cnt3*3)%mod;
	return 0;
}