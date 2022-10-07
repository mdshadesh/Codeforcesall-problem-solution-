#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc ;
	tc = 1 ;
	cin >> tc ;
	while(tc--){
		int n , x ;
		cin >> n >> x ;
		int arr[n] , sum = 0 ;
		for(int i=0;i<n;i++) cin >> arr[i] , sum += arr[i] ;
		if(sum % x != 0) cout<<n<<endl;
		else {
			int st = 0 , end = n-1 ;
			for(int i=0;i<n;i++){
				if(arr[i] % x != 0){
					st = i+1 ;
					break;
				}
			}
			for(int i=n-1;i>=0;i--){
				if(arr[i] % x != 0){
					end = i ;
					break;
				}
			}
			if(end-st+1==n) cout<<-1<<endl;
			else cout<<max(n-st , end)<<endl;
		} 
		
	}
}