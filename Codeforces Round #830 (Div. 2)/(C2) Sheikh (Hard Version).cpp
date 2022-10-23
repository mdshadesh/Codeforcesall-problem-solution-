#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define int long long
#define endl '\n'

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int z; cin >> z;

  while (z--) {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> nxt(n + 2), pre(n + 2);

    for (int i = 1; i <= n; i++) cin >> a[i];

    pre[1] = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i - 1] == 0) pre[i] = pre[i - 1];
      else pre[i] = i - 1;
    }

    nxt[n] = n + 1;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i + 1] == 0) nxt[i] = nxt[i + 1];
      else nxt[i] = i + 1;
    }

    vector<int> sum(n + 1, 0), xsum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
      xsum[i] = xsum[i - 1] ^ a[i];
    }

    for (int i = 1; i <= q; i++) {
      int l, r; cin >> l >> r;
      int len = r - l + 1;
      int val = sum[r] - sum[l - 1] - (xsum[r] ^ xsum[l - 1]);
      int ansl = l, ansr = r;
      if (sum[r] == sum[l - 1]) {
        cout << l << " " << l << endl;
        continue;
      }
      for (int j = l, totj = 0; totj <= 35 && j <= r; j = nxt[j], totj++) {
        for (int k = r, totk = 0; totk <= 35 && k >= l; k = pre[k], totk++) {
          if (k < j) break;
          int res = sum[k] - sum[j - 1] - (xsum[k] ^ xsum[j - 1]);
          if (res < val) continue;
          else if (k - j + 1 < len) {
            len = k - j + 1;
            ansl = j, ansr = k;
          }
        }
      }
      cout << ansl << " " << ansr << endl;
    }
  }

  return 0;
}
