#include<bits/stdc++.h>
using namespace std;
int a[45];
 
int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
		
   int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	a[i]=i;
	for(int i=1;i<=n;i++)
	{
		int kk=i;
		int f=0;
		for(int j=n;j>=1&&kk>0;j--,kk--)
		{
			 if(a[j]+kk>k) 
			{
				f=1;
				break;
			}
			else {
				a[j]+=kk;
			}
		}
		if(f==1) break;
	}
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	}
	return 0;
 } 