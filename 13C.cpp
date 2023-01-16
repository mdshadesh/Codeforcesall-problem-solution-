#include<bits/stdc++.h>

using namespace std;
long long n, ans;
priority_queue<long long> q;

int main()
{
    cin>>n;
    ans = 0;
    while (n--)
    {
        int x;
        cin>>x;
        q.push(x);
        if (q.top() > x) {
            ans += q.top() - x;
            q.pop();
            q.push(x);
         }
     }
    cout<<ans<<endl;
    return 0;
}
   		 	   	 		  	 		  			 	   	