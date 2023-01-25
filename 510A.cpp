#include <bits/stdc++.h>
using namespace std;

int main() 
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	char letter;
	cin >> n >> m;
	bool isRight = false;

	for (int r = 0; r < n; r++) 
    {
		for (int c = 0; c < m; c++) 
        {
			if (r % 2 == 0) {
				letter = '#';
			} else {
				if ((c == 0 && !isRight) || (c == m - 1 && isRight)) 
                {
					letter = '#';
				} else {
					letter = '.';
				}
			}
			cout << letter;
		}
		if (r % 2 == 0) 
        {
			isRight = !isRight;
		}

		cout << endl;
	}

	return 0;
}