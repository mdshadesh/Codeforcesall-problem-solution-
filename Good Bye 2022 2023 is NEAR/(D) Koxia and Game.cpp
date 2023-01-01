#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+5),b(n+5);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		vector<vector<int>> G(n+5);
		vector<int> good(n+5),bad(n+5);
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			G[a[i]].push_back(b[i]);
			G[b[i]].push_back(a[i]);
			if(a[i]==b[i])bad[a[i]]=1;
		}
		vector<int> vis(n+5);
		int cv,ce,cb;
		function<void(int)> dfs=[&](int u)
		{
			vis[u]=1;
			cv++;
			if(bad[u])cb++;
			for(auto v:G[u])
			{
				ce++;
				if(not vis[v])
				{
					dfs(v);
				}
			}
		};
		for(int i=1;i<=n;i++)
		{
			cv=ce=cb=0;
			if(not vis[i])
			{
				dfs(i);
				if(ce==cv*2)
				{
					if(cb==0)ans=ans*2%MOD;
					else ans=ans*n%MOD;
				}
				else
				{
					ans=0;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}