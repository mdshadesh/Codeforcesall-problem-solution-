#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7; 

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define For(i, a, b) for(int i = a; i <= b; i++)
#define RFor(i, a, b) for(int i = a; i >= b; i--)
#define Forr(a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
  #define debug(...) 42
  #define debugArr(...) 42
#endif
typedef long long ll;
typedef pair<int,int> pii; 
#define Maxn 100001

int main(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin >> t;
    while(t--) {
    	int n, k;cin >> n >> k;
    	int a[n+1];
    	int pre1 = 1e9, pre2 = 1e9, pos1;
    	For(i, 1, n) {
    		cin >> a[i];
    		if(a[i] < pre1) {
    			pos1 = i;
    			pre1 = a[i];
    		}
    	}
    	For(i, 1, n) {
    		if(i != pos1 && a[i] < pre2) {
    			pre2 = a[i];
    		}
    	}
    	int cnt = 0;
    	For(i, 1, n) {
    		if(i != pos1) {
    			cnt += (k-a[i])/pre1;
    		}
    	}
    	cout << cnt << endl;
    }
    return 0;
}


