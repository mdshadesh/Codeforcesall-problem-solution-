#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<stack>

using namespace std;

int n,a[500005],pos[1000005],lmin[500005],lmax[500005];
int rmin[500005],rmax[500005];
vector<int> divid[1000005],b[1000005];

int main()
{
	for(int i=1;i<=1000000;i++)
		for(int j=i+i;j<=1000000;j+=i)
			divid[j].push_back(i);
	memset(pos,0,sizeof(pos));
	int T;cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			b[a[i]].push_back(i);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int j=i;
			while((j<=n)&&(a[j+1]==a[j])) j++;
			ans+=1ll*(j-i+2)*(j-i+1)/2;
			i=j;
		}
		stack<int> st;
		for(int i=1;i<=n;i++)
		{
			while((!st.empty())&&(a[st.top()]>=a[i])) st.pop();
			lmin[i]=(st.empty())?1:(st.top()+1);
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++)
		{
			while((!st.empty())&&(a[st.top()]<=a[i])) st.pop();
			lmax[i]=(st.empty())?1:(st.top()+1);
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=n;i>=1;i--)
		{
			while((!st.empty())&&(a[st.top()]>=a[i])) st.pop();
			rmin[i]=(st.empty())?n:(st.top()-1);
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=n;i>=1;i--)
		{
			while((!st.empty())&&(a[st.top()]<a[i])) st.pop();
			rmax[i]=(st.empty())?n:(st.top()-1);
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<divid[a[i]].size();j++)
			{
				int tt=divid[a[i]][j];
				int yu=(pos[tt]>0)?b[tt][pos[tt]-1]:(-1);
				int p=0;
				if((yu>0)&&(rmin[yu]>=i)&&(lmax[i]<=yu))
				{
					ans+=1ll*(yu-max(lmin[yu],lmax[i])+1)*(min(rmax[i],rmin[yu])-i+1);
					p=yu+1;
				}
				if(pos[tt]<b[tt].size()) yu=b[tt][pos[tt]];else yu=-1;
				if((yu>0)&&(lmin[yu]<=i)&&(rmax[i]>=yu))
				{
					ans+=1ll*(i-max(p,max(lmin[yu],lmax[i]))+1)*(min(rmax[i],rmin[yu])-yu+1);
				}
			}
			pos[a[i]]++;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) 
		{
			b[a[i]].clear();
			pos[a[i]]--;
		}
	}
	return 0;
}