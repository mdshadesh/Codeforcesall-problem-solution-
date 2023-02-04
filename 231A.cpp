#include <bits/stdc++.h>

using namespace std;

int
main ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);

  int n;
  cin >> n;
  int count = 0;
  while (n--)
    {
      int a, b, c;
      cin >> a >> b >> c;
      if (a + b + c >= 2)
	{
	  count++;
	}
    }
  cout << count;

}
