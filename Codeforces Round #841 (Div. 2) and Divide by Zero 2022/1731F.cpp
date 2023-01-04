#include <bits/stdc++.h>
using namespace std;
constexpr int N = 50 + 5;
constexpr int mod = 998244353;
int z[N][N];
int ksm(int a, int b) {
  if(!a) return b ? 0 : 1;
  if(a < N && b < N && z[a][b]) {
    return z[a][b];
  }
  int s = 1, ta = a, tb = b;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  if(ta < N && tb < N) z[ta][tb] = s;
  return s;
}
int n, k, ans, c[N][N];
int main() {
  cin >> n >> k;
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % mod : 1;
  for(int v = 1; v <= n + 3; v++) {
    int f = 0;
    for(int p = 1; p <= n; p++)
      for(int t = 1; t <= v; t++) 
        for(int l = 0; l < p; l++)
          for(int r = l + 1; r <= n - p; r++) {
            int c = 1ll * ::c[p - 1][l] * ::c[n - p][r] % mod;
            c = 1ll * c * ksm(t - 1, l) % mod;
            c = 1ll * c * ksm(t, n - p - r) % mod;
            c = 1ll * c * ksm(v - t, r) % mod;
            c = 1ll * c * ksm(v - t + 1, p - 1 - l) % mod;
            f = (f + 1ll * t * c) % mod;
          }
    int c = 1;
    for(int j = 1; j <= n + 3; j++) {
      if(v == j) continue;
      c = 1ll * c * (k + mod - j) % mod;
      c = 1ll * c * ksm(v + mod - j, mod - 2) % mod; 
    }
    ans = (ans + 1ll * f * c) % mod;
  }
  cout << ans << "\n";
  return 0;
}