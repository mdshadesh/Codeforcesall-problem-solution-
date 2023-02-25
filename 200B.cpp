#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n,t,v=0;
    cin>>n;
    t=n;
    while(t--) 
	{
    	int x;
    	cin>>x;
    	v+=x;
	}
	cout<<fixed<<setprecision(4);
	cout<<(double)v/n;
}
