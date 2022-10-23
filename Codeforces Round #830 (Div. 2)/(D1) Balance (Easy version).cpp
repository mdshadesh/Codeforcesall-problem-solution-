#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("in.txt", "r", stdin);
  int T;
  cin >> T;
    map<long long, long long> f, g;
  while (T--) {
    string op;
    long long value;
    cin >> op >> value;
    if (op == "+") {
      f[value] = 1;
    } else {
      long long pre = max(value, g[value]);
      while (f[pre]) {
        pre += value;
      }
      g[value] = pre;
      cout << pre << "\n";
    }
  }
  return 0;
}