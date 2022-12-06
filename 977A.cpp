#include <iostream>
using namespace std;

int main()
{
	int x, y;
	std::cin >> x;
	std::cin >> y;
	for (int i = 0; i < y; i++) 
    {
		if (x % 10 == 0) 
        {
			x = x / 10;
		}
		else 
        {
			x -= 1;
		}
	};
	std::cout << x;
	return 0;
}

