#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const int mod = 1e9 + 9;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
long long n, a, b, k;
char s[maxn];

long long pow_mod(long long x, long long n)
{
    long long res = 1;
    while(n){
        if(n & 1) res = res * x% mod;
        x = x * x% mod;
        n >>= 1;
    }
    return res;
}

void Exgcd(long long a, long long b, long long& x, long long& y)
{
    if(!b){
        y = 0; x = 1;
        return;
    }
    Exgcd(b, a% b, y, x);
    y -= a/b * x;
}

long long NY(long long a, long long b)
{
    long long x, y;
    Exgcd(a, b, x, y);
    return (x% mod + mod)% mod;
}

int main()
{
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    scanf("%s", s);

    long long ans = 0;
    for(int i = 0; i <k; i++){
        long long tmp = pow_mod(a, n-i) * pow_mod(b, i)% mod;
        if(s[i] =='+') ans += tmp;
        else ans -= tmp;
        ans = (ans% mod + mod)% mod;
    }

    long long q = pow_mod(b, k) * NY(pow_mod(a, k), mod)% mod;
    long long m = (n + 1)/k;

    if(q == 1) ans = ans * m% mod;
    else ans = ans * (pow_mod(q, m)-1)% mod * NY(q-1, mod)% mod;

    ans = (ans% mod + mod)% mod;

    printf("%lld\n", ans);;

    return 0;
}