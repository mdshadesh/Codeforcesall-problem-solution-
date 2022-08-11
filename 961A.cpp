#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
    
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) 
    {
		cin >> a[i];
	}
	vector<int> counter(n + 1, 0);
	for (int i = 0; i < m; i++) 
    {
		counter[a[i]]++;
	}
	cout << *min_element(counter.begin() + 1, counter.end()) << '\n';
	return 0;
}