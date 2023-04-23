//k
#include <iostream> 
using namespace std; 
int main() 
{ 
	int t; 
	cin>>t; 
	while(t--) 
	{ 
		string s; 
		cin>>s; 
		int a=0,b=0;
		for(int i=1;i<s.size();i++) 
		{ 
			if(s[i]=='a'&&s[i-1]=='b')
				b++; 
			else 
				if(s[i]=='b'&&s[i-1]=='a') 
				a++;
		} 
		if(a==b) 
			cout<<s<<endl; 
		else if(a>b) 
			{ if(s[0]=='a') 
				s[0]='b'; 
				cout<<s<<endl; 
			} 
		else if(b>a) 
			{ 
				if(s[0]=='b') 
					s[0]='a'; 
					cout<<s<<endl; 
			} 
	} 
return 0; 
}
 			 		   					     	 				  			
