#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int t;

int main()
{
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<n/2+(n%2?1:0)<<endl;
	}
	return 0;
}
 						 					 		  	 	 	  			 	