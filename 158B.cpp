#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  int col1 = 0;
  int col2 = 0;
  int col3 = 0;
  int col4 = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 4) {
      ++col4;
      continue;
    }
    if (arr[i] == 3) {
      ++col3;
      continue;
    }
    if (arr[i] == 2) {
      ++col2;
      continue;
    }
    if (arr[i] == 1) {
      ++col1;
      continue;
    }
  }

  int res = col4;
  res += col3;
  col1 = std::max(0, col1 - col3);

  res += col2 / 2;

  if (col2 % 2 != 0) {
    ++res;
    col2 = 0;
    col1 = std::max(0, col1 - 2);
  }

  res += (col1 + 3) / 4;

  std::cout << res;
  return 0;
}