#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,v;
	cin>>n;
	int cnt[5]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		cnt[v]++;
	}
	int ans=cnt[4]+cnt[3];

	if(cnt[3]<=cnt[1])
		cnt[1]-=cnt[3];
	else
		cnt[1]=0;

	ans+=cnt[2]/2;
	if(cnt[2]%2==1)
	{
		ans++;
	    cnt[1]=max(0,cnt[1]-2);
	}

	ans+=cnt[1]/4;
	if(cnt[1]%4!=0)
		ans++;
	cout<<ans;

}