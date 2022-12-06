
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define forn(i, a, b) for(int i = a; i < b; i++)
#define forr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

template <typename T>
class fenwick {  
public:           
    vector<T> fenw; 
    int n;          

    fenwick(int n) : n(n) {
        fenw.resize(n);
    }

    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x = x | (x + 1);
        }
    }

    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }   // 0-based  // 0-based      // 0-based
    T get(int l, int r) {   // get(x)  /
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    forn(i,0,m) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
    fenwick<int> fen(3*m+1);
    fen.modify(3*m, n);
    set<pair<int, int>> a;
    a.insert(mp(0, 3*m));
    a.insert(mp(n, 3*m));
    int cur = 2*m;
    for(int i  = m-1; i>=0; i--) {
        --cur;
        auto it2 = a.lower_bound(mp(l[i]+1, -1));
        --it2;
        auto it = it2;
        vector<pair<int, int>> del;
        int mx = 0;
        auto last = *it;
        while(it->first <= r[i]) {
            last = *it;
            ++it2;
            mx = max(mx, it->second);
            if(it->first >= l[i]) del.pb(*it);
            int f = max(it->first, l[i]);
            int to = min(it2->first-1,r[i]);
            fen.modify(it->second, f-to-1);
            ++it;
        }
        for(auto x : del) a.erase(x);
        if(it->first > r[i]+1) a.insert(mp(r[i]+1, last.second));
        fen.modify(cur, r[i]-l[i]);
        fen.modify(mx, 1);
        a.insert(mp(l[i], mx));
        if(r[i] > l[i]) a.insert(mp(l[i]+1, cur));
    }
    vector<int> ans(m, 0);
    for(int i  = m-1; i>=0; i--) {
        --cur;
        auto it2 = a.lower_bound(mp(l[i]+1, -1));
        --it2;
        auto it = it2;
        vector<pair<int, int>> del;
        int mx = 0;
        auto last = *it;
        while(it->first <= r[i]) {
            last = *it;
            ++it2;
            mx = max(mx, it->second);
            if(it->first >= l[i]) del.pb(*it);
            int f = max(it->first, l[i]);
            int to = min(it2->first-1,r[i]);
            fen.modify(it->second, f-to-1);
            ++it;
        }
        for(auto x : del) a.erase(x);
        if(it->first > r[i]+1) a.insert(mp(r[i]+1, last.second));
        fen.modify(cur, r[i]-l[i]);
        fen.modify(mx, 1);
        a.insert(mp(l[i], mx));
        if(r[i] > l[i]) a.insert(mp(l[i]+1, cur));
        ans[i] = fen.get(cur+k, 3*m);
    }
    forn(i,0,m) printf("%d ", ans[i]);      
}
