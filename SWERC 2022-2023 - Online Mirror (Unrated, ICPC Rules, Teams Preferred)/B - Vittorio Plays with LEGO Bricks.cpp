#include<bits/stdc++.h>
using namespace std;

const int N=310,inf=3e11+10;
int n,h,x[N],h1[N][N];
long long ans[N][N];

int ceiling(int xl,int xr)
{
    if((xr-xl)%2) return (xr-xl)/2+1;
    else return (xr-xl)/2;
}
long long f(int l,int r)
{
    if(ans[l][r]!=-1) return ans[l][r];
    long long minf=inf;
    for(int m=l;m<r;m++) minf=min(minf,f(l,m)+f(m+1,r));
    ans[l][r]=minf-h1[l][r];
    return ans[l][r];
}
int main()
{
    scanf("%d %d\n",&n,&h);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++) 
        ans[i][j]=-1;
    for(int i=1;i<=n;i++) ans[i][i]=h;
    for(int l=1;l<n;l++)
      for(int r=l+1;r<=n;r++)
        h1[l][r]=max(0,h+1-ceiling(x[l],x[r]));
    printf("%lld",f(1,n));
    return 0;
}