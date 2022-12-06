#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a < b ? a : b;
    int d = abs(a - b) / 2;
    printf("%d %d", c, d);
}