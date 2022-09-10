#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e5;
vector<int> times;
vector<vector<int>> rmq;
 
struct dsu{
    vector<int> p;
    vector<unordered_set<int>> values;
    int sz;
    dsu(int sz){
        this->sz = sz;
        p.resize(sz);
        values.resize(sz);
        for (int i = 0; i < sz; i++){
            p[i] = i;
            values[i].insert(i);
        }
    }
    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    int join(int a, int b, int k) {
        a = find(a);
        b = find(b);
        if (a == b){
            return a;
        }
        if (values[a].size() < values[b].size()) {
            swap(a, b);
        }
        p[b] = a;
        for (int val: values[b]) {
            values[a].insert(val);
        }
        for (int val : values[b]){
            if (val != 0 && times[val-1] == -1){
                if (values[a].find(val-1) != values[a].end()){
                    times[val-1] = k;
                }
            }
            if (val != sz-1 && times[val] == -1){
                if (values[a].find(val+1) != values[a].end()){
                    times[val] = k;
                }
            }
        }
        values[b].clear();
        return a;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, m, q;
        cin >> n >> m >> q;
        times.resize(n-1);
        fill(times.begin(), times.end(), -1);
        vector<pair<int,int>> edges;
        vector<pair<int,int>> queries;
        vector<int> ans(q, -1);
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b; a--; b--;
            edges.push_back({a,b});
        }
        for (int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v; u--; v--;
            if (u > v) swap(u,v);
            if (u == v){
                ans[i] = 0;
            }
            queries.push_back({u,v});
        }
        dsu d(n);
        for (int k = 0; k < m; k++){
            d.join(edges[k].first, edges[k].second, k+1);
        }
        rmq = vector<vector<int>>(n - 1, vector<int>((int)(log2(n)+2), -1));
        for (int i = 0; i < n - 1; i++){
            rmq[i][0] = times[i];
        }
        for (int c = 1; c < 18; c++){
            for (int i = 0; i + (1 << c) - 1 < n - 1; i++){
                rmq[i][c] = max(rmq[i][c-1], rmq[i+ (1 << (c-1))][c-1]);
            }
        }
        for (int i = 0; i < q; i++){
            if (ans[i] != 0){
                int curr = queries[i].first;
                for (int c = 18; c >= 0; c--){
                    if (((queries[i].second - curr) >> c) & 1){
                        ans[i] = max(ans[i], rmq[curr][c]);
                        curr += (1 << c);
                    }
                }
            }
        }
        for (int i = 0; i < q; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}