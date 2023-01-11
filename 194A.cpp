#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<utility>
#define F int64_t
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k/n>2)
    {
        cout<<0;
    }
    if(k/n==2)
    {
        cout<<n-(k%n);
    }
    if(k/n<2)
    {
        cout<<0;
    }
    return 0;
}