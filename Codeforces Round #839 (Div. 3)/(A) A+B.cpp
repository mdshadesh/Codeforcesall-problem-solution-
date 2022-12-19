#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
 
    while (t--) 
    {
        string s;
        cin >> s;
 
         size_t pos = s.find('+');
 
        int a = stoi(s.substr(0, pos));
        int b = stoi(s.substr(pos + 1));
 
        cout << a + b << endl;
    }
 
    return 0;
}