#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
 
    while(tt--)
    {
        char c;
        set<char> s;
        for(int i=0;i<4;i++)
            {
                cin >> c;
                s.insert(c);
            }
       
    cout << s.size()-1 << endl;
             
    }
}