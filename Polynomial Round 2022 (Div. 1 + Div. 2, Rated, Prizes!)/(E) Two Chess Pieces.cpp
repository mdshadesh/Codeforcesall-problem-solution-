#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<bool> a(n), b(n);
    a[0] = b[0] = true;
    
    int m1;
    std::cin >> m1;
    for (int i = 0; i < m1; i++) {
        int x;
        std::cin >> x;
        x--;
        a[x] = true;
    }
    
    int m2;
    std::cin >> m2;
    for (int i = 0; i < m2; i++) {
        int x;
        std::cin >> x;
        x--;
        b[x] = true;
    }
    
    std::vector<int> par(n, -1), dep(n), p;
    auto dfs = [&](auto self, int u, std::array<int, 2> last) -> void {
        par[u] = (p.empty() ? -1 : p.back());
        
        if (a[u]) {
            last[0] = u;
        }
        
        if (b[u]) {
            last[1] = u;
        }
        
        if (a[u] && dep[last[1]] + d < dep[u]) {
            b[p.end()[-d]] = true;
        }
        
        if (b[u] && dep[last[0]] + d < dep[u]) {
            a[p.end()[-d]] = true;
        }
        
        for (int v : adj[u]) {
            if (v != par[u]) {
                dep[v] = dep[u] + 1;
                p.push_back(u);
                self(self, v, last);
                p.pop_back();
            }
        }
    };
    dfs(dfs, 0, std::array<int, 2> {-1, -1});
    
    int ans = 0;
    std::vector<bool> visa(n), visb(n);
    
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            int j = i;
            while (j != 0 && !visa[j]) {
                visa[j] = true;
                ans++;
                j = par[j];
            }
        }
        
        if (b[i]) {
            int j = i;
            while (j != 0 && !visb[j]) {
                visb[j] = true;
                ans++;
                j = par[j];
            }
        }
    }
    ans *= 2;
    
    std::cout << ans << '\n';
    
    return 0;
}