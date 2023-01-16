#include <iostream>

using namespace std;

int main()
{
    string s; cin >> s;
    int res {0};
    int pre = 97;
    for (int i = 0; i < s.size(); i++)
    {
        int ch  = (int)s[i];
        int s_a = abs(pre - ch);
        if (ch < pre) swap(ch, pre);
        int s_b = (122 - ch) + (pre - 97) + 1;
        res += min(s_a, s_b);
        pre = (int)s[i];
    }
    cout << res;
}
