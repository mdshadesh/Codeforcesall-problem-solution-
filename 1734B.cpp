#include <bits\stdc++.h>
using namespace std;
const int N =0;
int main(){
	int a;
	cin>>a;
	while(a--){
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cout<<(j == 0 || j == i)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}