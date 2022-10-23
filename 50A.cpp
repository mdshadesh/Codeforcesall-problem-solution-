#include <stdio.h>
 
int main() {
    long long int m,n;
	scanf("%lld %lld",&m,&n);
	long long int area=m*n;
	if(area%2==0)
	{
	    printf("%lld",area/2);
	}
	else
	    printf("%lld",(area-1)/2);
	return 0;
}