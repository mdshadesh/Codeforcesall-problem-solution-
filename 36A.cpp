#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string s;
int a[110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k=0;
	cin>>n>>s;
	for(int i=0;i<n;i++)if(s[i]=='1')a[++k]=i;
	for(int i=3;i<=k;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}