#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	if (n&1)
	{
		int lw=1,hg=n;
		while (lw<hg)
		{
			int md=(lw+hg)/2;
			int a,b;
			cout<<"? "<<1<<" "<<md<<" "<<2<<"\n";
			cin>>a;
			cout<<"? "<<md+1<<" "<<n<<" "<<2<<"\n";
			cin>>b;
			int fra=a-(md-a);
			int frb=b-(n-md-b);
			assert(fra!=frb);
			if (fra>frb)
			{
				hg=md;
			}
			else lw=md+1;
		}
		cout<<"! "<<lw<<"\n";
	}
	else 
	{
		int lw=1,hg=n;
		pair <int,int> pe={0,0};
		while (lw<hg)
		{
			int md=(lw+hg)/2;
			int a,b;
			cout<<"? "<<1<<" "<<md<<" "<<2<<"\n";
			cin>>a;
			cout<<"? "<<md+1<<" "<<n<<" "<<2<<"\n";
			cin>>b;
			int fra=a-(md-a);
			int frb=b-(n-md-b);
			if (1<=pe.first && pe.second<=md)fra--;
			else if(md+1<=pe.first && pe.second<=n)frb--;
			if (fra>frb)
			{
				hg=md;
			}
			else if(fra<frb)lw=md+1;
			else
			{
			    int ge;
			    if (1!=md){cout<<"? "<<1<<" "<<md<<" "<<n<<"\n";cin>>ge;ge--;}
			    else {cout<<"? "<<md+1<<" "<<n<<" "<<n<<"\n";cin>>ge;(ge==2)?ge=0:ge=1;}
			    if (ge){pe={1,md};lw=md+1;}
			    else {pe={md+1,n};hg=md;}
			}
		}
		cout<<"! "<<lw<<"\n";
	}
	return 0;
}