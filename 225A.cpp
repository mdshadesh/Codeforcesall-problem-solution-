#include <iostream>

using namespace std;

int main()
{
    int possible=1;
    int n, x, a, b;
    cin >> n >> x;
    while (n!=0)
    {
        cin >> a >> b;
        if (x == a || x == b || x == 7 - a || x == 7 - b)
        {
            possible = 0;
        }
        x = 7 - x;
        n--;
    }
    if(possible)
    	cout << "YES";
	else
		cout<<"NO"; 
    return 0;
}
