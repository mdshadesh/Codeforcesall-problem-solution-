#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string s;
        cin>>s;
        int count[26] = {0};
        for(ll i=0;i<s.length()/2;i++)
        {
            count[(int)s[i]-97]++;
        }
        int discount = 0;
        for(ll i=0;i<26;i++)
            discount+=(count[i]>0); 
            
        if(discount>1) 
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
    return  0;
}
