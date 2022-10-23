#include<bits/stdc++.h>
using namespace std;
int a[35],n;

int help()
{
    int c = 0;
    for(int i = n;i > 1;i --)
    {
        if(a[i] == 0) return -1;
        while(a[i-1] >= a[i] && a[i] > 0)
            a[i-1] /= 2,c ++;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i = 1;i <= n;i ++) cin >> a[i];
        cout << help() << "\n";
    }
	return 0;
}