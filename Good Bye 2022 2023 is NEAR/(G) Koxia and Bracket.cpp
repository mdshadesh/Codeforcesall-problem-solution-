#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,ggg=3,invggg=(mod+1)/ggg;
const int maxn=1048576;
int tmp[maxn],F[maxn],G[maxn];
int mypow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		y>>=1;x=1ll*x*x%mod;
	}return ret;
}
int revs[maxn];
void initrev(int Len){
	for(int i=1;i<Len;++i){
		revs[i]=revs[i>>1]>>1;
		if(i&1)revs[i]|=(Len>>1);
	}
}
void DFT(int *f,int n,int rev){
	int g0=rev==1?ggg:invggg;
	initrev(n);
	for(register int i=0;i<n;++i)
		if(i<revs[i])
			f[i]^=f[revs[i]]^=f[i]^=f[revs[i]];
	for(register int h=2;h<=n;h<<=1){
		int gn=mypow(g0,(mod-1)/h);
		for(register int j=0;j<n;j+=h){
			int gk=1;
			for(register int k=j;k<j+(h>>1);++k){
				int e=f[k],o=1ll*gk*f[k+(h>>1)]%mod;
				f[k]=(e+o)%mod,f[k+(h>>1)]=(e+mod-o)%mod;
				gk=1ll*gk*gn%mod;
			}
		}
	}
	if(rev==-1){
		int invv=mypow(n,mod-2);
		for(register int i=0;i<n;++i)
			f[i]=1ll*f[i]*invv%mod; 
	}
}
vector<int>mul(vector<int>a,vector<int>b){
	int N=1;
	while(a.size()+b.size()-1>N)N*=2;
	memset(F,0,N<<2);
	memset(G,0,N<<2);
	for(int i=0;i<a.size();i++)F[i]=a[i];
	for(int i=0;i<b.size();i++)G[i]=b[i];
	DFT(F,N,1);DFT(G,N,1);
	for(int i=0;i<N;i++)F[i]=1ll*F[i]*G[i]%mod;
	DFT(F,N,-1);
	vector<int>c;
	for(int i=0;i<a.size()+b.size()-1;i++)
		c.push_back(F[i]);
	return c;
}
int n;
string s;
int sum[500003],fac[1000003],inv[1000003];
vector<int>t;
vector<int>solve(int l,int r,vector<int>w){
	if(!w.size())return w;
	if(l==r){
		w=mul(w,{1,1});
		vector<int>tmp;
		if(t[l]==1){
			for(int i=1;i<w.size();i++)
				tmp.push_back(w[i]);
			w=tmp;
		}
		return w;
	}
	int cnt=0;
	for(int i=l;i<=r;i++)
		cnt+=t[i];
	cnt=min(cnt,int(w.size()));
	vector<int>t1,t2,t3;
	for(int i=0;i<w.size();i++)
		if(i<cnt)
			t1.push_back(w[i]);
		else
			t2.push_back(w[i]);
	for(int i=0;i<=r-l+1;i++)
		t3.push_back(1ll*fac[r-l+1]*inv[i]%mod*inv[r-l+1-i]%mod);
	t2=mul(t2,t3);
	t1=solve(l+r+2>>1,r,solve(l,l+r>>1,t1));
	for(int i=0;i<t1.size();i++)
		if(i>=t2.size())
			t2.push_back(t1[i]);
		else
			t2[i]=(t2[i]+t1[i])%mod;
	return t2;
}
int calc(string s){
	if(s=="")return 1;
	int cnt=0;t.clear();
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')cnt++;
		else{
			cnt--;
			t.push_back(cnt<0);
			if(cnt<0)cnt++;
		}
	return solve(0,t.size()-1,{1})[0]; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	fac[0]=1;
	for(int i=1;i<1000003;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[1000002]=mypow(fac[1000002],mod-2);
	for(int i=1000001;i>=0;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	cin>>s;n=s.size();
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i];
		if(s[i]=='(')sum[i+1]++;
		else sum[i+1]--;
	}int p=0;
	for(int i=1;i<=n;i++)
		if(sum[i]<sum[p])
			p=i;
	string l=s.substr(0,p),r=s.substr(p,n-p);
	reverse(r.begin(),r.end());
	for(int i=0;i<r.size();i++)
		r[i]=')'-r[i]+'(';
	cout<<1ll*calc(l)*calc(r)%mod;
}