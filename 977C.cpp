#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n + 2];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(k == 0 && a[1] == 1){
		cout << -1;
		return 0;
	}
	if(k == 0){
		cout << a[1] - 1;
		return 0;
	}
	if(a[k] != a[k + 1]) cout << a[k];
	else cout << -1;
	return 0;
}
