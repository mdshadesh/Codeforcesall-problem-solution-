#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> s(n);
    LL sum = 0;
    for (LL& si: s) {
        cin >> si;
        sum += si;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i += 1)
        p[i] = i;
    sort(p.begin(), p.end(), [&](int x, int y){
        return s[x] < s[y];
    });
    int L = 0, R = n - 1;
    auto check = [&](int u) {
        LL csum = s[u], bit = 1LL << u;
        LL msum = 0, mbit = 0;
        vector<int> f(n);
        for (int i = 0; i < n; i += 1) f[i] = i;
        for (int i = 0; i < n; i += 1) swap(f[i], f[rand() % n]);
        for (int i = 1; i < n; i *= 2) {
            if (csum * n / i < sum) return false;
            function<void(int, LL, LL)> DFS = [&](int u, LL x, LL psum) {
                if (psum > csum) return;
                if (__builtin_popcountll(x) == i) {
                    if (psum > msum and (msum == 0 or 1.0 * rand() / RAND_MAX > exp(-psum / msum))) {
                        msum = psum;
                        mbit = x;
                    }
                    return;
                }
                if (u == n) return;
                if ((bit >> f[u]) % 2 == 0) DFS(u + 1, x | (1LL << f[u]), psum + s[f[u]]);
                DFS(u + 1, x, psum);
            };
            DFS(0, 0, 0);
            if (not mbit) return false;
            csum += msum;
            bit |= mbit; 
        }
        return true;
    };
    auto check_time = [&](int time, int u) {
        for (int i = 1; i <= time; i += 1)
            if (check(u)) return true;
        return false;
    };
    while (L < R) {
        int M = (L + R) >> 1;
        if (check_time(15, p[M])) R = M;
        else L = M + 1;
    }
    for (int i = 0; i < n; i += 1)
        cout << (s[i] >= s[p[L]]);
    return 0;
}