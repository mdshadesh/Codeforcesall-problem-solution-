#include <bits/stdc++.h>
 
using namespace std;
map <int,int>mp;
int main()
{
    int n,cnt=0;
    bool ans = true;
    string s;
    cin >> n >> s;
    if (n > 26) 
        ans = false;
    for (int i=0;i<n;i++) 
    {
        mp[s[i]-'a']++;
        if (mp[s[i]-'a'] > 1) 
            cnt++;
        if (cnt >= 26) 
            ans = false;
    }
    cout << (ans ? cnt : -1) ;
}
