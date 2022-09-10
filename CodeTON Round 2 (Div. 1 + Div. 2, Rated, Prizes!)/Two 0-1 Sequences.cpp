# include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define pb push_back
#define endl "\n"
#define mod 1000000007
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    Speed_UP
    
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        string s1,s2;
        cin>>s1>>s2;
 
        ll f1=0,f2=0,j=0;
        for(ll i=0;i<a;i++)
        {
            if(i<=a-b)
            {
                if(s1[i]==s2[j])
                f1=1;
            }
            else
            {
                j++;
                if(s1[i] != s2[j])
                {
                    f2=1;
                    break;
                }
            }
        }
        if(f1==1 && f2==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
 
    }
    
}