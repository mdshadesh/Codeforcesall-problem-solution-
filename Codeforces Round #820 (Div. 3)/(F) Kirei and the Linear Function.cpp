#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
char s[N];
int preSum[N], mul[N];
vector<vector<int>> mp;
 
int n, w, m;
 
struct node {
    int l, r;
    bool operator < (const node& o) const {
        if(l == o.l) return r < o.r;
        return l < o.l;
    }
};
 
int get_val(int l, int r) {
    int len = r - l + 1;
    return (preSum[r] - preSum[l - 1] * mul[len] + 81) % 9;
}
 
void solve() {
    cin >> s + 1;
    n = strlen(s + 1);
    cin >> w >> m;
    mul[0] = 1;
    for(int i = 1; i <= n; i++) {
        preSum[i] = (preSum[i - 1] * 10 + (s[i] - '0')) % 9;
        mul[i] = mul[i - 1] * 10 % 9;
    }
    mp = vector<vector<int>>(9);
    for(int i = 1; i + w - 1 <= n; i++) {
        int l = i, r = i + w - 1;
        int val = get_val(l, r);
        mp[val].push_back(l);
    }
    int l, r, k;
    for(int i = 1; i <= m; i++) {
        cin >> l >> r >> k;
        int a = get_val(l, r);
        vector<node> candidates;
        for(int x = 0; x < 9; x++) {
            for(int y = 0; y < 9; y++) {
                if((a * x + y) % 9 == k) {
                    if(x != y && mp[x].size() && mp[y].size()) {
                        candidates.push_back({mp[x][0], mp[y][0]});
                    }
                    else if(x == y && mp[x].size() >= 2) {
                        candidates.push_back({mp[x][0], mp[x][1]});
                    }
                }
            }
        }
        sort(candidates.begin(), candidates.end());
        if(!candidates.size()) {
            cout << -1 << ' ' << -1 << '\n';
        } 
        else {
            cout << candidates[0].l << ' ' << candidates[0].r << '\n';
        }
    }
}
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int T; cin >> T;
    while(T--) solve();
    return 0;
}