#include <iostream>

using namespace std;

long long int Gcd(long long int a, long long int b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

int main()
{
    long long int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long int a[n+1];
        long long int gcdNiz[n+1];

        cin >> a[1];
        long long int gcd=a[1], res=-1;
        gcdNiz[1] = Gcd(a[1], 1);
        for(i=2;i<=n;i++)
        {
            cin >> a[i];
            gcd = Gcd(gcd, a[i]);
            gcdNiz[i] = Gcd(a[i], i);
            if(gcdNiz[i]==1)
            {
                res = n-i+1;
            }
        }

        if(gcd==1)
        {
            cout << 0 << endl;
        }
        else
        {
            for(i=n;i>=1;i--)
            {
                if(gcdNiz[i]==1 || Gcd(gcdNiz[i],gcd)==1)
                {
                    res = n-i+1;
                    break;
                }
            }
            if(res<3 && res!=-1)
            {
                cout << res << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }
    }
}