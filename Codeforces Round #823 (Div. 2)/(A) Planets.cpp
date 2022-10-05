#include<bits/stdc++.h>  
#include<iostream>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define PI acos(-1.0)
#define E 1e-6
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int dir[8][2] = { {-1,0},{0,-1},{1,0},{0,1} ,{-1,-1},{-1,1},{1,-1},{1,1}};
int a[105];	
int b[105];
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
		int n,c;
		scanf("%d %d",&n,&c);
		for(int i=0;i<=100;++i)
        {
			b[i]=0;
		}
		for(int i=1;i<=n;++i)
        {
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		int ans=0;
		for(int i=1;i<=100;++i)
        {
			if(b[i]>c)
            {
				ans+=c;
			}
			else ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
	 			  	 		 		   	  	    		 	