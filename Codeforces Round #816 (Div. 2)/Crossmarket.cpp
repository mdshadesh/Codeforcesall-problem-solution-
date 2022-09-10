#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (m > n)
        {
            swap(m, n);
        }
        if (m == n && m == 1)
        {
            cout << "0\n";
        }
        else
        {
            cout << n + (m - 2) * 2 + 2 << "\n";
        }
    }
    return 0;
}