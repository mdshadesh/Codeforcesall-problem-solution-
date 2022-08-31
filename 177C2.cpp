#include<bits/stdc++.h>
using namespace std; 

const int N=1e5+10;
typedef long long ll;
int n,k,m,a[N],b[N],x,y,da=0;
bitset<N>s;

int find(int x)
{
	if(x!=a[x]) 
        a[x]=find(a[x]);
	return a[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
        a[i]=i;
	cin>>k;
	for(int i=1;i<=k;i++)
    {
		scanf("%d%d",&x,&y);
		a[find(x)]=find(y);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
    {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)) 
           s[find(x)]=1;
	}
	for(int i=1;i<=n;i++) 
         b[find(i)]++;
	for(int i=1;i<=n;i++)
    {
		if(a[i]==i&&!s[i]){
			da=max(da,b[i]);
		}
	}
	cout<<da<<endl;
	return 0;
}