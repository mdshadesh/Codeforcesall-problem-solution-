#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int n,i,count=0;
    char ch[500],ch1;
    scanf("%d %s",&n,&ch);
    //printf("%d\n%s",n,ch);
    ch1 = ch[0];
    for(i=1;i<n;i++)
    {
        if (ch[i] == ch1)
        {
            ch1 = ch[i];
            count++;
        }
        else
        {
            ch1 = ch[i];
        }
    }
    printf("%d",count);


    return 0;
}