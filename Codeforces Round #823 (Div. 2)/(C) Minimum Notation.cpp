#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1e5+10;
const int dx[] = {0,1,0,-1},dy[]={1,0,-1,0}; 
int a[N];
int t[N];
PII d[N];
void solve()
{
	string s;
	cin>>s;
	map<char,int> mp;
	int n = s.size()-1;
	char c = s[n];
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]>c)
		{
			if(s[i]<'9')mp[s[i]+1] ++ ;
			else mp[s[i]]++; 
		}
		else 
		{
			mp[s[i]]++;
			c = s[i];
		}
	}
	for(auto p : mp)
	{
		for(int i=1;i<=p.y;i++)cout<<p.x;
	}
	cout<<endl;
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while( t -- )
		
		solve();
	
	return 0; 
}