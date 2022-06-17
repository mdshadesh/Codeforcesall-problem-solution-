#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n,m;
    int a[1050];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(a[0]<=m)
                {
                    if(a[0]+a[j]<=m)
                    {
                        a[0]+=a[j];
                        a[j]-=a[j];
                    }
                    else if(m-a[0])
                    {
                        a[0]+=(m-a[0]);
                    }
                }
                else if(a[0]==m)
                    break;
            }
        }
        cout<<a[0]<<endl;
    }
    return 0;
}
