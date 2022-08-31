#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,count=0;
    cin>>n;
    if(n==1)
    {
    	int f;
    	cin>>f;
    	cout<<f;
    }
    else
    {
    	int k=n/2;
    int a[n][n];
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		cin>>a[i][j];
    	}
    }
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(i==j)
    		{
    			count=count+a[i][j];
    		}
    		if(i+j==n-1)
    		{
    			count=count+a[i][j];
    		}
    		if(i==k)
    		{
    			count=count+a[i][j];
    		}
    		if(j==k)
    		{
    			count=count+a[i][j];
    		}
    		
    	}
    }
    count=count-3*a[k][k];
    cout<<count;
    }
    return 0;
}