#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    char s[100005], *p;
    int x;
    cin >> s;
    if( (p=strstr(s,"AB"))&&(strstr(p+2,"BA")))
    {
        cout<<"YES"<<endl;
    }
    else if((p=strstr(s,"BA"))&&(strstr(p+2,"AB")))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}