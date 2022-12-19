#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		string s; 
		cin >> s;
		bool f = true;
		for(int i = 1; i < s.size() ; i++){
			if(s[i] == '0')cout << '+' ;
			else if(s[i] == '1' && f == false){
				cout << '+';
				f = true;
			}
			else{
				cout << '-';
				f = false;
			}
		}
		cout << endl;
	}

	return 0;
	
}