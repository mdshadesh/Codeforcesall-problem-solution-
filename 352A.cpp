#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
   long int s5=0; 
    int flag=0; int five=1;
   string ans="";
    int c=0;
    int t=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==5)
        {s5+=5;
        c++;}
        if(a[i]==0)
        flag=1;
    }
     while(five>0)
     {
         if(s5%9==0)
         {
             t=s5/5;
             break;
         }
         else
         s5=s5-5;
     }
    
    for(int i=0;i<t;i++)
    {
        ans=ans+'5';
    }
   if(t!=0)
   {
    for(int i=0;i<(n-c);i++)
    {
        ans=ans+'0';
    }
   }
   else
   ans="0";
    if(flag==1)
    cout<<ans;
    else
    cout<<"-1";
}

