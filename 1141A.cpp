#include <bits/stdc++.h>
#define ll unsigned long long
const int N = 1e3 + 5;
const ll MOD = 1e9 + 7;
using namespace std;
 
int dp[N][N];
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t, cnt = 0;
    std:: cin >> n >> m;
    if(n == m) {
        std:: cout << 0;
        return 0;
    }
    else if(m % n != 0) {
        std:: cout << -1;
        return 0;
    }
    t = m / n;
    while(t > 1) {
        if(t % 3 == 0) {
            cnt++;
            t /= 3;}
        else if(t % 2 == 0){
            cnt++;
            t /= 2;}
        else {
            std:: cout << -1;
            return 0;
        }
    }
    std:: cout << cnt;
}