#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],c[1000];
    int i,n,len;
    scanf("%s",s);
    len=strlen(s);
    for(i=0; i<=len; i++)
    {
        if(i==0)
        {
            if((s[i]>='a')&&(s[i]<='z'))
                s[i]=s[i]-32;
            printf("%s",s);
        }

    }
}
