#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 998244353
int n,m,ds[N],ps[N],fa[N][18];struct Node {int l,r;}a[N];
int qId(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
int qry(int l,int r)
{
	int t=qId(r);
	for(int i=17;i>=0;--i) if(ps[fa[t][i]]>=l) t=fa[t][i];
	if(ps[t]>=l) t=fa[t][0];return ps[t]!=l-2;
}
int main()
{
	scanf("%d %d",&n,&m);
        ds[++ds[0]]=1e9;
	for(int i=1,l,r;i<=n;++i)
	{
		scanf("%d %d",&l,&r);++l;
		ds[++ds[0]]=r-1;a[i]=(Node) {l,r};
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=ds[0];++i) 
        ps[i]=-1e9;
	for(int i=1,t;i<=n;++i) 
        t=qId(a[i].r),ps[t]=max(ps[t],a[i].l-2);
	for(int i=1;i<=ds[0];++i)
	{
		if(i>1) ps[i]=max(ps[i],ps[i-1]);fa[i][0]=qId(ps[i]);
		for(int j=1;j<=17;++j) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	for(int i=1,l,r,t;i<=m;++i)
	{
		scanf("%d %d",&l,&r);++l;t=qry(l,r)-qry(l,r-1);
		if(t<0) t+=MOD;printf("%d\n",t);
	}
    return 0;
}