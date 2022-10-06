#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, m, k=0;
	vector<int> a;
	vector<int> b;
	cin >> t;
	for (int i=0; i < t; i++)
	{
		cin >> n;
		m = 0;
		a.clear();
		k = 0;
		for (int j=0; j < n; j++)//reading vector
		{
			int p;
			cin >> p;
			a.push_back(p);
		}
		m = *min_element(a.begin(), a.end());//find min
		for (int j = 0; j < n; j++) //summation
		{
			k += a[j] / (2*m - 1);
			if (a[j] % (2*m - 1) == 0)
				k --;
		}
		b.push_back(k);

	}
	for (int j = 0; j < t; j++)
	{
		cout << b[j]<<" ";
	}
}