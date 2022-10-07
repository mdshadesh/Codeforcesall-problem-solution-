#include<bits/stdc++.h>
using namespace std;
int main()
{
	int b,g,n;
	cin>>b;
	cin>>g;
	cin>>n;
	int y=min(min(b,g),n);
	cout<<min(y,b+g-n)+1<<endl;
	return 0;
}