#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 100005;
const ll mod = 1000000007;
 
vector< pair<int, int> > g[N];
int ara[N];
int vis[N];
int n, q;
vector< tuple<int, int, int> > qq;
 
void testcase()
{
    cin >> n >> q;
    qq.clear();
    for (int i = 0; i <= n; i++) ara[i] = (1<<30) - 1;
    for (int i = 0; i < q; i++) {
        int u, v, x; cin >> u >> v >> x;
        if (u == v) {
            ara[u] = x;
        }
        qq.push_back({u, v, x});
    }
    for (int bit = 30; bit >= 0; bit--) {
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        for (auto [u, v, x] : qq) {
            int w = (x>>bit) & 1;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : g[u]) {
                if (w == 0) {
                    ara[u] = ara[u] & (~(1<<bit));
                    ara[v] = ara[v] & (~(1<<bit));
                }
            }
        }
        for (int u = 1; u <= n; u++) {
            if ((ara[u]>>bit) & 1) {
                int okay = 1;
                for (auto [v, w] : g[u]) {
                    int w1 = ((ara[v]>>bit) & 1) | 0;
                    if (w1 != w || u == v) {
                        okay = 0;
                        break;
                    }
                }
                if (okay) ara[u] = ara[u] & (~(1<<bit));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ara[i] << " ";
    }
    cout << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}