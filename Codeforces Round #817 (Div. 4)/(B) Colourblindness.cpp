#include <bits/stdc++.h>
using namespace std;
 
void solve(){
 
    int n;
    cin >>n;
    string s;
    string s1;
    cin >> s;
    cin >> s1;
 
    int i;
    int j=0;
    for(i=0;i<n;i++)
    {
       if(s[i]==s1[j]) 
       {
           j++;continue;
       }
       else{        
            if((s[i]=='B' && s1[j]=='G') or (s[i]=='G' && s1[j]=='B' )) 
            { 
                j++;continue;
            }
            else 
            break;
       } 
    }
    if(i==n) 
       cout<<"YES"<<endl;
    else 
       cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       solve();
    }
}