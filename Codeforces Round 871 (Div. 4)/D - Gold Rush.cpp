
#include <iostream>
using namespace std;
bool dfs( int n, int m) 
{    if (m>n)
 {      
     return false;    }  
     if(m==n)
     return true; 
 if(n % 3 == 0) {
      if (n*2/3 == m||n*1/3==m)
       {        return true;    }  
   
  return (dfs( n*2/3, m) ||dfs(n/3,m));
    }
  else
    return false;
  }
  int main() 
  {    double n, m; 
  int t;cin>>t;
  while(t--){
  
   cin >> n >> m;  
    if (dfs( n, m)) {   
          cout << "Yes" << endl;    }
           else {      
             cout << "NO" << endl;    }  
         }
      return 0;
      }