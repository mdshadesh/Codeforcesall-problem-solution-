#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1="";
    int x=0;
    cin>>s;
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=65 && s[i]<=90)
            c++;
    }
    if(c==s.length() || (c==s.length()-1 && s[0]>=97 && s[0]<=122))
    {
        for(int i=0;i<s.length();i++)
        {
        if(s[i]>=65 && s[i]<=90)
        {
           x=(int)s[i];
           x=x+32;
           s1+=char(x);
        }
        else
        {
          x=(int)s[i];
          x=x-32;
          s1+=char(x);
        }         
      }
        cout<<s1<<endl;
    }
    else
      cout<<s<<endl;
    return 0;
}