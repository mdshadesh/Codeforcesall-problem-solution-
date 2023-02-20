#include <iostream>
#include <math.h>
int main()
{
	long long A;
	long long B;
	long long x;
	long long y;
	long long z;
	long long a;
	long long b;
	long long c=0;
	
	std::cin >> A;
	std::cin >> B;
	
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;

    a=2*x+y-A;
    b=y+3*z-B;

    if(a>0)
    {c+=a;
    	
    }
    if(b>0)
    {c+=b;
    	
    }
    
	std::cout << c << std::endl;
	return 0;
}
