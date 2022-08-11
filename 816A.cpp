#include<bits/stdc++.h>

typedef long long int ll;

#define pp pair<ll, ll>
#define dbg printf("in");
#define NL printf("\n");
#define S 100010
#define inf 1000000000000

using namespace std;

int main()
{
    ll i , j , k, hh, mm;
    ll n , count = 0;
    
    string s, h, m;
    cin>>s;
    h.push_back(s[0]);
    h.push_back(s[1]);
    h.push_back(s[2]);
    h.push_back(s[4]);

    while(1)
    {
        if(h[0] == m[1] && h[1]==m[0])
        {
            break;
        }
        mm = (m[0] - 48) * 10 + (m[1] - 48);
        hh = (h[0] - 48 )* 10 + (h[1] - 48);
        mm++;
        if(mm == 60)
        {
            hh++;
            mm = 0;
        }
        if(hh>23)
        {
            hh = 0;
        }
        j = mm%10;
        mm = mm/10;
        h[1] = j + 48;
        h[0] = hh + 48;

        j = hh % 10;
        hh = hh / 10;
        h[1] = j + 48;
        h[0] = hh + 48;

        count++;
    }
    cout<<count;

    return 0;
}