#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	 {
	      int x,y;
	      cin>>x>>y;
	      if(x<y)
	      cout<<"first"<<endl;
	      else if(x==y)
	      cout<<"any"<<endl;
	      else
	      cout<<"Second"<<endl;
	 }
	return 0;
}
