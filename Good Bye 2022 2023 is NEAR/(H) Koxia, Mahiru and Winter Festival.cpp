#include <bits/stdc++.h>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define PB push_back
using namespace std;
 
struct Paths{
	/* store paths in order */
	vector<vector<pair<int, int>>> NS, EW;
	
	Paths(){
		NS.clear();
		EW.clear();
	}
};
 
Paths solve(vector<int> p, vector<int> q){
	int n = p.size();
	Paths Ret;
	Ret.NS.resize(n);
	Ret.EW.resize(n);
	
	// Base case
	if (n == 0) return Ret;
	if (n == 1){
		Ret.NS[0].PB({1, 1});
		Ret.EW[0].PB({1, 1});
		return Ret;
	}
 
	// Route NS flow originating from (1, 1) and (1, n) using leftmost and rightmost edges
	FOE(i,1,n){
		Ret.NS[0].PB({i, 1});
		Ret.NS[n-1].PB({i, n});
	}
	// Routing to final destination using bottom edges
	FOE(i,2,p[0]) Ret.NS[0].PB({n, i});
	FOD(i,n,p[n-1]) Ret.NS[n-1].PB({n, i});
 
	// Create p'[] for n-2 instance
	vector<int> p_new(0);
	FOE(i,1,n-2) p_new.PB(p[i] - (p[i]>p[0]) - (p[i]>p[n-1]));
 
	// Route EW flow originating from (1, 1) using topmost and rightmost edges
	FOE(i,1,n) Ret.EW[0].PB({1, i});
	FOE(i,2,q[0]) Ret.EW[0].PB({i, n});
 
	// Route EW flow originating in (m, 1) with q[m] as small as possible
	int m = 1;
	// special handle so congestion is 1 if possible
	if (p[0] == 1 && p[n-1] == n && q[0] == 1 && q[n-1] == n){
		m = n - 1;
		FOE(i,1,n) Ret.EW[n-1].PB({n, i});
	}
	else{
		FOR(i,1,n) if (q[i] < q[m]) m = i;
		// Route(m+1, 1) --> (1, 1) --> (1, n) --> (q[m], n)
		
		FOD(i,m+2,2) Ret.EW[m].PB({i, 1});
		FOR(i,1,n) Ret.EW[m].PB({1, i});
		FOE(i,1,q[m]) Ret.EW[m].PB({i, n});
	}
	
	// Create q'[] for n-2 instance
	vector<int> q_new(0);
	FOR(i,1,n) if (i != m) q_new.PB(q[i] - (q[i]>q[0]) - (q[i]>q[m]));
 
	if (n > 1){
		Paths S = solve(p_new, q_new);
		int t;
		
		// connect NS paths
		FOR(i,1,n-1){
			Ret.NS[i].PB({1, i+1});
			for (auto [x, y]: S.NS[i-1]){
				Ret.NS[i].PB({x+1, y+1});
				t = y + 1;
			}
			Ret.NS[i].PB({n, t});
			if (p[i] != t) Ret.NS[i].PB({n, p[i]});
		}
 
		// connect EW paths
		int l = 0;
		FOR(i,1,n) if (i != m){
			Ret.EW[i].PB({i+1, 1});
			if (i > m) Ret.EW[i].PB({i, 1});
			
			for (auto [x, y]: S.EW[l]){
				Ret.EW[i].PB({x+1, y+1});
				t = x + 1;
			}
			
			Ret.EW[i].PB({t, n});
			if (q[i] != t) Ret.EW[i].PB({q[i], n});
			++l;
		}
	}
 
	return Ret;
}
 
int main(){
	int n;
	vector<int> p, q;
	
	scanf("%d", &n);
	p.resize(n), q.resize(n);
	FOR(i,0,n) scanf("%d", &p[i]);
	FOR(i,0,n) scanf("%d", &q[i]);
 
	Paths Solution = solve(p, q);
	
	for (auto path: Solution.NS){
		printf("%d", path.size());
		for (auto [x, y]: path) printf(" %d %d", x, y);
		puts("");
	}
	
	for (auto path: Solution.EW){
		printf("%d", path.size());
		for (auto [x, y]: path) printf(" %d %d", x, y);
		puts("");
	}
	return 0;
}