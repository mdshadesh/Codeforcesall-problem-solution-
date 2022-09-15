#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
using namespace std;
 
void judge(const string&, int );
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    for (;t--;) {
        int s; cin >> s;
        string str;
        cin >> str;
        judge(str, s);
    }
 
}
 
void judge(const string& str, int size) {
    for (int i = 0; i < size; i++)
    {
        int num = str[i] - '0';
        if (num <= 2 && i < size - 2 && str[i+2] == '0' && str[i+3]!='0') {
            char ch = char(num*10 + int(str[i+1] - '0')-1 + int('a'));
            cout << ch;
            i += 2;
        }
        else {
            char ch = char(num+int('a')-1);
            cout << ch;
        }     
    }
    cout << '\n';
}