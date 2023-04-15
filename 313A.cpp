#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k >= 0)
    {
        cout << k << endl;
    }
    else
    {
        int a = k / 10;
        int b = k / 100 * 10 + k % 10;
        cout << max(a, b) << endl;
    }
    return 0;
}
		 	 	 	 												  	 	    	
