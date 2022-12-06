#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int n,m;
    cin>>n>>m;
    float a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
       (a[i])=ceil(a[i]/float(m));
    }
    int k=0;
    int l;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=k)
        {
            k=a[i];
            l=i+1;
        }
    }
    cout<<l;

    return 0;
}