   #include <bits/stdc++.h>
   using namespace std;
   
   typedef long long ll;
   #define loop(n) for(ll i=0;i<n;i++)
   const ll one_by_six = 166666668;
   const ll mod =  1e9 + 7;
   
   #define dtb(n,x) bitset<n>(x).to_string();

   void solve()
   {
      ll n ,m ,k;
       cin >> n >> m >> k;

       puts((m>=n-1&&n*(n-1)/2>=m)&&((n==1&&k>1)||(n*(n-1)/2==m&&k>2)||k>3)? "YES":"NO");

   }
        
   int main()
   { 
          ll t;
           cin >> t;
           while(t--)
           {
              solve();
           }
           return 0;
   }
