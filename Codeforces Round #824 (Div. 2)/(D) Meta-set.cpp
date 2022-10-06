#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+10;
vector<int>a[maxn];
map<vector<int>,int>mp;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int t;
			cin>>t;
			a[i].push_back(t);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			vector<int>tt;
			for(int v=0;v<k;v++)
			{
				int t=(6-a[i][v]-a[j][v])%3;
				tt.push_back(t);
			}
			mp[tt]++;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int cnt=mp[a[i]];
		sum+=(cnt*(cnt-1)/2);
	}
	cout<<sum<<endl;
	return 0;
}