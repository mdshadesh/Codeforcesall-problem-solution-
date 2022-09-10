#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << n + 2 * (n / 2) + 2 * (n / 3) << '\n';
	}
	return 0;
}
