#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int N=200005;
array<int,4> one[N][32]; 
array<int,4> dp[N][32]; 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i];
    vector<vector<int>> v(n+1);
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    dp[0][0][0]=1;
    vector<int> sz(n+1,0);
    auto dfs=[&](auto &&self,int a)->void
    {
        sz[a]=1;
        int tmp=0;
        for(int to:v[a])
        {
            self(self,to);
            sz[a]+=sz[to];
            for(int m=0;m<32;m++)
            {
                for(int b=0;b<32;b++)
                {
                    if(dp[tmp][m][0]==1&&one[to][b][0]==1)
                    {
                        dp[to][m^b]={1,b,tmp,m};
                    }
                }
            }
            tmp=to;
        }
        for(int m=0;m<32;m++)
        {
            if(dp[tmp][m][0]==1)
            {
                int b=m^x[a];
                one[a][b]={1,0,tmp,m};
                if((sz[a]%2)==0&&b!=0) one[a][0]={1,1,tmp,m};
            }
        }
    };
    dfs(dfs,1);
    if(one[1][0][0]==1)
    {
        vector<int> res={1};
        auto go=[&](auto &&self,int a,int m,int tp)->void //tp: 0-one 1-dp
        {
            if(a==0) return;
            if(tp==0)
            {
                if(one[a][m][1]==1) res.push_back(a);
                self(self,one[a][m][2],one[a][m][3],1);
            }
            else
            {
                self(self,a,dp[a][m][1],0);
                self(self,dp[a][m][2],dp[a][m][3],1);
            }
        };
        go(go,1,0,0);
        cout << res.size() << "\n";
        ranges::reverse(res);
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}