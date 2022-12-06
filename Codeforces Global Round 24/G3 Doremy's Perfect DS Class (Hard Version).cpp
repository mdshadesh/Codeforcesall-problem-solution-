#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<array<int, 3>, int> asked;

    auto query = [&](int l, int r, int k) -> int {
        if (!asked.count({l, r, k})) {
            if (l >= r || r < 0 || l >= n) {
                asked[{l, r, k}] = 0;
            } else if (k == n && l + 1 == r) {
                asked[{l, r, k}] = 1;
            } else if (k == 2 && l == 0 && r == n) {
                asked[{l, r, k}] = n / 2 + 1;
            } else {
                cout << "? " << l + 1 << " " << r << " " << k << endl;
                cin >> asked[{l, r, k}];
            }
        }
        return asked[{l, r, k}];
    };

    auto inner = [&](int l, int r) {
        int res = query(l, r, 2);
        if (res == 0) {
            return 0;
        } else {
            return (r - l) - res;
        }
    };

    if (n % 2 == 1) {
        int L = 0, R = n;
        while (L + 1 < R) {
            int mid = (L + R) >> 1;
            int sum = mid - ((n / 2) - inner(mid, n) + inner(0, mid));
            if (sum == 1) {
                R = mid;
            } else {
                L = mid;
            }
        }
        cout << "! " << R << endl;
    } else {
        int L = 0, R = n;
        bool was_n = false;
        bool in_left = false;
        while (L + 2 < R) {
            int mid = (L + R) >> 1;
            int sum = mid - ((n / 2 - 1) - inner(mid, n) + inner(0, mid));
            if (sum == 2) {
                R = mid;
            } else if (sum == 0) {
                L = mid;
            } else if (was_n) {
                (in_left ? L : R) = mid;
            } else {
                was_n = true;
                if (mid > 1) {
                    in_left = query(0, mid, n) == 2;
                } else {
                    in_left = query(mid, n, n) != 2;
                }
                (in_left ? L : R) = mid;
            }
        }
        
        if (L + 1 < R) {
            int mid = (L + R) / 2;
            if (inner(0, L) + 1 == inner(0, R)) {
                if (inner(0, L) == inner(0, L + 1)) {
                    R = mid;
                }
            } else if (inner(R, n) + 1 == inner(L, n)) {
                if (inner(R, n) != inner(L + 1, n)) {
                    R = mid;
                }
            } else {
                if (L) {
                    if (query(0, L + 1, n) == 1) {
                        R = L + 1;
                    }
                } else {
                    if (query(L + 1, n, n) == 2) {
                        R = L + 1;
                    }
                }
            }
        }
        cout << "! " << R << endl;
    }

    return 0;
}