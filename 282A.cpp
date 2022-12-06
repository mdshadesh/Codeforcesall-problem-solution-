#include<iostream>
using namespace std;
int main()
{
    int n,p=0;
    cin>>n;
    string s;
    while(n--)
    {
         cin>>s;
         if(s[0]=='+' || s[1]=='+')
         {
              p=p+1;
         }
         else if(s[0]=='-' || s[1]=='-')
         {
              p=p-1;
         }
 
 
    }
      cout<<p;
 
}