#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,t,k;
	map <int,int> mp;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&t);
		mp[t] = i;
	}
	if(mp.size() < m) puts("NO");
	else{
		k = 0,puts("YES");
		for(auto i = mp.begin();i != mp.end();i++){
			if(k) puts(" ");
			printf("%d",i->second);
			if(++k == m) break;
		}
	}
	return 0;
}
		    				     	  		 		 	     	