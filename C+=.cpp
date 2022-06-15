#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
const int maxn=1e5+5;
typedef long long ll;
ll a[maxn];
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,n,cnt=0;
		cin>>a>>b>>n;
		if(a<b)
		{
			c=a;a=b;b=c;
		}
		while(1)
		{
			if(cnt%2==0) 
		     	b+=a,c=b;
			else 
			  a+=b,c=a;
			  cnt++;
			if(c>n)
		     	break;
		}
		printf("%d\n",cnt);
	}
		return 0;
}
