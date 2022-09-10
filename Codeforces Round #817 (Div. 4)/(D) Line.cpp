#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    ll n,ans=0,k=0;
    cin>>n;
     string s; cin>>s;
     for(int i=0;i<n;i++)
     {
         if(s[i]=='L') ans+=i;
         else ans+=n-i-1;
     }
     //cout<<ans<<endl;
     ll l=0,r=n-1,typ=1;
     while(l<=r)
     {
         if(typ){
                 if(s[l]=='R') l++;
                 else {
                     s[l]='R'; ans+=n-l-1; ans-=l;
                     l++;k++;
                     if(k<=n)
                     cout<<ans<<" "; 
                 }
         }
         else
         {
                if(s[r]=='L') r--;
                else{
                    s[r]='L'; ans+=r; ans-=n-r-1;
                    r--; k++; 
                    if(k<=n)
                    cout<<ans<<" ";
                }
         }
         typ=1-typ;
     }
     while(k<n) {cout<<ans<<" "; k++;}
     cout<<endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	 while(t--)
	  solve();
	return 0;
}