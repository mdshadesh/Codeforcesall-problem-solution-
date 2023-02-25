#include<bits/stdc++.h>
 using namespace std;
 
 void solve()
 {
       int n;
       cin>>n;
       string str;
        cin>>str;
         int res=0;
         string ans;
         int cnt=0;
         for(int i=0;i<n;i++)
         {
           cnt=0;
           for(int j=0;j<n;j++)
             {
              if(str[i]==str[j]&&str[i+1]==str[j+1])
              {
               cnt++;
               if(res<cnt)
               {
                res=cnt;
                ans=string(1,str[i])+string(1,str[i+1]);
               }
              }
             }
         }
         cout<<ans;
 }
 
  
  int main()
  {
     
       solve();
      
  }