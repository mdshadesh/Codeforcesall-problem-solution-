#include <bits/stdc++.h>
#define ll long long 
#pragma ("reroll")
using namespace std;
void qwerty()
{
    ll low = 0, down = 0;;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= 'a')
            ++low;
        else
            ++down;
    }
    if(down > low){
        for(int i = 0; i < s.size(); ++i)
            if(s[i] >= 'a')
                s[i]-=32;
    }
    else{
        for(int i = 0; i < s.size(); ++i)
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i]+=32;
    }
    cout << s;
}
int main()
{
    qwerty();
}
