#include<iostream>
using namespace std;
int n,t,r=90;
int bored[100];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>t;
		bored[t]=1;
	}
	t=0;
	for (int ans=1;ans<=90;ans++)
	{
		if (bored[ans]==0)
		{
			t++;
		}
		else
		{
			t=0;
		}
		if (t>=15)
		{
			r=ans;
			break;
		}
	}
	cout<<r;
	return 0;
}