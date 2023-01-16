#include <bits/stdc++.h>
using namespace std;
const int B=300*300;
const int mod=998244353;
int dp[305][B*2+10];
int a[400];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[2][a[2]+B]=1;
	for(int i=2;i<n;i++){
		for(int j=-B;j<=B;j++){
			if(j){
				dp[i+1][a[i+1]-j+B]=(dp[i+1][a[i+1]-j+B]+dp[i][j+B])%mod;
				dp[i+1][a[i+1]+j+B]=(dp[i+1][a[i+1]+j+B]+dp[i][j+B])%mod;
			}
			else dp[i+1][a[i+1]+B]=(dp[i+1][a[i+1]+B]+dp[i][j+B])%mod;
		}
	}
	int ans=0;
	for(int i=-B;i<=B;i++){
		ans=(ans+dp[n][i+B])%mod;
	}
	cout<<ans<<endl;
	return 0;
}