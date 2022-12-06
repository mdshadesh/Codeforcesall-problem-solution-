#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,m,T,ans,flg;
int cnt[maxn],del[maxn];
long long f[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cnt[i]=1;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%lld",&f[i][j]),f[j][i]=f[i][j];
	for(int t=1;t<n;t++){
		int mx=0;
		for(int i=1;i<=n;i++)
			if(del[i]==0&&f[i][i]>f[mx][mx])
				mx=i;
		int fa=0;
		del[mx]=1;
		for(int i=1;i<=n;i++)
			if(del[i]==0&&f[i][mx]>f[fa][mx])
				fa=i;
		int w=(f[mx][mx]-f[fa][mx])/(n-cnt[mx]);
		printf("%d %d %d\n",fa,mx,w),cnt[fa]+=cnt[mx];
	}
	return 0;
}
