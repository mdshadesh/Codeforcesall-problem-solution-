#include<bits/stdc++.h>
using namespace std;
#define ST freopen("/home/zz7/CFInput","r",stdin)
const int N=2e5+10;
vector<int>V[N];
int s[N];
int stk[N],cnt=0;
void dfs(int No,int par)
{
//	cerr<<No<<'\n';
	for(auto i:V[No]){
		if(i!=par)dfs(i,No);
	}
	stk[cnt++]=No;
	while(cnt>0){
		if(s[stk[cnt-1]]%2==0){
			cout<<stk[--cnt]<<'\n';
			for(auto i:V[stk[cnt]])s[i]++;
		}else break;
	}
}
int main()
{
//	ST;
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0)V[x].push_back(i+1),V[i+1].push_back(x),s[x]++,s[i+1]++;
	}if(n%2==1){
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			if(s[i]==1||s[i]==0){dfs(i,-1);break;}
		}
	}else cout<<"NO\n";
}