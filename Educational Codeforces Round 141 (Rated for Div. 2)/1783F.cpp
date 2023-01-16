#include<bits/stdc++.h>
using namespace std;
const int N = 5500;
vector<int> g[N];
int mt[N],u[N],n,vs[2];
vector<vector<int>> cycle[2];
vector<int> a[2];
vector<vector<int>> inter;
bool kuhn(int x)
{
    if(u[x]) return 0;
    u[x] = 1;
    for(auto y : g[x])
    {
        if(mt[y] == x) continue;
        if(mt[y] == -1 || kuhn(mt[y]))
        {
            mt[y] = x;
            return 1;
        }
    }
    return 0;
}
int find_intersection(const vector<int>& x, const vector<int>& y)
{
    for(auto i : x)
        for(auto j : y)
            if(i == j)
                return i;
    return -1;
}
int main()
{
    scanf("%d", &n);
    for(int k = 0; k < 2; k++)
    {
        a[k].resize(n);
        for(int j = 0; j < n; j++)
            scanf("%d", &a[k][j]),a[k][j]--;
    }
    for(int k = 0; k < 2; k++)
    {
        vector<bool> used(n);
        for(int i = 0; i < n; i++)
        {
            if(used[i]) continue;
            vector<int> cur;
            int j = i;
            while(!used[j])
            {
                cur.push_back(j);
                used[j] = 1;
                j = a[k][j];            
            }
            cycle[k].push_back(cur);
        }
        vs[k] = cycle[k].size();
    }
    inter.resize(vs[0], vector<int>(vs[1]));
    for(int i = 0; i < vs[0]; i++)
        for(int j = 0; j < vs[1]; j++)
        {
            inter[i][j] = find_intersection(cycle[0][i], cycle[1][j]);
            if(inter[i][j] != -1)
                g[i].push_back(j);
        }
 
    for(int i = 0; i < vs[1]; i++)
        mt[i] = -1;
    for(int i = 0; i < vs[0]; kuhn(i++))
        for(int j = 0; j < vs[0]; j++)
            u[j] = 0;
    set<int> res;
    for(int i = 0; i < n; i++) res.insert(i);
    for(int i = 0; i < vs[1]; i++)
        if(mt[i] != -1)
            res.erase(inter[mt[i]][i]);
    printf("%d\n", res.size());
    for(auto x : res) printf("%d ", x + 1);
    puts("");
}
