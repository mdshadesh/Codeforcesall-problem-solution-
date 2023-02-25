#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
void Solve() {
    LL n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int> > p;
    for (int i = 2; i * i <= 1e9; ++i) {
        int k = 0;
        for (; m1 % i == 0; ++k) m1 /= i;
        for (; m2 % i == 0; ++k) m2 /= i;
        if (k > 0) p.emplace_back(i, k);
    }
    if (m1 == m2 && m1 > 1) p.emplace_back(m1, 2);
    else {
        if (m1 > 1) p.emplace_back(m1, 1);
        if (m2 > 1) p.emplace_back(m2, 1);
    }
    gp_hash_table<LL, LL> f;
    // unordered_map<LL, LL> f;
    LL S = 0, X = 0;
    function<void(int, LL)> Dfs = [&](int i, LL s) {
        if (i == p.size()) {
            LL mx = 1;
            for (int j = 0; j < i; ++j) {
                if (s % p[j].first != 0) continue;
                mx = max(mx, f[s / p[j].first]);
            }
            if (s <= n) mx = max(mx, s);
            f[s] = mx;
            if (s / mx <= n) {
                S += 1; X ^= s / mx;
            }
            return;
        }
        for (int k = 0; k <= p[i].second; ++k) {
            Dfs(i + 1, s);
            s *= p[i].first;
        }
    };
    Dfs(0, 1);
    cout << S << ' ' << X << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) Solve();
    return 0;
}