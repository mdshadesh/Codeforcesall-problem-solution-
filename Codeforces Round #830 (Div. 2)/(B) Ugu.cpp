#include<iostream>
#include<cstdio>
using namespace std;
int T,n,i,N;
char a[100007],b[100007];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf(" %c",&a[i]);
		N=0;
		b[++N]=a[1];
		for(i=2;i<=n;++i)
			if(a[i]!=a[i-1]) b[++N]=a[i];
		if(N==1) printf("0\n");
		else
		if(b[1]=='0') printf("%d\n",N-2);
		else printf("%d\n",N-1);
	}
}