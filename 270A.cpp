#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int b=180-a;
        if(360%b==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
