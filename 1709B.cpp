#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

   long long int n,x;
    cin>>n>>x;
    long long ans[x];
    long long int num[n+1];
   long long int c=0;
   long long int l[n+4],r[n+4];
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    l[1]=0;
    r[n]=0;
    for(int i=2;i<=n;i++)
    {
        if(num[i]<num[i-1])
        {
            l[i]=l[i-1]+num[i-1]-num[i];
        }
        else
        {
            l[i]=l[i-1];
        }
    }
    for(int i=n-1;i>0;i--)
    {
       if(num[i]<num[i+1])
        {
            r[i]=r[i+1]+num[i+1]-num[i];
        }
        else
        {
            r[i]=r[i+1];
        }
    }
  long long int num1,num2;
  while(x!=0)
  {
      cin>>num1>>num2;
      if(num1<num2)
      {
          cout<<l[num2]-l[num1]<<endl;
      }
      else
      {
          cout<<r[num2]-r[num1]<<endl;
      }
      x--;
  }

    return 0;
}
