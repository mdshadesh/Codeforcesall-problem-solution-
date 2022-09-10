#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
		int n;
		cin>>n;
		int a[n];
		int k=1;
		while(k<=n)
        {
			k=k*2;
		}
		if(n%2==0)
        {
		for(int i=0;i<n;i++)
        {
			a[i]=i;
		}
		if(n%4!=0)
        {
			a[n-1]=a[n-1]+k-1;
			a[n-3]=a[n-3]+k;
		}
		}
		else{
			if(n%4==1)
            {
			for(int i=0;i<n;i++)
            {
				if(i%2==0)
                {
					a[i]=i;
				}
				else{
					a[i]=i+2;
				}
			}}
			else{
				for(int i=0;i<n;i++)
                {
					a[i]=i+1;
				}
			}
		}
		
		for(int i=0;i<n;i++)
        {
			cout<<a[i]<<" ";
        }
		cout<<endl;
	}
	return 0;
}