#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
 long long t,n,q,x,y,z,w; cin>>t; while (t--) 
 {
  cin>>n>>q;
  long long A[1'001][1'001] {};
  while (n--) 
  {
    cin>>x>>y; A[x][y]+=x*y;
  }
  for (int i{1}; i<=1'000; i++)
   for (int j{1}; j<=1'000; j++)
    A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
  while (q--) 
  {
   cin>>x>>y>>z>>w;
   cout<<A[z-1][w-1]-A[x][w-1]-A[z-1][y]+A[x][y]<<'\n';
  }
 }
}