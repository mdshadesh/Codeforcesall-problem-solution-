#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
	    int n;
	    cin>>n;
	    map<string,int>m;
	    map<int,vector<string>>um;
	    for(int i=0;i<3;i++)
        {
	        for(int j=0;j<n;j++)
            {
	            string s;
	            cin>>s;
	            um[i].push_back(s);
	            m[s]++;
	        }
	    }
	    for(int i=0;i<3;i++)
        {
	        int score=0;
	        for(auto x:um[i])
            {
	            if(m[x]==1) score+=3;
	            if(m[x]==2) score+=1;
	        }
	        cout<<score<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}