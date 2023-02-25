#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long a, b, c, d;
	
	long long counter = 0, mood = 1;
	
	cin >> a >> b >> c >> d;
	
	if (a == 0)
	{
		if (b || c || d) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}
	
	counter += a;
	
	mood += counter;
	
	long long dif = min(b, c);
	c = max(b, c) - dif;
	counter += (dif * 2);
	
	c = min(mood, c);
	counter += c;
	mood -= c;
	counter += min(mood, d);
	
	cout << counter << endl;
}

int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int a;
	cin >> a;
	while(a--) solve();
}