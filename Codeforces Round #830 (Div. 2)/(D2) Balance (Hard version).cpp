#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define lowbit(x) (x&(-x))
#define pb emplace_back
#define pr pair<int,int>
#define let const auto
const int N=2e5+5;
int read(){
	int x=0,f=1; char c=getchar();
	while(('0'>c||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=0,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?x:-x;
}
map <ll,int> pos;
set <ll> q;
map <ll,set<ll> > f;
map <ll,vector<ll> > t;
int n;
set <ll> p;
int main(){
	n=read();
	while(n--){
		char c; ll x;
		scanf(" %c%lld",&c,&x);
		if(c=='+'){
			q.insert(x);
			if(t[x].size()<128) for(let &v:t[x]) f[v].erase(x);
			else p.erase(x);
		}
		else if(c=='-'){
			if(t[x].size()>=128) p.insert(x);
			else
				for(let &v:t[x])  f[v].insert(x);
			q.erase(x);
		}
		else{
			while(q.count(pos[x]*x+x)){
				ll val=pos[x]*x+x;
				t[val].pb(x); pos[x]++;
			}
			ll res=(f[x].size()?*f[x].begin():pos[x]*x+x);
			for(let &v:p) if(v%x==0) res=min(res,v);
			printf("%lld\n",res);
		}
	}
	return 0;
}
