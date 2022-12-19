#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main() 
{
  int T;
  scanf("%d", &T);
  while (T--) 
  {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 0, r = 2e9;
    bool flag = 0;
    for (int i = 1; i < n; i++) 
    {
      if (a[i] > a[i + 1]) l = max(l, (a[i] + a[i + 1] + 1) / 2);
      if (a[i] < a[i + 1]) r = min(r, (a[i] + a[i + 1]) / 2);
    }
    if (l > r)
      puts("-1");
    else
      cout << l << endl;
  }
}