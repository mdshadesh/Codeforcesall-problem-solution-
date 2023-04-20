#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n, a[N], m, b[N], c[N], dp[N], ans;  // Declare variables

int main() {
  ios::sync_with_stdio(0), cin.tie(0);  // Optimize input/output
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);  // Sort the array
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {  // Count the frequency of each integer
      b[m]++;
    } else {
      b[++m] = 1;
    }
  }
  sort(b + 1, b + m + 1);  // Sort the frequency array
  for (int i = 1; i <= m; i++) {  // For each group of identical integers
    for (int j = 1; j <= b[i]; j++) {  // For each element in the group
      dp[j] = 0;  // Initialize the DP array
      if (!(j % 2)) {  // If the index is even
        dp[j] = c[j / 2];  // Take the previous value of c
      }
      dp[j] += j;  // Add the index to the DP value
      ans = max(ans, dp[j]);  // Update the answer
    }
    for (int j = 1; j <= b[i]; j++) {  // Update the c array
      c[j] = max(c[j], dp[j]);
    }
  }
  cout << ans;  // Output the answer
  return 0;
}
