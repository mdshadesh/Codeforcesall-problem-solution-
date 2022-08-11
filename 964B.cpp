#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,a,b,c,t;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &t);
    ll sum = n*a;
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        if(b < c) sum += (c - b)*(t - k);
    }
    printf("%lld\n", sum);
    return 0;
}