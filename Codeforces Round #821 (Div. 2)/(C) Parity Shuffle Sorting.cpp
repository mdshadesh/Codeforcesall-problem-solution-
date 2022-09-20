#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int count=0,l[n],r[n];
        for(int i=0;i<n;i++)
        {
            l[i]=-1;
            r[i]=-1;
        }
        if(n!=1)
        {
            if((a[0]+a[n-1])%2==0)
            {
                a[0]=a[n-1];
                r[0]=n;
                l[0]=1;
                count++;
            }
            else
            {
                a[n-1]=a[0];
                r[0]=n;
                l[0]=1;
                count++;
            }
            for(int i=1;i<n-1;i++)
            {
                if((a[i-1]+a[i])%2==1)
                {
                    a[i]=a[i-1];
                    r[i]=i+1;
                    l[i]=i;
                    count++;
                }
                else
                {
                    a[i]=a[n-1];
                    r[i]=n;
                    l[i]=i+1;
                    count++;
                }
            }
        }
        cout<<count<<endl;
        if(count!=0)
        {
            for(int i=0;i<n;i++)
            {
                if(l[i]!=-1 && r[i]!=-1)
                    cout<<l[i]<<" "<<r[i]<<endl;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }*/
        
    }
}