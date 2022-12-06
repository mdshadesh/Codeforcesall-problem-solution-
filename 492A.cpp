#include<bits/stdc++.h>
#include <numeric>
using namespace std;

void solve()
{
    int n,sum=0,count=0,j=0,pr;
    cin>>n;
    for(int i=1; i<=10000; i++)
    {
         pr=j+i;
         sum=sum+pr;
        if(sum>n)break;
        else
        {
            count++;
        }
        j=pr;
    }
    cout<<count<<endl;
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
