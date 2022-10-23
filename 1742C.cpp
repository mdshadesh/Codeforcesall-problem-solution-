#include<bits/stdc++.h>
using namespace std;

void solve()
{
   char arr[8][8];
   for(int i=0;i<8;i++)
   {
    for(int j=0;j<8;j++)
    {
        cin>>arr[i][j];
    }
   }
   for(int i=0;i<8;i++)
   {
    int a=0;
    for(int j=0;j<8;j++)
    {
        if(arr[i][j]!='R')
        {
            a=1;
            break;
        }
    }
    if(a==0)
        {
            cout<<'R'<<endl;
            return;
        }
   }
   cout<<'B'<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}