#include <bits/stdc++.h>

using namespace std;

char c[200001];

int n, i, k;

int main()
{
    cin >> n;

    for (i = 1; i <= n; i++) cin >> c[i];

    for (i = 2; i <= n; i += 2)
        if (c[i] == c[i - 1]) {
            k++;

            c[i - 1] = 'a';
            c[i] = 'b';
        }

    cout << k << endl;

    for (i = 1; i <= n; i++) cout << c[i];

    cout << endl;

    return 0;
}
