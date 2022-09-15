#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
using namespace std;
typedef pair<int, int> pii;
void solve()
{
    string s, ss;
    cin>> s >> ss;
    int N = s.size(), NN = ss.size();
    vector<int>pos;
    pos.emplace_back(-N);
    for(int i = 0; i<N-NN+1; i ++)
    {
        if(s.substr(i, NN) == ss)
        {
            pos.emplace_back(i);
        }
    }
    int siz = pos.size();
    siz++;
    pos.emplace_back(N+NN);
    vector <int> dp1(siz, 1e9), dp2(siz, 0);
    dp1[0] = 0;
    dp2[0] = 1;
    for(int i = 0; i < siz; i ++)
    {
        int j = i+1;
        while(j < siz && pos[i] + NN - 1 >= pos[j]){j++;}
        for(int k = j; k < siz && pos[k] <= pos[j]+NN-1; k++)
        {
            if(dp1[i]+1 < dp1[k])
            {
                dp1[k] = dp1[i] + 1;
                dp2[k] = dp2[i];
            }
            else if(dp1[i]+1 == dp1[k])
            {
                dp2[k] = (dp2[i]+dp2[k])%(int)(1e9+7);
            }
        }
    }
    cout << dp1[siz-1]-1 << " " << dp2[siz-1] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    N = 1;
    cin >> N;
    while(N--)solve();
    return 0;
}
