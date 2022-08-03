#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5+10;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
char s[maxn];
int q;
set<int> Set[26];
int main()
{
	scanf("%s", s+1);
	cin >> q;
	int n = strlen(s+1);
	for (int i = 1; i <= n; i++) 
		Set[s[i]-'a'].insert(i);
	for (int i = 0; i < q; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int p; char c;
			scanf("%d %c", &p, &c);
			int cur = s[p]-'a';
			if (Set[cur].count(p))
				Set[cur].erase(Set[cur].find(p));
			s[p] = c;
			Set[c-'a'].insert(p);
		} else {
			int l, r, ans = 0;
			scanf("%d%d", &l, &r);
			for (int j = 0; j < 26; j++) {
				int cur = *Set[j].lower_bound(l);
				if (cur >= l && cur <= r) {
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}