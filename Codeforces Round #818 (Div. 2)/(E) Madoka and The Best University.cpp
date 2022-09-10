#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 100005;

const LL M = 1e9 + 7;
LL n;
int u[N], flg[N], nxt[N], fi[N];
vector<int> D[N];
void init() {
	for(int i = 1; i < N; i++) D[i].clear();
	D[1].pb(1);
	for(LL i = 2; i < N; i++) {
		if(flg[i]) continue;
		nxt[i] = i;
		for(LL j = i * 2; j < N; j += i) flg[j] = 1, nxt[j] = i;
	}
	LL tp, tp_;
	memset(flg, 0, sizeof flg);
	
	for(int i = 2; i < N; i++) {
		tp = i / nxt[i];
		D[i].clear();
		for(auto v: D[tp]) {
			D[i].pb(v);
			flg[v] = i;
		}
		for(auto v: D[tp]) {
			tp_ = v * nxt[i];
			if(flg[tp_] == i) continue;
			flg[tp_] = i;
			D[i].pb(tp_);
		}
	}
	u[1] = 1;
	for(int i = 2; i < N; i++) {
		tp = i / nxt[i];
		if(tp % nxt[i] == 0) u[i] = 0;
		else u[i] = -u[tp];
	}
	fi[1] = 1;
	for(int i = 2; i < N; i++) {
		tp = i / nxt[i];
		if(tp % nxt[i]) fi[i] = fi[tp] * (nxt[i] - 1);
		else fi[i] = fi[tp] * nxt[i];
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	init();
	cin >> n;
	LL rlt = 0;
	int n_;
	for(int c = 1; c <= n - 2; c++) {
		n_ = n - c;
		for(auto v: D[n_]) {
			if(v == n_) continue;
			rlt += 1LL * c * v / __gcd(c, v) * fi[n_ / v];
			if(rlt >= M) rlt %= M;
		}
	}
	cout << rlt << endl;
	return 0;
}

