#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = INT_MAX;
const ll Linf = LLONG_MAX;

#define endl '\n'
#define int long long

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;
		if (n % 2)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == n / 2)
				{
					cout << n << " ";
				}
				else 
				{
					cout << i << " ";
				}
			}
		}
		cout << endl;
	} 
	
	return 0;
}
