#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353,I=M+1>>1;
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
int n,k,f[300004];ll ans;
int u[300004],v[300004],s[300004];
vector<int>g[300004];int p[300004];
void dfs(int x){
	for(auto y:g[x])if(y!=p[x])
		p[y]=x,dfs(y),s[x]+=s[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0,x;i<k;i++)scanf("%d",&x),s[x]=1,f[x]=1;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
	}
	dfs(1);ll ans=0;
	for(int i=1;i<n;i++){
		if(p[u[i]]==v[i])swap(u[i],v[i]);
		int A=f[u[i]],B=f[v[i]],C=M+1-A,D=M+1-B;
		int X=(ll)s[v[i]]*(k-s[v[i]])%M;
		int Y=(ll)(s[v[i]]+1)*(k-s[v[i]]-1)%M;
		int Z=(ll)(s[v[i]]-1)*(k-s[v[i]]+1)%M;
		ans+=((ll)A*B+(ll)C*D+(ll)A*D%M*I+(ll)B*C%M*I)%M*X%M;
		ans+=(ll)A*D%M*I%M*Y%M,ans+=(ll)B*C%M*I%M*Z%M;
		f[u[i]]=f[v[i]]=((ll)A*B+(ll)A*D%M*I+(ll)B*C%M*I)%M;
	}
	ans=ans*2%M*myp(k,M-2)%M*myp(k-1,M-2)%M;
	cout<<ans;
}