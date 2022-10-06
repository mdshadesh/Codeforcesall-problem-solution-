#include<bits/stdc++.h>

using ld = long double;
using namespace std;

struct seg {
    ld x, y;
    explicit seg(ld X = 0, ld Y = 0) : x(X), y(Y){};
};

bool operator < (const seg &A, const seg &B) {
    return A.x/A.y < B.x/B.y;
}

void solve() {
    int n; ld A, B;
    cin >> n >> A >> B;
    vector<seg> p(n);
    for(auto &[x, y] : p)
        cin >> x;
    for(auto &[x, y] : p)
        cin >> y;
    ld ax = A, ay = B;
    ld bx = A, by = B;
    multiset<seg> q;
    for(auto &[x, y] : p) {
        q.insert(seg(2*x, 2*y));
        ax -= x, ay += y;
        while(ax < 0) {
            auto [X, Y] = *q.rbegin();
            q.erase(prev(q.end()));
            if(ax + X <= 0) {
                ax += X;
                ay -= Y;
                continue;
            }
            ld k = -ax / X;
            ax = 0;
            ay -= k * Y;
            q.insert(seg(X*(1-k), Y*(1-k)));
            break;
        }
        bx += x, by -= y;
        while(by < 0) {
            auto [X, Y] = *q.begin(); q.erase(q.begin());
            if(by + Y <= 0) {
                bx -= X;
                by += Y;
                continue;
            }
            ld k = -by / Y;
            by = 0;
            bx -= k * X;
            q.insert(seg(X*(1-k), Y*(1-k)));
            break;
        }
        printf("%.7Lf\n", bx);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
