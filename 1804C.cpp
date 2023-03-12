#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(abs(a)!=abs(b))
        cout<<abs(a)+abs(b)+abs(abs(a)-abs(b))-1<<endl;
        else 
        cout<<abs(a)+abs(b)+abs(abs(a)-abs(b))<<endl;
    }
}
