#include <iostream>
using namespace std;
int main ()
{
    long long n, k, x, ans = 0;
    cin >> n >> k;
    long long ara[n], sum[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> ara[i];
        if (i == 0) sum[0] = ara[0];
        else sum[i] = sum[i-1] + ara[i];
    }

    long long mn = (long long) 1e16;
    for (int i = 0; i < n-k+1; i++) 
    {
        if (i == 0) 
        x = sum[i+k-1];
        else 
        x = sum[i+k-1] - sum[i-1];
        if (x < 0) 
        x *= -1;
        if (x < mn) {
            mn = x;
            ans = (long long) i;
        }
    }
    cout << ans+1 << endl;
    return 0;
}