#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
void solve() {
	int n = nxt();
	string a[3];
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
	}
	int maj = 0;
	for (int i = 0; i < 3; ++i) {
		maj += a[i][n - 1] - '0';
	}
	if (maj % 3 == 0) {
		cout << "0\n";
		return;
	}
	maj /= 2;
	for (int i = 0; i < 3; ++i) {
		if (a[i][n - 1] != '0' + maj) {
			rotate(a, a + i, a + 3);
			break;
		}
	}
 
	int mx[3] = {n, n, n};
	for (int i = 0; i < 3; ++i) {
		while (mx[i] && a[i][mx[i] - 1] == a[i][n - 1]) {
			--mx[i];
		}
	}
	if (mx[1] + mx[2] >= n) {
		cout << min(n - mx[2], n - mx[0]) + min(n - mx[1], n - mx[0]) << "\n";
	} else {
		cout << min({n, 2 * (n - mx[0]), n - mx[1] - mx[2] + min(n - mx[0], mx[1]) + min(n - mx[0], mx[2])}) << "\n";
	}
}
 
int main() {
	int t = nxt();
	while (t--) {
		solve();
	}
 
	return 0;
}