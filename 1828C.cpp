#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e6+2;
const int mod=1e9+7;

int arr[maxn];
int brr[maxn];

signed main()
{
	int t;
	cin>>t;
	
  	while(t--)
  	{
    		int n;
    		cin>>n;
    		
    		for(int i=1;i<=n;i++)
    		{
    		  cin>>arr[i];
    		}
    		for(int i=1;i<=n;i++)
    		{
    		  cin>>brr[i];
    		}
    		sort(arr+1,arr+1+n);
    		sort(brr+1,brr+1+n);
    		
    		int a=1,b=1;
    		map<int,int>vis;
    		
    		while(b<=n&&a<=n)
    		{
    			if(brr[b]<arr[a])
    			{
    			  vis[b]=n-a+1,b++;
    			}
    			else
    			{
    			  a++;
    			}
    		}
    		int ans=1;
    		for(int i=n;i>=1;i--)
    		{
    		  ans=ans%mod*(vis[i]-n+i)%mod,ans%=mod;
    		}
    		cout<<ans<<endl;
  	}
}
