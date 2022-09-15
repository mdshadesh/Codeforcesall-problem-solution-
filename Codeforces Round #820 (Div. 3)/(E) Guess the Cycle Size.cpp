#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; 
    while(t--)
    {
        for(int i=1 ; i<=27  ; i++) 
        {
            long long x,y;
            cout<<"? "<<i<<" "<<i+1<<endl;
            cin>>x;
            if(x==-1) 
            {
                cout<<"! "<<i<<endl;
                break;
            }
            cout<<"? "<<i+1<<" "<<i<<endl;
            cin>>y;
            if(x!=y) 
            {
                cout<<"! "<<x+y<<endl;
            }
        }
        
    }
    return 0;
}