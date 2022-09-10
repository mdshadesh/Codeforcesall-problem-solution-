#include<iostream>
using namespace std;
 
int a[100010], premin[100010];
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t, n, k;
	int i, j, v, p, temp, ans;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (i = 1; i <= n; i++) cin >> a[i];
		if (a[n] < k) { cout << "0\n"; continue; }
		a[n + 1] = 1 << 30;
		for (i = 0, j = 1; i <= 100000; i++)
		{
			while (i > a[j]) j++;
			premin[i] = a[j];
		}
 
		ans = 1 << 30;
		for (v = 1; v <= a[n]; v++)
		{
			if (a[n] >= k * (v + 1)) continue;
			p = 1 << 30;
			for (j = 0; j < k; j++)
			{
				if (j * (v + 1) > a[n]) break;
				if (premin[j * (v + 1)] <= (j + 1) * (v + 1) - 1)
				{
					temp = premin[j * (v + 1)] / (j + 1);
					if (p > temp) p = temp;
				}
			}
			if (ans > v - p) ans = v - p;
		}
		cout << ans << "\n";
	}
}