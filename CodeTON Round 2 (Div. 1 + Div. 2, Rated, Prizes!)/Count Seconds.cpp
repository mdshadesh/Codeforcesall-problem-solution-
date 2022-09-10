#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
bool qm[2009][2009];
long long buc[2009][2009];
int in[10009];
int out[10009];
int las;
struct node{
	int to;
	int next;
}e[10009];
int head[10009];
int idx;
void add(int a,int b){
	idx++;
	e[idx].to=b;
	e[idx].next=head[a];
	head[a]=idx;
}
queue <int> Q;
signed main(){
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=n+1;j++)
				buc[i][j]=0,qm[i][j]=0;
			in[i]=0;
			out[i]=0;
			head[i]=0;
		}
		idx=0;
		while(!Q.empty()) Q.pop();
		for(int i=1;i<=n;i++){
			cin >> buc[i][0];
		}
		for(int i=1;i<=m;i++){
			int u,v;
			cin >> u >> v;
			add(u,v);
			in[v]++;
			out[u]++;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==0)
				Q.push(i);
			if(out[i]==0)
				las=i;	
		}
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(int i=head[u];i;i=e[i].next){
				int v=e[i].to;
				for(int j=1;j<=n;j++){
					if(buc[u][j-1] || qm[u][j-1]){
						buc[v][j]+=buc[u][j-1];
						if(buc[v][j]>=mod || qm[u][j-1]){
							qm[v][j]=1;
							buc[v][j]%=mod;
						}
					}
				}
				in[v]--;
				if(in[v]==0)
					Q.push(v);
			}
		}
		long long ans=0;
		bool ansqm=0;
		for(int i=0;i<=n;i++){
			if(buc[las][i] || qm[las][i]){
				if(ansqm==0 && ans<i)
					ans=i;
				ans=ans+buc[las][i];
				if(ans>=mod || qm[las][i]){
					ans%=mod;
					ansqm=1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}